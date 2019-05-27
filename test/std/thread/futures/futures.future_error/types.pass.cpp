//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// UNSUPPORTED: libcpp-has-no-threads

// <future>

// class future_error : public logic_error {...};

#include "test_macros.h"

#include <future>
#include <type_traits>

int main(int, char**)
{
    static_assert((std::is_convertible<std::future_error*,
                                       std::logic_error*>::value), "");

  return 0;
}
