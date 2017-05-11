#!/bin/bash

rm attack_spell4.txt

gcc -m32 attack_spell4.c

./a.out > attack_spell4.txt

./challenge4.exe < attack_spell4.txt




