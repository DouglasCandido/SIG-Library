void ListaDeLivros(void);
char menuPrincipal(void); // Essa função é chamada para apresentar o Menu Principal.
int login(void); // Essa função é chamada para validar o login.
void menuAdmin(void); // Essa função é chamada para apresentar o Menu exclusivo do administrador.
void menuGerenciarEmprestimos(void); // Essa função é chamada para apresentar o Menu Gerenciar Empréstimos.
void sobre(void); // Essa função é chamada para apresentar o Menu Sobre.
char sair(void); // Essa função é chamada toda vez que o usuário deseja sair do sistema.
void cadastroLivro(void); // Essa função é responsável por cadastrar um novo livro no acervo da nossa biblioteca.
void cadastroPessoa(void); // Essa função é responsável por cadastrar novos usuários.
void gerenciarPessoas(void); //Essa função é chamada para gentenciar todas as informações de pessoas.
void gerenciarLivros(void); //Essa função é chamada para gentenciar todas as informações de livros.
void buscaPessoa(void); //Essa função é responsavel por buscar pessoas específicas.
void excluiPessoa(void); // Essa função é usada para excluir pessoas.
void editaPessoa(void); // Essa função é usada para editar informações pessoas.
void listaPessoas(void); // Esta função é usada para mostrar todas as pessoas cadastradas.
void exibeEstados(void); // Essa função é usada para exibir todos os estados.
void menuEditaPessoa(void); // Essa função é usada para exibir uma tela de menu de editar informações.
void menuEditaEndereco(void); // Essa função é usada para alterar o endereço de um usuário.
int starter(); // Essa função responsável por controlar a inicialização de todos os menus.
void emprestimo(void); // Essa função é responsável por tratar do empréstimo de um livro para um leitor.
int verifica_cpf_emprestimo(char cpf[11]); // Essa função verifica se o CPF referente ao usuário já existe, no processo de empréstimo de livros.
int verifica_matricula_emprestimo(char procurado[12]); // Essa função verifica se a matrícula referente ao livro já existe no processo de empréstimo de livros.
int verifica_matricula(char procurado[12]); // Essa função verifica se a matrícula referente ao livro já existe, no processo de empréstimo de livros.
int verifica_telefone(char procurado[12]); // Essa função verifica se o telefone informado já existe, no processo de cadastro de um novo leitor.
void devolve_livro(void);  // Essa função é responsável por tratar da devolução de um livro em posse de um leitor.
void busca_especifica_livro(void);
void busca_especifica_pessoa(void);
void ListaDePessoas(void);
void menuListaEmprestimos(void);
int verificaCPF(char procurado[11]); // Essa função é responsável por verificar se o CPF já está cadastrado no arquivo.
int verificaCodigoEmprestimo(char procurado[10]); // Essa função é responsável por verificar se o código do empréstimo já está cadastrado no arquivo.