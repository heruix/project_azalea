/// @file
/// @brief Kernel memory buffer helper functions

#include "buffers.h"
#include "klib/tracing/tracing.h"
#include "klib/panic/panic.h"
#include "klib/misc/assert.h"

/// @brief Kernel memory setting function
///
/// A drop-in replacement for the familiar memset function. The entire buffer must be contained within kernel memory
/// (i.e. the upper half of virtual memory space) and must not wrap.
///
/// @param buffer The buffer whose value is set to a repetition of val.
///
/// @param val This character is repetitively filled across buffer.
///
/// @param len The length of the buffer to fill with the value in val
void kl_memset(void* buffer, unsigned char val, unsigned long len)
{
  unsigned long end = (unsigned long)buffer + len;

  // If end is less than buffer, then that suggests that the mem-setting would wrap back in to user space.
  ASSERT(end > (unsigned long)buffer);

  // Make sure this setting occurs in kernel space, by checking that the high bit of the address is set.
#ifndef AZALEA_TEST_CODE
  ASSERT(((unsigned long)buffer & (((unsigned long)1) << 63)) != 0);
#endif

	unsigned char* b = (unsigned char*)buffer;
	for(unsigned long done = 0; done < len; done++)
	{
		b[done] = val;
	}
}

/// @brief Kernel buffer copying function
///
/// A drop in replacement for the familiar memcpy function.
///
/// Buffers must not wrap the end of memory, and must be contained entirely within either the kernel or user space
/// parts of virtual memory. They must not overlap both parts.
///
/// It is the caller's responsibility to ensure that the destination buffer is large enough for the copying to occur.
///
/// @param from The buffer to copy from
///
/// @param to The buffer to copy to
///
/// @param len The length of data to copy.
void kl_memcpy(void *from, void *to, unsigned long len)
{
  unsigned char *f = (unsigned char *)from;
  unsigned char *t = (unsigned char *)to;
  unsigned long from_end = (unsigned long)from + len;
  unsigned long to_end = (unsigned long)to + len;

  // Make sure that the copying doesn't wrap.
  ASSERT(from_end > (unsigned long)from);
  ASSERT(to_end > (unsigned long)to);

  // Ensure that the buffers are contained entirely within user space if they start there. If they start in kernel
  // space then the ASSERTs above prevent them wrapping back to overlap userspace.
  if ((unsigned long)from < 0x8000000000000000)
  {
    ASSERT(from_end < 0x8000000000000000);
  }
  if ((unsigned long)to < 0x8000000000000000)
  {
    ASSERT(to_end < 0x8000000000000000);
  }

  for (unsigned long i = 0; i < len; i++)
  {
    *t = *f;
    t++;
    f++;
  }
}
