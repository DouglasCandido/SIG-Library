#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "telas.h"
#include "validations.h"
#include "esqueleto.h"

int codigo_incremental = 0;
int codigo_incremental2 = 0;


typedef struct livro Livro;

struct livro {

  int cod;
  char nomeLiv[200]; 
  char autor[200]; 
  char genero[100]; 
  char editora[100]; 
  char edicao[100]; 
  char isbn[17];
  char status;

};


typedef struct pes Pes;

struct pes {
  int cod;
  int dia;
  int mes; 
  int ano;
  int numero_uf;
  int uf;
  char nome[100];
  char enderCid[100];
  char enderBair[100];
  char numCasa[50];
  char cpf[15];
  char tel[16];
  char email[30];
  char *estados[27][2];
  char c;
  char status;

};


void exibePessoas(Pes* cadastro_pess);


void menuEditaPessoa(void){
    system("clear");
    printf("\n =================================");
    printf("\n | | | Programa Biblioeteca | | |");                      
    printf("\n =================================");
    printf("\n >>>>>>ATUALIZAR INFORMAÇÕES<<<<<<");
    printf("\n =================================");
    printf("\n\n[]A - Alterar nome");
    printf("\n[]B - Alterar telefone");
    printf("\n[]C - Alterar email");
    printf("\n[]D - Alterar endereço");
    printf("\n[]E - Alterar CPF");
    printf("\n[]S - Voltar");
}


void editaPessoa(void){
  FILE* fp;
  Pes* pes;
  char resp;
  fp = fopen("pessoas.dat", "ab");
  pes = (Pes*) malloc(sizeof(Pes));

  do{
    menuEditaPessoa();
    printf("\n\nEscolha uma opção: ");
    scanf(" %c", &resp);
    resp = maius(resp);

  }while (resp != 'S');
  
  fclose(fp);
  free(pes);
}

void exibePessoas(Pes* cadastro_pess) {
  printf("Nome: %s\n", cadastro_pess->nome);
  printf("Cidade: %s\n", cadastro_pess->enderCid);
  printf("Bairro: %s\n", cadastro_pess->enderBair);
  printf("Numero da casa: %s\n", cadastro_pess->numCasa);
  printf("Email: %s\n", cadastro_pess->email);
  printf("CPF: %s\n", cadastro_pess->cpf);
  printf("Telefone: %s\n", cadastro_pess->tel);
  printf("Estado: %d\n", cadastro_pess->uf);
  printf("\n");
}

