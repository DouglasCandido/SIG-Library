typedef struct pes Pes;

struct pes {
  int dia;
  int mes; 
  int ano;
  int numero_uf;
  int uf;
  char nome[100];
  char enderCid[100];
  char enderBair[100];
  char numCasa[50];
  char cpf[14];
  char tel[15];
  char email[30];
  char *estados[27][2];
  char c;

};

void listaPessoas(void);
void exibePessoas(Pes* cadastro_pess);


void exibePessoas(Pes* cadastro_pess) {
  printf("Nome: %s\n", cadastro_pess->nome);
  printf("Cidade: %s\n", cadastro_pess->enderCid);
  printf("Bairro: %s\n", cadastro_pess->enderBair);
  printf("Numero da casa: %s\n", cadastro_pess->numCasa);
  printf("Email: %s\n", cadastro_pess->email);
  printf("CPF: %s\n", cadastro_pess->cpf);
  printf("Telefone: %s\n", cadastro_pess->tel);
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
  while(fread(cadastro_pess, sizeof(Pes), 1, fp)) {
    exibePessoas(cadastro_pess);    
  }
  fclose(fp);
  free(cadastro_pess);

  printf("Digite algo e tecle ENTER para continuar.\n");
  scanf(" %c",a);

}

void gravaPessoas(Pes* pes) {
  FILE* fp;
  fp = fopen("pessoas.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  fwrite(pes, sizeof(Pes), 1, fp);
  fclose(fp);
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
    while(validaCPF(cadastro_pess->cpf)==0){
      printf(" Insira um CPF válido - xxx.xxx.xxx-xx: ");
      scanf(" %99[^\n]", cadastro_pess->cpf);
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
}











