#!/bin/bash

#gcc -m32 -fno-stack-protector -g -O0 -z execstack -mpreferred-stack-boundary=2 arc_injection.c -o arc_injection
gcc -m32 -g -O0 data_section_overflow.c -o data_section_overflow