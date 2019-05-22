//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <memory>

// shared_ptr

// element_type& operator-[](ptrdiff_t i) const;

#include <memory>
#include <cassert>

template<class T>
struct array_deleter : std::default_delete<T>
{
    void operator()(T*)
    {}
};

int main(int, char**)
{
    int arr[4] = { 0, 1, 2, 3 };
    std::shared_ptr<int[4]> sp(&arr, array_deleter<int[4]>());

    return 0;
}

