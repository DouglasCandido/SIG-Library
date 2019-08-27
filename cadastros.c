#include <stdio.h>

int cadastroPess(){
    int cpf,dataNasc, tel;
    char nome[200], ender[200], numCasa[100];

    printf("Insira seu nome completo: ");
    scanf("%[^\n]s", nome);

    printf("\nInsira seu CPF: ");
    scanf("%d", &cpf);

    printf("\nInsira sua data de nascimento: ");
    scanf("%d", &dataNasc);

    printf("\nInsira seu número para contato: ");
    scanf("%d",&tel);

    printf("\nInsira seu endereço - BAIRRO e CIDADE: ");
    scanf(" %[^\n]s", ender);

    printf("\nInsira o número da sua casa: ");
    scanf(" %[^\n]s", numCasa);

    return 0;
}

int cadastroLiv(){
    int isbn;
    char nomeLiv[200], autor[200], genero[100], editora[100], edicao[100];

    printf("Insira o nome do livro: ");
    scanf("%[^\n]s",nomeLiv);

    printf("Insira o nome do autor: ");
    scanf("%[^\n]s",autor);

    printf("Insira o gênero do livro: ");
    scanf("%[^\n]s",genero);
    
    printf("Insira a editora do livro: ");
    scanf("%[^\n]s",editora);

    printf("Insira a edição do livro: ");
    scanf("%[^\n]s",edicao);

    return 0;
}
