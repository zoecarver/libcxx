//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <memory>

// shared_ptr

// explicit operator bool() const;

#include <memory>
#include <cassert>

struct A
{
    int a;
    virtual ~A() {};
};
struct B : A { };

int main(int, char**)
{
    {
        const std::shared_ptr<int> p(new int(32));
        assert(p);
    }
    {
        const std::shared_ptr<int> p;
        assert(!p);
    }
    {
        bool check = false;
        std::shared_ptr<A> basePtr = std::make_shared<B>();

        if (std::shared_ptr<B> sp = std::dynamic_pointer_cast<B>(basePtr))
        { check = true; }

        assert(check);
    }

    return 0;
}
