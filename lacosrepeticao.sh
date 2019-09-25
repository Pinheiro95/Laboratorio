#!/bin/bash

#laços de repetição 

#contador com while

CONTADOR=0

#enquanto o valor de CONTADOR for menor ou igual a 100
while [ "$CONTADOR" -le 100 ]
do
	echo -n "$CONTADOR " 
	CONTADOR=$(($CONTADOR + 1))

	if [ $CONTADOR -eq 50 ]
	then
		break
	fi
	
done

exit 0
