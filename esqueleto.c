/* 
SIG-Library.
A library system made with C.
Universidade Federal do Rio Gande do Norte (UFRN).
Students: Douglas Mateus and Lucas Silva.
Professor: Flavius Gorgônio. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telas.h"
#include "validations.h"

int main(void) {

	int resposta_menu_principal;
	char resposta_menu_admin;
	char resposta_menu_user;

	resposta_menu_principal = menuPrincipal();

	switch(resposta_menu_principal) {

		case 1:
			resposta_menu_admin = loginAdm();
			switch(resposta_menu_admin) {

				case 'A':
					break;

				case 'B':
					break;

				case 'C':
					break;

				case 'D':
					break;

				case 'E':
					break;

				case 'F':
					break;

				case 'G':
					menuRedefinirUser();
					break;

				case 'H':
					menuGerenciarEmprestimos();
					break;

				case 'I':
					menuLog();
					break;

				case '0':
					break;

			}
			break;

		case 2:
			resposta_menu_user = menuUser();
			switch(resposta_menu_user) {
				
				case 'A':
					break;

				case 'B':
					break;

				case 'C':
					break;

				case 'D':
					break;

				case 'E':
					break;

				case 'F':
					break;

				case 'G':
					break;

				case 'H':
					break;

				case '0':
					break;

			}
			break;

		case 3:
			break;

	}

	printf("\n");
	printf(" Você saiu do programa. Volte sempre.\n");
	printf("\n");

	return 0;

}