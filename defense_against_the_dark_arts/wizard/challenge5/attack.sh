#!/bin/bash

rm attack_spell5.txt

gcc -m32 attack_spell5.c

./a.out > attack_spell5.txt

./challenge5.exe < attack_spell5.txt




