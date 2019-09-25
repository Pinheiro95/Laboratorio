#!/bin/bash
#visualizar informacoes do sistema

clear
#use o simbolo $ para pegar o valor de uma variavel. É possível colocar entre chaves {} 
#para melhor organizacao. O texto em rosa é o que será printado na tela, o texto amarelo é 
#referente ao comando interno do kernel (localizado em /bin)que esta sendo utilizado e o texto em
#azul é referente a comentarios e/ou vlores de variáveis
echo "Usuario logado no sistema: $USER"
echo "ID do usuario		 ${UID}"
echo "Diretorio Pessoal		 $HOME"
echo "Nome do PC		 ${HOSTNAME}"
echo "Shell			 $SHELL"

#exige que se tecle enter
read 

exit 0


