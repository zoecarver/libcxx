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

int main()
{
    {
        std::observer_ptr<int> ptr;
        assert(ptr.release() == nullptr);
        assert(ptr.get() == nullptr);
    }
    {
        int* raw_ptr = new int;
        std::observer_ptr<int> ptr(raw_ptr);
        assert(ptr.release() == raw_ptr);
        assert(ptr.get() == nullptr);
        delete raw_ptr;
    }
}