#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "telas.h"
#include "validations.h"
#include "main.h"

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
    char c;
    char status;
    char multado;
    char motivo[101];
    time_t segundos;
    time_t segundos2;
    int dia_inicio;
    int mes_inicio;
    int ano_inicio;
    int hora_inicio;
    int minuto_inicio;
    int segundo_inicio;
    int dia_termino;
    int mes_termino;
    int ano_termino;
    int hora_termino;
    int minuto_termino;
    int segundo_termino;
    int quantidade_de_livros_emprestados;

};

typedef struct noPes NoPes;

struct noPes {

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
    char c;
    char status;
    char multado;
    char motivo[101];
    time_t segundos;
    time_t segundos2;
    int dia_inicio;
    int mes_inicio;
    int ano_inicio;
    int hora_inicio;
    int minuto_inicio;
    int segundo_inicio;
    int dia_termino;
    int mes_termino;
    int ano_termino;
    int hora_termino;
    int minuto_termino;
    int segundo_termino;
    int quantidade_de_livros_emprestados;
    NoPes* prox;

};

typedef struct livro Livro;

struct livro {

    char nome[101];
    char isbn[18];
    char autor[201];
    char genero[101];
    char editora[101];
    char edicao[3];
    char status;
    char matricula[13];
    char preco[4];
    char emprestado;
    int quantidade_de_vezes_emprestado;


};

typedef struct noLivro NoLivro;

struct noLivro {

    char nome[101];
    char isbn[18];
    char autor[201];
    char genero[101];
    char editora[101];
    char edicao[3];
    char status;
    char matricula[13];
    char preco[4];
    char emprestado;
    int quantidade_de_vezes_emprestado;
    NoLivro* prox;

};

typedef struct emprestimo Emprestimo;

struct emprestimo {

    char cod[11];
    char nome[101];
    char cpf[12];
    char nomeLiv[101];
    char isbn[18];
    char matricula[13];
    time_t segundos;
    time_t segundos2;
    char status;
    char emprestado;
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    int segundo;
    int dia_entrega;
    int mes_entrega;
    int ano_entrega;
    int hora_entrega;
    int minuto_entrega;
    int segundo_entrega;

};

typedef struct noEmprestimo NoEmprestimo;

struct noEmprestimo {

    char cod[11];
    char nome[101];
    char cpf[12];
    char nomeLiv[101];
    char isbn[18];
    char matricula[13];
    time_t segundos;
    time_t segundos2;
    char status;
    char emprestado;
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    int segundo;
    int dia_entrega;
    int mes_entrega;
    int ano_entrega;
    int hora_entrega;
    int minuto_entrega;
    int segundo_entrega;
    NoEmprestimo* prox;

};


NoPes* listaOrdenadaPessoas(void);
NoPes* listaDiretaPessoas(void);
NoPes* listaInvertidaPessoas(void);
void exibeListaPessoas(NoPes* lista);
NoLivro* listaDiretaLivros(void);
NoLivro* listaInvertidaLivros(void);
NoLivro* listaOrdenadaLivros(void);
void exibeListaLivros(NoLivro*);
NoEmprestimo* listaDiretaEmprestimo(void);
NoEmprestimo* listaInvertidaEmprestimo(void);
NoEmprestimo* listaOrdenadaEmprestimo(void);
void exibeListaEmprestimo(NoEmprestimo*);
int verificaCPF(char procurado[11]);
int verificaCodigoEmprestimo(char procurado[10]);
int verifica_matricula(char procurado[12]);
void gravaEmprestimo(Emprestimo* emprestimo);
void listaEmprestimos(void);
void exibeEmprestimo(Emprestimo* emprestimo);
void mostraPessoa(Emprestimo* emprestimo);
void mostraLivro(Emprestimo* emprestimo);
void exibePessoa(Pes* cadastro_pess);
void exibeLivro(Livro* livro);
void busca_especifica_pessoa(void);
void busca_especifica_livro(void);
void busca_especifica_emprestimo(void);
void pesquisaNomePessoa(void);
void pesquisaCPFPessoa(void);
void exibePessoasEncontradas(Pes** usuarios_encontrados, int quantidade);
void pesquisaTituloLivro(void);
void pesquisaAutorLivro(void);
void pesquisaISBNLivro(void);
void pesquisaMatriculaLivro(void);
void pesquisaGeneroLivro(void);
void exibeLivrosEncontrados(Livro** livros_encontrados, int quantidade);
void pesquisaPorCodigoEmprestimo(void);
void pesquisaPorCPFEmprestimo(void);
void pesquisaPorMatriculaEmprestimo(void);
void pesquisaPorDataEmprestimo(void);
void exibeEmprestimosEncontrados(Emprestimo** emprestimos_encontrados, int quantidade);

void listaEmprestimos(void) {

    system("clear");

    FILE* fp;
    Emprestimo* emprestimo;

    fp = fopen("emprestimos.dat", "rb");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    printf("\n");
    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>       LOG EMPRÉSTIMOS     <<<");
    printf("\n =================================\n");

    emprestimo = (Emprestimo*) malloc(sizeof(Emprestimo));

    while(fread(emprestimo, sizeof(Emprestimo), 1, fp)) {

        if(emprestimo->status == '1') {

            exibeEmprestimo(emprestimo);

        }

    }

    fclose(fp);
    free(emprestimo);

    printf(" Tecle ENTER para continuar.\n");
    getchar();
    getchar();

}

void exibeEmprestimo(Emprestimo* emprestimo) {

    printf("\n\n Código do empréstimo: %s \n", emprestimo->cod);
    printf("\n Nome do leitor: %s \n", emprestimo->nome);
    printf(" CPF do leitor: %s \n", emprestimo->cpf);
    printf(" Nome do livro: %s \n", emprestimo->nomeLiv);
    printf(" ISBN do livro: %s \n", emprestimo->isbn);
    printf(" Matrícula do livro: %s \n", emprestimo->matricula);
    printf(" Data de realização do empréstimo do livro: %d/", emprestimo->dia);
    printf("%d/", emprestimo->mes);
    printf("%d", emprestimo->ano);
    printf(" ---> Horário: %d horas, %d minutos e %d segundos.\n", emprestimo->hora, emprestimo->minuto, emprestimo->segundo);
    printf(" Data estimada de devolução do livro: %d/", emprestimo->dia_entrega);
    printf("%d/", emprestimo->mes_entrega);
    printf("%d", emprestimo->ano_entrega);
    printf(" ---> Horário: %d horas, %d minutos e %d segundos.\n", emprestimo->hora_entrega, emprestimo->minuto_entrega, emprestimo->segundo_entrega);
    printf("\n");

}

void gerenciarEmprestimos(void) {

    char op;
    char op2;


    NoEmprestimo* lista;

    do {

        menuGerenciarEmprestimos();

        printf("\n\nEscolha uma opção: ");
        scanf(" %c", &op);

        op = maius(op);

        switch (op) {

            case 'A':
                emprestimo();
                break;

            case 'B':
                devolve_livro();
                break;

            case 'C':
                do{
                    busca_especifica_emprestimo();
                    printf("\n Escolha uma opção: ");
                    scanf(" %c", &op2);
                    op2 = maius(op2);

                    switch(op2){
                        case 'A':
                        pesquisaPorCodigoEmprestimo();
                        break;

                        case 'B':
                        pesquisaPorCPFEmprestimo();
                        break;

                        case 'C':
                        pesquisaPorMatriculaEmprestimo();
                        break;

                        case 'D':
                        // pesquisaPorDataEmprestimo();
                        break;

                    }
                }while(op2 != 'S');
                break;

            case 'D':

                do{
                    menuListaEmprestimos();
                    printf("\n\nEscolha uma opção: ");
                    scanf(" %c", &op2);
                    op2 = maius(op2);

                    switch(op2){
                        case 'A':
                            lista = listaDiretaEmprestimo();
                            exibeListaEmprestimo(lista);
                            printf("\n Tecle ENTER para continuar.\n");
                            getchar();
                            getchar();
                            break;

                        case 'B':
                            lista = listaInvertidaEmprestimo();
                            exibeListaEmprestimo(lista);
                            printf("\n Tecle ENTER para continuar.\n");
                            getchar();
                            getchar();
                            break;

                        case 'C':
                            lista = listaOrdenadaEmprestimo();
                            exibeListaEmprestimo(lista);
                            printf("\n Tecle ENTER para continuar.\n");
                            getchar();
                            getchar();
                            
                            break;

                    }
                }while(op2 != 'S');
                break;

        }

    }while(op != 'S');

}

void gravaEmprestimo(Emprestimo* emprestimo) {

    FILE* fp;

    emprestimo->status = '1';

    fp = fopen("emprestimos.dat", "ab");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    fwrite(emprestimo, sizeof(Emprestimo), 1, fp);
    fclose(fp);

}

void emprestimo(void) {

    char resp;

    Emprestimo* emprestar;
    emprestar = (Emprestimo*) malloc(sizeof(Emprestimo));

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>      EMPRESTAR LIVRO      <<<");
    printf("\n =================================");
    printf("\n");

    printf(" Deseja mesmo emprestar um livro? (S/N): ");
    scanf(" %c",&resp);

    resp = maius(resp);

    while(resp != 'S' && resp != 'N') {

        printf(" Deseja mesmo emprestar o livro? (S/N): ");
        scanf(" %c",&resp);

        resp = maius(resp);

    }

    if (resp == 'S') {

        do{

            printf("\n Insira o CPF do leitor: ");
            scanf(" %11[^\n]", emprestar->cpf);

        }while((verifica_cpf_emprestimo(emprestar->cpf) == 0));

        mostraPessoa(emprestar);

        do{

            printf("\n Insira a matrícula do livro: ");
            scanf(" %12[^\n]", emprestar->matricula);

        }while((verifica_matricula_emprestimo(emprestar->matricula) == 0));

        mostraLivro(emprestar);

        printf("\n Insira o código do empréstimo: ");
        scanf(" %10[^\n]", emprestar->cod);

        while(validaCodigoEmprestimo(emprestar->cod) == 0) {

            printf("\n Insira um código válido para o empréstimo (10 números): ");
            scanf(" %10[^\n]", emprestar->cod);

        }
        emprestar->emprestado = '1';

        struct tm  *data_atual, *data_entrega;

        time(&emprestar->segundos2);

        data_atual = localtime(&emprestar->segundos2);
        emprestar->dia = data_atual->tm_mday;
        emprestar->mes = data_atual->tm_mon+1;
        emprestar->ano = data_atual->tm_year+1900;
        emprestar->hora = data_atual->tm_hour;
        emprestar->minuto = data_atual->tm_min;
        emprestar->segundo = data_atual->tm_sec;

        printf("\n Data de empréstimo........ %d/", data_atual->tm_mday);
        printf("%d/", data_atual->tm_mon+1);
        printf("%d\n", data_atual->tm_year+1900);
        printf(" Hora ....................: %d:",data_atual->tm_hour);
        printf("%d:",data_atual->tm_min);
        printf("%d\n",data_atual->tm_sec);

        time(&emprestar->segundos);
        emprestar->segundos = emprestar->segundos + 259200;

        data_entrega = localtime(&emprestar->segundos);

        emprestar->dia_entrega = data_entrega->tm_mday;
        emprestar->mes_entrega = data_entrega->tm_mon+1;
        emprestar->ano_entrega = data_entrega->tm_year+1900;
        emprestar->hora_entrega = data_entrega->tm_hour;
        emprestar->minuto_entrega = data_entrega->tm_min;
        emprestar->segundo_entrega = data_entrega->tm_sec;

        printf("\n Data para entrega........ %d/", data_entrega->tm_mday);
        printf("%d/", data_entrega->tm_mon+1);
        printf("%d\n", data_entrega->tm_year+1900);
        printf(" Hora ...................: %d:",data_entrega->tm_hour);
        printf("%d:",data_entrega->tm_min);
        printf("%d\n",data_entrega->tm_sec);

        setbuf(stdin, NULL);

        gravaEmprestimo(emprestar);


    }

        printf("\n Tecle ENTER para continuar.\n");
        getchar();
        getchar();

    free(emprestar);

}

void menuEditaEndereco(void) {

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>       EDITAR ENDEREÇO     <<<");
    printf("\n =================================");
    printf("\n\n []A - Alterar Cidade");
    printf("\n []B - Alterar Bairro");
    printf("\n []C - Alterar Estado");
    printf("\n []D - Alterar Número casa");
    printf("\n []S - Voltar");

}

void menuEditaPessoa(void) {

    system("clear");

    printf("\n ===================================");
    printf("\n | | |   Programa Biblioteca   | | |");
    printf("\n ===================================");
    printf("\n >>> EDITAR INFORMAÇÕES PESSOAIS <<<");
    printf("\n ===================================");
    printf("\n\n []A - Alterar nome");
    printf("\n []B - Alterar telefone");
    printf("\n []C - Alterar email");
    printf("\n []D - Alterar endereço");
    printf("\n []E - Alterar CPF");
    printf("\n []F - Alterar Data de nascimento");
    printf("\n []S - Voltar");

}

void menuEditaLivro(void) {

    system("clear");

    printf("\n =====================================");
    printf("\n | | |    Programa Biblioteca    | | |");
    printf("\n =====================================");
    printf("\n >>> EDITAR INFORMAÇÕES DOS LIVROS <<<");
    printf("\n =====================================");
    printf("\n\n []A - Alterar Nome");
    printf("\n []B - Alterar ISBN");
    printf("\n []C - Alterar Autor");
    printf("\n []D - Alterar Gênero");
    printf("\n []E - Alterar Editora");
    printf("\n []F - Alterar Edição");
    printf("\n []G - Alterar Preço");
    printf("\n []S - Voltar");

}

