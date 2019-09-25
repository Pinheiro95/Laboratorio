#!/bin/bash

#--------------------------------------------------------------------#
#Script Name: Gerencia_apache.sh
#Description: Atualizando o sistema utilizando o comando apt
#Linkedin: https://www.linkedin.com/in/bruno-pinheiro-502796152
#Escrito por: Bruno Pinheiro
#Manutenção: Bruno Pinheiro
#-------------------------------------------------------------------#
#Comando:
#	$ ./Gerencia_apache.sh
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

clear

TIME=2
echo "PROGRAMA DE GERENCIAMENTO DO WEBSERVER APACHE"
echo " "
echo "Escolha uma opção para gerir o webserver apache
	1 - Iniciar o serviço Apache
	2 - Parar o serviço Apache
	3 - Reiniciar o serviço Apache
	4 - Mostrar status do Apache
	0 - Sair do menu"

echo " "
echo -n "Opção escolhida: "
read opcao
case $opcao in
	1)
		echo "Iniciando o serviço do apache..."
		sleep $TIME
		systemctl start httpd
		;;
	2)
		echo "Parando o serviço do Apache..."
		sleep $TIME
		systemctl stop httpd
		;;
	3)
		echo "Reiniciando o serviço do Apache..."
		sleep $TIME
		systemctl restart httpd
		;;
	4)
		echo "Mostrando o status do Apache..."
		sleep $TIME
		systemctl status httpd
		;;
	0)
		echo "Saindo do sistema..."
		sleep $TIME
		exit 0
		;;
	*)
		echo "Opcao invalida, tente novamente"
		;;
esac
exit 0
