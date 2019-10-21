#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int menuPrincipal(void);
void cadastraLivro(void);
void buscaLivro(void);
void editaLivro(void);
void excluiLivro(void);
void listaLivros(void);
void exibeLivro(Livro*);
void gravaLivro(Livro*);

int main(void) {
  int opcao;
  opcao = menuPrincipal();
  while (opcao != 0) {
    switch (opcao) {
      case 1 :  cadastraLivro();
                break;
      case 2 :  buscaLivro();
                break;
      case 3 :  editaLivro();
                break;
      case 4 :  excluiLivro();
                break;
      case 5 :  listaLivros();
                break;
    }
    opcao = menuPrincipal();
  }
  printf("\nFim do programa!\n\n");
  return 0;
}

int menuPrincipal(void) {
  int op;
  printf("\n\n");
  printf("= = = = = = = Sig-Library = = = = = = = \n");
  printf("= Sistema de Gerenciamento de Livros  = \n");
  printf("= = = = = = = = = = = = = = = = = = = \n");
  printf("\nMenu Principal\n");
  printf("1 - Cadastrar livro\n");
  printf("2 - Pesquisar livro\n");
  printf("3 - Alterar livro\n");
  printf("4 - Excluir livro\n");
  printf("5 - Listar todos os livros\n");
  printf("0 - Encerrar programa\n");
  printf("Escolha sua opção: ");
  scanf("%d", &op);
  return op;
}


void cadastraLivro(void) {
  Livro* livro;
  printf("\n\n");
  printf("= = = Sig-Library = = = \n");
  printf("= Cadastrar Livro  = \n");
  printf("= = = = = = = = = = = \n");
  livro = (Livro*) malloc(sizeof(Livro));
  printf("\nInforme o código do livro: ");
  scanf("%d", &livro->cod);
  printf("Informe o nome do livro: ");
  scanf(" %199[^\n]", livro->nomeLiv);
  printf("Informe o autor do livro: ");
  scanf(" %199[^\n]", livro->autor);
  printf("Informe o gênero do livro: ");
  scanf(" %99[^\n]", livro->genero);
  printf("Informe a edição do livro: ");
  scanf(" %99[^\n]", livro->edicao);
  printf("Informe o isbn do livro: ");
  scanf(" %16[^\n]", livro->isbn);
  livro->status = '1';
  printf("###############################\n");
  exibeLivro(livro);
  printf("###############################\n");
  gravaLivro(livro);
}

void buscaLivro(void) {
  FILE* fp;
  Livro* livro;
  int achou;
  char procurado[200];
  fp = fopen("livro.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("= = = Sig-Library = = = \n");
  printf("= = Buscar Livro = = \n");
  printf("= = = = = = = = = = = \n");
  printf("Informe o nome do livro a ser buscado: ");
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
    printf("O livro %s não foi encontrado...\n", procurado);
  }
  free(livro);
}


void editaLivro(void) {
  printf("Menu edita \n");
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
  printf("\n\n");
  printf("= = = Sig-Library = = = \n");
  printf("= = Apagar Livro = = \n");
  printf("= = = = = = = = = = = \n");
  printf("Informe o nome do livro a ser apagado: ");
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
    getchar();
    printf("Deseja realmente apagar este livro (S/N)? ");
    scanf(" %c", &resp);
    if (resp == 's' || resp == 'S') {
      livro->status = '0';
      fseek(fp, -1 * sizeof(Livro), SEEK_CUR);
      fwrite(livro, sizeof(Livro), 1, fp);
      printf("\nLivro excluído com sucesso!!!\n");
     } else {
       printf("\nOk, os dados não foram alterados\n");
     }
  } else {
    printf("O livro %s não foi encontrado...\n", procurado);
  }
  free(livro);
}


void listaLivros(void) {
  FILE* fp;
  Livro* livro;
  fp = fopen("livro.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("= = = Sig-Library = = = \n");
  printf("= = Exibe Livros = = \n");
  printf("= = = = = = = = = = = \n");
  livro = (Livro*) malloc(sizeof(Livro));
  while(fread(livro, sizeof(Livro), 1, fp)) {
    if (livro->status == '1') {
      exibeLivro(livro);
    }
  }
  fclose(fp);
  free(livro);
}


void gravaLivro(Livro* livro) {
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
  printf("Código: %d\n", livro->cod);
  printf("Nome do livro: %s\n", livro->nomeLiv);
  printf("Autor: %s\n", livro->autor);
  printf("Gênero: %s\n", livro->genero);
  printf("Edição: %s\n", livro->edicao);
  printf("ISBN: %s\n", livro->isbn);
  printf("\n");
}

