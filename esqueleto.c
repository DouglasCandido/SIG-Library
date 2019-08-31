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
#include <ctype.h>
#include <regex.h>
#include "telas.h"
#include "validations.h"

int starter(void);

int main(void) {

	
	starter();

		
	return 0;

}

int starter() {

	char resposta_menu_principal;


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
			if((sair()) == 'S') {
				system("clear");
				printf("       _.--._  _.--._\n");
				printf(" ,-=.-\":;:;:;\\':;:;:;\"-._\n");
				printf(" \\\\\\:;:;:;:;:;\\:;:;:;:;:;\\\n");
				printf("  \\\\\\:;:;:;:;:;\\:;:;:;:;:;\\\n");
				printf("   \\\\\\:;:;:;:;:;\\:;:;:;:;:;\\\n");
				printf("    \\\\\\:;:;:;:;:;\\:;::;:;:;:\\\n");
				printf("     \\\\\\;:;::;:;:;\\:;:;:;::;:\\\n");
				printf("      \\\\\\;;:;:_:--:\\:_:--:_;:;\\    Adeus, caro leitor!\n");
				printf("       \\\\\\_.-\"      :      \"-._\\\n");
				printf("        \\`_..--\"\"--.;.--\"\"--.._=>\n");
				printf("         \"");
				printf("\n Você saiu do SIG-Library. Volte sempre.\n\n");
				break;
			} else {
				resposta_menu_principal = starter();
			}			
			break;
		default:
			printf("Você digitou uma opção inválida.\n");
			
	}

	return 1;
  
}
