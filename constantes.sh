#!/bin/bash

#criando variaveis e constantes para scripts no shell

clear
#declarando variavel

NOME='BRUNO'
IDADE=24

echo "Meu nome é $NOME, e eu tenho $IDADE anos"


#outra forma de declarar variavel

declare NOME2
declare ALTURA
#o prefixo -i significa que o conteudo da variavel será um número inteiro
declare -i PESO
declare IMC
declare -r CONSTANTE=10

echo "Valor da constante: $CONSTANTE"
CONSTANTE=15

#interagindo com o usuario
#o prefixo -n serve para que o comando echo nao pule linha
echo -n "Diga seu nome: "
read NOME2

echo -n "Qual a sua altura: "
read ALTURA

echo -n "Qual o seu peso: "
read PESO

#calculo do IMC
IMC=$(echo "scale=2.0;$PESO/($ALTURA^2)" | bc)

echo "$NOME2 seu IMC é: $IMC"

exit 0
