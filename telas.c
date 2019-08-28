#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telas.h"
#include "validations.h"

char menuPrincipal() {

	char resp;

	system("clear");

	printf("\n ================================= \n ||||SIG-Library - Biblioteca!|||| \n ================================= \n >>>>>>>  MENU PRINCIPAL  <<<<<<<< \n ================================= \n Escolha uma opção: \n []A - LOGIN ADM \n []B - LOGIN USUÁRIO \n []C - Sobre \n []S - SAIR \n\n(LOGIN ADM e SENHA padrão - admin)\n(LOGIN USUÁRIO e SENHA padrão - teste)\n\n");

	printf("\n");

	printf("Digite: ");

   
	scanf(" %c", &resp);
    printf("\n");
    
    
	while(resp != 'A' && resp !=  'B' && resp != 'C' && resp != 'S') { 
		
		printf("\nDigite uma opção válida: ");
		scanf(" %c", &resp);
		
	}

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
    printf("\n Login do Administrador\n");
    printf("\n Informe o nome de usuário: ");
    scanf("%s", login1);
	printf(" Informe a senha: ");
	scanf("%s", senha1);

	a = strcmp(login, login1);
	b = strcmp(senha, senha1);

	while (!(a == 0 && b == 0)){

		system("clear");
		
		printf("\n Login ou senha incorretos, tente novamente.\n");
		printf("\n Informe o nome de usuário: ");
    	scanf("%s",login1);
		printf(" Informe a senha: ");
		scanf("%s",senha1);
		a = strcmp(login,login1);
		b = strcmp(senha, senha1);		

	}

	if(a == 0 && b == 0){
		
		printf("\n Login realizado com sucesso.\n");
		return 1;
	}
	
	return 0;
	
}

void menuAdmin() {

	char resp; 

	do {
		
		system("clear");

		printf("\n ================================================= \n |  |  |  |  |  Programa Biblioteca  |  |  |  |  | \n ================================================= \n >>>>>>>>>>>>>> MENU ADMINISTRADOR <<<<<<<<<<<<<<< \n ================================================= \n []Digite A - Cadastrar livro \n []Digite B - Cadastro de Pessoas \n []Digite C - Exibir informações de pessoas \n []Digite D - Excluir pessoa \n []Digite E - Exibir livros cadastrados \n []Digite F - Excluir livro cadastrado \n []Digite G - Redefinir nome de usuário ou senha \n []Digite H - Gerenciar empréstimos \n []Digite I - Logs e Relatórios \n []Digite S - Sair \n\n(As opções -G-,-H- e -I-, são as únicas que possuem menu.)\n\n");

		printf("\n");

		printf("Escolha uma opção: ");

		scanf(" %c", &resp);
		
		switch(resp) {
			
			case 'A':
				printf("Ainda não implementado.\n");
				break;
				
			case 'B':
				printf("Ainda não implementado.\n");
				break;
				
			case 'C':
				printf("Ainda não implementado.\n");
				break;
				
			case 'D':
				printf("Ainda não implementado.\n");
				break;
			
			case 'E':
				printf("Ainda não implementado.\n");
				break;
			
			case 'F':
				printf("Ainda não implementado.\n");
				break;
				
			case 'G':
				menuRedefinirUser();
				break;
				
			case 'H':
				menuGerenciarEmprestimos();
				break;
			case 'I':
				menuLog();
				break;
				
		}
		
	}while(resp != 'S');

	printf("\n");

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

	while (!(a == 0 && b == 0)){

		system("clear");

		printf("\n Login ou senha incorretos, tente novamente.\n");
		printf("\n Informe o nome de usuário: ");
    	scanf("%s",login1);
		printf(" Informe a senha: ");
		scanf("%s",senha1);
		a = strcmp(login,login1);
		b = strcmp(senha, senha1);
				

	}
	
	if(a == 0 && b == 0){
		
		printf("\n Login realizado com sucesso.\n");
		
	}
	
	return 1;
	
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

char menuRedefinirUser(){
	
	char resp;

	system("clear");

	printf("\n =================================");
	printf("\n | | | Programa Biblioteca | | |");                      
	printf("\n =================================");
	printf("\n >>> Alterar usuário ou senha <<<");
	printf("\n =================================");
	printf("\n []A - Alterar nome de Usuário");              
	printf("\n []B - Alterar senha"); 
	printf("\n []C - Voltar ao Menu do Administrador");

	printf("\n\n Escolha uma opção: ");
	scanf(" %c", &resp);

	printf("\n");

    return resp;

}

char menuGerenciarEmprestimos(){
	
	char resp;

	system("clear");

	printf("\n =================================");
	printf("\n | | | Programa Biblioteca | | | ");                  
	printf("\n =================================");
	printf("\n >>>>> GERENCIAR EMPRÉSTIMOS <<<<<");
	printf("\n =================================");
	printf("\n []A - Emprestar Livro");
	printf("\n []B - Devolução de Livro");
	printf("\n []C - Relatório");
	printf("\n []D - Voltar ao Menu do Administrador");

	printf("\n\n Escolha uma opção: ");
	scanf(" %c", &resp);

	printf("\n");

	return resp;
}

char menuLog(){
	
	char resp;

	system("clear");

	printf("\n =================================");
	printf("\n | | | Programa Biblioteca | | | ");              
	printf("\n =================================");
	printf("\n >>>>>>>> MENU RELATÓRIO <<<<<<<<");
	printf("\n ================================="); 
	printf("\n []A - Relatório Emprestimos");
	printf("\n []B - Histórico de todos os empréstimos");
	printf("\n []C - Voltar ao Menu do Administrador");

	printf("\n\n Escolha uma opção: ");
	scanf(" %c", &resp);

	printf("\n");

	return resp;

 }
 
void sobre() {

 	char resp;

 	system("clear");

	printf("\n A library system made with C. \n Universidade Federal do Rio Gande do Norte (UFRN). \n Students: Douglas Mateus and Lucas Silva. \n Professor: Flavius Gorgônio. \n");
	printf("\n Digite qualquer tecla pra continuar.\n\n");
	scanf(" %c", &resp);

}

char sair() {
	 
	char resp;
	 
	printf("\n Deseja sair do sistema? (S/N)?");
	scanf(" %c", &resp);
	
	return resp;

}