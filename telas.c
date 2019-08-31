#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "telas.h"
#include "validations.h"
#include "esqueleto.h"

char menuPrincipal() {

	char resp;

	do{

	system("clear");

	printf("\n ================================= \n ||| SIG-Library - Biblioteca! ||| \n ================================= \n >>>>>>>  MENU PRINCIPAL  <<<<<<<< \n ================================= \n Escolha uma opção: \n []A - LOGIN \n []B - Sobre \n []S - SAIR \n\n * Credenciais default: \n (Administrador ---> Username: admin / Password: admin)\n (Usuário ---> Username: teste / Password: teste)\n\n");

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
    
	}while(resp != 'A' && resp !=  'B' && resp != 'S'); 	

    return resp;

}

int login() {

    char loginA[51] = "admin";
    char senhaA[51] = "admin";
    char loginU[51] = "teste";
    char senhaU[51] = "teste";
    char login1[51];
    char senha1[51];

	system("clear");

	printf("\n =================================");
	printf("\n | | | Programa Biblioeteca | | |");                      
	printf("\n =================================");
	printf("\n >>>      LOGIN DO LEITOR      <<<");
	printf("\n =================================");

    printf("\n\n Informe o nome de usuário: ");
    scanf("%s", login1);
	printf(" Informe a senha: ");
	scanf("%s", senha1);

	while(!(strcmp(loginA, login1) == 0 && strcmp(senhaA, senha1) == 0) && !(strcmp(loginU, login1) == 0 && strcmp(senhaU, senha1) == 0)) {

		system("clear");

		printf("\n =================================");
		printf("\n | | | Programa Biblioeteca | | |");                      
		printf("\n =================================");
		printf("\n >>>      LOGIN DO LEITOR      <<<");
		printf("\n =================================");
		
	    printf("\n\n Informe o nome de usuário: ");
	    scanf("%s", login1);
		printf(" Informe a senha: ");
		scanf("%s", senha1);

	}

	if(strcmp(loginA, login1) == 0 && strcmp(senhaA, senha1) == 0) {
		
		// printf("\n Login realizado com sucesso.\n");
		return 1;

	} else if(strcmp(loginU, login1) == 0 && strcmp(senhaU, senha1) == 0) {
		// printf("\n Login realizado com sucesso.\n");
		return 2;
	}

	return 0;
	
}

void menuAdmin() {

	char resp;

	do {
		
		system("clear");

		printf("\n ================================================= \n |  |  |  |  |  Programa Biblioteca  |  |  |  |  | \n ================================================= \n >>>>>>>>>>>>>> MENU ADMINISTRADOR <<<<<<<<<<<<<<< \n ================================================= \n []A - Cadastrar livro \n []B - Cadastro de pessoas \n []C - Exibir informações de pessoas \n []D - Excluir pessoa \n []E - Exibir livros cadastrados \n []F - Excluir livro cadastrado \n []G - Redefinir nome de usuário ou senha \n []H - Gerenciar empréstimos \n []I - Logs e Relatórios \n []S - Deslogar \n\n (As opções A, B, G, H e I, são as únicas que possuem menu atualmente.)\n\n");

		printf("\n\n Escolha uma opção: ");

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
			case 'S':
				if((sair()) == 'S') {
					starter();
				} else {
					menuAdmin();
				}
				break;
				
		}
		
	}while(resp != 'S');

}

/*
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

		printf("\n\n LOGIN OU SENHA INCORRETOS, TENTE NOVAMENTE.\n");
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
*/

void menuUser() {

	char resp; 

	do{

		system("clear");

		printf("\n ================================================= \n |  |  |  |  |  Programa Biblioteca  |  |  |  |  | \n ================================================= \n >>>>>>>>>>>>>> MENU USUÁRIO <<<<<<<<<<<<<<< \n ================================================= \n []A - Exibir todos os livros do acervo \n []B - Pesquisar livro no acervo \n []C - Gerenciar empréstimos \n []D - Redefinir dados pessoais \n []S - Deslogar \n");

		

		printf(" \n\n Escolha uma opção: ");

		scanf(" %c", &resp);
		resp = maius(resp);

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
			
			case 'S':
				if((sair()) == 'S') {
					starter();
				} else {
					menuUser();
				}
				break;
				
		}
		
	}while(resp != 'S');

}

char menuRedefinirUser(){
	
	char resp;

	do{
	system("clear");

	printf("\n =================================");
	printf("\n | | | Programa Biblioteca | | |");                      
	printf("\n =================================");
	printf("\n >>> Alterar usuário ou senha <<<");
	printf("\n =================================");
	printf("\n []A - Alterar nome de Usuário");              
	printf("\n []B - Alterar senha"); 
	printf("\n []S - Voltar ao Menu do Administrador");

	printf("\n\n Escolha uma opção: ");
	scanf(" %c", &resp);
	resp = maius(resp);

	}while(resp != 'S');	

	return resp;

}

