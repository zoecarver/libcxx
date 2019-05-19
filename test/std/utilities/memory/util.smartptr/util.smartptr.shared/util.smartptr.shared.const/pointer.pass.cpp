//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <memory>

// template<class Y> explicit shared_ptr(Y* p);

#include <memory>
#include <cassert>

struct A
{
    static int count;

    A() {++count;}
    A(const A&) {++count;}
    ~A() {--count;}
};

int A::count = 0;

int main(int, char**)
{
    {
        A* ptr = new A;
        std::shared_ptr<A> p(ptr);
        assert(A::count == 1);
        assert(p.use_count() == 1);
        assert(p.get() == ptr);
    }
    assert(A::count == 0);

//     {
//         A* ptr = new A;
//         std::shared_ptr<void> p(ptr);
//         assert(A::count == 1);
//         assert(p.use_count() == 1);
//         assert(p.get() == ptr);
//     }
//     assert(A::count == 0);

// TODO: add fail tests for when `delete[]` or `delete` does not work.
// #if _LIBCPP_NEW_SHARED_PTR && false
//     {
//         A* ptr[8];
//         for (unsigned i = 0; i < 8; ++i) ptr[i] = new A;
//
//         std::shared_ptr<A[8]> p(ptr);
//         assert(A::count == 8);
//         assert(p.use_count() == 1);
//         assert(p.get() == ptr);
//     }
//     assert(A::count == 0);
// #endif

    return 0;
}
