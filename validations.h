// Expressões regulares utilizadas nas validações dos campos dos cadastros:

#define RE_EMAIL ".+@.+\\.[a-z]+" 
#define RE_TEL "[0-9]{2}-([0-9]{8}|[0-9]{9})"
#define RE_ISBN "^[0-9]{3}\\-[0-9]{2}\\-[0-9]{3}\\-[0-9]{4}\\-[0-9]{1}$"
#define RE_MATR "^[0-9]{12}$"
#define RE_COD_EMP "^[0-9]{10}$"
#define RE_NUMBER "[0-9*]"
#define RE_NAME "[A-Z a-z A-ZàáâäãåąčćęèéêëėįìíîïłńòóôöõøùúûüųūÿýżźñçčšžÀÁÂÄÃÅĄĆČĖĘÈÉÊËÌÍÎÏĮŁŃÒÓÔÖÕØÙÚÛÜŲŪŸÝŻŹÑßÇŒÆČŠŽ∂ð'*]$"
#define RE_MIX "[A-ZàáâäãåąčćęèéêëėįìíîïłńòóôöõøùúûüųūÿýżźñçčšžÀÁÂÄÃÅĄĆČĖĘÈÉÊËÌÍÎÏĮŁŃÒÓÔÖÕØÙÚÛÜŲŪŸÝŻŹÑßÇŒÆČŠŽ∂ð' a-z 0-9*]$"
// #define RE_CPF "^[0-9]{3}\\.[0-9]{3}\\.[0-9]{3}\\-[0-9]{2}$"

char maius(char r); // Essa função é responsável por converter letras minúsculas em maiúsculas para casos de validação de entradas.
int validaEmail(char email[30]); // Essa função é responsável por validar o campo email no cadastro do usuário.
int validaTelefone(char tel[12]); // Essa função é responsável por validar o campo telefone no cadastro do usuário.
int validaCPF(char cpf[11]); // Essa função é responsável por validar o campo CPF no cadastro do usuário.
int validaCodigoEmprestimo(char cod[10]); // Essa função é responsável por validar o campo código no cadastro do empréstimo.
int validaNome(char nome[100]); // Essa função é responsável por validar o campo nome em ambos os cadastros.
int validaISBN(char isbn[17]); // Essa função é responsável por validar o campo ISBN no cadastro do livro.
int validaLetrasNumeros(char string[100]); // Essa função é responsável por validar o campo editora no cadastro do livro.
int validaEdicao(char edicao[2]); // Essa função é responsável por validar o campo edição no cadastro do livro.
int bissexto(int ano); // Essa função é responsável por validar se o ano é ou não é bissexto.
int validaData(int dia, int mes, int ano); // Essa função é responsável por validar a data inserida no cadastro.
int validaMatr(char matricula[12]); // Essa função é responsável por validar a matrícula no cadastro do livro.
int clean_stdin(void); // Essa função é utilizada para fins de controle do buffer de entrada de dados do teclado.



