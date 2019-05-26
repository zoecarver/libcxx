//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <ios>

// template <class StateT> class fpos

// Addition

#include "test_macros.h"

#include <ios>
#include <cassert>

int main(int, char**)
{
    typedef std::fpos<std::mbstate_t> P;
    P p(5);
    std::streamoff o(6);
    P q = p + o;
    assert(q == P(11));
    p += o;
    assert(p == q);

  return 0;
}
