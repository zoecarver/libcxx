//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// test <assert.h>

#include "test_macros.h"

#include <assert.h>

#ifndef assert
#error assert not defined
#endif

int main(int, char**)
{

  return 0;
}
