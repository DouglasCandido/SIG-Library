int menuPrincipal() {

	int resp;

	system("clear");

	printf(" ================================= \n | | | Programa biblioteca | | | \n ================================= \n >>>>>>>  MENU PRINCIPAL  <<<<<<<< \n ================================= \n Escolha uma opção: \n []1 - LOGIN ADM \n []2 - LOGIN USUÁRIO \n []3 - SAIR \n");

	printf("\n");

	printf(" Digite: ");

    scanf("%d", &resp);

    printf("\n");

    return resp;

}

int menuAdmin() {

	char resp; 

	system("clear");

 	printf(" ================================================= \n |  |  |  |  |  Programa Biblioteca  |  |  |  |  | \n ================================================= \n >>>>>>>>>>>>>> MENU ADMINISTRADOR <<<<<<<<<<<<<<< \n ================================================= \n []Digite A - Cadastrar livro \n []Digite B - Cadastro de Pessoas \n []Digite C - Exibir informações de pessoas \n []Digite D - Excluir pessoa \n []Digite E - Exibir livros cadastrados \n []Digite F - Excluir livro cadastrado \n []Digite G - Redefinir nome de usuário ou senha \n []Digite H - Gerenciar empréstimos \n []Digite 0 - Sair \n");

	printf("\n");

	printf(" Escolha uma opção: ");

	scanf(" %c", &resp);

	printf("\n");

	return resp;

}

int menuUser() {

	char resp; 

	system("clear");

	printf(" ================================================= \n |  |  |  |  |  Programa Biblioteca  |  |  |  |  | \n ================================================= \n >>>>>>>>>>>>>> MENU USUÁRIO <<<<<<<<<<<<<<< \n ================================================= \n []Digite A -  \n []Digite B -  \n []Digite C -  \n []Digite D -  \n []Digite E - Exibir todos os livros do acervo \n []Digite F - Pesquisar livro no acervo \n []Digite G - Redefinir nome de usuário ou senha \n []Digite H - Gerenciar empréstimos \n []Digite 0 - Sair \n");

	printf("\n");

	printf(" Escolha uma opção: ");

	scanf(" %c", &resp);

	printf("\n");

	return resp;

}