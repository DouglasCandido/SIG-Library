#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>
#include "telas.h"
#include "validations.h"
#include "esqueleto.h"

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

typedef struct livro Livro;

struct livro {

    char nome[101];
    char isbn[18];
    char autor[201];
    char genero[101];
    char editora[101];
    char edicao[101];
    char status;
    char matricula[13];
    char preco[4];

};

typedef struct emprestimo Emprestimo;

struct emprestimo {

    char nome[101];
    char cpf[12];
    char nomeLiv[101];
    char isbn[18];
    char matricula[13];
    time_t segundos;
    time_t segundos2;
    char status;
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

int verificaCPF(char procurado[12]);
int verifica_matricula(char procurado[13]);
void gravaEmprestimo(Emprestimo* emprestimo);
void listaEmprestimos(void);
void exibeEmprestimo(Emprestimo* emprestimo);
void mostraPessoa(Emprestimo* emprestimo);
void mostraLivro(Emprestimo* emprestimo);
void exibePessoa(Pes* cadastro_pess);
void exibeLivro(Livro* livro);

void listaEmprestimos(void) {

    char a;

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

    printf(" Digite algo e tecle ENTER para continuar.\n");
    scanf(" %c",&a);

}

void exibeEmprestimo(Emprestimo* emprestimo) {

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

void gerenciarEmprestimos (void) {

    char op;

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

        }

    } while(op != 'S');

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
    char op2;

    Emprestimo* emprestar;

    emprestar = (Emprestimo*) malloc(sizeof(Emprestimo));

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>      EMPRESTAR LIVRO      <<<");
    printf("\n =================================");
    printf("\n");

    printf("Deseja mesmo emprestar o livro? (S/N): ");
    scanf(" %c",&resp);

    resp = maius(resp);

    if (resp == 'S') {

        do {

            printf("\nInsira o CPF previamente cadastrado - (Somente números): ");
            scanf(" %15[^\n]", emprestar->cpf);

            if((verifica_cpf_emprestimo(emprestar->cpf) == 1)) {

                mostraPessoa(emprestar);

            }

            printf("\nInsira a matrícula previamente cadastrada - (Somente numeros): ");
            scanf(" %12[^\n]", emprestar->matricula);

            if((verifica_matricula_emprestimo(emprestar->matricula) == 1)) {

                mostraLivro(emprestar);

            }

        } while((verifica_cpf_emprestimo(emprestar->cpf) == 0 && verifica_matricula_emprestimo(emprestar->matricula) == 0));

        struct tm  *data_atual, *data_entrega;

        time(&emprestar->segundos2);

        data_atual = localtime(&emprestar->segundos2);
        emprestar->dia = data_atual->tm_mday;
        emprestar->mes = data_atual->tm_mon+1;
        emprestar->ano = data_atual->tm_year+1900;
        emprestar->hora = data_atual->tm_hour;
        emprestar->minuto = data_atual->tm_min;
        emprestar->segundo = data_atual->tm_sec;

        printf("\nData de empréstimo........ %d/", data_atual->tm_mday);
        printf("%d/", data_atual->tm_mon+1);
        printf("%d\n", data_atual->tm_year+1900);
        printf("Hora ....................: %d:",data_atual->tm_hour);
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

        printf("\nData para entrega........ %d/", data_entrega->tm_mday);
        printf("%d/", data_entrega->tm_mon+1);
        printf("%d\n", data_entrega->tm_year+1900);
        printf("Hora ...................: %d:",data_entrega->tm_hour);
        printf("%d:",data_entrega->tm_min);
        printf("%d\n",data_entrega->tm_sec);

        setbuf(stdin, NULL);

        gravaEmprestimo(emprestar);

    }

