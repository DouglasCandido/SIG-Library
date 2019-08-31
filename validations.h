#define RE_EMAIL ".+@.+\\.[a-z]+" 
#define RE_TEL "[0-9]{2}-([0-9]{8}|[0-9]{9})"
#define RE_CPF "^[0-9]{3}\\.[0-9]{3}\\.[0-9]{3}\\-[0-9]{2}$"
#define RE_NAME  "[A-Z a-z*]$"
#define RE_ISBN "[0-9]{3}\\-[0-9]{2}\\-[0-9]{3}\\-[0-9]{4}\\-[0-9]{1}$"
#define RE_NUM "[A-Z a-z 0-9*]$"

char maius(char r); // Essa função é responsável por converter letras minúsculas em maiúsculas para casos de validação de entradas.
int validaEmail(char email[30]);
int validaTelefone(char tel[15]);
int validaCPF(char cpf[14]);
int validaNome(char nome[100]);
int validaCPF(char cpf[14]);
int validaISBN(char isbn[17]);
int validaEdt(char edit[100]);
int bissexto(int ano);
int validaData(int dia, int mes, int ano);
int clean_stdin(void); // Essa função é responsável por limpar o buffer.