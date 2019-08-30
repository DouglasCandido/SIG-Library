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

				return 1;

			} else {

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
	



int validaCPF(char cpf[14]) {

	regex_t reg;
	
	if((strlen(cpf)) > 14) {
		return 0;

	} else {
		if(regcomp(&reg, RE_CPF, REG_EXTENDED|REG_NOSUB) != 0) {
			return 0;

		} else {
			if((regexec(&reg, cpf, 0, (regmatch_t*)NULL, 0)) == 0) {
				return 1;
				
			} else {
				return 0;
			}
		}
	}
}


int validaNome(char nome[100]) {

	regex_t reg;
	
	if((strlen(nome)) > 100) {
		return 0;

	} else {
		if(regcomp(&reg, RE_NAME, REG_EXTENDED|REG_NOSUB) != 0) {
			return 0;

		} else {
			if((regexec(&reg, nome, 0, (regmatch_t*)NULL, 0)) == 0) {
				return 1;
				
			} else {
				return 0;
			}
		}
	}
}

int validaISBN(char isbn[17]) {

	regex_t reg;
	
	if((strlen(isbn)) > 17) {
		return 0;

	} else {
		if(regcomp(&reg, RE_ISBN, REG_EXTENDED|REG_NOSUB) != 0) {
			return 0;

		} else {
			if((regexec(&reg, isbn, 0, (regmatch_t*)NULL, 0)) == 0) {
				return 1;
				
			} else {
				return 0;
			}
		}
	}
}


int validaEdt(char edit[100]) {

	regex_t reg;
	
	if((strlen(edit)) > 100) {
		return 0;

	} else {
		if(regcomp(&reg, RE_NUM, REG_EXTENDED|REG_NOSUB) != 0) {
			return 0;

		} else {
			if((regexec(&reg, edit, 0, (regmatch_t*)NULL, 0)) == 0) {
				return 1;
				
			} else {
				return 0;
			}
		}
	}
}



/*
int validaCNPJ(cnpj) {

    regex = '^[0-9]{2}\\.[0-9]{3}\\.[0-9]{3}\\/[0-9]{4}\\-[0-9]{2}$';

}
*/

