//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <locale>

// template <> class ctype<char>;

// const char* widen(const char* low, const char* high, char* to) const;

#include "test_macros.h"

#include <locale>
#include <string>
#include <vector>
#include <cassert>

int main(int, char**)
{
    std::locale l = std::locale::classic();
    {
        typedef std::ctype<char> F;
        const F& f = std::use_facet<F>(l);
        std::string in(" A\x07.a1");
        std::vector<char> v(in.size());

        assert(f.widen(&in[0], in.data() + in.size(), v.data()) == in.data() + in.size());
        assert(v[0] == ' ');
        assert(v[1] == 'A');
        assert(v[2] == '\x07');
        assert(v[3] == '.');
        assert(v[4] == 'a');
        assert(v[5] == '1');
    }

  return 0;
}
