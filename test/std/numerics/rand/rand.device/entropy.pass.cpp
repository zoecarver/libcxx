//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <random>

// class random_device;

// double entropy() const;

#include "test_macros.h"

#include <random>
#include <cassert>

int main(int, char**)
{
    std::random_device r;
    double e = r.entropy();
    ((void)e); // Prevent unused warning

  return 0;
}
