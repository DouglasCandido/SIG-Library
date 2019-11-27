#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int contador;

void preencheVetor(int*, int);
void exibeVetor(int*, int);
int buscaLinear(int*, int, int);
void procuraNumeros(int*, int);

int main(void) {
  int n;
  int* v;

  srand(time(NULL));
  printf("Busca Linear\n");
  printf("Quantos elementos no vetor? ");
  scanf("%d", &n);
  v = (int*) malloc(n * sizeof(int));
  preencheVetor(v, n);
  exibeVetor(v, n);
  procuraNumeros(v, n);
  return 0;
}

void preencheVetor(int* v, int n) {
  for (int i = 0; i < n; i++) {
    v[i] = rand()%1000;
  }
} 

void exibeVetor(int* v, int n) {
  printf("Vetor gerado\n");
  for (int i = 0; i < n; i++) {
    printf("%4d", v[i]);
  }
  printf("\n");
}

int buscaLinear(int* v, int n, int num) {
  int  cont = 0;
  for (int i = 0; i < n; i++) {
    cont++;
    if (v[i] == num) {
      printf("Apos %d testes\n", cont);
      return i;
    }
  }
  return -1;
}

void procuraNumeros(int* v, int n) {
  int valor, pos;
  printf("Informe um valor a ser buscado: ");
  scanf("%d", &valor);
  pos = buscaLinear(v, n, valor);
  if (pos >= 0) {
    printf("O valor %d foi encontrado na posição %d\n", valor, pos);
  } else {
    printf("O valor %d não foi encontrado no vetor\n", valor);
  }
} 