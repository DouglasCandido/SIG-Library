#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>
#include "validations.h"

char maius(char r) {

    char letra;

    letra = toupper(r);

    return letra;

}

int validaEmail(char email[30]) {

	regex_t reg;

	if((strlen(email)) > 30) {

		return 0;

	} else {

		if(regcomp(&reg, RE_EMAIL, REG_EXTENDED|REG_NOSUB) != 0) {
			return 0;

		} else {

			if((regexec(&reg, email, 0, (regmatch_t*)NULL, 0)) == 0) {

				//printf("Email válido.\n");
				return 1;

			} else {

				//printf("Email inválido.\n");
				return 0;

			}

		}

	}

}


int validaTelefone(char tel[15]) {
	
	regex_t reg;
	
	if((strlen(tel)) > 15) {

		return 0;

	} else {

		if(regcomp(&reg, RE_TEL, REG_EXTENDED|REG_NOSUB) != 0) {
			return 0;

		} else {

			if((regexec(&reg, tel, 0, (regmatch_t*)NULL, 0)) == 0) {
				return 1;

			} else {
				return 0;

			}
			
		}
		
	}

}
	


/*
int validaCPF(cpf) {

    regex = '^[0-9]{3}\\.[0-9]{3}\\.[0-9]{3}\\-[0-9]{2}$';

}


int validaCNPJ(cnpj) {

    regex = '^[0-9]{2}\\.[0-9]{3}\\.[0-9]{3}\\/[0-9]{4}\\-[0-9]{2}$';

}
*/

