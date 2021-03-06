#ifndef _TEST_CORE_H
#define _TEST_CORE_H

// Allow asserting in all tests. Expect to be linked against the dummy panic lib
// so that panics are caught by the test system.
#include "klib/misc/assert.h"
#include "klib/tracing/tracing.h"
#include "klib/panic/panic.h"

typedef void (*test_entry_ptr)();

struct single_test
{
  const test_entry_ptr entry_point;
  const char *test_name;
};

class assertion_failure
{
public:
  assertion_failure(const char *reason);
  const char *get_reason();

private:
  const char *_reason;
};

extern single_test test_list[];
extern unsigned int number_of_tests;

#endif
