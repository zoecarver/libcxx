//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <version>

#include "test_macros.h"

#include <version>

#if !defined(_LIBCPP_VERSION)
#error "_LIBCPP_VERSION must be defined after including <version>"
#endif

int main(int, char**)
{

  return 0;
}
