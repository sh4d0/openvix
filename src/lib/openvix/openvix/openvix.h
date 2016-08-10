#pragma once
#ifndef OPENVIX_H
#define OPENVIX_H

#include <vix.h>

#ifdef openvix_EXPORTS
#define OPENVIXAPI __declspec(dllexport)
#else
#define OPENVIXAPI __declspec(dllimport)
#endif

enum {
    VIX_HANDLE_TYPE_INVALID = 0,
    VIX_HANDLE_TYPE_HOST,
    VIX_HANDLE_TYPE_VM,
    VIX_HANDLE_TYPE_SNAPSHOT
};

typedef struct {
    uint32_t object_type;
    uint32_t object_version;
    uint32_t ref_count;
} vix_object_ctx;

typedef struct {
    vix_object_ctx header;
} vix_host_ctx;

typedef struct {
    vix_object_ctx header;
} vix_vm_ctx;

typedef struct {
    vix_object_ctx header;
} vix_snapshot_ctx;

#endif
