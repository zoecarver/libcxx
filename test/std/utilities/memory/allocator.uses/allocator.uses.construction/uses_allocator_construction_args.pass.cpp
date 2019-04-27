//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <memory>

#include <memory>
#include <utility>
#include <cassert>
#include <iostream>

#include "test_macros.h"

using pair_t = std::pair<int, double>;

struct A
{
    int a;
    float b;

    A(int a, float b): a(a), b(b) { }
};

template <class T, class... Args>
T test_uses_alloc(Args&&... args)
{
    auto args_tuple = std::uses_allocator_construction_args<T>(std::forward<Args>(args)...);
    auto arg_count = std::tuple_size<decltype(args_tuple)>::value;
    assert(arg_count == 3);

    return std::make_from_tuple<T>(args_tuple);
}

int main(int, char**)
{
    // non pair contruction
    std::allocator<A> alloc;
    auto a = std::make_obj_using_allocator<A>(alloc, 10, 5.0);

    ASSERT_SAME_TYPE(decltype(a), A);
    assert(a.a == 10);
    assert(a.b == 5.0);

    auto* b = std::uninitialized_construct_using_allocator(&a, alloc, 20, 10.0);

    assert(a.a == 20);
    assert(a.b == 10.0);

    ASSERT_SAME_TYPE(decltype(b), A*);
    assert(b->a == 20);
    assert(b->b == 10.0);

    assert(&a == b);

    // pair construction
    std::allocator<pair_t> p_alloc;
    pair_t p { 10, 5.0 };

    test_uses_alloc<pair_t>(p_alloc);
    auto res = test_uses_alloc<pair_t>(p_alloc, 10, 5.0);
    auto res1 = test_uses_alloc<pair_t>(p_alloc, p);
    assert(res.first == res1.first &&
           res.second == res1.second &&
           res.first == 10 &&
           res.second == 5.0);

    return 0;
}
