//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <queue>

// template <class T, class Container>
//   bool operator==(const queue<T, Container>& x,const queue<T, Container>& y);
//
// template <class T, class Container>
//   bool operator!=(const queue<T, Container>& x,const queue<T, Container>& y);

#include "test_macros.h"

#include <queue>
#include <cassert>

template <class C>
C
make(int n)
{
    C c;
    for (int i = 0; i < n; ++i)
        c.push(i);
    return c;
}

int main(int, char**)
{
    std::queue<int> q1 = make<std::queue<int> >(5);
    std::queue<int> q2 = make<std::queue<int> >(10);
    std::queue<int> q1_save = q1;
    std::queue<int> q2_save = q2;
    assert(q1 == q1_save);
    assert(q1 != q2);
    assert(q2 == q2_save);

  return 0;
}
