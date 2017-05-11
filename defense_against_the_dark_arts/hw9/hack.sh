#!/bin/bash

rm name.txt

gcc -m32 attack_format_string.c

./a.out > name.txt

./format_string_vulnerability.exe < name.txt
