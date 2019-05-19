//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <memory>

// shared_ptr();

#include <memory>
#include <cassert>

struct A { };

template<class T>
void test()
{
    {
        std::shared_ptr<T> p;
        assert(p.use_count() == 0);
        assert(p.get() == 0);
    }
    {
        std::shared_ptr<T> p {};
        assert(p.use_count() == 0);
        assert(p.get() == 0);
    }
}

int main(int, char**)
{
    test<int>();
    test<A>();
    test<int*>();
//     test<int[]>();
//     test<int[8]>();

    return 0;
}
