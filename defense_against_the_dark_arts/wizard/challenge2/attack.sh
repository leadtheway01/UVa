#!/bin/bash

rm attack_spell2.txt
rm a.out

gcc -m32 attack_spell2.c

./a.out > attack_spell2.txt

./challenge2.exe < attack_spell2.txt