void editaPessoa(void) {

    FILE* fp;
    Pes* cadastro_pess;
    int achou;
    char op2;
    char op;
    char resp;
    char procurado[101];

    fp = fopen("pessoas.dat", "r+b");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    printf("\n\n");

    system("clear");

    printf("\n ===================================");
    printf("\n | | |   Programa Biblioteca   | | |");
    printf("\n ===================================");
    printf("\n >>> EDITAR INFORMAÇÕES PESSOAIS <<<");
    printf("\n ===================================");
    printf("\n\n Informe o CPF da pessoa a ser alterada: ");
    scanf(" %100[^\n]", procurado);

    cadastro_pess = (Pes*) malloc(sizeof(Pes));

    achou = 0;

    while((!achou) && (fread(cadastro_pess, sizeof(Pes), 1, fp))) {

        if ((strcmp(cadastro_pess->cpf, procurado) == 0) && (cadastro_pess->status == '1')) {

            achou = 1;

        }

    }

    if (achou) {

        exibePessoa(cadastro_pess);

        printf("Deseja alterar informações dessa pessoa (S/N): ");
        scanf(" %c",&resp);

        resp = maius(resp);

        if (resp == 'S') {

            do {

                menuEditaPessoa();

                exibePessoa(cadastro_pess);

                printf("\n\n Escolha uma opção: ");
                scanf(" %c", &op);

                op =  maius(op);

                switch(op) {

                case 'A':
                    printf("\n Informe o novo nome: ");
                    scanf(" %100[^\n]", cadastro_pess->nome);
                    while(validaNome(cadastro_pess->nome) == 0) {
                        printf(" Insira um nome válido: ");
                        scanf(" %100[^\n]", cadastro_pess->nome);
                    }
                    fseek(fp, (-1)*sizeof(Pes), SEEK_CUR);
                    fwrite(cadastro_pess, sizeof(Pes), 1, fp);

                    printf("\nInformação editada com sucesso!\n");
                    
                    printf("\n Tecle ENTER para continuar.\n");
                    getchar();
                    getchar();
                    break;

                case 'B':
                    printf(" Informe o novo númerode telefone telefone: ");
                    scanf(" %12[^\n]", cadastro_pess->tel);
                    while(validaTelefone(cadastro_pess->tel)==0) {
                        printf(" Insira um número de telefone válido no formato xx-xxxxxxxxx: ");
                        scanf(" %12[^\n]", cadastro_pess->tel);
                    }
                    fseek(fp, (-1)*sizeof(Pes), SEEK_CUR);
                    fwrite(cadastro_pess, sizeof(Pes), 1, fp);

                    printf("\n Informação editada com sucesso!\n");
                    
                    printf("\n Tecle ENTER para continuar.\n");
                    getchar();
                    getchar();
                    break;

                case 'C':
                    printf(" Informe o novo email: ");
                    scanf(" %100[^\n]", cadastro_pess->email);

                    while(validaEmail(cadastro_pess->email)==0) {
                        printf(" Insira um email válido: ");
                        scanf(" %100[^\n]", cadastro_pess->email);
                    }
                    fseek(fp, (-1)*sizeof(Pes), SEEK_CUR);
                    fwrite(cadastro_pess, sizeof(Pes), 1, fp);

                    printf("\n Informação editada com sucesso!\n");
            
                    printf("\n Tecle ENTER para continuar.\n");
                    getchar();
                    getchar();
                    break;

                case 'D':

                    do {
                        menuEditaEndereco();
                        exibePessoa(cadastro_pess);
                        printf("\n Escolha uma opção: ");
                        scanf(" %c", &op2);
                        op2 = maius(op2);
                        switch(op2) {
                        case 'A':
                            printf("\n Insira sua cidade: ");
                            scanf(" %100[^\n]", cadastro_pess->enderCid);
                            while(validaNome(cadastro_pess->enderCid) == 0) {
                                printf(" Insira um nome válido para a cidade: ");
                                scanf(" %100[^\n]", cadastro_pess->enderCid);
                            }
                            fseek(fp, (-1)*sizeof(Pes), SEEK_CUR);
                            fwrite(cadastro_pess, sizeof(Pes), 1, fp);
                            printf("\n Informação editada com sucesso!\n");
                            
                            printf("\n Tecle ENTER para continuar.\n");
                            getchar();
                            getchar();
                            break;

                        case 'B':
                            printf("\n Insira seu bairro: ");
                            scanf(" %100[^\n]", cadastro_pess->enderBair);
                            while(validaNome(cadastro_pess->enderBair) == 0) {
                                printf(" Insira um nome válido para o bairro: ");
                                scanf(" %100[^\n]", cadastro_pess->enderBair);
                            }
                            fseek(fp, (-1)*sizeof(Pes), SEEK_CUR);
                            fwrite(cadastro_pess, sizeof(Pes), 1, fp);
                            printf("\n Informação editada com sucesso!\n");
                            
                            printf("\n Tecle ENTER para continuar.\n");
                            getchar();
                            getchar();
                            break;

                        case 'C':
                            exibeEstados();
                            do {
                                printf("\n Digite o número correspondente ao seu estado: ");
                            } while (((scanf("%d%c", &cadastro_pess->uf, &cadastro_pess->c) != 2 || cadastro_pess->c != '\n') && clean_stdin()) || cadastro_pess->uf < 1 || cadastro_pess->uf > 27);

                            cadastro_pess->numero_uf = cadastro_pess->uf;
                            cadastro_pess->numero_uf = cadastro_pess->numero_uf - 1;
                            fseek(fp, (-1)*sizeof(Pes), SEEK_CUR);
                            fwrite(cadastro_pess, sizeof(Pes), 1, fp);
                            printf("\n Informação editada com sucesso!\n");
                            
                            printf("\n Tecle ENTER para continuar.\n");
                            getchar();
                            getchar();
                            break;

                        case 'D':
                            printf("\n Insira o número da sua casa: ");
                            scanf(" %100[^\n]", cadastro_pess->numCasa);
                            while(validaLetrasNumeros(cadastro_pess->numCasa)==0) {
                                printf(" Insira um número válido da sua casa: ");
                                scanf(" %100[^\n]", cadastro_pess->numCasa);
                            }
                            fseek(fp, (-1)*sizeof(Pes), SEEK_CUR);
                            fwrite(cadastro_pess, sizeof(Pes), 1, fp);
                            printf("\n Informação editada com sucesso!\n");
                            
                            printf("\n Tecle ENTER para continuar.\n");
                            getchar();
                            getchar();
                            break;

                        }

                    } while (resp != 'S');


                    
                break;

                case 'E':
                    printf("\n Insira o novo CPF - (SOMENTE NÚMEROS): ");
                    scanf(" %11[^\n]", cadastro_pess->cpf);
                    setbuf(stdin, NULL);

                    while((validaCPF(cadastro_pess->cpf)==0)) {
                        printf(" Insira o CPF válido ou que não esteja cadastrado - (SOMENTE NÚMEROS)\n  >>>>>:");
                        scanf(" %11[^\n]", cadastro_pess->cpf);
                        setbuf(stdin, NULL);
                    }
                    fseek(fp, (-1)*sizeof(Pes), SEEK_CUR);
                    fwrite(cadastro_pess, sizeof(Pes), 1, fp);
                    printf("\n Informação editada com sucesso!\n");

                    printf("\n Tecle ENTER para continuar.\n");
                    getchar();
                    getchar();
                
                break;

                case 'F':
                    do {
                        printf("\n Insira seu dia de nascimento: ");
                    } while(((scanf("%d%c", &cadastro_pess->dia, &cadastro_pess->c) != 2 || cadastro_pess->c != '\n') && clean_stdin()) || cadastro_pess->dia < 1 || cadastro_pess->dia > 31);

                    do {
                        printf("\n Insira seu mês de nascimento: ");

                    } while (((scanf("%d%c", &cadastro_pess->mes, &cadastro_pess->c) != 2 || cadastro_pess->c != '\n') && clean_stdin()) || cadastro_pess->mes < 1 || cadastro_pess->mes > 12);

                    do {
                        printf("\n Insira seu ano de nascimento: ");
                    } while (((scanf("%d%c", &cadastro_pess->ano, &cadastro_pess->c) != 2 || cadastro_pess->c != '\n') && clean_stdin()) || cadastro_pess->ano < 1900 || cadastro_pess->ano > 2019);
                    if(validaData(cadastro_pess->dia, cadastro_pess->mes, cadastro_pess->ano) == 1) {
                        printf("\n Data de nascimento registrada: %d/%d/%d.\n\n", cadastro_pess->dia, cadastro_pess->mes, cadastro_pess->ano);
                    }

                    fseek(fp, (-1)*sizeof(Pes), SEEK_CUR);
                    fwrite(cadastro_pess, sizeof(Pes), 1, fp);

                    printf("\n Informação editada com sucesso!\n");
                    
                    printf("\n Tecle ENTER para continuar.\n");
                    getchar();
                    getchar();
                    }
                    break;


            }while(op != 'S');   
        }

        free(cadastro_pess);
        fclose(fp);

    }

}

void editaLivro(void) {

    FILE* fp;
    Livro* livro;
    int achou;
    char op;
    char resp;
    char procurado[101];

    fp = fopen("livros.dat", "r+b");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    printf("\n\n");

    system("clear");

    printf("\n =====================================");
    printf("\n | | |    Programa Biblioteca    | | |");
    printf("\n =====================================");
    printf("\n >>> EDITAR INFORMAÇÕES DOS LIVROS <<<");
    printf("\n =====================================");
    printf("\n\n Informe a matrícula do livro a ser alterado: ");
    scanf(" %100[^\n]", procurado);

    livro = (Livro*) malloc(sizeof(Livro));

    achou = 0;

    while((!achou) && (fread(livro, sizeof(Livro), 1, fp))) {

        if ((strcmp(livro->matricula, procurado) == 0) && (livro->status == '1')) {

            achou = 1;

        }

    }

    if (achou) {

        exibeLivro(livro);

        printf("Deseja alterar informações desse livro (S/N): ");
        scanf(" %c",&resp);

        resp = maius(resp);

        if (resp == 'S') {

            do {

                menuEditaLivro();
                exibeLivro(livro);
                printf("\n\n Escolha uma opção: ");
                scanf(" %c", &op);

                op =  maius(op);

                switch(op) {

                case 'A':
                    printf("\n Informe o novo nome: ");
                    scanf(" %100[^\n]", livro->nome);
                    while(validaNome(livro->nome) == 0) {
                        printf(" Insira um nome válido: ");
                        scanf(" %100[^\n]", livro->nome);
                    }
                    fseek(fp, (-1)*sizeof(Livro), SEEK_CUR);
                    fwrite(livro, sizeof(Livro), 1, fp);

                    printf("\nInformação editada com sucesso!\n");
                    
                    printf("\n Tecle ENTER para continuar.\n");
                    getchar();
                    getchar();
                    break;

                case 'B':
                    printf(" Informe o novo ISBN [xxx-xx-xxx-xxxx-x]: ");
                    scanf(" %17[^\n]", livro->isbn);
                    while(validaISBN(livro->isbn)==0) {
                        printf(" Insira um ISBN válido [xxx-xx-xxx-xxxx-x]: ");
                        scanf(" %17[^\n]", livro->isbn);
                    }
                    fseek(fp, (-1)*sizeof(Livro), SEEK_CUR);
                    fwrite(livro, sizeof(Livro), 1, fp);

                    printf("\n Informação editada com sucesso!\n");
                    
                    printf("\n Tecle ENTER para continuar.\n");
                    getchar();
                    getchar();
                    break;

                case 'C':
                    printf(" Informe o novo autor: ");
                    scanf(" %200[^\n]", livro->autor);
                    while(validaNome(livro->autor)==0) {
                        printf(" Insira um autor válido: ");
                        scanf(" %200[^\n]", livro->autor);
                    }
                    fseek(fp, (-1)*sizeof(Livro), SEEK_CUR);
                    fwrite(livro, sizeof(Livro), 1, fp);

                    printf("\n Informação editada com sucesso!\n");
                    
                    printf("\n Tecle ENTER para continuar.\n");
                    getchar();
                    getchar();
                    break;

                case 'D':
                    printf(" Informe o novo gênero: ");
                    scanf(" %100[^\n]", livro->genero);

                    while(validaNome(livro->genero)==0) {
                        printf(" Insira um gênero válido: ");
                        scanf(" %100[^\n]", livro->genero);
                    }
                    fseek(fp, (-1)*sizeof(Livro), SEEK_CUR);
                    fwrite(livro, sizeof(Livro), 1, fp);

                    printf("\n Informação editada com sucesso!\n");
                    
                    printf("\n Tecle ENTER para continuar.\n");
                    getchar();
                    getchar();
                    break;

                case 'E':
                    printf(" Informe a nova editora: ");
                    scanf(" %100[^\n]", livro->editora);
                    while(validaNome(livro->editora)==0) {
                        printf(" Insira uma editora válida: ");
                        scanf(" %100[^\n]", livro->editora);
                    }
                    fseek(fp, (-1)*sizeof(Livro), SEEK_CUR);
                    fwrite(livro, sizeof(Livro), 1, fp);

                    printf("\n Informação editada com sucesso!\n");
                    
                    printf("\n Tecle ENTER para continuar.\n");
                    getchar();
                    getchar();
                    break;

                case 'F':
                    printf(" Informe a nova edição: ");
                    scanf(" %2[^\n]", livro->edicao);
                    while(validaNome(livro->edicao)==0) {
                        printf(" Insira uma edição válida: ");
                        scanf(" %2[^\n]", livro->edicao);
                        setbuf(stdin, NULL);
                    }
                    fseek(fp, (-1)*sizeof(Livro), SEEK_CUR);
                    fwrite(livro, sizeof(Livro), 1, fp);
                    printf("\n Informação editada com sucesso!\n");
                    
                    printf("\n Tecle ENTER para continuar.\n");
                    getchar();
                    getchar();
                    break;

                case 'G':
                    printf(" Informe o novo preço: ");
                    scanf(" %3[^\n]", livro->preco);
                    while(validaPreco(livro->preco)==0) {
                        printf(" Insira um preço válido: ");
                        scanf(" %3[^\n]", livro->preco);
                        setbuf(stdin, NULL);
                    }
                    fseek(fp, (-1)*sizeof(Livro), SEEK_CUR);
                    fwrite(livro, sizeof(Livro), 1, fp);
                    printf("\n Informação editada com sucesso!\n");
                    
                    printf("\n Tecle ENTER para continuar.\n");
                    getchar();
                    getchar();
                    break;

                }

            } while(op != 'S');

        }

        free(livro);
        fclose(fp);

    }

}

