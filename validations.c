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

		printf("Email inválido, pois excedeu o número máximo de caracteres.");
		return 0;

	} else {

		if(regcomp(&reg, RE_EMAIL, REG_EXTENDED|REG_NOSUB) != 0) {

			printf("Expressão regular inválida!\n");
			return 0;

		} else {

			if((regexec(&reg, email, 0, (regmatch_t*)NULL, 0)) == 0) {

				printf("Email válido.\n");
				return 1;

			} else {

				printf("Email inválido.\n");
				return 0;

			}

		}

	}

}

/*
int validaTelefone(telefone) {

    regex = '^\\([1-9]{2}\\) (?:[2-8]|9[1-9])[0-9]{3}\\-[0-9]{4}$';

}


int validaCPF(cpf) {

    regex = '^[0-9]{3}\\.[0-9]{3}\\.[0-9]{3}\\-[0-9]{2}$';

}


int validaCNPJ(cnpj) {

    regex = '^[0-9]{2}\\.[0-9]{3}\\.[0-9]{3}\\/[0-9]{4}\\-[0-9]{2}$';

}
*/

