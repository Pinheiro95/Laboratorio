#!/bin/bash

#usando o laço de repetição for para mostrar os usuarios do sistema

TIME=1
for user in `ls /home/`
	do
		echo "os usuarios sao: $user"
		sleep $TIME
	done
