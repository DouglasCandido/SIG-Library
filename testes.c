#include <stdio.h>
#include <stdlib.h>
#include "telas.h"

int main(void) {

	int resp;

	resp = menuPrincipal();

	switch(resp) {

		case 1:
			printf("Apenas um teste.\n");
			break;

		case 2:
			printf("Outro teste.\n");
			break;

	}

	return 0;

}