    printf("\n\nDigite qualquer coisa e tecle ENTER para continuar.\n");
    scanf(" %c",&op2);

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
    printf("\n []D - Alterar login");
    printf("\n []E - Alterar senha");
    printf("\n []F - Alterar endereço");
    printf("\n []G - Alterar CPF");
    printf("\n []H - Alterar Data de nascimento");
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

void alteraLogin(void) {

    FILE* fp;
    Pes* cadastro_pess;

    fp = fopen("pessoas.dat", "r+b");

    char a;

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    cadastro_pess = (Pes*) malloc(sizeof(Pes));

    printf("\n Informe o novo login: ");
    scanf(" %100[^\n]", cadastro_pess->login);

    fseek(fp, (-1)*sizeof(Pes), SEEK_CUR);
    fwrite(cadastro_pess, sizeof(Pes), 1, fp);

    printf("\nInformação editada com sucesso!\n");
    printf(" Digite qualquer coisa e tecle ENTER para continuar.\n");
    scanf(" %c",&a);

    free(cadastro_pess);
    fclose(fp);

}

void alteraSenha(void) {

    FILE* fp;
    Pes* cadastro_pess;

    fp = fopen("pessoas.dat", "r+b");

    char a;

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    cadastro_pess = (Pes*) malloc(sizeof(Pes));

    printf("\n Informe a nova senha: ");
    scanf(" %100[^\n]", cadastro_pess->senha);

    fseek(fp, (-1)*sizeof(Pes), SEEK_CUR);
    fwrite(cadastro_pess, sizeof(Pes), 1, fp);

    printf("\nInformação editada com sucesso!\n");
    printf(" Digite qualquer coisa e tecle ENTER para continuar.\n");
    scanf(" %c",&a);

    free(cadastro_pess);
    fclose(fp);

}

void editaPessoa(void) {

    FILE* fp;
    Pes* cadastro_pess;
    int achou;
    char a;
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
    printf("\n\n Informe o nome da pessoa a ser alterada: ");
    scanf(" %100[^\n]", procurado);

    cadastro_pess = (Pes*) malloc(sizeof(Pes));

    achou = 0;

    while((!achou) && (fread(cadastro_pess, sizeof(Pes), 1, fp))) {

        if ((strcmp(cadastro_pess->nome, procurado) == 0) && (cadastro_pess->status == '1')) {

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
                    printf("Digite qualquer coisa e tecle ENTER para continuar.\n");
                    scanf(" %c",&a);
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
                    printf(" Digite qualquer coisa e tecle ENTER para continuar.\n");
                    scanf(" %c",&a);
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
                    printf(" Digite qualquer coisa e tecle ENTER para continuar.\n");
                    scanf(" %c",&a);
                    break;

                case 'D':
                    printf(" Informe o novo login: ");
                    scanf(" %50[^\n]", cadastro_pess->login);

                    while(validaNome(cadastro_pess->login)==0) {
                        printf(" Insira um login válido: ");
                        scanf(" %50[^\n]", cadastro_pess->login);
                    }
                    fseek(fp, (-1)*sizeof(Pes), SEEK_CUR);
                    fwrite(cadastro_pess, sizeof(Pes), 1, fp);

                    printf("\n Informação editada com sucesso!\n");
                    printf(" Digite qualquer coisa e tecle ENTER para continuar.\n");
                    scanf(" %c",&a);
                    break;

                case 'E':
                    printf(" Informe a nova senha: ");
                    scanf(" %50[^\n]", cadastro_pess->senha);

                    while(validaNome(cadastro_pess->senha)==0) {
                        printf(" Insira uma senha válida: ");
                        scanf(" %50[^\n]", cadastro_pess->senha);
                    }
                    fseek(fp, (-1)*sizeof(Pes), SEEK_CUR);
                    fwrite(cadastro_pess, sizeof(Pes), 1, fp);

                    printf("\n Informação editada com sucesso!\n");
                    printf(" Digite qualquer coisa e tecle ENTER para continuar.\n");
                    scanf(" %c",&a);
                    break;

                case 'F':
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
                            printf(" Digite qualquer coisa e tecle ENTER para continuar.\n");
                            scanf(" %c",&a);
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
                            printf(" Digite qualquer coisa e tecle ENTER para continuar.\n");
                            scanf(" %c",&a);
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
                            printf(" Digite qualquer coisa e tecle ENTER para continuar.\n");
                            scanf(" %c",&a);
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
                            printf(" Digite qualquer coisa e tecle ENTER para continuar.\n");
                            scanf(" %c",&a);
                            break;

                        }

                    } while (resp != 'S');

                    break;

                case 'G':
                    printf("\n Insira o novo CPF - (SOMENTE NÚMEROS): ");
                    scanf(" %15[^\n]", cadastro_pess->cpf);
                    setbuf(stdin, NULL);

                    while((validaCPF(cadastro_pess->cpf)==0)) {
                        printf(" Insira o CPF válido ou que não esteja cadastrado- (SOMENTE NÚMEROS)\n  >>>>>:");
                        scanf(" %15[^\n]", cadastro_pess->cpf);
                        setbuf(stdin, NULL);
                    }
                    fseek(fp, (-1)*sizeof(Pes), SEEK_CUR);
                    fwrite(cadastro_pess, sizeof(Pes), 1, fp);
                    printf("\n Informação editada com sucesso!\n");
                    break;

                case 'H':
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
                    printf(" Digite qualquer coisa e tecle ENTER para continuar.\n");
                    scanf(" %c",&a);

                }

            } while(op != 'S');

        }

        free(cadastro_pess);
        fclose(fp);

    }

}

