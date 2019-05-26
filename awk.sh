#!/bin/bash

if ! grep -q "test_macros.h" $1 ; then
#     echo foo
    awk -i inplace '!r && /^(#include.*)/ {
val=/^(#include.*)/;
sub($val,$val" \"test_macros.h\"\n\n#include");
r=1
} 1' $1 ;
fi