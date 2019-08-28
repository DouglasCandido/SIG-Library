#include <stdio.h>
#include <regex.h>

#define RE_EMAIL ".+@.+\\.[a-z]+" 	

int main(void) {

	char email[30];

	regex_t reg;

	printf("Digite um email: ");
	scanf("%[^\n]s", email);

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