void exibePessoa(Pes* cadastro_pess) {

    int dia = cadastro_pess->dia;
    int mes = cadastro_pess->mes;
    int ano = cadastro_pess->ano;
    int numero_uf = cadastro_pess->uf;

    printf("\n\n Nome: %s \n", cadastro_pess->nome);
    printf(" CPF: %c%c%c.%c%c%c.%c%c%c-%c%c \n", cadastro_pess->cpf[0], cadastro_pess->cpf[1], cadastro_pess->cpf[2], cadastro_pess->cpf[3], cadastro_pess->cpf[4], cadastro_pess->cpf[5], cadastro_pess->cpf[6], cadastro_pess->cpf[7], cadastro_pess->cpf[8], cadastro_pess->cpf[9], cadastro_pess->cpf[10]);

    printf(" Data de nascimento: %d/%d/%d \n", dia, mes, ano);

    printf(" Email: %s \n", cadastro_pess->email);
    printf(" Telefone: %s \n", cadastro_pess->tel);

    if(cadastro_pess->multado == '0') {
        printf(" Esse leitor não está multado.\n");
    } else {
        printf(" Esse leitor está multado.\n");
        printf(" Motivo: %s \n", cadastro_pess->motivo);
        printf(" Data de início do banimento: %d/", cadastro_pess->dia_inicio);
        printf("%d/", cadastro_pess->mes_inicio);
        printf("%d", cadastro_pess->ano_inicio);
        printf(" ---> Horário: %d horas, %d minutos e %d segundos.\n", cadastro_pess->hora_inicio, cadastro_pess->minuto_inicio, cadastro_pess->segundo_inicio);
        printf(" Data do término do banimento: %d/", cadastro_pess->dia_termino);
        printf("%d/", cadastro_pess->mes_termino);
        printf("%d", cadastro_pess->ano_termino);
        printf(" ---> Horário: %d horas, %d minutos e %d segundos.\n", cadastro_pess->hora_termino, cadastro_pess->minuto_termino, cadastro_pess->segundo_termino);
        printf("\n");
    }

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

    printf(" Cidade: %s \n", cadastro_pess->enderCid);
    printf(" Bairro: %s \n", cadastro_pess->enderBair);
    printf(" Numero da casa: %s \n", cadastro_pess->numCasa);
    printf(" Quantidade de livros emprestados a esse leitor: %d \n", cadastro_pess->quantidade_de_livros_emprestados);
    printf("\n");

}

void gravaPessoa(Pes* pes) {

    FILE* fp;

    pes->status = '1';
    pes->multado = '0';
    pes->quantidade_de_livros_emprestados = 0;

    fp = fopen("pessoas.dat", "ab");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");

        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    fwrite(pes, sizeof(Pes), 1, fp);
    fclose(fp);

}

void exibeEstados(void) {

    printf("\nESTADOS E SEUS RESPECTIVOS NÚMEROS.\n\n");
    printf(" 1 - AC \n");
    printf(" 2 - AL \n");
    printf(" 3 - AP \n");
    printf(" 4 - AM \n");
    printf(" 5 - BA \n");
    printf(" 6 - CE \n");
    printf(" 7 - DF \n");
    printf(" 8 - ES \n");
    printf(" 9 - GO \n");
    printf(" 10 - MA \n");
    printf(" 11 - MT \n");
    printf(" 12 - MS \n");
    printf(" 13 - MG \n");
    printf(" 14 - PA \n");
    printf(" 15 - PB \n");
    printf(" 16 - PR \n");
    printf(" 17 - PE \n");
    printf(" 18 - PI \n");
    printf(" 19 - RJ \n");
    printf(" 20 - RN \n");
    printf(" 21 - RS \n");
    printf(" 22 - RO \n");
    printf(" 23 - RR \n");
    printf(" 24 - SC \n");
    printf(" 25 - SP \n");
    printf(" 26 - SE \n");
    printf(" 27 - TO \n");

}

void cadastroPessoa() {

    char resp;
    char op;
    Pes* cadastro_pess;

    cadastro_pess = (Pes*) malloc(sizeof(Pes));

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>    CADASTRO DE USUÁRIO    <<<");
    printf("\n =================================");

    printf("\n Deseja cadastrar uma pessoa? (S/N)\n >>>>: ");
    scanf(" %c", &op);
    op = maius(op);
    
    if (op == 'S'){
        do {
            printf("\n Insira o CPF - (SOMENTE NÚMEROS): ");
            scanf(" %11[^\n]", cadastro_pess->cpf);
            setbuf(stdin, NULL);
            while((validaCPF(cadastro_pess->cpf)==0)) {
                printf(" Insira o CPF válido ou que não esteja cadastrado - (SOMENTE NÚMEROS)\n  >>>>>:");
                scanf(" %11[^\n]", cadastro_pess->cpf);
                setbuf(stdin, NULL);
            }

            printf("\n Insira o nome: ");
            scanf(" %100[^\n]", cadastro_pess->nome);
            while(validaNome(cadastro_pess->nome) == 0) {
                printf(" Insira um nome válido: ");
                scanf(" %100[^\n]", cadastro_pess->nome);
            }

            do {
                printf("\n Insira o dia de nascimento: ");
            } while(((scanf("%d%c", &cadastro_pess->dia, &cadastro_pess->c) != 2 || cadastro_pess->c != '\n') && clean_stdin()) || cadastro_pess->dia < 1 || cadastro_pess->dia > 31);

            do {
                printf("\n Insira o mês de nascimento: ");

            } while (((scanf("%d%c", &cadastro_pess->mes, &cadastro_pess->c) != 2 || cadastro_pess->c != '\n') && clean_stdin()) || cadastro_pess->mes < 1 || cadastro_pess->mes > 12);

            do {
                printf("\n Insira o ano de nascimento: ");
            } while (((scanf("%d%c", &cadastro_pess->ano, &cadastro_pess->c) != 2 || cadastro_pess->c != '\n') && clean_stdin()) || cadastro_pess->ano < 1900 || cadastro_pess->ano > 2019);
            if(validaData(cadastro_pess->dia, cadastro_pess->mes, cadastro_pess->ano) == 1) {
                printf("\n Data de nascimento registrada: %d/%d/%d.\n\n", cadastro_pess->dia, cadastro_pess->mes, cadastro_pess->ano);
            }

            exibeEstados();
            do {
                printf("\n Digite o número correspondente ao estado: ");
            } while (((scanf("%d%c", &cadastro_pess->uf, &cadastro_pess->c) != 2 || cadastro_pess->c != '\n') && clean_stdin()) || cadastro_pess->uf < 1 || cadastro_pess->uf > 27);

            cadastro_pess->numero_uf = cadastro_pess->uf;
            cadastro_pess->numero_uf = cadastro_pess->numero_uf - 1; // Para acessar o índice correto da matriz é necessário diminuir 1 do número correspondente a letra escolhida pelo usuário.

            printf("\n Insira a cidade: ");
            scanf(" %100[^\n]", cadastro_pess->enderCid);
            while(validaNome(cadastro_pess->enderCid) == 0) {
                printf(" Insira um nome válido para a cidade: ");
                scanf(" %100[^\n]", cadastro_pess->enderCid);
            }

            printf("\n Insira o bairro: ");
            scanf(" %100[^\n]", cadastro_pess->enderBair);
            while(validaNome(cadastro_pess->enderBair) == 0) {
                printf(" Insira um nome válido para o bairro: ");
                scanf(" %100[^\n]", cadastro_pess->enderBair);
            }

            printf("\n Insira o número da casa: ");
            scanf(" %100[^\n]", cadastro_pess->numCasa);
            while(validaLetrasNumeros(cadastro_pess->numCasa)==0) {
                printf(" Insira o número válido da casa: ");
                scanf(" %100[^\n]", cadastro_pess->numCasa);
            }

            printf("\n Insira o número de telefone para contato no formato xx-xxxxxxxxx: "); 
            scanf(" %12[^\n]", cadastro_pess->tel);
            while(validaTelefone(cadastro_pess->tel)==0) {
                printf(" Insira um número de telefone válido no formato xx-xxxxxxxxx: ");
                scanf(" %12[^\n]", cadastro_pess->tel);
            }

            printf("\n Insira o email: ");
            scanf(" %100[^\n]", cadastro_pess->email);
            while(validaEmail(cadastro_pess->email)==0) {
                printf(" Insira um email válido: ");
                scanf(" %100[^\n]", cadastro_pess->email);
            }

            gravaPessoa(cadastro_pess);

            printf("\n Deseja cadastrar outra pessoa? (S/N)\n >>>>: ");
            scanf(" %c", &resp);

            resp = maius(resp);

        }while((resp == 'S'));
    }
}

void gravaLivro(Livro* livro) {

    FILE* fp;

    livro->status = '1';
    livro->emprestado = '0';

    livro->quantidade_de_vezes_emprestado = 0;

    fp = fopen("livros.dat", "ab");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    fwrite(livro, sizeof(Livro), 1, fp);
    fclose(fp);

}

void cadastroLivro() {

    Livro* livro;

    livro = (Livro*) malloc(sizeof(Livro));

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>     CADASTRO DE LIVRO     <<<");
    printf("\n =================================");

    printf("\n Insira a matrícula: ");
    scanf(" %12[^\n]", livro->matricula);
    while(validaMatr(livro->matricula) == 0) {
        printf(" Insira uma matrícula válida para o livro: ");
        scanf(" %12[^\n]", livro->matricula);
    }

    printf("\n Insira o nome: ");
    scanf(" %100[^\n]", livro->nome);
    while(validaNome(livro->nome) == 0) {
        printf(" Insira um nome válido: ");
        scanf(" %100[^\n]", livro->nome);
    }

    printf("\n Insira o ISBN [xxx-xx-xxx-xxxx-x]: ");
    scanf(" %17[^\n]", livro->isbn);
    while(validaISBN(livro->isbn) == 0) {
        printf(" Insira um ISBN válido [xxx-xx-xxx-xxxx-x]: ");
        scanf(" %17[^\n]", livro->isbn);
    }

    printf("\n Insira o autor: ");
    scanf(" %199[^\n]", livro->autor);
    while(validaNome(livro->autor) == 0) {
        printf(" Insira um nome válido para o autor: ");
        scanf(" %199[^\n]", livro->autor);
    }

    printf("\n Insira o gênero: ");
    scanf(" %99[^\n]", livro->genero);
    while(validaNome(livro->genero) == 0) {
        printf(" Insira um nome válido para o gênero: ");
        scanf(" %99[^\n]", livro->genero);
    }

    printf("\n Insira a editora: ");
    scanf(" %99[^\n]", livro->editora);
    while(validaNome(livro->editora) == 0) {
        printf(" Insira um nome válido para a editora: ");
        scanf(" %99[^\n]", livro->editora);
    }

    printf("\n Insira a edição: ");
    scanf(" %2[^\n]", livro->edicao);
    while(validaEdicao(livro->edicao) == 0) {
        printf(" Insira um nome válido para a edição: ");
        scanf(" %2[^\n]", livro->edicao);
    }

    printf("\n Insira o preço do livro (Para fins de multa em caso da perda do livro por parte do usuário): ");
    scanf(" %3[^\n]", livro->preco);
    while(validaPreco(livro->preco) == 0) {
        printf("\n Insira um preço válido para o livro: ");
        scanf(" %3[^\n]", livro->preco);
    }

    gravaLivro(livro);
    exibeLivro(livro);

    printf("\n Tecle ENTER para continuar.\n");
    getchar();
    getchar();

    

}

void exibeLivro(Livro* livro) {

    printf("\n\n Nome do livro: %s \n", livro->nome);
    printf(" Matricula: %s \n", livro->matricula);
    printf(" ISBN: %s \n", livro->isbn);
    printf(" Autor: %s \n", livro->autor);
    printf(" Gênero: %s \n", livro->genero);
    printf(" Editora: %s \n", livro->editora);
    printf(" Edição: %sª \n", livro->edicao);
    printf(" Preço: %s R$ \n", livro->preco);
    if(livro->emprestado == '0') {
        printf(" O livro não está emprestado.\n");
    } else {
        printf(" O livro está emprestado.\n");
    }
    
    printf(" Quantidade de vezes que esse livro foi emprestado: %d \n", livro->quantidade_de_vezes_emprestado);
    printf("\n");

}



