// Main include for Project Azalea Kernel Support Library - 'klib'
//
// klib provides processor-agnostic helper functions that will be used throughout the kernel.
#pragma once

// For the time being, map _DEBUG to KLIB_DEBUG. There's no actual need for this to be fixed.
// If KLIB_DEBUG is set, the debug version of the klib library is needed.
#ifdef _DEBUG
#define KLIB_DEBUG
#endif

#include "klib/misc/kernel_types.h"
#include "klib/misc/error_codes.h"
#include "klib/data_structures/lists.h"
#include "klib/data_structures/binary_tree.h"
#include "klib/data_structures/red_black_tree.h"
#include "klib/c_helpers/string_fns.h"
#include "klib/data_structures/string.h"
#include "panic/panic.h"
#include "c_helpers/buffers.h"
#include "misc/assert.h"
#include "memory/memory.h"
#include "misc/math_hacks.h"
#include "misc/vargs.h"
#include "tracing/tracing.h"
#include "synch/kernel_locks.h"
#include "synch/kernel_mutexes.h"
#include "synch/kernel_semaphores.h"
#include "c_helpers/printf_fns.h"
