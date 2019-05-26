//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <random>

// template<class RealType = double>
// class weibull_distribution
// {
//     class param_type;

#include "test_macros.h"

#include <random>
#include <limits>
#include <cassert>

int main(int, char**)
{
    {
        typedef std::weibull_distribution<> D;
        typedef D::param_type param_type;
        param_type p0(10, .125);
        param_type p = p0;
        assert(p.a() == 10);
        assert(p.b() == .125);
    }

  return 0;
}