char menuGerenciarEmprestimos(){
	
	char resp;

	do{
	system("clear");

	printf("\n =================================");
	printf("\n | | | Programa Biblioteca | | | ");                  
	printf("\n =================================");
	printf("\n >>>>> GERENCIAR EMPRÉSTIMOS <<<<<");
	printf("\n =================================");
	printf("\n []A - Emprestar Livro");
	printf("\n []B - Devolução de Livro");
	printf("\n []C - Relatório");
	printf("\n []S - Voltar ao Menu do Administrador");

	printf("\n\n Escolha uma opção: ");
	scanf(" %c", &resp);
	resp = maius(resp);

	}while(resp != 'S');

	return resp;
}

char menuLog(){
	
	char resp;

	do{
	system("clear");

	printf("\n =================================");
	printf("\n | | | Programa Biblioteca | | | ");              
	printf("\n =================================");
	printf("\n >>>>>>>> MENU RELATÓRIO <<<<<<<<");
	printf("\n ================================="); 
	printf("\n []A - Relatório Emprestimos");
	printf("\n []B - Histórico de todos os empréstimos");
	printf("\n []S - Voltar ao Menu do Administrador");

	printf("\n\n Escolha uma opção: ");
	scanf(" %c", &resp);
	
	resp = maius(resp);
	}while(resp != 'S');

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

	printf("\n Digite algo e tecle ENTER para continuar.\n\n");
	scanf(" %c", &resp);
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
    while(validaEdt(nomeLiv) == 0){
    	printf(" Insira um nome válido para o livro: ");
    	scanf(" %[^\n]s", nomeLiv);
    }

    printf("\n Insira o ISBN do livro [xxx-xx-xxx-xxxx-x]: ");
    scanf(" %[^\n]s", isbn);
    while(validaISBN(isbn) == 0){
		printf(" Insira o ISBN correto [xxx-xx-xxx-xxxx-x]: ");
		scanf(" %[^\n]s", isbn);
	}

    printf("\n Insira o nome do autor: ");
    scanf(" %[^\n]s", autor);
    while(validaNome(autor) == 0){
		printf(" Insira um nome válido: ");
		scanf(" %[^\n]s", autor);
	}

    printf("\n Insira o gênero do livro: ");
    scanf(" %[^\n]s", genero);
    while (validaNome(genero)== 0){
    	printf(" Insira um gênero válido do livro: ");
    	scanf(" %[^\n]s", genero);
    }
    
    printf("\n Insira a editora do livro: ");
    scanf(" %[^\n]s", editora);
    while(validaEdt(editora) == 0){
    	printf(" Insira um nome válido para a editora do livro: ");
    	scanf(" %[^\n]s", editora);
    }


    printf("\n Insira a edição do livro: ");
    scanf(" %[^\n]s", edicao);
    while(validaEdt(edicao)==0){
    	printf(" Insira uma edição válida para o livro: ");
    	scanf(" %[^\n]s", edicao);
    }
    
}

