//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <random>

// template<class RealType = double>
// class normal_distribution

// bool operator=(const normal_distribution& x,
//                const normal_distribution& y);
// bool operator!(const normal_distribution& x,
//                const normal_distribution& y);

#include "test_macros.h"

#include <random>
#include <cassert>

int main(int, char**)
{
    {
        typedef std::normal_distribution<> D;
        D d1(2.5, 4);
        D d2(2.5, 4);
        assert(d1 == d2);
    }
    {
        typedef std::normal_distribution<> D;
        D d1(2.5, 4);
        D d2(2.5, 4.5);
        assert(d1 != d2);
    }

  return 0;
}
