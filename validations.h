#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include "telas.h"


char maius(char);

char maius(char a){
    char letra;
    letra = toupper(a);
    return letra;
}