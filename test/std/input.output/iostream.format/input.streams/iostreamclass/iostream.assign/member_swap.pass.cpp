//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <istream>

// template <class charT, class traits = char_traits<charT> >
// class basic_iostream;

// void swap(basic_iostream& rhs);

#include "test_macros.h"

#include <istream>
#include <cassert>

template <class CharT>
struct testbuf
    : public std::basic_streambuf<CharT>
{
    testbuf() {}
};

template <class CharT>
struct test_iostream
    : public std::basic_iostream<CharT>
{
    typedef std::basic_iostream<CharT> base;
    test_iostream(testbuf<CharT>* sb) : base(sb) {}

    void swap(test_iostream& s) {base::swap(s);}
};

int main(int, char**)
{
    {
        testbuf<char> sb1;
        testbuf<char> sb2;
        test_iostream<char> is1(&sb1);
        test_iostream<char> is2(&sb2);
        is1.swap(is2);
        assert(is1.rdbuf() == &sb1);
        assert(is1.tie() == 0);
        assert(is1.fill() == ' ');
        assert(is1.rdstate() == is1.goodbit);
        assert(is1.exceptions() == is1.goodbit);
        assert(is1.flags() == (is1.skipws | is1.dec));
        assert(is1.precision() == 6);
        assert(is1.getloc().name() == "C");
        assert(is2.rdbuf() == &sb2);
        assert(is2.tie() == 0);
        assert(is2.fill() == ' ');
        assert(is2.rdstate() == is2.goodbit);
        assert(is2.exceptions() == is2.goodbit);
        assert(is2.flags() == (is2.skipws | is2.dec));
        assert(is2.precision() == 6);
        assert(is2.getloc().name() == "C");
    }
    {
        testbuf<wchar_t> sb1;
        testbuf<wchar_t> sb2;
        test_iostream<wchar_t> is1(&sb1);
        test_iostream<wchar_t> is2(&sb2);
        is1.swap(is2);
        assert(is1.rdbuf() == &sb1);
        assert(is1.tie() == 0);
        assert(is1.fill() == ' ');
        assert(is1.rdstate() == is1.goodbit);
        assert(is1.exceptions() == is1.goodbit);
        assert(is1.flags() == (is1.skipws | is1.dec));
        assert(is1.precision() == 6);
        assert(is1.getloc().name() == "C");
        assert(is2.rdbuf() == &sb2);
        assert(is2.tie() == 0);
        assert(is2.fill() == ' ');
        assert(is2.rdstate() == is2.goodbit);
        assert(is2.exceptions() == is2.goodbit);
        assert(is2.flags() == (is2.skipws | is2.dec));
        assert(is2.precision() == 6);
        assert(is2.getloc().name() == "C");
    }

  return 0;
}
