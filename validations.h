#define RE_EMAIL ".+@.+\\.[a-z]+" 
#define RE_TEL "^\\([1-9]{2}\\) (?:[2-8]|9[1-9])[0-9]{4}\\-[0-9]{4}$"

char maius(char r); // Essa função é responsável por converter letras minúsculas em maiúsculas para casos de validação de entradas.
int validaEmail(char email[30]);
int validaTelefone(char tel[15]);

