int gerEmprestimo(){
  int resp;
    system('clear');

    printf("\n=================================");
    printf("\n | | | Programa biblioteca | | | ");                  
    printf("\n=================================");
    printf("\n>>>>> GERENCIAR EMPRÉSTIMOS <<<<<");
    printf("\n=================================");
    printf("\n\n[]1 - Emprestar Livro");
    printf("\n[]2 - Devolução de Livro");
    printf("\n[]3 - Relatório");
    printf("\n[]4 - Voltar ao Menu administrador");

    printf("\n\nEscolha uma opção: ");
    scanf(" %c", &resp);

    printf("\n");

    return resp;
}

int menuRelatorio(){
  int resp;
    system('clear');

 printf("\n=================================");
 printf("\n | | | Programa biblioteca | | | ");              
 printf("\n=================================");
 printf("\n>>>>>>>> MENU RELATÓRIO <<<<<<<<");
 printf("\n================================="); 
 printf("\n\n[0] - Relatório Emprestimos");
 printf("\n[1] - Voltar ao Menu administrador");
 printf("\n[2] - Histórico de todos os empréstimos");

  printf("\n\nEscolha uma opção: ");
  scanf(" %c", &resp);

  printf("\n");

  return resp;
  }

int redefinirUsu(){
  int resp;
    system('clear');
      printf("\n=================================");
      printf("\n| | | Programa biblioteca | | |");                      
      printf("\n=================================");
      printf("\n>>> Alterar usuário ou senha <<<");
      printf("\n=================================");
      printf("\n\n[]1 - Alterar nome de Usuário");              
      printf("\n[]2 - Alterar senha"); 
      printf("\n[]3 - Sair");

      printf("\n\nEscolha uma opção: ");
      scanf(" %c", &resp);

      printf("\n");

      return resp;
}

