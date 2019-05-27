//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <memory>

// unique_ptr

// test op->()

#include "test_macros.h"

#include <memory>
#include <cassert>

struct A {
  int i_;

  A() : i_(7) {}
};

int main(int, char**) {
  std::unique_ptr<A> p(new A);
  assert(p->i_ == 7);

  return 0;
}
