#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telas.h"
#include "validations.h"

char menuPrincipal() {

	char resp;

	system("clear");

	printf("\n ================================= \n ||| SIG-Library - Biblioteca! ||| \n ================================= \n >>>>>>>  MENU PRINCIPAL  <<<<<<<< \n ================================= \n Escolha uma opção: \n []A - LOGIN ADMINISTRADOR \n []B - LOGIN USUÁRIO \n []C - Sobre \n []S - SAIR \n\n * Credenciais default: \n (Administrador ---> Username: admin / Password: admin)\n (Usuário ---> Username: teste / Password: teste)\n\n");

	printf("       ______ ______\n");
	printf("     _/      Y      \\_\n");
	printf("    // ~~ ~~ | ~~ ~  \\\\\n");
	printf("   // ~ ~ ~~ | ~~~ ~~ \\\\      \n");
	printf("  //________.|.________\\\\     \n");
	printf(" `----------`-'----------'\n");

	printf("\n");

	printf(" Digite uma opção: ");

	scanf(" %c", &resp);
	resp = maius(resp);
    printf("\n");
    
    
	while(resp != 'A' && resp !=  'B' && resp != 'C' && resp != 'S') { 
		
		printf("\n Digite uma opção válida: ");
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

	printf("\n =================================");
	printf("\n | | | Programa Biblioeteca | | |");                      
	printf("\n =================================");
	printf("\n >>>  LOGIN DO ADMINISTRADOR <<<");
	printf("\n =================================");
    printf("\n\n Informe o nome de usuário: ");
    scanf("%s", login1);
	printf(" Informe a senha: ");
	scanf("%s", senha1);

	a = strcmp(login, login1);
	b = strcmp(senha, senha1);

	while (!(a == 0 && b == 0)){

		system("clear");
		printf("\n =================================");
		printf("\n | | | Programa Biblioeteca | | |");                      
		printf("\n =================================");
		printf("\n >>>  LOGIN DO ADMINISTRADOR <<<");
		printf("\n =================================");
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

		printf("\n ================================================= \n |  |  |  |  |  Programa Biblioteca  |  |  |  |  | \n ================================================= \n >>>>>>>>>>>>>> MENU ADMINISTRADOR <<<<<<<<<<<<<<< \n ================================================= \n []A - Cadastrar livro \n []B - Cadastro de pessoas \n []C - Exibir informações de pessoas \n []D - Excluir pessoa \n []E - Exibir livros cadastrados \n []F - Excluir livro cadastrado \n []G - Redefinir nome de usuário ou senha \n []H - Gerenciar empréstimos \n []I - Logs e Relatórios \n []S - Deslogar \n\n (As opções A, B, G, H e I, são as únicas que possuem menu atualmente.)\n\n");

		printf("\n");

		printf("Escolha uma opção: ");

		scanf(" %c", &resp);
		resp = maius(resp);

		switch(resp) {
			
			case 'A':
				cadastroLivro();
				break;
				
			case 'B':
				cadastroPessoa();
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
    printf("\n =================================");
	printf("\n | | | Programa Biblioeteca | | |");                      
	printf("\n =================================");
	printf("\n >>>>>>   LOGIN DO USUÁRIO  <<<<<<");
	printf("\n =================================");

    printf("\n\n Informe o nome de usuário: ");
    scanf("%s", login1);
	printf(" Informe a senha: ");
	scanf("%s", senha1);

	a = strcmp(login, login1);
	b = strcmp(senha, senha1);

	while (!(a == 0 && b == 0)){

		system("clear");

		printf("\n =================================");
		printf("\n | | | Programa Biblioeteca | | |");                      
		printf("\n =================================");
		printf("\n >>>>>>   LOGIN DO USUÁRIO  <<<<<<");
		printf("\n =================================");

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

void menuUser() {

	char resp; 

	system("clear");

	printf("\n ================================================= \n |  |  |  |  |  Programa Biblioteca  |  |  |  |  | \n ================================================= \n >>>>>>>>>>>>>> MENU USUÁRIO <<<<<<<<<<<<<<< \n ================================================= \n []A - Exibir todos os livros do acervo \n []B - Pesquisar livro no acervo \n []C - Gerenciar empréstimos \n []D - Redefinir dados pessoais \n []S - Deslogar \n");

	printf("\n");

	printf(" Escolha uma opção: ");

	scanf(" %c", &resp);
	resp = maius(resp);

	printf("\n");

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
	
	resp = maius(resp);

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
	resp = maius(resp);

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
	
	resp = maius(resp);
	printf("\n");

	return resp;

 }
 
void sobre() {

 	char resp;

 	system("clear");

	printf("\n A library system made with C. \n Universidade Federal do Rio Gande do Norte (UFRN). \n Students: Douglas Mateus and Lucas Silva. \n Professor: Flavius Gorgônio. \n\n");
	
	printf("       _.--._  _.--._\n");
	printf(" ,-=.-\":;:;:;\\':;:;:;\"-._\n");
	printf(" \\\\\\:;:;:;:;:;\\:;:;:;:;:;\\\n");
	printf("  \\\\\\:;:;:;:;:;\\:;:;:;:;:;\\\n");
	printf("   \\\\\\:;:;:;:;:;\\:;:;:;:;:;\\\n");
	printf("    \\\\\\:;:;:;:;:;\\:;::;:;:;:\\\n");
	printf("     \\\\\\;:;::;:;:;\\:;:;:;::;:\\\n");
	printf("      \\\\\\;;:;:_:--:\\:_:--:_;:;\\    SIG-Library\n");
	printf("       \\\\\\_.-\"      :      \"-._\\\n");
	printf("        \\`_..--\"\"--.;.--\"\"--.._=>\n");
	printf("         \"");

	printf("\n Digite qualquer tecla pra continuar.\n\n");
	scanf(" %c", &resp);

	resp = maius(resp);

}

char sair() {
	 
	char resp;
	 
	printf(" Deseja sair do sistema? (S/N)? ");
	scanf(" %c", &resp);

	resp = maius(resp);

	return resp;

}

void cadastroLivro() {

    char nomeLiv[200], autor[200], genero[100], editora[100], edicao[100], isbn[17];

    system("clear");

    printf("\n =================================");
	printf("\n | | | Programa Biblioeteca | | |");                      
	printf("\n =================================");
	printf("\n >>>>>>> CADASTRO DE LIVROS <<<<<<");
	printf("\n =================================");


    printf("\n\n Insira o nome do livro: ");
    scanf(" %[^\n]s", nomeLiv);

    printf("\n Insira o ISBN do livro: ");
    scanf(" %[^\n]s", isbn);

    printf("\n Insira o nome do autor: ");
    scanf(" %[^\n]s", autor);
    while(validaNome(autor) == 0){
		printf("\n Insira um nome válido: ");
		scanf(" %[^\n]s", autor);
	}

    printf("\n Insira o gênero do livro: ");
    scanf(" %[^\n]s", genero);
    while (validaNome(genero)== 0){
    printf("\n Insira um gênero válido do livro: ");
    scanf(" %[^\n]s", genero);
    }
    
    printf("\n Insira a editora do livro: ");
    scanf(" %[^\n]s", editora);

    printf("\n Insira a edição do livro: ");
    scanf(" %[^\n]s", edicao);
    
}

void cadastroPessoa() {

    char nome[100], enderEst[2], enderCid[100], enderBair[100], numCasa[50], cpf[14], dataNasc[10], tel[15], email[30];

    system("clear");

	printf("\n =================================");
	printf("\n | | | Programa Biblioeteca | | |");                      
	printf("\n =================================");
	printf("\n >>>>>> CADASTRO DE PESSOAS <<<<<<");
	printf("\n =================================");


    printf("\n\n Insira seu nome completo: ");
    scanf(" %[^\n]s", nome);
    while(validaNome(nome) == 0){
		printf("\n Insira um nome válido: ");
		scanf(" %[^\n]s", nome);
	}

    printf("\n Insira seu Estado: ");
    scanf(" %[^\n]s", enderEst);

    printf("\n Insira sua cidade: ");
    scanf(" %[^\n]s", enderCid);
     while(validaNome(enderCid) == 0){
		printf("\n Insira um nome válido: ");
		scanf(" %[^\n]s", nome);
	}
    printf("\n Insira seu bairro: ");
    scanf(" %[^\n]s", enderBair);
    while(validaNome(enderBair) == 0){
		printf("\n Insira um nome válido: ");
		scanf(" %[^\n]s", nome);
	}

    printf("\n Insira o número da sua casa: ");
    scanf(" %[^\n]s", numCasa);


    printf("\n Insira seu CPF - xxx.xxx.xxx-xx: ");
    scanf(" %[^\n]s", cpf);
	while(validaCPF(cpf)==0){
		printf("\n Insira um CPF válido - xxx.xxx.xxx-xx: ");
		scanf(" %[^\n]s", cpf);
	}
    printf("\n Insira sua data de nascimento: ");
    scanf(" %[^\n]s", dataNasc);
	
	printf("\n Insira seu número para contato - xx-xxxxxxxxx: ");
	scanf(" %[^\n]s", tel);
	while(validaTelefone(tel)==0){
		printf("\n Insira um número válido (xx)x xxxx-xxxx: ");
		scanf(" %[^\n]s", tel);
	}
		
    printf("\n Insira seu email: ");
	scanf(" %[^\n]s", email);
    while(validaEmail(email)==0){
			printf("Insira um email válido: ");
			scanf(" %[^\n]s", email);
	}
   
    

}

