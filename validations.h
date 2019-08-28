#define RE_EMAIL ".+@.+\\.[a-z]+" 
#define RE_TEL "[0-9]{2}-([0-9]{8}|[0-9]{9})"

char maius(char r); // Essa função é responsável por converter letras minúsculas em maiúsculas para casos de validação de entradas.
int validaEmail(char email[30]);
int validaTelefone(char tel[15]);

