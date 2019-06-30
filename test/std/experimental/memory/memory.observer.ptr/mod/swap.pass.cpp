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

int main(int, char**)
{
    int* raw_ptr1 = new int;
    int* raw_ptr2 = new int;

    {
        std::experimental::observer_ptr<int> ptr1;
        std::experimental::observer_ptr<int> ptr2;
        ptr1.swap(ptr2);
        assert(ptr1.get() == nullptr);
        assert(ptr2.get() == nullptr);
    }
    {
        std::experimental::observer_ptr<int> ptr1(raw_ptr1);
        std::experimental::observer_ptr<int> ptr2;
        ptr1.swap(ptr2);
        assert(ptr1.get() == nullptr);
        assert(ptr2.get() == raw_ptr1);
    }
    {
        std::experimental::observer_ptr<int> ptr1;
        std::experimental::observer_ptr<int> ptr2(raw_ptr2);
        ptr1.swap(ptr2);
        assert(ptr1.get() == raw_ptr2);
        assert(ptr2.get() == nullptr);
    }
    {
        std::experimental::observer_ptr<int> ptr1(raw_ptr1);
        std::experimental::observer_ptr<int> ptr2(raw_ptr2);
        ptr1.swap(ptr2);
        assert(ptr1.get() == raw_ptr2);
        assert(ptr2.get() == raw_ptr1);
    }

    delete raw_ptr1;
    delete raw_ptr2;

    return 0;
}