void excluiPessoa(void) {

    FILE* fp;
    Pes* cadastro_pess;
    int achou;
    char resp;
    char procurado[100];

    fp = fopen("pessoas.dat", "r+b");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>        EXCLUI PESSOA      <<<");
    printf("\n =================================");
    printf("\n");

    printf(" Informe o CPF da pessoa a ser removida: ");
    scanf(" %100[^\n]", procurado);

    cadastro_pess = (Pes*) malloc(sizeof(Pes));

    achou = 0;

    while((!achou) && (fread(cadastro_pess, sizeof(Pes), 1, fp))) {

        if ((strcmp(cadastro_pess->cpf, procurado) == 0) && (cadastro_pess->status == '1')) {

            achou = 1;

        }

    }

    if (achou) {

        exibePessoa(cadastro_pess);

        printf(" Deseja realmente remover esta pessoa (S/N)? ");

        scanf(" %c", &resp);

        if (resp == 's' || resp == 'S') {

            cadastro_pess->status = '0';

            fseek(fp, -1 * sizeof(Pes), SEEK_CUR);
            fwrite(cadastro_pess, sizeof(Pes), 1, fp);

            printf("\nPessoa removida com sucesso!\n");

        } else {

            printf("\n Ok, os dados não foram alterados\n");

        }

    } else {

        printf(" %s não foi encontrado...\n", procurado);

    }


    fclose(fp);
    free(cadastro_pess);

    printf("\n Tecle ENTER para continuar.\n");
    getchar();
    getchar();

}

void excluiLivro(void) {

    FILE* fp;
    Livro* livro;
    int achou;
    char resp;
    char procurado[100];

    fp = fopen("livros.dat", "r+b");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>        EXCLUI LIVRO       <<<");
    printf("\n =================================");
    printf("\n");

    printf(" Informe a matrícula do livro a ser removido: ");
    scanf(" %100[^\n]", procurado);

    livro = (Livro*) malloc(sizeof(Livro));

    achou = 0;

    while((!achou) && (fread(livro, sizeof(Livro), 1, fp))) {

        if ((strcmp(livro->matricula, procurado) == 0) && (livro->status == '1')) {

            achou = 1;

        }

    }

    if (achou) {

        exibeLivro(livro);

        printf(" Deseja realmente remover este livro (S/N)? ");

        scanf(" %c", &resp);

        if (resp == 's' || resp == 'S') {

            livro->status = '0';

            fseek(fp, -1 * sizeof(Livro), SEEK_CUR);

            fwrite(livro, sizeof(Livro), 1, fp);

            printf("\nLivro removido com sucesso!\n");

        } else {

            printf("\n Ok, os dados não foram alterados\n");

        }

    } else {

        printf(" %s não foi encontrado...\n", procurado);

    }

    fclose(fp);
    free(livro);

    printf("\n Tecle ENTER para continuar.\n");
    getchar();
    getchar();
}

char menuPrincipal() {

    char resp;

    do {

        system("clear");

        printf("\n ================================= \n ||| SIG-Library - Biblioteca! ||| \n ================================= \n >>>>>>   MENU PRINCIPAL    <<<<<< \n ================================= \n Escolha uma opção: \n []A - LOGIN \n []B - Sobre \n []S - SAIR \n\n * Credenciais padrão: \n (Administrador ---> Username: admin / Password: admin) \n\n");

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

    } while(resp != 'A' && resp !=  'B' && resp != 'S');

    return resp;

}

int login() {

    char loginA[50] = "admin";
    char senhaA[50] = "admin";
    char login1[50];
    char senha1[50];

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>           LOGIN           <<<");
    printf("\n =================================");

    printf("\n\n Informe o nome de usuário: ");
    scanf("%s", login1);
    printf(" Informe a senha: ");
    scanf("%s", senha1);

    while(!(strcmp(loginA, login1) == 0 && strcmp(senhaA, senha1) == 0)) {

        system("clear");

        printf("\n =================================");
        printf("\n | | |  Programa Biblioteca  | | |");
        printf("\n =================================");
        printf("\n >>>            LOGIN          <<<");
        printf("\n =================================");

        printf("\n\n Informe o nome de usuário: ");
        scanf("%s", login1);
        printf(" Informe a senha: ");
        scanf("%s", senha1);

    }

    if(strcmp(loginA, login1) == 0 && strcmp(senhaA, senha1) == 0) {

        // printf("\n Login realizado com sucesso.\n");
        return 1;

    } 
    return 0;

}

void menuAdmin() {

    char resp;
    char op;
    char op2;
    char op3;
    char op4;
    char op5;
    char op6;
    NoPes* listaP;
    NoLivro* listaL;

    do {
        system("clear");

        printf("\n =================================");
        printf("\n | | |  Programa Biblioteca  | | |");
        printf("\n =================================");
        printf("\n >>>         MENU ADM          <<<");
        printf("\n =================================");
        printf("\n\n []A - Gerenciar Pessoas\n");
        printf(" []B - Gerenciar Livros\n");
        printf(" []C - Gerenciar Emprestimos\n");
        printf(" []S - Sair\n");

        printf("\n Escolha uma opção: ");
        scanf(" %c", &resp);
        resp = maius(resp);

        switch(resp) {

        case 'A':
            do {
                gerenciarPessoas();
                printf("\n Escolha uma opção: ");
                scanf(" %c", &op);
                op = maius(op);
                switch(op) {
                case 'A':
                    cadastroPessoa();
                    break;

                case 'B':
                    do{
                        busca_especifica_pessoa();
                        printf("\n Escolha uma opção: ");
                        scanf(" %c", &op5);
                        op5 = maius(op5);

                        switch(op5){
                            case 'A':
                            pesquisaCPFPessoa();
                            break;

                            case 'B':
                            pesquisaNomePessoa();
                            break;
                        }
                    }while(op5 != 'S');
                    break;

                case 'C':
                    do{
                        ListaDePessoas();
                        printf("\n Escolha uma opção: ");
                        scanf(" %c", &op6);
                        op6 = maius(op6);

                        switch(op6){
                            case 'A':
                                listaP = listaDiretaPessoas();
                                exibeListaPessoas(listaP);
                                
                                printf("\n Tecle ENTER para continuar.\n");
                                getchar();
                                getchar();
                                break;

                            case 'B':

                                listaP = listaInvertidaPessoas();
                                exibeListaPessoas(listaP);
                                
                                printf("\n Tecle ENTER para continuar.\n");
                                getchar();
                                getchar();
                                break;

                            case 'C':

                                listaP = listaOrdenadaPessoas();
                                exibeListaPessoas(listaP);

                                printf("\n Tecle ENTER para continuar.\n");
                                getchar();
                                getchar();
                                break;

                        }                        
                    }while(op6 != 'S');
                    break;

                case 'D':
                    excluiPessoa();
                    break;

                case 'E':
                    editaPessoa();
                    break;

                }
            } while (op != 'S');

            break;

        case 'B':
            do {

                gerenciarLivros();
                printf("\n Escolha uma opção: ");
                scanf(" %c", &op2);
                op2 = maius(op2);

                switch(op2) {
                    case 'A':
                        cadastroLivro();
                        break;

                    case 'B':
                    do{
                        busca_especifica_livro();
                        printf("\n Escolha uma opção: ");
                        scanf(" %c", &op4);
                        op4 = maius(op4);

                        switch(op4){

                            case 'A':
                            pesquisaTituloLivro();
                            break;

                            case 'B':
                            pesquisaAutorLivro();
                            break;

                            case 'C':
                            pesquisaISBNLivro();
                            break;

                            case 'D':
                            pesquisaGeneroLivro();
                            break;

                            case 'E':
                            pesquisaMatriculaLivro();
                            break;

                        }


                    }while(op4 != 'S');

                        

                        break;

                    case 'C':
                        do{
                        ListaDeLivros();
                        printf("\n Escolha uma opção: ");
                        scanf(" %c", &op3);
                        op3 = maius(op3);

                        switch(op3){

                            case 'A':
                                listaL = listaDiretaLivros();
                                exibeListaLivros(listaL);
                                
                                printf("\n Tecle ENTER para continuar.\n");
                                getchar();
                                getchar();
                                break;

                            case 'B':
                                listaL = listaInvertidaLivros();
                                exibeListaLivros(listaL);
                                
                                printf("\n Tecle ENTER para continuar. \n");
                                getchar();
                                getchar();
                                break;

                            case 'C':
                                listaL = listaOrdenadaLivros();
                                exibeListaLivros(listaL);
                                
                                printf("\n Tecle ENTER para continuar.\n");
                                getchar();
                                getchar();
                                break;      
                            }
                        }while(op3 != 'S');

                        break;

                    case 'D':
                        excluiLivro();  
                        
                        break;

                    case 'E':
                        editaLivro();
                        break;

                }
            } while(op2 != 'S');
            break;

        case 'C':
            gerenciarEmprestimos();
            break;

        case 'S':
            if((sair()) == 'S') {
                starter();
            } else {
                menuAdmin();
            }
            break;

        }

    } while(resp != 'S');

}


void ListaDeLivros(void) {

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>        LISTA LIVROS       <<<");
    printf("\n =================================");
    printf("\n\n []A - Listar livros cadastrados\n");
    printf(" []B - Listar livros na ordem inversa de cadastro\n");
    printf(" []C - Listar livros na ordem alfabética\n");
    printf(" []S - Sair\n");

}


void ListaDePessoas(void) {

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>        LISTA PESSOAS      <<<");
    printf("\n =================================");
    printf("\n\n []A - Listar pessoas cadastrados \n");
    printf(" []B - Listar pessoas na ordem inversa de cadastro\n");
    printf(" []C - Listar pessoas na ordem alfabética\n");
    printf(" []S - Sair\n");

}



void gerenciarPessoas(void) {

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>     GERENCIAR PESSOAS     <<<");
    printf("\n =================================");
    printf("\n\n []A - Cadastrar Pessoa\n");
    printf(" []B - Buscar Pessoa\n");
    printf(" []C - Listar pessoas \n");
    printf(" []D - Excluir pessoas\n");
    printf(" []E - Editar informações\n");
    printf(" []S - Sair\n");

}

void gerenciarLivros(void) {

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>      GERENCIAR LIVROS     <<<");
    printf("\n =================================");
    printf("\n\n []A - Cadastrar Livro\n");
    printf(" []B - Buscar Livro\n");
    printf(" []C - Listar Livros\n");
    printf(" []D - Excluir livros\n");
    printf(" []E - Editar livro\n");
    printf(" []S - Sair\n");

}


void busca_especifica_livro(void) {

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>        BUSCAR LIVROS      <<<");
    printf("\n =================================");
    printf("\n\n []A - Busca por Título\n");
    printf(" []B - Busca por Autor\n");
    printf(" []C - Busca por ISBN\n");
    printf(" []D - Busca por Gênero\n");
    printf(" []E - Busca por Matricula\n");
    printf(" []S - Sair\n");
}

void busca_especifica_pessoa(void) {

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>        BUSCAR PESSOA      <<<");
    printf("\n =================================");
    printf("\n\n []A - Busca por CPF\n");
    printf(" []B - Busca por Nome\n");
    printf(" []S - Sair\n");
}

void busca_especifica_emprestimo(void) {

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>    BUSCAR EMPRÉSTIMO      <<<");
    printf("\n =================================");
    printf("\n\n []A - Busca por Código do empréstimo\n");
    printf(" []B - Busca por CPF do leitor\n");
    printf(" []C - Busca por Matrícula do livro\n");
    printf(" []D - Busca por Data\n");
    printf(" []S - Sair\n");
}

void menuGerenciarEmprestimos(void) {

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>   GERENCIAR EMPRÉSTIMOS   <<<");
    printf("\n =================================");
    printf("\n\n []A - Emprestar livro");
    printf("\n []B - Devolver livro");
    printf("\n []C - Buscar Empréstimo");
    printf("\n []D - Histórico de empréstimos");
    printf("\n []S - Voltar ao Menu do Administrador");

}

void menuListaEmprestimos(void) {

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>   HISTÓRICO EMPRÉSTIMOS   <<<");
    printf("\n =================================");
    printf("\n\n []A - Histórico de todos os empréstimos de livros");
    printf("\n []B - Histórico de empréstimos de livros na ordem inversa");
    printf("\n []C - Histórico de empréstimos de livros em ordem alfabética");
    
    printf("\n []S - Voltar ao Menu do Administrador");

}


