/* 
SIG-Library.
Alunos: Douglas Mateus e Lucas Silva.
*/

#include <stdio.h>
#include <stdlib.h>
#include "telas.h"
#include "validations.h"

int main(void) {

	int resp;

	resp = menuPrincipal();

	switch(resp) {

		case 1:
			printf("Primeiro teste.\n");
			break;

		case 2:
			printf("Segundo teste.\n");
			break;

		case 3:
			printf("Terceiro teste.\n");
			break;

	}

	return 0;

}