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

    A(int a, float b) : a(a), b(b) { }
};

struct B : A
{
    using allocator_type = std::allocator<B>;
    B(std::allocator_arg_t, std::allocator<B>, int a, int b) : A(a, b) { }
};

struct C : A
{
    using allocator_type = std::allocator<C>;
    C(int a, int b, std::allocator<C>) : A(a, b) { }
};

template <class T, class... Args>
T test_uses_alloc(Args&&... args)
{
    auto args_tuple = std::uses_allocator_construction_args<T>(std::forward<Args>(args)...);
    const auto arg_count = std::tuple_size<decltype(args_tuple)>::value;
    static_assert(arg_count == sizeof...(Args) - 1);

    return std::make_from_tuple<T>(args_tuple);
}

void general_tests()
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

    auto res2 = test_uses_alloc<A>(std::allocator<A>(), 10, 10.0);
    assert(res2.a == res2.b && res2.a == 10);
}

void test_no_allocator()
{
    auto args_tuple = std::uses_allocator_construction_args<A>(std::allocator<void>{}, 10, 5.0);
    const auto arg_count = std::tuple_size<decltype(args_tuple)>::value;
    static_assert(arg_count == 2);

    assert(std::get<0>(args_tuple) == 10);
    assert(std::get<1>(args_tuple) == 5.0);

    auto a = std::make_from_tuple<A>(args_tuple);
    assert(a.a == 10);
    assert(a.b == 5.0);
}

void test_no_pair()
{
    { // make sure we are calling the correct overload
        static_assert(!std::uses_allocator<A, std::allocator<A>>::value);
        static_assert(!std::is_constructible<A, std::allocator_arg_t, std::allocator<A>, int, int>::value);
        static_assert( std::is_constructible<A, int, int>::value);
        static_assert( std::uses_allocator<B, std::allocator<B>>::value);
        static_assert( std::is_constructible<B, std::allocator_arg_t, std::allocator<B>, int, int>::value);
        static_assert( std::uses_allocator<C, std::allocator<C>>::value);
        static_assert( std::is_constructible<C, int, int, std::allocator<B>>::value);
    }
    {
        auto args_tuple = std::uses_allocator_construction_args<B>(std::allocator<B>{}, 10, 5.0);
        const auto arg_count = std::tuple_size<decltype(args_tuple)>::value;
        static_assert(arg_count == 4);

        assert(std::get<2>(args_tuple) == 10);
        assert(std::get<3>(args_tuple) == 5.0);

        auto b = std::make_from_tuple<B>(args_tuple);
        assert(b.a == 10);
        assert(b.b == 5.0);
    }
    {
        auto args_tuple = std::uses_allocator_construction_args<C>(std::allocator<C>{}, 10, 5.0);
        const auto arg_count = std::tuple_size<decltype(args_tuple)>::value;
        static_assert(arg_count == 3);

        assert(std::get<0>(args_tuple) == 10);
        assert(std::get<1>(args_tuple) == 5.0);

        auto c = std::make_from_tuple<C>(args_tuple);
        assert(c.a == 10);
        assert(c.b == 5.0);
    }
}

int main(int, char**)
{
    general_tests();
    test_no_allocator();
    test_no_pair();

    return 0;
}
