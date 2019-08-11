/* 
SIG-Library.
A library system made with C.
Universidade Federal do Rio Gande do Norte (UFRN).
Students: Douglas Mateus and Lucas Silva.
Professor: Flavius Gorgônio. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "telas.h"
#include "validations.h"

int main(void) {

	int resposta_menu_principal;
	char resposta_menu_admin;
	char resposta_menu_user;

	resposta_menu_principal = menuPrincipal();

	switch(resposta_menu_principal) {

		case 1:
			resposta_menu_admin = menuAdmin();
			break;

		case 2:
			resposta_menu_user = menuUser();
			break;

		case 3:
			system("clear");
			printf("Você saiu do programa. Volte sempre.\n");
			printf("\n");
			break;

	}

	return 0;

}