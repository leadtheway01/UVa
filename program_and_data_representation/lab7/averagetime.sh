#Wright Kim
#wdk7bj
#10/30/15
#averagetime.sh

#!bin/bash
echo 'enter the exponent for counter.cpp:'
	read number

count=1
counter=0

if [[ $number = "quit" ]] ; then
	exit 1
else
	while [[ $counter -lt 5 ]]; do
		RUNNING_TIME=`./a.out $number | tail -1`
		total=$(( total + RUNNING_TIME ))
		
		echo "Running iteration $count..."
		echo "time taken: $RUNNING_TIME ms"
		let counter=$(( counter + 1 ))
		let count=$(( count + 1 ))
	done
	echo "5 iteration took $total ms"
	average=$(( total / 5 ))
	echo "Average time was $average ms"
fi