#!/bin/bash

rm attack_spell3.txt

gcc -m32 attack_spell3.c

./a.out > attack_spell3.txt

./challenge3.exe < attack_spell3.txt




