#!/bin/bash

#estruturas condicionais

#o uso de [] representa o comando test que serve para verificar algo
#o prefixo -f é usado para verificar a existencia de um arquivo
if [ -f /etc/passwd ] 
then
	echo "arquivo existe"

	if [ "$USER" = "debian" ] 
	then
		echo "Usuario é debian"

	fi
fi
