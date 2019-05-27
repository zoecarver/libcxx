//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <iterator>

// class ostream_iterator

// ostream_iterator& operator*() const;

#include "test_macros.h"

#include <iterator>
#include <sstream>
#include <cassert>

int main(int, char**)
{
    std::ostringstream os;
    std::ostream_iterator<int> i(os);
    std::ostream_iterator<int>& iref = *i;
    assert(&iref == &i);

  return 0;
}
