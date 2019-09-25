#!/bin/bash

#Estrutura condicional com case

declare ESTADO
declare IDADE

echo "Digite o nome de um estado da região sudeste"
read TEMP

#passando os caracteres minusculos para maiusculos 
ESTADO=`echo $TEMP | tr [:lower:] [:upper:]`

#estrutura case
case $ESTADO in
	'RIO DE JANEIRO') echo "A capital do $ESTADO é RIO DE JANEIRO";;
	'SAO PAULO') echo "A capital do $ESTADO é SÃO PAULO";;
	'ESPIRITO SANTO') echo "A capital do $ESTADO é VITÓRIA";;
	'MINAS GERAIS') echo "A capital do $ESTADO é BELO HORIZONTE";;
	*) echo "Estado não reconhecido";;
esac

#usando case com numeros

echo "Digite a sua idade"
read IDADE

case $IDADE in
	[0-9]) echo "você é criança";;
	[1][0-9]) echo "Você é jovem";;
	[2-5][0-9]) echo "Você é adulto completo";;
	[6-8][0-9]) echo "Você é um idoso";;
	*) echo "Você é muito velho mesmo";;
esac

