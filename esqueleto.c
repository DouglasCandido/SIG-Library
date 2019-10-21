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
#include "esqueleto.h"

int main(void) {

	
	starter();

		
	return 0;

}

int starter() {

	char resposta_menu_principal;


	switch(resposta_menu_principal = menuPrincipal()) {
		
		case 'A':
			if(login() == 1) {
				menuAdmin();
			}else{
				menuUser();
			}
			break;
		case 'B':
			sobre();
			resposta_menu_principal = starter();
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
