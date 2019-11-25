#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pes Pes;

struct pes {

    int dia;
    int mes;
    int ano;
    int numero_uf;
    int uf;
    char nome[101];
    char enderCid[101];
    char enderBair[101];
    char numCasa[51];
    char cpf[12]; 
    char tel[13];
    char email[31];
    char login[51];
    char senha[51];
    char c;
    char status;

};

void exibePessoasEncontradas(Pes** usuarios_encontrados, int quantidade);

int main (void) {

    FILE* fp;

    Pes* cadastro_pess;
    Pes** usuarios_encontrados;

    int i;
    int aux;
    int tam;
    int achou;

    char procurado[100];
    char resp;

    fp = fopen("pessoas.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>       BUSCA PESSOA        <<<");
    printf("\n =================================");
    printf("\n");

    printf(" Informe o nome da pessoa a ser buscada: ");
    scanf(" %100[^\n]", procurado);

    i = 0;
    aux = 0;
    achou = 0;

    cadastro_pess = (Pes*) malloc(sizeof(Pes));

    while(fread(cadastro_pess, sizeof(Pes), 1, fp)) {

      i += 1;

    }

    fclose(fp);
    free(cadastro_pess);

    Pes* cadastro_pess2;
    Pes* auxiliar;
    cadastro_pess2 = (Pes*) malloc(sizeof(Pes));

    FILE* fp2;
    fp2 = fopen("pessoas.dat", "rb");
    if (fp2 == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }

    tam = i;
    usuarios_encontrados = (Pes**) malloc(tam * sizeof(Pes*));

    int tamanho_procurado = strlen(procurado);

    while(fread(cadastro_pess2, sizeof(Pes), 1, fp2)) {

        char string_auxiliar[100];

        strcpy(string_auxiliar, cadastro_pess2->nome);

        int tamanho_string_auxiliar;

        tamanho_string_auxiliar = strlen(string_auxiliar);

        for(int i = 0; i < tamanho_procurado; i++) {
          
          if(tamanho_procurado == 1) {

            if((string_auxiliar[i] == procurado[i]) && (cadastro_pess2->status == '1')) {

              usuarios_encontrados[aux] = cadastro_pess2;
            
              aux += 1;
              achou = 1;

              auxiliar = (Pes*) malloc(sizeof(Pes));

              cadastro_pess2 = auxiliar;

              break;               
            }

          } else {

            if((string_auxiliar[i] == procurado[i]) && (string_auxiliar[i + 1] == procurado[i + 1]) && (cadastro_pess2->status == '1')) {

              usuarios_encontrados[aux] = cadastro_pess2;
            
              aux += 1;
              achou = 1;

              auxiliar = (Pes*) malloc(sizeof(Pes));

              cadastro_pess2 = auxiliar;

              break;   
    
            }

          }

        }

    }

    fclose(fp2);

    if (achou) {

        exibePessoasEncontradas(usuarios_encontrados, aux);

    } else {

        printf("\n %s não foi encontrado(a)...\n", procurado);

    }

    printf("\n Digite algo e tecle ENTER para continuar.\n\n");
    scanf(" %c", &resp);

    free(auxiliar);
    free(cadastro_pess2);

    return 0;

}

void exibePessoasEncontradas(Pes** usuarios_encontrados, int quantidade) {

  for(int k = 0; k < quantidade; k++) {
    
    int dia = usuarios_encontrados[k]->dia;
    int mes = usuarios_encontrados[k]->mes;
    int ano = usuarios_encontrados[k]->ano;
    int numero_uf = usuarios_encontrados[k]->uf;

    printf("\n\n Nome: %s \n", usuarios_encontrados[k]->nome);
    printf(" CPF: %c%c%c.%c%c%c.%c%c%c-%c%c \n", usuarios_encontrados[k]->cpf[0], usuarios_encontrados[k]->cpf[1], usuarios_encontrados[k]->cpf[2], usuarios_encontrados[k]->cpf[3], usuarios_encontrados[k]->cpf[4], usuarios_encontrados[k]->cpf[5], usuarios_encontrados[k]->cpf[6], usuarios_encontrados[k]->cpf[7], usuarios_encontrados[k]->cpf[8], usuarios_encontrados[k]->cpf[9], usuarios_encontrados[k]->cpf[10]);

    printf(" Data de nascimento: %d/%d/%d \n", dia, mes, ano);

    printf(" Email: %s \n", usuarios_encontrados[k]->email);
    printf(" Login: %s \n", usuarios_encontrados[k]->login);
    printf(" Senha: %s \n", usuarios_encontrados[k]->senha);
    printf(" Telefone: %s \n", usuarios_encontrados[k]->tel);

    if(numero_uf == 1) {
        char nome_uf[] = "Acre";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 2) {
        char nome_uf[] = "Alagoas";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 3) {
        char nome_uf[] = "Amapá";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 4) {
        char nome_uf[] = "Amazonas";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 5) {
        char nome_uf[] = "Bahia";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 6) {
        char nome_uf[] = "Ceará";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 7) {
        char nome_uf[] = "Distrito Federal";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 8) {
        char nome_uf[] = "Espírito Santo";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 9) {
        char nome_uf[] = "Goiás";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 10) {
        char nome_uf[] = "Maranhão";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 11) {
        char nome_uf[] = "Mato Grosso";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 12) {
        char nome_uf[] = "Mato Grosso do Sul";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 13) {
        char nome_uf[] = "Minas Gerais";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 14) {
        char nome_uf[] = "Pará";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 15) {
        char nome_uf[] = "Paraíba";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 16) {
        char nome_uf[] = "Paraná";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 17) {
        char nome_uf[] = "Pernambuco";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 18) {
        char nome_uf[] = "Piauí";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 19) {
        char nome_uf[] = "Rio de Janeiro";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 20) {
        char nome_uf[] = "Rio Grande do Norte";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 21) {
        char nome_uf[] = "Rio Grande do Sul";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 22) {
        char nome_uf[] = "Rondônia";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 23) {
        char nome_uf[] = "Roraima";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 24) {
        char nome_uf[] = "Santa Catarina";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 25) {
        char nome_uf[] = "São Paulo";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 26) {
        char nome_uf[] = "Sergipe";
        printf(" Estado: %s \n", nome_uf);
    } else if(numero_uf == 27) {
        char nome_uf[] = "Tocantins";
        printf(" Estado: %s \n", nome_uf);
    }

    printf(" Cidade: %s \n", usuarios_encontrados[k]->enderCid);
    printf(" Bairro: %s \n", usuarios_encontrados[k]->enderBair);
    printf(" Numero da casa: %s \n", usuarios_encontrados[k]->numCasa);
    printf("\n");

  }

  free(usuarios_encontrados);

}