void sobre() {

    char resp;

    system("clear");

    printf("\n A library system made with C. \n \n Universidade Federal do Rio Gande do Norte (UFRN). \n \n Students: \n          Douglas Mateus Soares Cândido da Silva / Email: douglasmateus1@hotmail.com / Cellphone: (84)99996-4793 \n          Lucas da Silva Santos / Email: santoslucas9956@gmail.com / Cellphone: (84)99803-4865 \n \n Professor: Flavius Gorgônio. \n\n");

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

int starter() {

    char resposta_menu_principal;

    switch(resposta_menu_principal = menuPrincipal()) {

    case 'A':
        if(login() == 1) {
            menuAdmin();
        }
        break;

    case 'B':
        sobre();
        resposta_menu_principal = starter();
        break;

    case 'S':
        if((sair()) == 'S') {
            system("clear");

            printf("       _.--._  _.--._\n");
            printf(" ,-=.-\":;:;:;\\':;:;:;\"-._\n");
            printf(" \\\\\\:;:;:;:;:;\\:;:;:;:;:;\\\n");
            printf("  \\\\\\:;:;:;:;:;\\:;:;:;:;:;\\\n");
            printf("   \\\\\\:;:;:;:;:;\\:;:;:;:;:;\\\n");
            printf("    \\\\\\:;:;:;:;:;\\:;::;:;:;:\\\n");
            printf("     \\\\\\;:;::;:;:;\\:;:;:;::;:\\\n");
            printf("      \\\\\\;;:;:_:--:\\:_:--:_;:;\\    Adeus, caro leitor!\n");
            printf("       \\\\\\_.-\"      :      \"-._\\\n");
            printf("        \\`_..--\"\"--.;.--\"\"--.._=>\n");
            printf("         \"");
            printf("\n Você saiu do SIG-Library. Volte sempre.\n\n");
            break;
        } else {
            resposta_menu_principal = starter();
        }
        break;

    default:
        printf("Você digitou uma opção inválida.\n");

    }

    return 1;

}

int verificaCPF(char procurado[11]) {

    FILE* fp;
    Pes* cadastro_pess;
    int achou;

    fp = fopen("pessoas.dat", "rb");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }


    cadastro_pess = (Pes*) malloc(sizeof(Pes));

    achou = 0;

    while((!achou) && (fread(cadastro_pess, sizeof(Pes), 1, fp))) {

        if ((strcmp(cadastro_pess->cpf, procurado) == 0) && (cadastro_pess->status == '1')) {

            achou = 1;

        }

    }


    if (achou) {

        return 0;

    } else {

        return 1;

    }

    fclose(fp);
    free(cadastro_pess);

}

int verificaCodigoEmprestimo(char procurado[10]) {

    FILE* fp;
    Emprestimo* emprestimo;
    int achou;

    fp = fopen("emprestimos.dat", "rb");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    emprestimo = (Emprestimo*) malloc(sizeof(Emprestimo));

    achou = 0;

    while((!achou) && (fread(emprestimo, sizeof(Emprestimo), 1, fp))) {

        if ((strcmp(emprestimo->cod, procurado) == 0) && (emprestimo->status == '1')) {

            achou = 1;

        }

    }

    if (achou) {

        return 0;

    } else {

        return 1;

    }

    fclose(fp);
    free(emprestimo);

}

int verifica_cpf_emprestimo(char procurado[11]) {

    FILE* fp;
    Pes* cadastro_pess;
    int achou;

    fp = fopen("pessoas.dat", "rb");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    cadastro_pess = (Pes*) malloc(sizeof(Pes));

    achou = 0;

    while((!achou) && (fread(cadastro_pess, sizeof(Pes), 1, fp))) {

        if ((strcmp(cadastro_pess->cpf, procurado) == 0) && (cadastro_pess->status == '1') && (cadastro_pess->multado == '0')) {

            achou = 1;

        }

    }

    if (achou) {

        return 1;

    } else {

        return 0;

    }

    fclose(fp);
    free(cadastro_pess);

}

void mostraPessoa(Emprestimo* emprestimo) {

    FILE* fp;
    Pes* cadastro_pess;
    int achou = 0;

    fp = fopen("pessoas.dat", "r+b");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    cadastro_pess = (Pes*) malloc(sizeof(Pes));

    while((!achou) && (fread(cadastro_pess, sizeof(Pes), 1, fp))) {

        if ((strcmp(cadastro_pess->cpf, emprestimo->cpf) == 0) && (cadastro_pess->status == '1')) {

            achou = 1;

        }

    }

    if (achou) {

        int dia = cadastro_pess->dia;
        int mes = cadastro_pess->mes;
        int ano = cadastro_pess->ano;
        int numero_uf = cadastro_pess->uf;

        printf("\n\n Nome: %s \n", cadastro_pess->nome);
        printf(" CPF: %c%c%c.%c%c%c.%c%c%c-%c%c \n", cadastro_pess->cpf[0], cadastro_pess->cpf[1], cadastro_pess->cpf[2], cadastro_pess->cpf[3], cadastro_pess->cpf[4], cadastro_pess->cpf[5], cadastro_pess->cpf[6], cadastro_pess->cpf[7], cadastro_pess->cpf[8], cadastro_pess->cpf[9], cadastro_pess->cpf[10]);

        printf(" Data de nascimento: %d/%d/%d \n", dia, mes, ano);

        printf(" Email: %s \n", cadastro_pess->email);
        printf(" Telefone: %s \n", cadastro_pess->tel);

        if(cadastro_pess->multado == '0') {
            printf(" Esse leitor não está multado.\n");
        } else {
            printf(" Esse leitor está multado.\n");
            printf(" Motivo: %s \n", cadastro_pess->motivo);
            printf(" Data de início do banimento: %d/", cadastro_pess->dia_inicio);
            printf("%d/", cadastro_pess->mes_inicio);
            printf("%d", cadastro_pess->ano_inicio);
            printf(" ---> Horário: %d horas, %d minutos e %d segundos.\n", cadastro_pess->hora_inicio, cadastro_pess->minuto_inicio, cadastro_pess->segundo_inicio);
            printf(" Data do término do banimento: %d/", cadastro_pess->dia_termino);
            printf("%d/", cadastro_pess->mes_termino);
            printf("%d", cadastro_pess->ano_termino);
            printf(" ---> Horário: %d horas, %d minutos e %d segundos.\n", cadastro_pess->hora_termino, cadastro_pess->minuto_termino, cadastro_pess->segundo_termino);
            printf("\n");
        }

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

        printf(" Cidade: %s \n", cadastro_pess->enderCid);
        printf(" Bairro: %s \n", cadastro_pess->enderBair);
        printf(" Numero da casa: %s \n", cadastro_pess->numCasa);
        printf("\n");

        cadastro_pess->quantidade_de_livros_emprestados += 1;
        fseek(fp, (-1)*sizeof(Pes), SEEK_CUR);
        fwrite(cadastro_pess, sizeof(Pes), 1, fp);


        strcpy(emprestimo->nome, cadastro_pess->nome);
        strcpy(emprestimo->cpf, cadastro_pess->cpf);
    }

    fclose(fp);
    free(cadastro_pess);

}

int verifica_matricula_emprestimo(char procurado[12]) {

    FILE* fp;
    Livro* livro;
    int achou;

    fp = fopen("livros.dat", "rb");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    livro = (Livro*) malloc(sizeof(Livro));

    achou = 0;

    while((!achou) && (fread(livro, sizeof(Livro), 1, fp))) {

        if ((strcmp(livro->matricula, procurado) == 0) && (livro->status == '1') && (livro->emprestado == '0')) {

            achou = 1;

        }

    }

    if (achou) {

        return 1;

    } else {

        return 0;

    }

    fclose(fp);
    free(livro);

}

void mostraLivro(Emprestimo* emprestimo) {

    FILE* fp;
    Livro* livro;
    int achou = 0;

    fp = fopen("livros.dat", "r+b");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    livro = (Livro*) malloc(sizeof(Livro));

    while((!achou) && (fread(livro, sizeof(Livro), 1, fp))) {

        if ((strcmp(livro->matricula, emprestimo->matricula) == 0) && (livro->status == '1')) {

            achou = 1;

        }

    }

    if (achou) {

        printf("\n\n Nome do livro: %s \n", livro->nome);
        printf(" Matricula: %s \n", livro->matricula);
        printf(" ISBN: %s \n", livro->isbn);
        printf(" Autor: %s \n", livro->autor);
        printf(" Gênero: %s \n", livro->genero);
        printf(" Editora: %s \n", livro->editora);
        printf(" Edição: %sª \n", livro->edicao);
        printf(" Preço: %s R$ \n", livro->preco);

        if(livro->emprestado == '0') {
            printf(" Esse livro não está emprestado.\n");
        }else{
            printf(" Esse livro está emprestado.\n");
            printf(" Data de início do empréstimo: %d/", emprestimo->dia);
            printf("%d/", emprestimo->mes);
            printf("%d", emprestimo->ano);
            printf(" ---> Horário: %d horas, %d minutos e %d segundos.\n", emprestimo->hora, emprestimo->minuto, emprestimo->segundo);
            printf(" Data estimada do término do empréstimo: %d/", emprestimo->dia_entrega);
            printf("%d/", emprestimo->mes_entrega);
            printf("%d", emprestimo->ano_entrega);
            printf(" ---> Horário: %d horas, %d minutos e %d segundos.\n", emprestimo->hora_entrega, emprestimo->minuto_entrega, emprestimo->segundo_entrega);
            printf("\n");
        }
        printf("\n");

        livro->emprestado = '1';
        fseek(fp, (-1)*sizeof(Livro), SEEK_CUR);
        fwrite(livro, sizeof(Livro), 1, fp);

        livro->quantidade_de_vezes_emprestado += 1;
        fseek(fp, (-1)*sizeof(Livro), SEEK_CUR);
        fwrite(livro, sizeof(Livro), 1, fp);


        strcpy(emprestimo->nomeLiv, livro->nome);
        strcpy(emprestimo->isbn, livro->isbn);

    }

    fclose(fp);
    free(livro);

}

int verifica_matricula(char procurado[12]) {

    FILE* fp;
    Livro* livro;
    int achou;

    fp = fopen("livros.dat", "rb");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    livro = (Livro*) malloc(sizeof(Livro));

    achou = 0;

    while((!achou) && (fread(livro, sizeof(Livro), 1, fp))) {

        if ((strcmp(livro->matricula, procurado) == 0) && (livro->status == '1')) {

            achou = 1;

        }

    }

    if (achou) {

        return 0;

    } else {

        return 1;

    }

    fclose(fp);
    free(livro);

}

void devolve_livro(void) {

    FILE* fp;
    FILE* fp2;

    Emprestimo* devolve;
    Livro* livro;

    int achou2;
    int achou;
    char resp;
    char matricula[13];

    fp = fopen("emprestimos.dat", "r+b");
    fp2 = fopen("livros.dat", "r+b");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>    DEVOLUÇÃO DE LIVRO     <<<");
    printf("\n =================================");
    printf("\n");

    printf(" Informe a matricula do livro a ser devolvido: ");
    scanf(" %12[^\n]", matricula);

    devolve = (Emprestimo*) malloc(sizeof(Emprestimo));

    livro = (Livro*) malloc(sizeof(Livro));

    achou = 0;

    achou2 = 0;

    while((!achou) && (fread(devolve, sizeof(Emprestimo), 1, fp))) {

        if ((strcmp(devolve->matricula, matricula) == 0) && (devolve->status == '1')) {

            achou = 1;

        }

    }


    if (achou) {

        exibeEmprestimo(devolve);

        printf(" Deseja devolver este livro (S/N)? ");

        scanf(" %c", &resp);

        if (resp == 's' || resp == 'S') {
            

                while((!achou2) && (fread(livro, sizeof(Livro), 1, fp2))) {

                    if ((strcmp(livro->matricula, devolve->matricula) == 0) && (livro->status == '1')) {

                        achou2 = 1;


                        }
                    }

                    if (achou2){

                        livro->emprestado = '0';

                        fseek(fp2, -1 * sizeof(Livro), SEEK_CUR);
                        fwrite(livro, sizeof(Livro), 1, fp2);
                    }
            devolve->emprestado = '0';
            fseek(fp, -1 * sizeof(Emprestimo), SEEK_CUR);
            fwrite(devolve, sizeof(Emprestimo), 1, fp);



            /*devolve->status = '0';

            fseek(fp, -1 * sizeof(Emprestimo), SEEK_CUR);
            fwrite(devolve, sizeof(Emprestimo), 1, fp);*/

            printf("\nLivro devolvido com sucesso!\n");

        } else {

            printf("\n Ok, os dados não foram alterados\n");

        }

    } else {

        printf(" Matricula %s não foi encontrada...\n", matricula);

    }

    printf("\n Tecle ENTER para continuar.\n");
    getchar();
    getchar();
    
    fclose(fp);
    fclose(fp2);
    free(livro);
    free(devolve);

}

