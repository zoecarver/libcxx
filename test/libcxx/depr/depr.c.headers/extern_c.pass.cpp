//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// Sometimes C++'s <foo.h> headers get included within extern "C" contexts. This
// is ill-formed (no diagnostic required), per [using.headers]p3, but we permit
// it as an extension.

extern "C" {
#include "test_macros.h"

#include <assert.h>
// complex.h is not supported in extern "C".
#include <ctype.h>
#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <inttypes.h>
#include <iso646.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdalign.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// tgmath.h is not supported in extern "C".
#include <time.h>
// FIXME: #include <uchar.h>
#include <wchar.h>
#include <wctype.h>
}

int main(int, char**) {
  return 0;
}
