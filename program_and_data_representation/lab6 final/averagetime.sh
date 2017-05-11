#Wright Kim
#wdk7nk
#10/21/15
#averagetime.sh

#!bin/bash
echo 'Input the dictionary file name'
	read dictionary


echo 'Input the grid file name'
	read grid


RUNNING_TIME=`./a.out $dictionary $grid | tail -1`

t1=RUNNING_TIME
t2=RUNNING_TIME
t3=RUNNING_TIME
t4=RUNNING_TIME
t5=RUNNING_TIME

tot=`(expr($t1 + $t2 + $t3 + $t4 + $t5) / 5)`
echo "$tot"
