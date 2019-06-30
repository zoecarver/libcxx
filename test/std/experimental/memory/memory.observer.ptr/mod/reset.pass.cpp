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
        std::experimental::observer_ptr<int> ptr;
        ptr.reset(raw_ptr1);
        assert(ptr.get() == raw_ptr1);
    }
    {
        std::experimental::observer_ptr<int> ptr(raw_ptr1);
        ptr.reset(raw_ptr2);
        assert(ptr.get() == raw_ptr2);
    }

    delete raw_ptr1;
    delete raw_ptr2;

    return 0;
}