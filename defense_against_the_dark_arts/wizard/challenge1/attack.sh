#!/bin/bash

rm attack_spell1.txt

gcc -m32 attack_spell1.c

./a.out > attack_spell1.txt

./challenge1.exe < attack_spell1.txt




