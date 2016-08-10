#pragma once
#ifndef  VM_BASIC_TYPES_H
#define VM_BASIC_TYPES_H

typedef signed char        int8_t;
typedef short              int16_t;
typedef int                int32_t;
typedef long long          int64_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;

#ifndef _UINTPTR_T_DEFINED
#define _UINTPTR_T_DEFINED
#ifdef _WIN64
typedef unsigned __int64  uintptr_t;
#else
typedef unsigned int uintptr_t;
#endif
#endif


#endif // ! VM_BASIC_TYPES_H
