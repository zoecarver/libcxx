// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++98, c++03, c++11, c++14

// <experimental/memory>

// observer_ptr

#include <experimental/memory>
#include <type_traits>
#include <cassert>

#include "test_macros.h"

template<class T>
void custom_delete(T* ptr) { delete ptr; }
void custom_delete(void* ptr) { delete (int*)ptr; }

template<class T, class U>
void assert_constructability()
{
    typedef std::observer_ptr<T> OP;
    static_assert(std::is_nothrow_constructible<OP>::value, "");
    static_assert(std::is_nothrow_constructible<OP, std::nullptr_t>::value, "");
    static_assert(std::is_nothrow_constructible<OP, T*>::value, "");
    static_assert(std::is_nothrow_constructible<OP, OP const&>::value, "");
    static_assert(std::is_nothrow_constructible<OP, OP&&>::value, "");
    static_assert(std::is_nothrow_constructible<OP, std::observer_ptr<U>>::value, "");
}

template<class T>
void constrct_nullptr()
{
    {
        std::observer_ptr<T> ptr;
        assert(ptr.get() == nullptr);
    }
    {
        std::observer_ptr<T> ptr(nullptr);
        assert(ptr.get() == nullptr);
    }
}

template<class T>
void constrct_ptr(T* raw_ptr)
{
    std::observer_ptr<T> ptr(raw_ptr);
    assert(ptr.get() == raw_ptr);
    custom_delete(raw_ptr);
}

template<class T, class U>
void constrct_other(U* raw_ptr)
{
    std::observer_ptr<U> uptr(raw_ptr);
    std::observer_ptr<T> tptr(uptr);
    assert(uptr.get() == raw_ptr);
    assert(tptr.get() == raw_ptr);
    custom_delete(raw_ptr);
}

template<class T>
void test_copy_move(T* raw_ptr)
{
    std::observer_ptr<T> ptr_a(raw_ptr);
    std::observer_ptr<T> ptr_b(ptr_a);
    std::observer_ptr<T> ptr_c(std::move(ptr_a));
    assert(ptr_b.get() == raw_ptr);
    assert(ptr_c.get() == raw_ptr);
    custom_delete(raw_ptr);
}

struct Foo;
struct Bar
{
    Bar(int) {}
};

int main(int, char**)
{
    {
        assert_constructability<void, void>();
        assert_constructability<void, int>();
        assert_constructability<void, Bar>();
        assert_constructability<Foo,  void>();
        assert_constructability<Foo,  int>();
        assert_constructability<Foo,  Bar>();
        assert_constructability<int,  void>();
        assert_constructability<int,  int>();
        assert_constructability<int,  Bar>();
    }
    {
        constrct_nullptr<Foo>();
        constrct_nullptr<Bar>();
        constrct_nullptr<int>();
        constrct_nullptr<void>();
    }
    {
        constrct_ptr(new int);
        constrct_ptr(new Bar(42));
        constrct_ptr((void*)new int);
    }
    {
        // TODO: test overload resolution
        constrct_other<void>(new int);
        constrct_other<void>(new Bar(42));
    }
    {
        test_copy_move(new int);
        test_copy_move((void*)new int);
        test_copy_move(new Bar(42));
    }

    return 0;
}