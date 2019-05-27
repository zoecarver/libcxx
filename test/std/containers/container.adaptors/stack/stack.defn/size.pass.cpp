//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <stack>

// size_type size() const;

#include "test_macros.h"

#include <stack>
#include <cassert>

int main(int, char**)
{
    std::stack<int> q;
    assert(q.size() == 0);
    q.push(1);
    assert(q.size() == 1);

  return 0;
}
