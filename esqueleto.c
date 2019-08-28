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

	char resposta_menu_principal;

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
				printf("Você digitou uma opção inválida.");
				
			
	}
		
	
	}while(resposta_menu_principal != 'S');

	
			
	return 0;

}
