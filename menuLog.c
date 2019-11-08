void menuLog(){
	
  char resp;
  char op;
  char op2;

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
        if((sair()) == 'S') {
          starter();
        } else {
          menuAdmin();
        }
        break;
        
    }
    
  }while(resp != 'S');

}

void exibeEmprestimo(Emprestimo* emprestimo) {
 
  // Falta a manipulação de data

  printf("\n\n Nome do leitor: %s \n", emprestimo->nome);
  printf(" CPF do leitor: %s \n", emprestimo->cpf);
  printf(" Nome do livro: %s \n", emprestimo->nomeLiv);
  printf(" ISBN do livro: %s \n", emprestimo->isbn);
  printf(" Matrícula do livro: %s \n", emprestimo->matricula);
  printf(" Data de realização do empréstimo: %s \n", );
  printf(" Data estimada de devolução: %s \n", );
  printf("\n");

}

void listaEmprestimos(void) {

  char a;
  system("clear");

  FILE* fp;
  Emprestimo* emprestimo;
  fp = fopen("emprestimo.dat", "rb");

  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  printf("\n");
  printf("\n =================================");
  printf("\n | | | Programa Biblioeteca  | | |");                      
  printf("\n =================================");
  printf("\n >>>>>>      EMPRÉSTIMOS     <<<<<<");
  printf("\n ================================= \n");

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