void cadastroPessoa() {

    char nome[100], enderCid[100], enderBair[100], numCasa[50], cpf[14], tel[15], email[30], *estados[27][2], c;
    int dia, mes, ano, numero_uf, uf;


    system("clear");

	printf("\n =================================");
	printf("\n | | | Programa Biblioeteca | | |");                      
	printf("\n =================================");
	printf("\n >>>>>> CADASTRO DE PESSOAS <<<<<<");
	printf("\n =================================");


    printf("\n\n Insira seu nome completo: ");
    scanf(" %[^\n]s", nome);
    while(validaNome(nome) == 0){
		printf(" Insira um nome válido: ");
		scanf(" %[^\n]s", nome);
	}

	do {  

        printf("\n Insira seu dia de nascimento: ");

    } while (((scanf("%d%c", &dia, &c) != 2 || c != '\n') && clean_stdin()) || dia < 1 || dia > 31);



    do {  

        printf("\n Insira seu mês de nascimento: ");

    } while (((scanf("%d%c", &mes, &c) != 2 || c != '\n') && clean_stdin()) || mes < 1 || mes > 12);

    do {  

        printf("\n Insira seu ano de nascimento: ");

    } while (((scanf("%d%c", &ano, &c) != 2 || c != '\n') && clean_stdin()) || ano < 1900 || ano > 2019);

    if(validaData(dia, mes, ano) == 1) {
    	printf("\n Data de nascimento registrada: %d/%d/%d.\n\n", dia, mes, ano);
    }

    estados[0][0] = "1 - AC";
    estados[0][1] = "Acre";
    estados[1][0] = "2 - AL";
    estados[1][1] = "Alagoas";
    estados[2][0] = "3 - AP";
    estados[2][1] = "Amapá";
    estados[3][0] = "4 - AM";
    estados[3][1] = "Amazonas";
    estados[4][0] = "5 - BA";
    estados[4][1] = "Bahia";
    estados[5][0] = "6 - CE";
    estados[5][1] = "Ceará";
    estados[6][0] = "7 - DF";
    estados[6][1] = "Distrito Federal";
    estados[7][0] = "8 - ES";
    estados[7][1] = "Espírito Santo";
    estados[8][0] = "9 - GO";
    estados[8][1] = "Goiás";
    estados[9][0] = "10 - MA";
    estados[9][1] = "Maranhão";
    estados[10][0] = "11 - MT";
    estados[10][1] = "Mato Grosso";
    estados[11][0] = "12 - MS";
    estados[11][1] = "Mato Grosso do Sul";
    estados[12][0] = "13 - MG";
    estados[12][1] = "Minas Gerais";
    estados[13][0] = "14 - PA";
    estados[13][1] = "Pará";
    estados[14][0] = "15 - PB";
    estados[14][1] = "Paraíba";
    estados[15][0] = "16 - PR";
    estados[15][1] = "Paraná";
    estados[16][0] = "17 - PE";
    estados[16][1] = "Pernambuco";
    estados[17][0] = "18 - PI";
    estados[17][1] = "Piauí";
    estados[18][0] = "19 - RJ";
    estados[18][1] = "Rio de Janeiro";
    estados[19][0] = "20 - RN";
    estados[19][1] = "Rio Grande do Norte";
    estados[20][0] = "21 - RS";
    estados[20][1] = "Rio Grande do Sul";
    estados[21][0] = "22 - RO";
    estados[21][1] = "Rondônia";
    estados[22][0] = "23 - RR";
    estados[22][1] = "Roraima";
    estados[23][0] = "24 - SC";
    estados[23][1] = "Santa Catarina";
    estados[24][0] = "25 - SP";
    estados[24][1] = "São Paulo";
    estados[25][0] = "26 - SE";
    estados[25][1] = "Sergipe";
    estados[26][0] = "27 - TO";
    estados[26][1] = "Tocantins";

    for(int i = 0; i < 27; i++){
        printf(" %s ---> %s.\n", estados[i][0], estados[i][1]);
    }

    do {  

    	printf("\n Digite o número correspondente ao seu estado: ");

    } while (((scanf("%d%c", &uf, &c) != 2 || c != '\n') && clean_stdin()) || uf < 1 || uf > 27);

    numero_uf = uf;

    numero_uf = numero_uf - 1; // Para acessar o índice correto da matriz é necessário diminuir 1 do número correspondente a letra escolhida pelo usuário.

    printf("\n Insira sua cidade: ");
    scanf(" %[^\n]s", enderCid);
     while(validaNome(enderCid) == 0){
		printf(" Insira um nome válido para a cidade: ");
		scanf(" %[^\n]s", enderCid);
	}

    printf("\n Insira seu bairro: ");
    scanf(" %[^\n]s", enderBair);
    while(validaNome(enderBair) == 0){
		printf(" Insira um nome válido para o bairro: ");
		scanf(" %[^\n]s", enderBair);
	}

    printf("\n Insira o número da sua casa: ");
    scanf(" %[^\n]s", numCasa);
    while(validaEdt(numCasa)==0){
    	printf(" Insira um número válido da sua casa: ");
    	scanf(" %[^\n]s", numCasa);
    }


    printf("\n Insira seu CPF - xxx.xxx.xxx-xx: ");
    scanf(" %[^\n]s", cpf);
	while(validaCPF(cpf)==0){
		printf(" Insira um CPF válido - xxx.xxx.xxx-xx: ");
		scanf(" %[^\n]s", cpf);
	}
	
	printf("\n Insira seu número para contato - xx-xxxxxxxxx: ");
	scanf(" %[^\n]s", tel);
	while(validaTelefone(tel)==0){
		printf(" Insira um número válido (xx)x xxxx-xxxx: ");
		scanf(" %[^\n]s", tel);
	}
		
    printf("\n Insira seu email: ");
	scanf(" %[^\n]s", email);
    while(validaEmail(email)==0){
			printf(" Insira um email válido: ");
			scanf(" %[^\n]s", email);
	}
   
    

}
