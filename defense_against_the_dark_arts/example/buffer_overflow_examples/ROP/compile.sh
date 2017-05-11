#!/bin/bash

gcc -m32 -fno-stack-protector -g -O0 -z execstack -mpreferred-stack-boundary=2 ROP.c gadgets.s -o ROP
#execstack -s vulnerable_app