NoPes* listaOrdenadaPessoas(void) {
  FILE* fp;
  Pes* pessoa;
  NoPes* noPes;
  NoPes* lista;

  lista = NULL;

  fp = fopen("pessoas.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  pessoa = (Pes*) malloc(sizeof(Pes));

  while(fread(pessoa, sizeof(Pes), 1, fp)) {
    if (pessoa->status == '1') {
      noPes = (NoPes*) malloc(sizeof(NoPes));
      strcpy(noPes->cpf, pessoa->cpf);
      strcpy(noPes->nome, pessoa->nome);
      strcpy(noPes->enderCid, pessoa->enderCid);
      strcpy(noPes->enderBair, pessoa->enderBair);
      strcpy(noPes->numCasa, pessoa->numCasa);
      strcpy(noPes->tel, pessoa->tel);
      strcpy(noPes->email, pessoa->email);
      strcpy(noPes->motivo, pessoa->motivo);
      noPes->dia = pessoa->dia;
      noPes->mes = pessoa->mes;
      noPes->ano = pessoa->ano;
      noPes->numero_uf = pessoa->numero_uf;
      noPes->uf = pessoa->uf;
      noPes->c = pessoa->c;
      noPes->status = pessoa->status;
      noPes->multado = pessoa->multado;
      noPes->segundos = pessoa->segundos;
      noPes->segundos2 = pessoa->segundos2;
      noPes->dia_inicio = pessoa->dia_inicio;
      noPes->mes_inicio = pessoa->mes_inicio;
      noPes->ano_inicio = pessoa->ano_inicio;
      noPes->hora_inicio = pessoa->hora_inicio;
      noPes->minuto_inicio = pessoa->minuto_inicio;
      noPes->segundo_inicio = pessoa->segundo_inicio;
      noPes->dia_termino = pessoa->dia_termino;
      noPes->mes_termino = pessoa->mes_termino;
      noPes->ano_termino = pessoa->ano_termino;
      noPes->hora_termino = pessoa->hora_termino;
      noPes->minuto_termino = pessoa->minuto_termino;
      noPes->segundo_termino = pessoa->segundo_termino;
      noPes->quantidade_de_livros_emprestados = pessoa->quantidade_de_livros_emprestados;

      if (lista == NULL) {
        lista = noPes;
        noPes->prox = NULL;
      } else if (strcmp(noPes->nome,lista->nome) < 0) {
        noPes->prox = lista;
        lista = noPes;
      } else {
        NoPes* anter = lista;
        NoPes* atual = lista->prox;
        while ((atual != NULL) && strcmp(atual->nome,noPes->nome) < 0) {
          anter = atual;
          atual = atual->prox;
        }
        anter->prox = noPes;
        noPes->prox = atual;
      }
    }
  }
  fclose(fp);
  free(pessoa);
  return lista;
}

NoPes* listaInvertidaPessoas(void) {
  FILE* fp;
  Pes* pessoa;
  NoPes* noPes;
  NoPes* lista;
  
  lista = NULL;
  fp = fopen("pessoas.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  pessoa = (Pes*) malloc(sizeof(Pes));
  while(fread(pessoa, sizeof(Pes), 1, fp)){

    printf("nome: %s \n", pessoa->nome);
    if (pessoa->status == '1') {

      noPes = (NoPes*) malloc(sizeof(NoPes));
   
      strcpy(noPes->cpf, pessoa->cpf);
      strcpy(noPes->nome, pessoa->nome);
      strcpy(noPes->enderCid, pessoa->enderCid);
      strcpy(noPes->enderBair, pessoa->enderBair);
      strcpy(noPes->numCasa, pessoa->numCasa);
      strcpy(noPes->tel, pessoa->tel);
      strcpy(noPes->email, pessoa->email);
      strcpy(noPes->motivo, pessoa->motivo);
      noPes->dia = pessoa->dia;
      noPes->mes = pessoa->mes;
      noPes->ano = pessoa->ano;
      noPes->numero_uf = pessoa->numero_uf;
      noPes->uf = pessoa->uf;
      noPes->c = pessoa->c;
      noPes->status = pessoa->status;
      noPes->multado = pessoa->multado;
      noPes->segundos = pessoa->segundos;
      noPes->segundos2 = pessoa->segundos2;
      noPes->dia_inicio = pessoa->dia_inicio;
      noPes->mes_inicio = pessoa->mes_inicio;
      noPes->ano_inicio = pessoa->ano_inicio;
      noPes->hora_inicio = pessoa->hora_inicio;
      noPes->minuto_inicio = pessoa->minuto_inicio;
      noPes->segundo_inicio = pessoa->segundo_inicio;
      noPes->dia_termino = pessoa->dia_termino;
      noPes->mes_termino = pessoa->mes_termino;
      noPes->ano_termino = pessoa->ano_termino;
      noPes->hora_termino = pessoa->hora_termino;
      noPes->minuto_termino = pessoa->minuto_termino;
      noPes->segundo_termino = pessoa->segundo_termino;
      noPes->quantidade_de_livros_emprestados = pessoa->quantidade_de_livros_emprestados;

      noPes->prox = lista;
      lista = noPes;
    }
  }
  fclose(fp);
  free(pessoa);
  return lista;
}

NoPes* listaDiretaPessoas(void) {
  FILE* fp;
  Pes* pessoa;
  NoPes* noPes;
  NoPes* lista;
  NoPes* ultimo;

  lista = NULL;

  fp = fopen("pessoas.dat", "rb");
  
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  pessoa = (Pes*) malloc(sizeof(Pes));
  while(fread(pessoa, sizeof(Pes), 1, fp)) {
    if (pessoa->status == '1') {

      noPes = (NoPes*) malloc(sizeof(NoPes));

      strcpy(noPes->cpf, pessoa->cpf);
      strcpy(noPes->nome, pessoa->nome);
      strcpy(noPes->enderCid, pessoa->enderCid);
      strcpy(noPes->enderBair, pessoa->enderBair);
      strcpy(noPes->numCasa, pessoa->numCasa);
      strcpy(noPes->tel, pessoa->tel);
      strcpy(noPes->email, pessoa->email);
      strcpy(noPes->motivo, pessoa->motivo);
      noPes->dia = pessoa->dia;
      noPes->mes = pessoa->mes;
      noPes->ano = pessoa->ano;
      noPes->numero_uf = pessoa->numero_uf;
      noPes->uf = pessoa->uf;
      noPes->c = pessoa->c;
      noPes->status = pessoa->status;
      noPes->multado = pessoa->multado;
      noPes->segundos = pessoa->segundos;
      noPes->segundos2 = pessoa->segundos2;
      noPes->dia_inicio = pessoa->dia_inicio;
      noPes->mes_inicio = pessoa->mes_inicio;
      noPes->ano_inicio = pessoa->ano_inicio;
      noPes->hora_inicio = pessoa->hora_inicio;
      noPes->minuto_inicio = pessoa->minuto_inicio;
      noPes->segundo_inicio = pessoa->segundo_inicio;
      noPes->dia_termino = pessoa->dia_termino;
      noPes->mes_termino = pessoa->mes_termino;
      noPes->ano_termino = pessoa->ano_termino;
      noPes->hora_termino = pessoa->hora_termino;
      noPes->minuto_termino = pessoa->minuto_termino;
      noPes->segundo_termino = pessoa->segundo_termino;
      noPes->quantidade_de_livros_emprestados = pessoa->quantidade_de_livros_emprestados;

      noPes->prox = NULL;

      if (lista == NULL) {
        lista = noPes;
      } else {
        ultimo->prox = noPes;
      }
      ultimo = noPes;
    }
  }
  fclose(fp);
  free(pessoa);
  return lista;
}

void exibeListaPessoas(NoPes* lista) {

    int dia = lista->dia;
    int mes = lista->mes;
    int ano = lista->ano;
    int numero_uf = lista->uf;

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>    USUÁRIOS CADASTRADOS   <<<");
    printf("\n ================================= \n");

  while (lista != NULL) {

    printf("\n\n Nome: %s \n", lista->nome);
    printf(" CPF: %c%c%c.%c%c%c.%c%c%c-%c%c \n", lista->cpf[0], lista->cpf[1], lista->cpf[2], lista->cpf[3], lista->cpf[4], lista->cpf[5], lista->cpf[6], lista->cpf[7], lista->cpf[8], lista->cpf[9], lista->cpf[10]);

    printf(" Data de nascimento: %d/%d/%d \n", dia, mes, ano);

    printf(" Email: %s \n", lista->email);
    printf(" Telefone: %s \n", lista->tel);

    if(lista->multado == '0') {
        printf(" Esse leitor não está multado.\n");
    } else {
        printf(" Esse leitor está multado.\n");
        printf(" Motivo: %s \n", lista->motivo);
        printf(" Data de início do banimento: %d/", lista->dia_inicio);
        printf("%d/", lista->mes_inicio);
        printf("%d", lista->ano_inicio);
        printf(" ---> Horário: %d horas, %d minutos e %d segundos.\n", lista->hora_inicio, lista->minuto_inicio, lista->segundo_inicio);
        printf(" Data do término do banimento: %d/", lista->dia_termino);
        printf("%d/", lista->mes_termino);
        printf("%d", lista->ano_termino);
        printf(" ---> Horário: %d horas, %d minutos e %d segundos.\n", lista->hora_termino, lista->minuto_termino, lista->segundo_termino);
        printf("\n");
    }

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

    printf(" Cidade: %s \n", lista->enderCid);
    printf(" Bairro: %s \n", lista->enderBair);
    printf(" Numero da casa: %s \n", lista->numCasa);
    printf(" Quantidade de livros emprestados a esse leitor: %d \n", lista->quantidade_de_livros_emprestados);
    printf("\n");

    lista = lista->prox;
  }
}

NoLivro* listaDiretaLivros(void) {

  FILE* fp;

  Livro* livro;

  NoLivro* noLivro;
  NoLivro* lista;
  NoLivro* ultimo;

  lista = NULL;

  fp = fopen("livros.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  livro = (Livro*) malloc(sizeof(Livro));

  while(fread(livro, sizeof(Livro), 1, fp)) {
    if (livro->status == '1') {
      noLivro = (NoLivro*) malloc(sizeof(NoLivro));
      strcpy(noLivro->nome, livro->nome);
      strcpy(noLivro->isbn, livro->isbn);
      strcpy(noLivro->autor, livro->autor);
      strcpy(noLivro->genero, livro->genero);
      strcpy(noLivro->editora, livro->editora);
      strcpy(noLivro->edicao, livro->edicao);
      strcpy(noLivro->matricula, livro->matricula);
      strcpy(noLivro->preco, livro->preco);
      noLivro->status = livro->status;
      noLivro->emprestado = livro->emprestado;
      noLivro->quantidade_de_vezes_emprestado = livro->quantidade_de_vezes_emprestado;
      noLivro->prox = NULL;
      if (lista == NULL) {
        lista = noLivro;
      } else {
        ultimo->prox = noLivro;
      }
      ultimo = noLivro;
    }
  }
  fclose(fp);
  free(livro);
  return lista;
}

NoLivro* listaInvertidaLivros(void) {

  FILE* fp;
  Livro* livro;
  NoLivro* noLivro;
  NoLivro* lista;

  lista = NULL;

  fp = fopen("livros.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  livro = (Livro*) malloc(sizeof(Livro));
  while(fread(livro, sizeof(Livro), 1, fp)) {
    if (livro->status == '1') {
      noLivro = (NoLivro*) malloc(sizeof(NoLivro));
      strcpy(noLivro->nome, livro->nome);
      strcpy(noLivro->isbn, livro->isbn);
      strcpy(noLivro->autor, livro->autor);
      strcpy(noLivro->genero, livro->genero);
      strcpy(noLivro->editora, livro->editora);
      strcpy(noLivro->edicao, livro->edicao);
      strcpy(noLivro->matricula, livro->matricula);
      strcpy(noLivro->preco, livro->preco);
      noLivro->status = livro->status;
      noLivro->emprestado = livro->emprestado;
      noLivro->quantidade_de_vezes_emprestado = livro->quantidade_de_vezes_emprestado;
      noLivro->prox = lista;
      lista = noLivro;
    }
  }
  fclose(fp);
  free(livro);
  return lista;
}

NoLivro* listaOrdenadaLivros(void) {

  FILE* fp;
  Livro* livro;
  NoLivro* noLivro;
  NoLivro* lista;

  lista = NULL;

  fp = fopen("livros.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  livro = (Livro*) malloc(sizeof(Livro));
  while(fread(livro, sizeof(Livro), 1, fp)) {
    if (livro->status == '1') {
      noLivro = (NoLivro*) malloc(sizeof(NoLivro));
      strcpy(noLivro->nome, livro->nome);
      strcpy(noLivro->isbn, livro->isbn);
      strcpy(noLivro->autor, livro->autor);
      strcpy(noLivro->genero, livro->genero);
      strcpy(noLivro->editora, livro->editora);
      strcpy(noLivro->edicao, livro->edicao);
      strcpy(noLivro->matricula, livro->matricula);
      strcpy(noLivro->preco, livro->preco);
      noLivro->status = livro->status;
      noLivro->emprestado = livro->emprestado;
      noLivro->quantidade_de_vezes_emprestado = livro->quantidade_de_vezes_emprestado;

      if (lista == NULL) {
        lista = noLivro;
        noLivro->prox = NULL;
      } else if (strcmp(noLivro->nome,lista->nome) < 0) {
        noLivro->prox = lista;
        lista = noLivro;
      } else {
        NoLivro* anter = lista;
        NoLivro* atual = lista->prox;
        while ((atual != NULL) && strcmp(atual->nome,noLivro->nome) < 0) {
          anter = atual;
          atual = atual->prox;
        }
        anter->prox = noLivro;
        noLivro->prox = atual;
      }
    }
  }
  fclose(fp);
  free(livro);
  return lista;
}

void exibeListaLivros(NoLivro* lista) {
    system("clear");
    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>    ACERVO DA BIBLIOTECA   <<<");
    printf("\n ================================= \n");
  while (lista != NULL) {
    printf("\n\n Nome do livro: %s \n", lista->nome);
    printf(" Matricula: %s \n", lista->matricula);
    printf(" ISBN: %s \n", lista->isbn);
    printf(" Autor: %s \n", lista->autor);
    printf(" Gênero: %s \n", lista->genero);
    printf(" Editora: %s \n", lista->editora);
    printf(" Edição: %sª \n", lista->edicao);
    printf(" Preço: %s R$ \n", lista->preco);
    if(lista->emprestado == '0') {
        printf(" O livro está disponível para ser emprestado.\n");
    } else {

        printf(" O livro está indisponível para ser emprestado.\n");
    }

    printf(" Quantidade de vezes que esse livro foi emprestado: %d \n", lista->quantidade_de_vezes_emprestado);
    printf("\n");
    lista = lista->prox;
  }
}

void pesquisaNomePessoa(void) {

    FILE* fp;

    Pes* cadastro_pess;
    Pes** usuarios_encontrados;

    int i;
    int aux;
    int tam;
    int achou;

    char procurado[100];


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

    printf("\n Tecle ENTER para continuar.\n");
    getchar();
    getchar();



}

void pesquisaCPFPessoa(void) {

    FILE* fp;
    Pes* cadastro_pess;
    int achou;
    char procurado[100];


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

    printf(" Informe o CPF da pessoa a ser buscada: ");
    scanf(" %100[^\n]", procurado);

    cadastro_pess = (Pes*) malloc(sizeof(Pes));

    achou = 0;

    while((!achou) && (fread(cadastro_pess, sizeof(Pes), 1, fp))) {

        if ((strcmp(cadastro_pess->cpf, procurado) == 0) && (cadastro_pess->status == '1')) {

            achou = 1;

        }

    }

    fclose(fp);

    if (achou) {

        exibePessoa(cadastro_pess);

    } else {

        printf("\n %s não foi encontrado(a)...\n", procurado);

    }

    printf("\n Tecle ENTER para continuar.\n");
    getchar();
    getchar();
    
    free(cadastro_pess);

}



void pesquisaPorMatriculaEmprestimo(void) {

    FILE* fp;
    Emprestimo* pesquisa;
    int achou;
    char procurado[100];
    

    fp = fopen("emprestimos.dat", "rb");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>     BUSCAR EMPRÉSTIMO     <<<");
    printf("\n =================================");
    printf("\n");

    printf(" Informe a matrícula do livro: ");
    scanf(" %100[^\n]", procurado);

    pesquisa = (Emprestimo*) malloc(sizeof(Emprestimo));

    achou = 0;

    while((!achou) && (fread(pesquisa, sizeof(Emprestimo), 1, fp))) {

        if ((strcmp(pesquisa->matricula, procurado) == 0) && (pesquisa->status == '1')) {

            achou = 1;

        }

    }

    fclose(fp);

    if (achou) {

        exibeEmprestimo(pesquisa);

    } else {

        printf("\n %s não foi encontrado(a)...\n", procurado);

    }

    printf("\n Tecle ENTER para continuar.\n");
    getchar();
    getchar();
    free(pesquisa);

}




void pesquisaPorCPFEmprestimo(void) {

    FILE* fp;
    Emprestimo* cadastro_pess;
    int achou;
    char procurado[100];
    

    fp = fopen("emprestimos.dat", "rb");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>     BUSCAR EMPRÉSTIMO     <<<");
    printf("\n =================================");
    printf("\n");

    printf(" Informe o CPF cadastro no empréstimo: ");
    scanf(" %100[^\n]", procurado);

    cadastro_pess = (Emprestimo*) malloc(sizeof(Emprestimo));

    achou = 0;

    while((!achou) && (fread(cadastro_pess, sizeof(Emprestimo), 1, fp))) {

        if ((strcmp(cadastro_pess->cpf, procurado) == 0) && (cadastro_pess->status == '1')) {

            achou = 1;

        }

    }

    fclose(fp);

    if (achou) {

        exibeEmprestimo(cadastro_pess);

    } else {

        printf("\n %s não foi encontrado(a)...\n", procurado);

    }

    printf("\n Tecle ENTER para continuar.\n");
    getchar();
    getchar();

    free(cadastro_pess);

}






void pesquisaPorCodigoEmprestimo(void) {

    FILE* fp;
    Emprestimo* pesquisa;
    int achou;
    char procurado[100];
    

    fp = fopen("emprestimos.dat", "rb");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>     BUSCAR EMPRÉSTIMO     <<<");
    printf("\n =================================");
    printf("\n");

    printf(" Informe o Código do empréstimo: ");
    scanf(" %100[^\n]", procurado);

    pesquisa = (Emprestimo*) malloc(sizeof(Emprestimo));

    achou = 0;

    while((!achou) && (fread(pesquisa, sizeof(Emprestimo), 1, fp))) {

        if ((strcmp(pesquisa->cod, procurado) == 0) && (pesquisa->status == '1')) {

            achou = 1;

        }

    }

    fclose(fp);

    if (achou) {

        exibeEmprestimo(pesquisa);

    } else {

        printf("\n %s não foi encontrado(a)...\n", procurado);

    }

    printf("\n Tecle ENTER para continuar.\n");
    getchar();
    getchar();

    free(pesquisa);

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
    printf(" Telefone: %s \n", usuarios_encontrados[k]->tel);

    if(usuarios_encontrados[k]->multado == '0') {
        printf(" Esse leitor não está multado.\n");
    } else {
        printf(" Esse leitor está multado.\n");
        printf(" Motivo: %s \n", usuarios_encontrados[k]->motivo);
        printf(" Data de início do banimento: %d/", usuarios_encontrados[k]->dia_inicio);
        printf("%d/", usuarios_encontrados[k]->mes_inicio);
        printf("%d", usuarios_encontrados[k]->ano_inicio);
        printf(" ---> Horário: %d horas, %d minutos e %d segundos.\n", usuarios_encontrados[k]->hora_inicio, usuarios_encontrados[k]->minuto_inicio, usuarios_encontrados[k]->segundo_inicio);
        printf(" Data do término do banimento: %d/", usuarios_encontrados[k]->dia_termino);
        printf("%d/", usuarios_encontrados[k]->mes_termino);
        printf("%d", usuarios_encontrados[k]->ano_termino);
        printf(" ---> Horário: %d horas, %d minutos e %d segundos.\n", usuarios_encontrados[k]->hora_termino, usuarios_encontrados[k]->minuto_termino, usuarios_encontrados[k]->segundo_termino);
        printf("\n");
    }

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
    printf(" Quantidade de livros emprestados a esse leitor: %d \n", usuarios_encontrados[k]->quantidade_de_livros_emprestados);
    printf("\n");

  }

  free(usuarios_encontrados);

}

void pesquisaTituloLivro(void) {

    FILE* fp;

    Livro* livro;
    Livro** livros_encontrados;

    int i;
    int aux;
    int tam;
    int achou;

    char procurado[100];
    

    fp = fopen("livros.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>       BUSCA LIVRO        <<<");
    printf("\n =================================");
    printf("\n");

    printf(" Informe o título do livro a ser buscado: ");
    scanf(" %100[^\n]", procurado);

    i = 0;
    aux = 0;
    achou = 0;

    livro = (Livro*) malloc(sizeof(Livro));

    while(fread(livro, sizeof(Livro), 1, fp)) {

      i += 1;

    }

    fclose(fp);
    free(livro);

    Livro* livro2;
    Livro* auxiliar;
    livro2 = (Livro*) malloc(sizeof(Livro));

    FILE* fp2;
    fp2 = fopen("livros.dat", "rb");
    if (fp2 == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }

    tam = i;
    livros_encontrados = (Livro**) malloc(tam * sizeof(Livro*));

    int tamanho_procurado = strlen(procurado);

    while(fread(livro2, sizeof(Livro), 1, fp2)) {

        char string_auxiliar[100];

        strcpy(string_auxiliar, livro2->nome);

        for(int i = 0; i < tamanho_procurado; i++) {
          
          if(tamanho_procurado == 1) {

            if((string_auxiliar[i] == procurado[i]) && (livro2->status == '1')) {

              livros_encontrados[aux] = livro2;
            
              aux += 1;
              achou = 1;

              auxiliar = (Livro*) malloc(sizeof(Livro));

              livro2 = auxiliar;

              break;               
            }

          } else {

            if((string_auxiliar[i] == procurado[i]) && (string_auxiliar[i + 1] == procurado[i + 1]) && (livro2->status == '1')) {

              livros_encontrados[aux] = livro2;
            
              aux += 1;
              achou = 1;

              auxiliar = (Livro*) malloc(sizeof(Livro));

              livro2 = auxiliar;

              break;   
    
            }

          }

        }

    }

    fclose(fp2);

    if (achou) {

        exibeLivrosEncontrados(livros_encontrados, aux);

    } else {

        printf("\n %s não foi encontrado(a)...\n", procurado);

    }

    printf("\n Tecle ENTER para continuar.\n");
    getchar();
    getchar();

}

void pesquisaAutorLivro(void) {

    FILE* fp;

    Livro* livro;
    Livro** livros_encontrados;

    int i;
    int aux;
    int tam;
    int achou;

    char procurado[100];
    

    fp = fopen("livros.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>       BUSCA LIVRO        <<<");
    printf("\n =================================");
    printf("\n");

    printf(" Informe o nome do autor do livro a ser buscado: ");
    scanf(" %100[^\n]", procurado);

    i = 0;
    aux = 0;
    achou = 0;

    livro = (Livro*) malloc(sizeof(Livro));

    while(fread(livro, sizeof(Livro), 1, fp)) {

      i += 1;

    }

    fclose(fp);
    free(livro);

    Livro* livro2;
    Livro* auxiliar;
    livro2 = (Livro*) malloc(sizeof(Livro));

    FILE* fp2;
    fp2 = fopen("livros.dat", "rb");
    if (fp2 == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }

    tam = i;
    livros_encontrados = (Livro**) malloc(tam * sizeof(Livro*));

    int tamanho_procurado = strlen(procurado);

    while(fread(livro2, sizeof(Livro), 1, fp2)) {

        char string_auxiliar[100];

        strcpy(string_auxiliar, livro2->autor);

        for(int i = 0; i < tamanho_procurado; i++) {
          
          if(tamanho_procurado == 1) {

            if((string_auxiliar[i] == procurado[i]) && (livro2->status == '1')) {

              livros_encontrados[aux] = livro2;
            
              aux += 1;
              achou = 1;

              auxiliar = (Livro*) malloc(sizeof(Livro));

              livro2 = auxiliar;

              break;               
            }

          } else {

            if((string_auxiliar[i] == procurado[i]) && (string_auxiliar[i + 1] == procurado[i + 1]) && (livro2->status == '1')) {

              livros_encontrados[aux] = livro2;
            
              aux += 1;
              achou = 1;

              auxiliar = (Livro*) malloc(sizeof(Livro));

              livro2 = auxiliar;

              break;   
    
            }

          }

        }

    }

    fclose(fp2);

    if (achou) {

        exibeLivrosEncontrados(livros_encontrados, aux);

    } else {

        printf("\n %s não foi encontrado(a)...\n", procurado);

    }

    printf("\n Tecle ENTER para continuar.\n");
    getchar();
    getchar();

}

void pesquisaISBNLivro(void) {

    FILE* fp;
    Livro* livro;
    int achou;
    char procurado[100];
    

    fp = fopen("livros.dat", "rb");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>       BUSCA LIVRO        <<<");
    printf("\n =================================");
    printf("\n");

    printf(" Informe a ISBN do livro a ser buscado: ");
    scanf(" %100[^\n]", procurado);

    livro = (Livro*) malloc(sizeof(Livro));

    achou = 0;

    while((!achou) && (fread(livro, sizeof(Livro), 1, fp))) {

        if ((strcmp(livro->isbn, procurado) == 0) && (livro->status == '1')) {

            achou = 1;

        }

    }

    fclose(fp);

    if (achou) {

        exibeLivro(livro);

    } else {

        printf("\n %s não foi encontrado(a)...\n", procurado);

    }

 
    printf("\n Tecle ENTER para continuar.\n");
    getchar();
    getchar();
    
    free(livro);

}

void pesquisaMatriculaLivro(void) {

    FILE* fp;
    Livro* livro;
    int achou;
    char procurado[100];
    

    fp = fopen("livros.dat", "rb");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>       BUSCA LIVRO        <<<");
    printf("\n =================================");
    printf("\n");

    printf(" Informe a matrícula do livro a ser buscado: ");
    scanf(" %100[^\n]", procurado);

    livro = (Livro*) malloc(sizeof(Livro));

    achou = 0;

    while((!achou) && (fread(livro, sizeof(Livro), 1, fp))) {

        if ((strcmp(livro->matricula, procurado) == 0) && (livro->status == '1')) {

            achou = 1;

        }

    }

    fclose(fp);

    if (achou) {

        exibeLivro(livro);

    } else {

        printf("%d", achou);
        printf("\n %s não foi encontrado(a)...\n", procurado);

    }

    printf("\n Tecle ENTER para continuar.\n");
    getchar();
    getchar();

    free(livro);

}

void pesquisaGeneroLivro(void) {

    FILE* fp;

    Livro* livro;
    Livro** livros_encontrados;

    int i;
    int aux;
    int tam;
    int achou;

    char procurado[100];
    
    fp = fopen("livros.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>       BUSCA LIVRO        <<<");
    printf("\n =================================");
    printf("\n");

    printf(" Informe o gênero do livro a ser buscado: ");
    scanf(" %100[^\n]", procurado);

    i = 0;
    aux = 0;
    achou = 0;

    livro = (Livro*) malloc(sizeof(Livro));

    while(fread(livro, sizeof(Livro), 1, fp)) {

      i += 1;

    }

    fclose(fp);
    free(livro);

    Livro* livro2;
    Livro* auxiliar;
    livro2 = (Livro*) malloc(sizeof(Livro));

    FILE* fp2;
    fp2 = fopen("livros.dat", "rb");
    if (fp2 == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }

    tam = i;
    livros_encontrados = (Livro**) malloc(tam * sizeof(Livro*));

    int tamanho_procurado = strlen(procurado);

    while(fread(livro2, sizeof(Livro), 1, fp2)) {

        char string_auxiliar[100];

        strcpy(string_auxiliar, livro2->genero);

        for(int i = 0; i < tamanho_procurado; i++) {
          
          if(tamanho_procurado == 1) {

            if((string_auxiliar[i] == procurado[i]) && (livro2->status == '1')) {

              livros_encontrados[aux] = livro2;
            
              aux += 1;
              achou = 1;

              auxiliar = (Livro*) malloc(sizeof(Livro));

              livro2 = auxiliar;

              break;               
            }

          } else {

            if((string_auxiliar[i] == procurado[i]) && (string_auxiliar[i + 1] == procurado[i + 1]) && (livro2->status == '1')) {

              livros_encontrados[aux] = livro2;
            
              aux += 1;
              achou = 1;

              auxiliar = (Livro*) malloc(sizeof(Livro));

              livro2 = auxiliar;

              break;   
    
            }

          }

        }

    }

    fclose(fp2);

    if (achou) {

        exibeLivrosEncontrados(livros_encontrados, aux);

    } else {

        printf("\n %s não foi encontrado(a)...\n", procurado);

    }

    printf("\n Tecle ENTER para continuar.\n");
    getchar();
    getchar();

}

void exibeLivrosEncontrados(Livro** livros_encontrados, int quantidade) {

  for(int k = 0; k < quantidade; k++) {
    
    printf("\n\n Nome do livro: %s \n", livros_encontrados[k]->nome);
    printf(" Matricula: %s \n", livros_encontrados[k]->matricula);
    printf(" ISBN: %s \n", livros_encontrados[k]->isbn);
    printf(" Autor: %s \n", livros_encontrados[k]->autor);
    printf(" Gênero: %s \n", livros_encontrados[k]->genero);
    printf(" Editora: %s \n", livros_encontrados[k]->editora);
    printf(" Edição: %sª \n", livros_encontrados[k]->edicao);
    printf(" Preço: %s R$ \n", livros_encontrados[k]->preco);
    if(livros_encontrados[k]->emprestado == '0') {
        printf(" O livro não está emprestado.\n");
    } else {
        printf(" O livro está emprestado.\n");
    }
    printf(" Quantidade de vezes que esse livro foi emprestado: %d \n", livros_encontrados[k]->quantidade_de_vezes_emprestado);
    printf("\n");

  }

  free(livros_encontrados);

}

void exibeEmprestimosEncontrados(Emprestimo** emprestimos_encontrados, int quantidade) {

  for(int k = 0; k < quantidade; k++) {
    
    printf("\n\n Código do empréstimo: %s \n", emprestimos_encontrados[k]->cod);
    printf("\n Nome do leitor: %s \n", emprestimos_encontrados[k]->nome);
    printf(" CPF do leitor: %s \n", emprestimos_encontrados[k]->cpf);
    printf(" Nome do livro: %s \n", emprestimos_encontrados[k]->nomeLiv);
    printf(" ISBN do livro: %s \n", emprestimos_encontrados[k]->isbn);
    printf(" Matrícula do livro: %s \n", emprestimos_encontrados[k]->matricula);
    printf(" Data de realização do empréstimo do livro: %d/", emprestimos_encontrados[k]->dia);
    printf("%d/", emprestimos_encontrados[k]->mes);
    printf("%d", emprestimos_encontrados[k]->ano);
    printf(" ---> Horário: %d horas, %d minutos e %d segundos.\n", emprestimos_encontrados[k]->hora, emprestimos_encontrados[k]->minuto, emprestimos_encontrados[k]->segundo);
    printf(" Data estimada de devolução do livro: %d/", emprestimos_encontrados[k]->dia_entrega);
    printf("%d/", emprestimos_encontrados[k]->mes_entrega);
    printf("%d", emprestimos_encontrados[k]->ano_entrega);
    printf(" ---> Horário: %d horas, %d minutos e %d segundos.\n", emprestimos_encontrados[k]->hora_entrega, emprestimos_encontrados[k]->minuto_entrega, emprestimos_encontrados[k]->segundo_entrega);
    printf("\n");


  }

  free(emprestimos_encontrados);

}

NoEmprestimo* listaDiretaEmprestimo(void) {
  
  FILE* fp;
  Emprestimo* emprestimo;
  NoEmprestimo* noEmprestimo;
  NoEmprestimo* lista;
  NoEmprestimo* ultimo;

  lista = NULL;

  fp = fopen("emprestimos.dat", "rb");
  
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  emprestimo = (Emprestimo*) malloc(sizeof(Emprestimo));
  while(fread(emprestimo, sizeof(Emprestimo), 1, fp)) {
    if (emprestimo->status == '1') {

      noEmprestimo = (NoEmprestimo*) malloc(sizeof(NoEmprestimo));

      strcpy(noEmprestimo->cod, emprestimo->cod);
      strcpy(noEmprestimo->nome, emprestimo->nome);
      strcpy(noEmprestimo->cpf, emprestimo->cpf);
      strcpy(noEmprestimo->nomeLiv, emprestimo->nomeLiv);
      strcpy(noEmprestimo->isbn, emprestimo->isbn);
      strcpy(noEmprestimo->matricula, emprestimo->matricula);
      noEmprestimo->emprestado = emprestimo->emprestado;
      noEmprestimo->segundos = emprestimo->segundos;
      noEmprestimo->segundos2 = emprestimo->segundos2;
      noEmprestimo->status = emprestimo->status;
      noEmprestimo->dia = emprestimo->dia;
      noEmprestimo->mes = emprestimo->mes;
      noEmprestimo->ano = emprestimo->ano;
      noEmprestimo->hora = emprestimo->hora;
      noEmprestimo->minuto = emprestimo->minuto;
      noEmprestimo->segundo = emprestimo->segundo;
      noEmprestimo->dia_entrega = emprestimo->dia_entrega;
      noEmprestimo->mes_entrega = emprestimo->mes_entrega;
      noEmprestimo->ano_entrega = emprestimo->ano_entrega;
      noEmprestimo->hora_entrega = emprestimo->hora_entrega;
      noEmprestimo->minuto_entrega = emprestimo->minuto_entrega;
      noEmprestimo->segundo_entrega = emprestimo->segundo_entrega;
     

      noEmprestimo->prox = NULL;

      if (lista == NULL) {
        lista = noEmprestimo;
      } else {
        ultimo->prox = noEmprestimo;
      }
      ultimo = noEmprestimo;
    }
  }
  fclose(fp);
  free(emprestimo);
  return lista;
}

NoEmprestimo* listaInvertidaEmprestimo(void) {

  FILE* fp;
  Emprestimo* emprestimo;
  NoEmprestimo* noEmprestimo;
  NoEmprestimo* lista;

  lista = NULL;
  fp = fopen("emprestimos.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  emprestimo = (Emprestimo*) malloc(sizeof(Emprestimo));
  while(fread(emprestimo, sizeof(Emprestimo), 1, fp)) {
    if (emprestimo->status == '1') {

      noEmprestimo = (NoEmprestimo*) malloc(sizeof(NoEmprestimo));

      strcpy(noEmprestimo->cod, emprestimo->cod);
      strcpy(noEmprestimo->nome, emprestimo->nome);
      strcpy(noEmprestimo->cpf, emprestimo->cpf);
      strcpy(noEmprestimo->nomeLiv, emprestimo->nomeLiv);
      strcpy(noEmprestimo->isbn, emprestimo->isbn);
      strcpy(noEmprestimo->matricula, emprestimo->matricula);
      noEmprestimo->segundos = emprestimo->segundos;
      noEmprestimo->emprestado = emprestimo->emprestado;
      noEmprestimo->segundos2 = emprestimo->segundos2;
      noEmprestimo->status = emprestimo->status;
      noEmprestimo->dia = emprestimo->dia;
      noEmprestimo->mes = emprestimo->mes;
      noEmprestimo->ano = emprestimo->ano;
      noEmprestimo->hora = emprestimo->hora;
      noEmprestimo->minuto = emprestimo->minuto;
      noEmprestimo->segundo = emprestimo->segundo;
      noEmprestimo->dia_entrega = emprestimo->dia_entrega;
      noEmprestimo->mes_entrega = emprestimo->mes_entrega;
      noEmprestimo->ano_entrega = emprestimo->ano_entrega;
      noEmprestimo->hora_entrega = emprestimo->hora_entrega;
      noEmprestimo->minuto_entrega = emprestimo->minuto_entrega;
      noEmprestimo->segundo_entrega = emprestimo->segundo_entrega;

      noEmprestimo->prox = lista;
      lista = noEmprestimo;
    }
  }
  fclose(fp);
  free(emprestimo);
  return lista;
}

NoEmprestimo* listaOrdenadaEmprestimo(void) {

  FILE* fp;
  Emprestimo* emprestimo;
  NoEmprestimo* noEmprestimo;
  NoEmprestimo* lista;

  lista = NULL;
  fp = fopen("emprestimos.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  emprestimo = (Emprestimo*) malloc(sizeof(Emprestimo));
  while(fread(emprestimo, sizeof(Emprestimo), 1, fp)) {
    if (emprestimo->status == '1') {
      noEmprestimo = (NoEmprestimo*) malloc(sizeof(NoEmprestimo));
      
      strcpy(noEmprestimo->cod, emprestimo->cod);
      strcpy(noEmprestimo->nome, emprestimo->nome);
      strcpy(noEmprestimo->cpf, emprestimo->cpf);
      strcpy(noEmprestimo->nomeLiv, emprestimo->nomeLiv);
      strcpy(noEmprestimo->isbn, emprestimo->isbn);
      strcpy(noEmprestimo->matricula, emprestimo->matricula);
      noEmprestimo->segundos = emprestimo->segundos;
      noEmprestimo->emprestado = emprestimo->emprestado;
      noEmprestimo->segundos2 = emprestimo->segundos2;
      noEmprestimo->status = emprestimo->status;
      noEmprestimo->dia = emprestimo->dia;
      noEmprestimo->mes = emprestimo->mes;
      noEmprestimo->ano = emprestimo->ano;
      noEmprestimo->hora = emprestimo->hora;
      noEmprestimo->minuto = emprestimo->minuto;
      noEmprestimo->segundo = emprestimo->segundo;
      noEmprestimo->dia_entrega = emprestimo->dia_entrega;
      noEmprestimo->mes_entrega = emprestimo->mes_entrega;
      noEmprestimo->ano_entrega = emprestimo->ano_entrega;
      noEmprestimo->hora_entrega = emprestimo->hora_entrega;
      noEmprestimo->minuto_entrega = emprestimo->minuto_entrega;
      noEmprestimo->segundo_entrega = emprestimo->segundo_entrega;

      if (lista == NULL) {
        lista = noEmprestimo;
        noEmprestimo->prox = NULL;
      } else if (strcmp(noEmprestimo->nome,lista->nome) < 0) {
        noEmprestimo->prox = lista;
        lista = noEmprestimo;
      } else {
        NoEmprestimo* anter = lista;
        NoEmprestimo* atual = lista->prox;
        while ((atual != NULL) && strcmp(atual->nome,noEmprestimo->nome) < 0) {
          anter = atual;
          atual = atual->prox;
        }
        anter->prox = noEmprestimo;
        noEmprestimo->prox = atual;
      }
    }
  }
  fclose(fp);
  free(emprestimo);
  return lista;
}

void exibeListaEmprestimo(NoEmprestimo* lista) {

    struct tm;
    time_t segundos2;
    time(&segundos2);
      
    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>  EMPRÉSTIMOS REALIZADOS   <<<");
    printf("\n ================================= \n");

    while (lista != NULL) {

        printf("\n\n Código do empréstimo: %s \n", lista->cod);
        printf(" Nome do leitor: %s \n", lista->nome);
        printf(" CPF do leitor: %s \n", lista->cpf);
        printf(" Nome do livro: %s \n", lista->nomeLiv);
        printf(" ISBN do livro: %s \n", lista->isbn);
        printf(" Matrícula do livro: %s \n", lista->matricula);
        printf(" Data de realização do empréstimo do livro: %d/", lista->dia);
        printf("%d/", lista->mes);
        printf("%d", lista->ano);
        printf(" ---> Horário: %d horas, %d minutos e %d segundos.\n", lista->hora, lista->minuto, lista->segundo);
        printf(" Data estimada de devolução do livro: %d/", lista->dia_entrega);
        printf("%d/", lista->mes_entrega);
        printf("%d", lista->ano_entrega);
        printf(" ---> Horário: %d horas, %d minutos e %d segundos.\n", lista->hora_entrega, lista->minuto_entrega, lista->segundo_entrega);
        printf("\n");

        /*
        if(lista->emprestado == '0'){
            printf(" Este livro esta disponível para ser emprestado novamente\n");
        }
        */

        if (((segundos2 - lista->segundos) >= 0) && (lista->emprestado == '1')){
            printf(" Este Livro emprestado está Atrasado.\n");
        }else if (((segundos2 - lista->segundos) <= 0) && (lista->emprestado == '1')){
            printf(" Este Livro emprestado está em dia.\n");    
        }

        lista = lista->prox;

    }


    
    }
