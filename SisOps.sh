#!/bin/bash

#--------------------------------------------------------------------#
#Script Name: SisOps.sh
#Description: Atualizando o sistema utilizando o comando apt
#Linkedin: https://www.linkedin.com/in/bruno-pinheiro-502796152
#Escrito por: Bruno Pinheiro
#Manutenção: Bruno Pinheiro
#-------------------------------------------------------------------#
#Comando:
#	$ ./atualiza_sistema.sh
#-------------------------------------------------------------------#
#Versão Bash
#	5.0.3
#-------------------------------------------------------------------#
#Historico
#	v1.0 25/09/2019, Bruno:
#	-Inicio do programa
#-------------------------------------------------------------------#
#Obs:
#	Execute o script como root para aplicar as opcoes
#-------------------------------------------------------------------#

TIME=1
clear
#laco de repeticao while
while true
do
	echo " "
	echo "Seja Bem vindo"
	echo " "
	echo "Escolha uma opção abaixo para começar

	1 - Verificar repositorio do sistema
	2 - Mostrar atualizações do sistema
	3 - Instalar atualizações do sistema
	4 - Limpar o sistema
	5 - Remover pacotes não necessários
	0 - Sair do sistema"

echo " "
echo -n "Opção escolhida: "
read opcao

#estrutura condicional case
case $opcao in
	1)
		echo "Verificando por atualizações..."
		sleep $TIME
		apt update
		;;
	2)
		echo "Mostrando as atualizações do sistema..."
		sleep $TIME
		apt list --upgradable
		;;
	3)
		echo "Instalando atualizações do sistema..."
		sleep $TIME
		apt upgrade -y
		;;
	4)
		echo "Limpando o sistema..."
		sleep $TIME
		apt autoclean
		;;
	5)
		echo "Removendo pacotes desnecessários do sistema..."
		sleep $TIME
		apt autoremove -y
		;;
	0)
		echo "Saindo do sistema"
		sleep $TIME
		exit 0
		;;
	*)
		echo "Opcao invalida, tente novamente"
		;;
esac
done
