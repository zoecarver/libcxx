//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <iterator>

// struct output_iterator_tag {};

#include "test_macros.h"

#include <iterator>
#include <type_traits>

int main(int, char**)
{
    std::output_iterator_tag tag;
    ((void)tag); // Prevent unused warning
    static_assert((!std::is_base_of<std::input_iterator_tag,
                                    std::output_iterator_tag>::value), "");

  return 0;
}
