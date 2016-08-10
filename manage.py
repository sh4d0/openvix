import argparse
import os
import subprocess
import sys

SCRIPT_DIR = os.path.dirname(__file__)


class ExecException(Exception):
    pass


class Exec(object):
    @staticmethod
    def run(cmd, workingdir=None):
        p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, cwd=workingdir)
        out = p.communicate()[0]

        return out

    @classmethod
    def run_cmd(cls, args, workingdir=None):
        return cls.run('cmd /c %s' % args, workingdir)

    @classmethod
    def cmake_version(cls):
        cmd = 'cmake --version'
        out = cls.run_cmd(cmd).decode()

        if 'cmake version' not in out:
            raise ExecException('Unable to find cmake, if it is installed, check your PATH variable.')

    @classmethod
    def vs_info(cls):
        if 'VCINSTALLDIR' not in os.environ:
            raise ExecException('Unable to detect build environment.')

        cmd = 'cl'
        out = cls.run_cmd(cmd).decode()

        if 'x86' in out:
            arch = 'x86'
        elif 'x64' in out:
            arch = 'x64'
        else:
            raise ExecException('Unable to detect build environment.')

        if '15.00' in out:
            version = 9
        elif '16.00' in out:
            version = 10
        elif '17.00' in out:
            version = 11
        elif '18.00' in out:
            version = 12
        elif '19.00' in out:
            version = 14
        else:
            raise ExecException('Unable to detect build environment.')

        return arch, version


class CMake(object):
    def __init__(self, arch, version):
        assert version in [7, 8, 9, 10, 11, 12, 14], 'Unsupported version (%s)' % version
        assert arch.lower() in ['x86', 'x64'], 'Unsupported arch (%s)' % arch

        self.version = version
        self.arch = arch

    @property
    def generator(self):

        if self.arch.lower() == 'x64':
            arch = 'Win64'
        else:
            arch = ''

        return ('Visual Studio %s %s' % (self.version, arch)).strip()


def generate(arch=None, version=None):
    cmake = CMake(arch=arch, version=version)

    build_dir = os.path.join(SCRIPT_DIR, 'build', cmake.arch)
    if not os.path.exists(build_dir):
        os.makedirs(build_dir)

    result = Exec.run_cmd(
        'cmake -G "%s" ../.. --debug-output' % cmake.generator, workingdir=build_dir).decode()
    print(result)


def manage(generate_sln=True, build_sln=False, test_sln=False, **kwargs):
    if test_sln is True:
        build_sln = True

    if build_sln is True:
        generate_sln = True

    if generate_sln is True:
        generate(**kwargs)
    else:
        raise Exception('Did not enable at least one of "generate", "build" or "test"');


def main(argv=sys.argv[1:]):
    parser = argparse.ArgumentParser(description='Manage CMake projects')
    parser.add_argument('--generate', dest='generate_sln', action='store_true', default=True,
                        help='Generate VS Solution file')
    parser.add_argument('--build', dest='build_sln', action='store_true', default=False, help='Build source')
    parser.add_argument('--test', dest='test_sln', action='store_true', default=False, help='Run tests')
    parser.add_argument('--arch', default=None, choices=['x86', 'x64'],
                        help='Arch of Visual Studio if not run from VS command prompt')
    parser.add_argument('--version', default=None, choices=[7, 8, 9, 10, 11, 12, 14], type=int,
                        help='Version of Visual Studio of not run from VS command prompt')

    args = parser.parse_args(argv)

    Exec.cmake_version()  # Make sure we have located cmake

    if args.arch is None or args.version is None:
        vs_info = Exec.vs_info()
        if args.arch is None:
            args.arch = vs_info[0]

        if args.version is None:
            args.version = vs_info[1]

    manage(**vars(args))


if __name__ == '__main__':
    main()
