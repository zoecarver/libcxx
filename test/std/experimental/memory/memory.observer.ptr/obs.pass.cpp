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

struct Foo {
    int x;
    Foo(int x) : x(x) {}
};

int main()
{
    int* raw_ptr = new int;
    {
        std::observer_ptr<int> ptr(raw_ptr);
        assert(ptr.get() == raw_ptr);
    }
    {
        std::observer_ptr<int> ptr1;
        bool check = ptr1;
        assert(check == false);

        std::observer_ptr<int> ptr2(raw_ptr);
        check = ptr2;
        assert(check == true);
    }
    {
        Foo* foo_ptr = new Foo(42);
        std::observer_ptr<Foo> ptr(foo_ptr);
        assert(ptr->x == 42);
        assert((*ptr).x == 42);

    }
    delete raw_ptr;

    return 0;
}