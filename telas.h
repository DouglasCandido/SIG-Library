int menuPrincipal();
int loginAdm();
char menuAdmin();
int loginUser();
char menuUser();
int menuGerenciarEmprestimos();
int menuLog(); 
int menuRedefinirUser();

int menuPrincipal() {

	int resp;

	system("clear");

	printf("\n ================================= \n | | | Programa Biblioteca | | | \n ================================= \n >>>>>>>  MENU PRINCIPAL  <<<<<<<< \n ================================= \n Escolha uma opção: \n []1 - LOGIN ADM \n []2 - LOGIN USUÁRIO \n []3 - Sobre \n []4 - SAIR \n");

	printf("\n");

	printf(" Digite: ");

    scanf("%d", &resp);

    printf("\n");

    return resp;

}

int loginAdm(){

    char login[51] = "admin";
    char login1[51];
    char senha[51] = "admin";
    char senha1[51];
	int a;
	int b;

	system("clear");
    
    printf("\n Login do Administrador \n");

    printf("\n Informe o nome de usuário: ");
    scanf("%s", login1);
	printf(" Informe a senha: ");
	scanf("%s", senha1);

	a = strcmp(login, login1);
	b = strcmp(senha, senha1);

	if(a == 0 && b == 0){
		printf("\n Login realizado com sucesso.\n");
		return 1;
	}

	else {
		printf("\n Algo deu errado.\n");
		return 0;
	}
	
}

char menuAdmin() {

	char resp; 

	system("clear");

 	printf("\n ================================================= \n |  |  |  |  |  Programa Biblioteca  |  |  |  |  | \n ================================================= \n >>>>>>>>>>>>>> MENU ADMINISTRADOR <<<<<<<<<<<<<<< \n ================================================= \n []Digite A - Cadastrar livro \n []Digite B - Cadastro de Pessoas \n []Digite C - Exibir informações de pessoas \n []Digite D - Excluir pessoa \n []Digite E - Exibir livros cadastrados \n []Digite F - Excluir livro cadastrado \n []Digite G - Redefinir nome de usuário ou senha \n []Digite H - Gerenciar empréstimos \n []Digite I - Logs e Relatórios \n []Digite S - Sair \n");

	printf("\n");

	printf(" Escolha uma opção: ");

	scanf(" %c", &resp);

	printf("\n");

	return resp;

}

int loginUser(){

    char login[51] = "teste";
    char login1[51];
    char senha[51] = "teste";
    char senha1[51];
	int a;
	int b;

	system("clear");
    
    printf("\n Login do Usuário \n");

    printf("\n Informe o nome de usuário: ");
    scanf("%s", login1);
	printf(" Informe a senha: ");
	scanf("%s", senha1);

	a = strcmp(login, login1);
	b = strcmp(senha, senha1);

	if(a == 0 && b == 0){
		printf("\n Login realizado com sucesso.\n");
		return 1;
	}

	else {
		printf("\n Algo deu errado.\n");
		return 0;
	}
	
}

char menuUser() {

	char resp; 

	system("clear");

	printf("\n ================================================= \n |  |  |  |  |  Programa Biblioteca  |  |  |  |  | \n ================================================= \n >>>>>>>>>>>>>> MENU USUÁRIO <<<<<<<<<<<<<<< \n ================================================= \n []Digite A -  \n []Digite B -  \n []Digite C -  \n []Digite D -  \n []Digite E - Exibir todos os livros do acervo \n []Digite F - Pesquisar livro no acervo \n []Digite G - Redefinir nome de usuário ou senha \n []Digite H - Gerenciar empréstimos \n []Digite S - Sair \n");

	printf("\n");

	printf(" Escolha uma opção: ");

	scanf(" %c", &resp);

	printf("\n");

	return resp;

}

int menuRedefinirUser(){
	int resp;

	system("clear");

	printf("\n =================================");
	printf("\n | | | Programa Biblioteca | | |");                      
	printf("\n =================================");
	printf("\n >>> Alterar usuário ou senha <<<");
	printf("\n =================================");
	printf("\n []1 - Alterar nome de Usuário");              
	printf("\n []2 - Alterar senha"); 
	printf("\n []3 - Voltar ao Menu do Administrador");
	printf("\n []4 - Sair");

	printf("\n\n Escolha uma opção: ");
	scanf(" %d", &resp);

	printf("\n");

    return resp;

}

int menuGerenciarEmprestimos(){
	int resp;

	system("clear");

	printf("\n =================================");
	printf("\n | | | Programa Biblioteca | | | ");                  
	printf("\n =================================");
	printf("\n >>>>> GERENCIAR EMPRÉSTIMOS <<<<<");
	printf("\n =================================");
	printf("\n []1 - Emprestar Livro");
	printf("\n []2 - Devolução de Livro");
	printf("\n []3 - Relatório");
	printf("\n []4 - Voltar ao Menu do Administrador");
	printf("\n []5 - Sair");

	printf("\n\n Escolha uma opção: ");
	scanf(" %d", &resp);

	printf("\n");

	return resp;
}

int menuLog(){
	int resp;

	system("clear");

	printf("\n =================================");
	printf("\n | | | Programa Biblioteca | | | ");              
	printf("\n =================================");
	printf("\n >>>>>>>> MENU RELATÓRIO <<<<<<<<");
	printf("\n ================================="); 
	printf("\n []1 - Relatório Emprestimos");
	printf("\n []2 - Histórico de todos os empréstimos");
	printf("\n []3 - Voltar ao Menu do Administrador");
	printf("\n []4 - Sair");

	printf("\n\n Escolha uma opção: ");
	scanf(" %d", &resp);

	printf("\n");

	return resp;

 }

