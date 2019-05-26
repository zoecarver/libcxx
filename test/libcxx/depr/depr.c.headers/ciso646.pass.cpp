//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <ciso646>

#include "test_macros.h"

#include <ciso646>

#ifndef _LIBCPP_VERSION
#error _LIBCPP_VERSION not defined
#endif

int main(int, char**)
{

  return 0;
}
