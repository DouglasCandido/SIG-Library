# Apenas um script que facilita a compilação e execução do programa.

#!/bin/bash

function pause(){

   read -p "$*"

}

gcc -c -Wall telas.c validations.c
gcc -o executavel telas.o validations.o

pause "Aperte [Enter] para continuar com a execução do SIG-Library..."

./executavel



