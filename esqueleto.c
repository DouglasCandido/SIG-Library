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
	int resposta_menu_redefinir_user;
	int resposta_menu_gerenciar_emprestimos;
	int resposta_menu_log;

	menu_principal: resposta_menu_principal = menuPrincipal();

	switch(resposta_menu_principal) {

		case 1:

			if(loginAdm() == 1) {

				menu_admin: resposta_menu_admin = menuAdmin();

			}

			switch(resposta_menu_admin) {

				case 'A':
					goto menu_admin;
					break;

				case 'B':
					goto menu_admin;
					break;

				case 'C':
					goto menu_admin;
					break;

				case 'D':
					goto menu_admin;
					break;

				case 'E':
					goto menu_admin;
					break;

				case 'F':
					goto menu_admin;
					break;

				case 'G':
					resposta_menu_redefinir_user = menuRedefinirUser();

					if(resposta_menu_redefinir_user == 3) {

						goto menu_admin;

					}

					else if(resposta_menu_redefinir_user == 4){

						break;

					}

					break;
					

				case 'H':
					resposta_menu_gerenciar_emprestimos = menuGerenciarEmprestimos();

					if(resposta_menu_gerenciar_emprestimos == 4) {

						goto menu_admin;

					}

					else if(resposta_menu_redefinir_user == 5){

						break;

					}

					break;

				case 'I':
					resposta_menu_log = menuLog();

					if(resposta_menu_log == 3) {

						goto menu_admin;

					}

					else if(resposta_menu_redefinir_user == 4){

						break;

					}

					break;

				case 'S':
					break;

			}
			break;

		case 2:

			if(loginUser() == 1) {

				menu_user: resposta_menu_user = menuUser();

			}

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

				case 'S':
					break;

			}
			break;

		case 3:

			printf(" A library system made with C. \n Universidade Federal do Rio Gande do Norte (UFRN). \n Students: Douglas Mateus and Lucas Silva. \n Professor: Flavius Gorgônio. \n");

			int resposta;

			printf("\n Deseja voltar para o Menu Principal (1) ou Sair (0)?");

			scanf("%d", &resposta);

			if(resposta == 1){

				goto menu_principal;

			}

			else {
	
				break;
				
			}

			break;

		case 4:
			break;

	}

	printf("\n");
	printf(" Você saiu do SIG-Library. Volte sempre.\n");
	printf("\n");

	return 0;

}
