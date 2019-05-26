#!/bin/bash

find test/ -type f -name \*pass.cpp -exec ./awk.sh {} \;