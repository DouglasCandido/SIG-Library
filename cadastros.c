#include <stdio.h>
#include <stdlib.h>

int main(void){
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
}
