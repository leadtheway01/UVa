#!/bin/bash

gcc -m32 -fno-stack-protector -g -O0 -z execstack vulnerable_app.c -o vulnerable_app
#execstack -s vulnerable_app
