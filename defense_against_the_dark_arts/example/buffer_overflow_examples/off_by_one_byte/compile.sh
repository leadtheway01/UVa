#!/bin/bash

gcc -m32 -fno-stack-protector -g -O0 -z execstack off_by_one.s -o off_by_one
#execstack -s vulnerable_app
