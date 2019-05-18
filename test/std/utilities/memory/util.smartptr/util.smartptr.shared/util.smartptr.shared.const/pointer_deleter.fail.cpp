//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <memory>

// shared_ptr

// template<class Y, class D> shared_ptr(Y* p, D d);

#include <memory>

struct NotDeleter
{
    NotDeleter() = default;
    NotDeleter(NotDeleter const&) = default;
    NotDeleter(NotDeleter&&) = default;
};

template<class T>
struct NoMoveDeleter
{
    NoMoveDeleter() = default;
    NoMoveDeleter(NoMoveDeleter const&) = default;
    NoMoveDeleter(NoMoveDeleter&&) = delete;

    void operator()(T*) { }
};

int main(int, char**)
{
    {
        int* ptr = new int;
        // expected-error@memory:* {{type 'NotDeleter' does not provide a call operator}}
        std::shared_ptr<int> bp0(ptr, NotDeleter()); // expected-error@memory:* {{type 'NotDeleter' does not provide a call operator}}
        std::shared_ptr<int> bp1(ptr, NoMoveDeleter<int>()); // expected-error@memory:* {{call to deleted constructor of 'NoMoveDeleter<int>'}}
    }

    return 0;
}
