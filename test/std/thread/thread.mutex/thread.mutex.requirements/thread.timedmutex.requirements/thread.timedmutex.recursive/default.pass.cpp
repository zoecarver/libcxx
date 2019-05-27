//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// UNSUPPORTED: libcpp-has-no-threads

// <mutex>

// class recursive_timed_mutex;

// recursive_timed_mutex();

#include "test_macros.h"

#include <mutex>

int main(int, char**)
{
    std::recursive_timed_mutex m;

  return 0;
}