void listaPessoas(void) {
  char a;
  system("clear");

  FILE* fp;
  Pes* cadastro_pess;
  fp = fopen("pessoas.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  printf("\n\n");
  printf("\n =================================");
  printf("\n | | | Programa Biblioeteca | | |");                      
  printf("\n =================================");
  printf("\n >>>>>> Listar Pessoas <<<<<<");
  printf("\n =================================\n\n");


  cadastro_pess = (Pes*) malloc(sizeof(Pes));

  cadastro_pess->cod = codigo_incremental2;

  while(fread(cadastro_pess, sizeof(Pes), 1, fp)) {
    if(cadastro_pess->status == '1') {
    	exibePessoas(cadastro_pess);
	}
        
  }
  exibeEstados();
  fclose(fp);
  free(cadastro_pess);

  printf("Digite algo e tecle ENTER para continuar.\n");
  scanf(" %c",&a);

}

void gravaPessoas(Pes* pes) {
  FILE* fp;
  pes->status = '1';

  fp = fopen("pessoas.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  fwrite(pes, sizeof(Pes), 1, fp);
  fclose(fp);
}

void exibeEstados(void){
  Pes* cadastro_pess;
  cadastro_pess = (Pes*) malloc(sizeof(Pes));

    cadastro_pess->estados[0][0] = "1 - AC";
    cadastro_pess->estados[0][1] = "Acre";
    cadastro_pess->estados[1][0] = "2 - AL";
    cadastro_pess->estados[1][1] = "Alagoas";
    cadastro_pess->estados[2][0] = "3 - AP";
    cadastro_pess->estados[2][1] = "Amapá";
    cadastro_pess->estados[3][0] = "4 - AM";
    cadastro_pess->estados[3][1] = "Amazonas";
    cadastro_pess->estados[4][0] = "5 - BA";
    cadastro_pess->estados[4][1] = "Bahia";
    cadastro_pess->estados[5][0] = "6 - CE";
    cadastro_pess->estados[5][1] = "Ceará";
    cadastro_pess->estados[6][0] = "7 - DF";
    cadastro_pess->estados[6][1] = "Distrito Federal";
    cadastro_pess->estados[7][0] = "8 - ES";
    cadastro_pess->estados[7][1] = "Espírito Santo";
    cadastro_pess->estados[8][0] = "9 - GO";
    cadastro_pess->estados[8][1] = "Goiás";
    cadastro_pess->estados[9][0] = "10 - MA";
    cadastro_pess->estados[9][1] = "Maranhão";
    cadastro_pess->estados[10][0] = "11 - MT";
    cadastro_pess->estados[10][1] = "Mato Grosso";
    cadastro_pess->estados[11][0] = "12 - MS";
    cadastro_pess->estados[11][1] = "Mato Grosso do Sul";
    cadastro_pess->estados[12][0] = "13 - MG";
    cadastro_pess->estados[12][1] = "Minas Gerais";
    cadastro_pess->estados[13][0] = "14 - PA";
    cadastro_pess->estados[13][1] = "Pará";
    cadastro_pess->estados[14][0] = "15 - PB";
    cadastro_pess->estados[14][1] = "Paraíba";
    cadastro_pess->estados[15][0] = "16 - PR";
    cadastro_pess->estados[15][1] = "Paraná";
    cadastro_pess->estados[16][0] = "17 - PE";
    cadastro_pess->estados[16][1] = "Pernambuco";
    cadastro_pess->estados[17][0] = "18 - PI";
    cadastro_pess->estados[17][1] = "Piauí";
    cadastro_pess->estados[18][0] = "19 - RJ";
    cadastro_pess->estados[18][1] = "Rio de Janeiro";
    cadastro_pess->estados[19][0] = "20 - RN";
    cadastro_pess->estados[19][1] = "Rio Grande do Norte";
    cadastro_pess->estados[20][0] = "21 - RS";
    cadastro_pess->estados[20][1] = "Rio Grande do Sul";
    cadastro_pess->estados[21][0] = "22 - RO";
    cadastro_pess->estados[21][1] = "Rondônia";
    cadastro_pess->estados[22][0] = "23 - RR";
    cadastro_pess->estados[22][1] = "Roraima";
    cadastro_pess->estados[23][0] = "24 - SC";
    cadastro_pess->estados[23][1] = "Santa Catarina";
    cadastro_pess->estados[24][0] = "25 - SP";
    cadastro_pess->estados[24][1] = "São Paulo";
    cadastro_pess->estados[25][0] = "26 - SE";
    cadastro_pess->estados[25][1] = "Sergipe";
    cadastro_pess->estados[26][0] = "27 - TO";
    cadastro_pess->estados[26][1] = "Tocantins";

    for(int i = 0; i < 27; i++){
        printf(" %s ---> %s.\n", cadastro_pess->estados[i][0], cadastro_pess->estados[i][1]);
    }
    free(cadastro_pess);
}


void cadastroPessoa() {
    Pes* cadastro_pess;

    cadastro_pess = (Pes*) malloc(sizeof(Pes));

    system("clear");

    printf("\n =================================");
    printf("\n | | | Programa Biblioeteca | | |");                      
    printf("\n =================================");
    printf("\n >>>>>> CADASTRO DE PESSOAS <<<<<<");
    printf("\n =================================");


    printf("\n\n Insira seu nome completo: ");
    scanf(" %99[^\n]", cadastro_pess->nome);

    while(validaNome(cadastro_pess->nome) == 0){
        printf(" Insira um nome válido: ");
        scanf(" %99[^\n]", cadastro_pess->nome);
    }


    do {  
      printf("\n Insira seu dia de nascimento: ");
    }while(((scanf("%d%c", &cadastro_pess->dia, &cadastro_pess->c) != 2 || cadastro_pess->c != '\n') && clean_stdin()) || cadastro_pess->dia < 1 || cadastro_pess->dia > 31);

    do{  
      printf("\n Insira seu mês de nascimento: ");

    }while (((scanf("%d%c", &cadastro_pess->mes, &cadastro_pess->c) != 2 || cadastro_pess->c != '\n') && clean_stdin()) || cadastro_pess->mes < 1 || cadastro_pess->mes > 12);

    do {  
      printf("\n Insira seu ano de nascimento: ");
    } while (((scanf("%d%c", &cadastro_pess->ano, &cadastro_pess->c) != 2 || cadastro_pess->c != '\n') && clean_stdin()) || cadastro_pess->ano < 1900 || cadastro_pess->ano > 2019);
        if(validaData(cadastro_pess->dia, cadastro_pess->mes, cadastro_pess->ano) == 1) {
          printf("\n Data de nascimento registrada: %d/%d/%d.\n\n", cadastro_pess->dia, cadastro_pess->mes, cadastro_pess->ano);
        }
      exibeEstados();

    do {  
      printf("\n Digite o número correspondente ao seu estado: ");
    } while (((scanf("%d%c", &cadastro_pess->uf, &cadastro_pess->c) != 2 || cadastro_pess->c != '\n') && clean_stdin()) || cadastro_pess->uf < 1 || cadastro_pess->uf > 27);

    cadastro_pess->numero_uf = cadastro_pess->uf;
    cadastro_pess->numero_uf = cadastro_pess->numero_uf - 1; // Para acessar o índice correto da matriz é necessário diminuir 1 do número correspondente a letra escolhida pelo usuário.



    printf("\n Insira sua cidade: ");
    scanf(" %99[^\n]", cadastro_pess->enderCid);
    while(validaNome(cadastro_pess->enderCid) == 0){
      printf(" Insira um nome válido para a cidade: ");
      scanf(" %99[^\n]", cadastro_pess->enderCid);
    }

    printf("\n Insira seu bairro: ");
    scanf(" %99[^\n]", cadastro_pess->enderBair);
    while(validaNome(cadastro_pess->enderBair) == 0){
      printf(" Insira um nome válido para o bairro: ");
      scanf(" %99[^\n]", cadastro_pess->enderBair);
    }

    printf("\n Insira o número da sua casa: ");
    scanf(" %99[^\n]", cadastro_pess->numCasa);
    while(validaEdt(cadastro_pess->numCasa)==0){
      printf(" Insira um número válido da sua casa: ");
      scanf(" %99[^\n]", cadastro_pess->numCasa);
    }


    printf("\n Insira seu CPF - xxx.xxx.xxx-xx: ");
    scanf(" %99[^\n]", cadastro_pess->cpf);
    setbuf(stdin, NULL);
    while(validaCPF(cadastro_pess->cpf)==0){
      printf(" Insira um CPF válido - xxx.xxx.xxx-xx: ");
      scanf(" %99[^\n]", cadastro_pess->cpf);
      setbuf(stdin, NULL);
    }
    
    printf("\n Insira seu número para contato - xx-xxxxxxxxx: ");
    scanf(" %99[^\n]", cadastro_pess->tel);
    while(validaTelefone(cadastro_pess->tel)==0){
      printf(" Insira um número válido (xx)x xxxx-xxxx: ");
      scanf(" %99[^\n]", cadastro_pess->tel);
    }
        
    printf("\n Insira seu email: ");
    scanf(" %99[^\n]", cadastro_pess->email);
    while(validaEmail(cadastro_pess->email)==0){
      printf(" Insira um email válido: ");
      scanf(" %99[^\n]", cadastro_pess->email);
    }
    gravaPessoas(cadastro_pess);
    codigo_incremental += 1;    
}



void gravaLivro(Livro* livro) {

  livro->status = '1';

  FILE* fp;

  fp = fopen("livro.dat", "ab");

  if (fp == NULL) {

    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");

    exit(1);
  
  }

  fwrite(livro, sizeof(Livro), 1, fp);

  fclose(fp);

}



void exibeLivro(Livro* livro) {

	printf(" Código: %d\n", livro->cod);
	printf(" Nome do livro: %s\n", livro->nomeLiv);
	printf(" Autor: %s\n", livro->autor);
	printf(" Gênero: %s\n", livro->genero);
	printf(" Edição: %s\n", livro->edicao);
	printf(" ISBN: %s\n", livro->isbn);
	printf("\n");

}

void buscaLivro(void) {

  FILE* fp;
  Livro* livro;
  int achou;
  char procurado[200];
  char resp;

  fp = fopen("livro.dat", "rb");

  if (fp == NULL) {

    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");

    exit(1);

  }

  system("clear");

		printf("\n =================================");
		printf("\n | | | Programa Biblioeteca | | |");                      
		printf("\n =================================");
		printf("\n >>>        BUSCA LIVRO        <<<");
		printf("\n =================================");
		printf("\n");

  printf(" Informe o nome do livro a ser buscado: ");
  scanf(" %199[^\n]", procurado);

  livro = (Livro*) malloc(sizeof(Livro));

  achou = 0;

  while((!achou) && (fread(livro, sizeof(Livro), 1, fp))) {

   if ((strcmp(livro->nomeLiv, procurado) == 0) && (livro->status == '1')) {

     achou = 1;

   }

  }

  fclose(fp);

  if (achou) {

    exibeLivro(livro);

  } else {

    printf("\n O livro %s não foi encontrado...\n", procurado);

  }

  printf("\n Digite algo e tecle ENTER para continuar.\n\n");
  scanf(" %c", &resp);

  free(livro);

}

void buscaPessoa(void) {

  FILE* fp;
  Pes* cadastro_pess;
  int achou;
  char procurado[200];
  char resp;

  fp = fopen("pessoas.dat", "rb");

  if (fp == NULL) {

    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");

    exit(1);

  }

  system("clear");

		printf("\n =================================");
		printf("\n | | | Programa Biblioeteca | | |");                      
		printf("\n =================================");
		printf("\n >>>        BUSCA PESSOAS        <<<");
		printf("\n =================================");
		printf("\n");

  printf(" Informe o nome da pessoa a ser buscada: ");
  scanf(" %199[^\n]", procurado);

  cadastro_pess = (Pes*) malloc(sizeof(Pes));

  achou = 0;

  while((!achou) && (fread(cadastro_pess, sizeof(Pes), 1, fp))) {

   if ((strcmp(cadastro_pess->nome, procurado) == 0) && (cadastro_pess->status == '1')) {

     achou = 1;

   }

  }

  fclose(fp);

  if (achou) {

    exibePessoas(cadastro_pess);

  } else {

    printf("\n  %s não foi encontrado(a)...\n", procurado);

  }

  printf("\n Digite algo e tecle ENTER para continuar.\n\n");
  scanf(" %c", &resp);

  free(cadastro_pess);

}


void editaLivro(void) {

  printf("Menu editar Livro \n");

}

void excluiLivro(void) {

  FILE* fp;
  Livro* livro;
  int achou;
  char resp;
  char procurado[200];

  fp = fopen("livro.dat", "r+b");

  if (fp == NULL) {

    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");

    exit(1);

  }

  system("clear");

		printf("\n =================================");
		printf("\n | | | Programa Biblioeteca | | |");                      
		printf("\n =================================");
		printf("\n >>>        EXCLUI LIVRO       <<<");
		printf("\n =================================");
		printf("\n");

  printf(" Informe o nome do livro a ser apagado: ");
  scanf(" %199[^\n]", procurado);

  livro = (Livro*) malloc(sizeof(Livro));

  achou = 0;

  while((!achou) && (fread(livro, sizeof(Livro), 1, fp))) {

   if ((strcmp(livro->nomeLiv, procurado) == 0) && (livro->status == '1')) {

     achou = 1;

   }

  }

  if (achou) {

    exibeLivro(livro);

    printf(" Deseja realmente apagar este livro (S/N)? ");

    scanf(" %c", &resp);

    if (resp == 's' || resp == 'S') {

      livro->status = '0';

      fseek(fp, -1 * sizeof(Livro), SEEK_CUR);

      fwrite(livro, sizeof(Livro), 1, fp);

      printf("\n Livro excluído com sucesso!!!\n");

    } else {

      printf("\n Ok, os dados não foram alterados\n");

    }

  } else {

    printf(" O livro %s não foi encontrado...\n", procurado);

  }

  fclose(fp);

  free(livro);

}

void excluiPessoa(void) {

  FILE* fp;
  Pes* cadastro_pess;
  int achou;
  char resp;
  char procurado[200];

  fp = fopen("pessoas.dat", "r+b");

  if (fp == NULL) {

    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");

    exit(1);

  }

  system("clear");

		printf("\n =================================");
		printf("\n | | | Programa Biblioeteca | | |");                      
		printf("\n =================================");
		printf("\n >>>        EXCLUI PESSOA      <<<");
		printf("\n =================================");
		printf("\n");

  printf(" Informe o nome da pessoa a ser removida: ");
  scanf(" %199[^\n]", procurado);

  cadastro_pess = (Pes*) malloc(sizeof(Pes));

  achou = 0;

  while((!achou) && (fread(cadastro_pess, sizeof(Pes), 1, fp))) {

   if ((strcmp(cadastro_pess->nome, procurado) == 0) && (cadastro_pess->status == '1')) {

     achou = 1;

   }

  }

  if (achou) {

    exibePessoas(cadastro_pess);

    printf(" Deseja realmente remover esta pessoa (S/N)? ");

    scanf(" %c", &resp);

    if (resp == 's' || resp == 'S') {

      cadastro_pess->status = '0';

      fseek(fp, -1 * sizeof(Pes), SEEK_CUR);

      fwrite(cadastro_pess, sizeof(Pes), 1, fp);

      printf("\nPessoa removida com sucesso!!!\n");

    } else {

      printf("\n Ok, os dados não foram alterados\n");

    }

  } else {

    printf(" %s não foi encontrado...\n", procurado);

  }

  fclose(fp);

  free(cadastro_pess);

}




void listaLivros(void) {

  char resp;

  FILE* fp;
  Livro* livro;

  fp = fopen("livro.dat", "rb");

  if (fp == NULL) {

    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");

    exit(1);

  }

  system("clear");
  
		printf("\n =================================");
		printf("\n | | | Programa Biblioeteca | | |");                      
		printf("\n =================================");
		printf("\n >>>       EXIBE LIVRO         <<<");
		printf("\n =================================");
		printf("\n");

  livro = (Livro*) malloc(sizeof(Livro));

  while(fread(livro, sizeof(Livro), 1, fp)) {

  	if(livro->status == '1') {

    	exibeLivro(livro);

	}

  }

  printf("\n Digite algo e tecle ENTER para continuar.\n\n");
  scanf(" %c", &resp);

  fclose(fp);

  free(livro);

}


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

	/*
	Livro* livro;

	livro = (Livro*) malloc(sizeof(Livro));
	*/

	char resp;
	char op;
	char op2;
	do {
		
		system("clear");
		printf("\n =================================");
		printf("\n | | | Programa Biblioeteca | | |");                      
		printf("\n =================================");
		printf("\n >>>         MENU ADM          <<<");
		printf("\n =================================");
		printf("\n\n []A - Gerenciar Pessoas\n");
		printf(" []B - Gerenciar Livros\n");
		printf(" []C - Gerenciar Emprestimos\n");
		printf(" []D - Logs e Relatórios\n");
		printf(" []S - Sair\n");
		
		printf(" \nEscolha uma opção: ");
		scanf(" %c", &resp);
		resp = maius(resp);

		switch(resp) {
			
			case 'A':
				do {
				gerenciarPessoas();
				printf(" \nEscolha uma opção: ");
				scanf(" %c", &op);
				op = maius(op);

			
				switch(op){
					case 'A':
					cadastroPessoa();
					break;

					case 'B':
					buscaPessoa();
					break;

					case 'C':
					listaPessoas();
					break;

					case 'D':
					excluiPessoa();
					break;

					
					case 'E':
					editaPessoa();
					break;
					
					case 'F':
					printf("não implementado\n");
					break;
					}


					}while (op != 'S'); 
								
			break;
			
			
			case 'B':
				do{
					gerenciarLivros();
					printf(" \nEscolha uma opção: ");
					scanf(" %c", &op2);
					op2 = maius(op2);
					switch(op2){
						case 'A':
						cadastroLivro();
						break;

						case 'B':
						buscaLivro();
						break;

						case 'C':
						listaLivros();
						break;

						case 'D':
						excluiLivro();
						break;

						case 'E':
						printf("ainda não implementado\n" );
						break;

					}
				}while(op2 != 'S');
			break;
				
			case 'C':
				menuGerenciarEmprestimos();
				break;
				
			case 'D':
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

void gerenciarPessoas(void){
	system("clear");
	printf("\n =================================");
	printf("\n | | | Programa Biblioeteca | | |");                      
	printf("\n =================================");
	printf("\n >>>     GERENCIAR PESSOAS     <<<");
	printf("\n =================================");
	printf("\n\n []A - Cadastrar Pessoa\n");
	printf(" []B - Buscar Pessoa\n");
	printf(" []C - Listar pessoas cadastradas\n");
	printf(" []D - Excluir pessoas\n");
	printf(" []E - Editar informações\n");
	printf(" []F - Redefinir nome de usuário ou senha\n");		
	printf(" []S - Sair\n");
}


void gerenciarLivros(void){
		system("clear");
		printf("\n =================================");
		printf("\n | | | Programa Biblioeteca | | |");                      
		printf("\n =================================");
		printf("\n >>>      GERENCIAR LIVROS     <<<");
		printf("\n =================================");
		printf("\n\n []A - Cadastrar Livro\n");
		printf(" []B - Buscar Livro\n");
		printf(" []C - Listar livros cadastradas\n");
		printf(" []D - Excluir livros\n");
		printf(" []E - Editar livro\n");		
		printf(" []S - Sair\n");
}


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
				listaLivros();
				break;
				
			case 'B':
				buscaLivro();
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

	Livro* livro;

	livro = (Livro*) malloc(sizeof(Livro));

    system("clear");

    printf("\n =================================");
	printf("\n | | | Programa Biblioeteca | | |");                      
	printf("\n =================================");
	printf("\n >>>>>>> CADASTRO DE LIVROS <<<<<<");
	printf("\n =================================");

	livro->cod = codigo_incremental;

    printf("\n Insira o nome do livro: ");
    scanf(" %[^\n]s", livro->nomeLiv);
    while(validaEdt(livro->nomeLiv) == 0){
    	printf(" Insira um nome válido para o livro: ");
    	scanf(" %[^\n]s", livro->nomeLiv);
    }

    printf("\n Insira o ISBN do livro [xxx-xx-xxx-xxxx-x]: ");
    scanf(" %[^\n]s", livro->isbn);
    while(validaISBN(livro->isbn) == 0){
		printf(" Insira o ISBN correto [xxx-xx-xxx-xxxx-x]: ");
		scanf(" %[^\n]s", livro->isbn);
	}

    printf("\n Insira o nome do autor: ");
    scanf(" %[^\n]s", livro->autor);
    while(validaNome(livro->autor) == 0){
		printf(" Insira um nome válido: ");
		scanf(" %[^\n]s", livro->autor);
	}

    printf("\n Insira o gênero do livro: ");
    scanf(" %[^\n]s", livro->genero);
    while (validaNome(livro->genero)== 0){
    	printf(" Insira um gênero válido do livro: ");
    	scanf(" %[^\n]s", livro->genero);
    }
    
    printf("\n Insira a editora do livro: ");
    scanf(" %[^\n]s", livro->editora);
    while(validaEdt(livro->editora) == 0){
    	printf(" Insira um nome válido para a editora do livro: ");
    	scanf(" %[^\n]s", livro->editora);
    }


    printf("\n Insira a edição do livro: ");
    scanf(" %[^\n]s", livro->edicao);
    while(validaEdt(livro->edicao)==0){
    	printf(" Insira uma edição válida para o livro: ");
    	scanf(" %[^\n]s", livro->edicao);
    }

    printf("###############################\n");
  	exibeLivro(livro);
  	printf("###############################\n");
  	gravaLivro(livro);

  	codigo_incremental += 1;
    
}

