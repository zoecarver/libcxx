//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <random>

// template<class RealType = double>
// class extreme_value_distribution
// {
//     class param_type;

#include "test_macros.h"

#include <random>
#include <limits>
#include <cassert>

int main(int, char**)
{
    {
        typedef std::extreme_value_distribution<> D;
        typedef D::param_type param_type;
        param_type p1(0.75, .5);
        param_type p2(0.75, .5);
        assert(p1 == p2);
    }
    {
        typedef std::extreme_value_distribution<> D;
        typedef D::param_type param_type;
        param_type p1(0.75, .5);
        param_type p2(0.5, .5);
        assert(p1 != p2);
    }

  return 0;
}