void editaLivro(void) {

    FILE* fp;
    Livro* livro;
    int achou;
    char a;
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
    printf("\n\n Informe o nome do livro a ser alterado: ");
    scanf(" %100[^\n]", procurado);

    livro = (Livro*) malloc(sizeof(Livro));

    achou = 0;

    while((!achou) && (fread(livro, sizeof(Livro), 1, fp))) {

        if ((strcmp(livro->nome, procurado) == 0) && (livro->status == '1')) {

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
                    printf("Digite qualquer coisa e tecle ENTER para continuar.\n");
                    scanf(" %c",&a);
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
                    printf(" Digite qualquer coisa e tecle ENTER para continuar.\n");
                    scanf(" %c",&a);
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
                    printf(" Digite qualquer coisa e tecle ENTER para continuar.\n");
                    scanf(" %c",&a);
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
                    printf(" Digite qualquer coisa e tecle ENTER para continuar.\n");
                    scanf(" %c",&a);
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
                    printf(" Digite qualquer coisa e tecle ENTER para continuar.\n");
                    scanf(" %c",&a);
                    break;

                case 'F':
                    printf(" Informe a nova edição: ");
                    scanf(" %100[^\n]", livro->edicao);
                    while(validaNome(livro->edicao)==0) {
                        printf(" Insira uma edição válida: ");
                        scanf(" %100[^\n]", livro->edicao);
                        setbuf(stdin, NULL);
                    }
                    fseek(fp, (-1)*sizeof(Livro), SEEK_CUR);
                    fwrite(livro, sizeof(Livro), 1, fp);
                    printf("\n Informação editada com sucesso!\n");
                    printf(" Digite qualquer coisa e tecle ENTER para continuar.\n");
                    scanf(" %c",&a);
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
                    printf(" Digite qualquer coisa e tecle ENTER para continuar.\n");
                    scanf(" %c",&a);
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
    printf(" Login: %s \n", cadastro_pess->login);
    printf(" Senha: %s \n", cadastro_pess->senha);
    printf(" Telefone: %s \n", cadastro_pess->tel);

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

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>    USUÁRIOS CADASTRADOS   <<<");
    printf("\n ================================= \n");

    cadastro_pess = (Pes*) malloc(sizeof(Pes));

    while(fread(cadastro_pess, sizeof(Pes), 1, fp)) {

        if(cadastro_pess->status == '1') {

            exibePessoa(cadastro_pess);

        }

    }

    fclose(fp);
    free(cadastro_pess);

    printf(" Digite algo e tecle ENTER para continuar.\n");
    scanf(" %c",&a);

}

void listaLivros(void) {

    char a;

    system("clear");

    FILE* fp;
    Livro* livro;

    fp = fopen("livros.dat", "rb");

    if (fp == NULL) {

        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");

        exit(1);

    }

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>    ACERVO DA BIBLIOTECA   <<<");
    printf("\n ================================= \n");

    livro = (Livro*) malloc(sizeof(Livro));

    while(fread(livro, sizeof(Livro), 1, fp)) {

        if(livro->status == '1') {

            exibeLivro(livro);

        }

    }

    fclose(fp);
    free(livro);

    printf(" Digite algo e tecle ENTER para continuar.\n");
    scanf(" %c",&a);

}

void gravaPessoa(Pes* pes) {

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
    Pes* cadastro_pess;

    cadastro_pess = (Pes*) malloc(sizeof(Pes));

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>    CADASTRO DE USUÁRIO    <<<");
    printf("\n =================================");

    do {
        printf("\n Insira o CPF - (SOMENTE NÚMEROS): ");
        scanf(" %15[^\n]", cadastro_pess->cpf);
        setbuf(stdin, NULL);
        while((validaCPF(cadastro_pess->cpf)==0)) {
            printf(" Insira o CPF válido ou que não esteja cadastrado- (SOMENTE NÚMEROS)\n  >>>>>:");
            scanf(" %15[^\n]", cadastro_pess->cpf);
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

        printf("\n Insira o login: ");
        scanf(" %50[^\n]", cadastro_pess->login);
        while(validaLetrasNumeros(cadastro_pess->login)==0) {
            printf(" Insira um login válido: ");
            scanf(" %50[^\n]", cadastro_pess->login);
        }

        printf("\n Insira a senha: ");
        scanf(" %50[^\n]", cadastro_pess->senha);
        while(validaLetrasNumeros(cadastro_pess->senha)==0) {
            printf(" Insira uma senha válida: ");
            scanf(" %50[^\n]", cadastro_pess->senha);
        }

        gravaPessoa(cadastro_pess);

        printf("\n Deseja cadastrar outra pessoa? (S/N)\n >>>>: ");
        scanf(" %c", &resp);

    } while((resp == 'S'));

}

void gravaLivro(Livro* livro) {

    FILE* fp;

    livro->status = '1';

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
    scanf(" %99[^\n]", livro->edicao);
    while(validaEdicao(livro->edicao) == 0) {
        printf(" Insira um nome válido para a edição: ");
        scanf(" %99[^\n]", livro->edicao);
    }

    printf("\n Insira o preço do livro (Para fins de multa em caso da perda do livro por parte do usuário): ");
    scanf(" %3[^\n]", livro->preco);
    while(validaPreco(livro->preco) == 0) {
    	printf("\n Insira um preço válido para o livro: ");
    	scanf(" %3[^\n]", livro->preco);
    }

    char resp;

    exibeLivro(livro);

    printf(" Digite qualquer coisa e tecle ENTER para continuar.\n");
    scanf(" %c", &resp);

    gravaLivro(livro);

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
    printf("\n");

}

void buscaPessoa(void) {

    FILE* fp;
    Pes* cadastro_pess;
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

    cadastro_pess = (Pes*) malloc(sizeof(Pes));

    achou = 0;

    while((!achou) && (fread(cadastro_pess, sizeof(Pes), 1, fp))) {

        if ((strcmp(cadastro_pess->nome, procurado) == 0) && (cadastro_pess->status == '1')) {

            achou = 1;

        }

    }

    fclose(fp);

    if (achou) {

        exibePessoa(cadastro_pess);

    } else {

        printf("\n %s não foi encontrado(a)...\n", procurado);

    }

    printf("\n Digite algo e tecle ENTER para continuar.\n\n");
    scanf(" %c", &resp);

    free(cadastro_pess);

}

void buscaLivro(void) {

    FILE* fp;
    Livro* livro;
    int achou;
    char procurado[100];
    char resp;

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
    printf("\n >>>        BUSCA LIVRO        <<<");
    printf("\n =================================");
    printf("\n");

    printf(" Informe o nome do livro a ser buscado: ");
    scanf(" %100[^\n]", procurado);

    livro = (Livro*) malloc(sizeof(Livro));

    achou = 0;

    while((!achou) && (fread(livro, sizeof(Livro), 1, fp))) {

        if ((strcmp(livro->nome, procurado) == 0) && (livro->status == '1')) {

            achou = 1;

        }

    }

    fclose(fp);

    if (achou) {

        exibeLivro(livro);

    } else {

        printf("\n %s não foi encontrado(a)...\n", procurado);

    }

    printf("\n Digite algo e tecle ENTER para continuar.\n\n");
    scanf(" %c", &resp);

    free(livro);

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

    printf(" Informe o nome da pessoa a ser removida: ");
    scanf(" %100[^\n]", procurado);

    cadastro_pess = (Pes*) malloc(sizeof(Pes));

    achou = 0;

    while((!achou) && (fread(cadastro_pess, sizeof(Pes), 1, fp))) {

        if ((strcmp(cadastro_pess->nome, procurado) == 0) && (cadastro_pess->status == '1')) {

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

    printf(" Informe o nome do livro a ser removido: ");
    scanf(" %100[^\n]", procurado);

    livro = (Livro*) malloc(sizeof(Livro));

    achou = 0;

    while((!achou) && (fread(livro, sizeof(Livro), 1, fp))) {

        if ((strcmp(livro->nome, procurado) == 0) && (livro->status == '1')) {

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
    char loginU[50] = "teste";
    char senhaU[50] = "teste";
    char login1[50];
    char senha1[50];

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
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
        printf("\n | | |  Programa Biblioteca  | | |");
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
    char op;
    char op2;

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
        printf(" []D - Logs e Relatórios\n");
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
                    buscaLivro();
                    break;

                case 'C':
                    listaLivros();
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

    } while(resp != 'S');

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
    printf(" []C - Listar pessoas cadastradas\n");
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
    printf(" []C - Listar livros cadastrados\n");
    printf(" []D - Excluir livros\n");
    printf(" []E - Editar livro\n");
    printf(" []S - Sair\n");

}

void menuUser() {

    char resp;

    do {
        system("clear");

        printf("\n =================================");
        printf("\n | | |  Programa Biblioteca  | | |");
        printf("\n =================================");
        printf("\n >>>        MENU USUÁRIO       <<<\n");
        printf("\n =================================\n");
        printf("\n\n []A - Exibir todos os livros do acervo\n");
        printf(" []B - Pesquisar livro no acervo\n");
        printf(" []C - Gerenciar empréstimos\n");
        printf(" []D - Redefinir dados pessoais\n");
        printf(" []S - Deslogar\n");

        printf("\n\n Escolha uma opção: ");
        scanf(" %c", &resp);

        resp = maius(resp);

        switch(resp) {

        case 'A':
            listaEmprestimos();
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

    } while(resp != 'S');

}

void menuGerenciarEmprestimos(void) {

    system("clear");

    printf("\n =================================");
    printf("\n | | |  Programa Biblioteca  | | |");
    printf("\n =================================");
    printf("\n >>>   GERENCIAR EMPRÉSTIMOS   <<<");
    printf("\n =================================");
    printf("\n []A - Emprestar Livro");
    printf("\n []B - Devolução de Livro");
    printf("\n []S - Voltar ao Menu do Administrador");

}

void menuLog(){
	
  char resp;

  do {
    
    system("clear");

    printf("\n =================================");
    printf("\n | | | Programa Biblioteca | | | ");              
    printf("\n =================================");
    printf("\n >>>>>>>> MENU RELATÓRIOS <<<<<<<<");
    printf("\n ================================="); 
    printf("\n []A - Histórico de todos os logins no sistema");
    printf("\n []B - Histórico de todos os empréstimos");
    printf("\n []C - Histórico de todos os empréstimos de um usuário");
    printf("\n []S - Voltar ao Menu do Administrador");
    
    printf("\n Escolha uma opção: ");
    scanf(" %c", &resp);
    resp = maius(resp);

    switch(resp) {
      
      case 'A':
      break;
      
      case 'B':
        listaEmprestimos();
      break;
        
      case 'C':
        break;
      
      case 'S':
        break;
        
    }
    
  }while(resp != 'S');

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
        } else {
            menuUser();
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

int verificaCPF(char procurado[12]) {

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

int verifica_cpf_emprestimo(char procurado[12]) {

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

    fp = fopen("pessoas.dat", "rb");

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

        printf("\nNome cadastrado com este CPF: %s\n", cadastro_pess->nome);

        strcpy(emprestimo->nome, cadastro_pess->nome);

    }

    fclose(fp);
    free(cadastro_pess);

}

int verifica_matricula_emprestimo(char procurado[13]) {

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

    fp = fopen("livros.dat", "rb");

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

        printf("\nNome do livro cadastrado com esta matricula: %s", livro->nome);
        printf("\nISBN do livro cadastrado com esta matricula: %s\n", livro->isbn);

        strcpy(emprestimo->nomeLiv, livro->nome);
        strcpy(emprestimo->isbn, livro->isbn);

    }

    fclose(fp);
    free(livro);

}

int verifica_matricula(char procurado[13]) {

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
    Emprestimo* devolve;
    int achou;
    char resp;
    char matricula[13];

    fp = fopen("emprestimos.dat", "r+b");

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
    scanf(" %100[^\n]", matricula);

    devolve = (Emprestimo*) malloc(sizeof(Emprestimo));

    achou = 0;

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

            devolve->status = '0';

            fseek(fp, -1 * sizeof(Emprestimo), SEEK_CUR);
            fwrite(devolve, sizeof(Emprestimo), 1, fp);

            printf("\nLivro devolvido com sucesso!\n");

        } else {

            printf("\n Ok, os dados não foram alterados\n");

        }

    } else {

        printf(" Matricula %s não foi encontrada...\n", matricula);

    }

    printf("\n Digite algo e tecle ENTER para continuar...\n");
    scanf(" %c", &resp);

    fclose(fp);
    free(devolve);

}
