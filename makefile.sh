#!/bin/bash

function pause(){

   read -p "$*"

}

gcc -c -Wall esqueleto.c telas.c validations.c
gcc -o executavel esqueleto.o telas.o validations.o

pause "Aperte [Enter] para continuar com a execução do SIG-Library..."

./executavel



