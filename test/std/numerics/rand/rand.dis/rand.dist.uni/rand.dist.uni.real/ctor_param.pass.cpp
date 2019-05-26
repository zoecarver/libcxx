//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <random>

// template<class RealType = double>
// class uniform_real_distribution

// explicit uniform_real_distribution(const param_type& parm);

#include "test_macros.h"

#include <random>
#include <cassert>

int main(int, char**)
{
    {
        typedef std::uniform_real_distribution<> D;
        typedef D::param_type P;
        P p(3.5, 8);
        D d(p);
        assert(d.a() == 3.5);
        assert(d.b() == 8);
    }

  return 0;
}
