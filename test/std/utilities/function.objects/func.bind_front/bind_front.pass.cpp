//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++98, c++03, c++11, c++14, c++17

// functional

// template <class F, class... Args> unspecified bind_front(F&&, Args&&...);

#include <functional>
#include "../callable_types.h"

void basic_tests()
{
    int add (int a, int b) { return a + b; }

    int long_test (int a, int b, int c, int d, int e, int f)
    { return a + b + c + d + e + f; }

    struct S { bool operator()(int a) { return a == 1; } };

    int n = 2;
    int m = 1;

    auto a = std::bind_front(add, m, n);
    assert(a() == 3);

    auto b = std::bind_front(long_test, m, n, m, m, m, m);
    assert(b() == 7);

    auto c = std::bind_front(long_test, n, m);
    assert(c(1, 1, 1, 1) == 7);

    auto d = std::bind_front(S{}, m);
    assert(d());

    auto f = std::bind_front(add, n);
    assert(f(3) == 5);
}

int main(int, char**)
{
    basic_tests();

    return 0;
}