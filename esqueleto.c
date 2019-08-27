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
#include "telas.c"

int main(void) {

	char resposta_menu_principal;
	char resposta_menu_admin;
	char resposta_menu_user;
	int resposta_menu_redefinir_user;
	int resposta_menu_gerenciar_emprestimos;
	int resposta_menu_log;

	do {

		switch(resposta_menu_principal = menuPrincipal()) {
			
			case 'A':
				if(loginAdm()){
					menuAdmin();
				}
				break;
			case 'B':
				if(loginUser()){
					menuUser();
				}
				break;
			case 'C':
				sobre();
				break;
			case 'S':
				printf("\n");
				printf(" Você saiu do SIG-Library. Volte sempre.\n");
				printf("\n");
				break;
			default:
				printf("Você digitou uma opção errada.");
				
			
	}
		
	
	}while(resposta_menu_principal != 'S');

	
			
	return 0;

}
