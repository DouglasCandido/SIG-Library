int menuPrincipal() {

	int resp;

	printf("=================================");
    printf("\n | | | Programa biblioteca | | |");                   
    printf("\n=================================");
    printf("\n>>>>>>>  MENU PRINCIPAL  <<<<<<<<");
    printf("\n=================================");   
    printf("\nEscolha uma opção:");                 
    printf("\n[]1 - LOGIN");             
    printf("\n[]2 - SAIR");
    printf("\n\nDigite a opção desejada: ");
    resp = scanf("%d", &resp);
    return resp;

}

int loginAdm(){
    char login[51] = "admin";
    char login1[51];
    char senha[51] = "admin";
    char senha1[51];
	int a;
	int b;
    
    printf("\nFaça login de administrador\n");

    printf("\nInforme o nome de usuário: ");
    scanf("%s",login1);
	printf("Informe a senha: ");
	scanf("%s",senha1);

	a = strcmp(login,login1);
	b = strcmp(senha, senha1);

	if (a == 0 && b == 0){
		printf("\nLogin realizado com sucesso.\n");
	}

	else {
		printf("\nAlgo deu errado.\n");
	}
	
	}