#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>
#include "validations.h"
#include "telas.h"

int validaMatr(char matricula[12]) {

    regex_t reg;

    if (verifica_matricula(matricula) == 0) {

        return 0;

    }

    if((strlen(matricula)) > 12 && strlen(matricula) < 12) {

        return 0;

    } else {

        if(regcomp(&reg, RE_MATR, REG_EXTENDED|REG_NOSUB) != 0) {

            return 0;

        } else {

            if((regexec(&reg, matricula, 0, (regmatch_t*)NULL, 0)) == 0) {

                return 1;

            } else {

                return 0;

            }

        }

    }

}

char maius(char r) {

    char letra;

    letra = toupper(r);

    return letra;

}

int validaEmail(char email[30]) {

    regex_t reg;

    if((strlen(email)) > 30) {

        return 0;

    } else {

        if(regcomp(&reg, RE_EMAIL, REG_EXTENDED|REG_NOSUB) != 0) {

            return 0;

        } else {

            if((regexec(&reg, email, 0, (regmatch_t*)NULL, 0)) == 0) {

                return 1;

            } else {

                return 0;

            }

        }

    }

}

int validaTelefone(char tel[12]) { 

    regex_t reg;

    if((strlen(tel)) > 12 && strlen(tel) < 12) {

        return 0;

    } else {

        if(regcomp(&reg, RE_TEL, REG_EXTENDED|REG_NOSUB) != 0) {

            return 0;

        } else {

            if((regexec(&reg, tel, 0, (regmatch_t*)NULL, 0)) == 0) {

                return 1;

            } else {

                return 0;

            }

        }

    }

}

int validaCPF(char cpf[11]) { 

    int cpfTrans[11], soma = 0, dig1, res1, res2, dig2, restante;

    if(strlen(cpf) > 11) {

        return 0;

    } 

    else if(strcmp(cpf, "00000000000") == 0) {

        return 0;

    }

    else if(strcmp(cpf, "11111111111") == 0) {

        return 0;

    }

    else if(strcmp(cpf, "22222222222") == 0) {

        return 0;

    }

    else if(strcmp(cpf, "33333333333") == 0) {

        return 0;

    }

    else if(strcmp(cpf, "44444444444") == 0) {

        return 0;

    }

    else if(strcmp(cpf, "55555555555") == 0) {

        return 0;

    }

    else if(strcmp(cpf, "66666666666") == 0) {

        return 0;

    }

    else if(strcmp(cpf, "77777777777") == 0) {

        return 0;

    }

    else if(strcmp(cpf, "88888888888") == 0) {

        return 0;

    }

    else if(strcmp(cpf, "99999999999") == 0) {

        return 0;

    }

    else if(verificaCPF(cpf) == 0) {

        return 0;

    } else {

        for(int i = 0; i < 11 ; i++) {

            cpfTrans[i] = cpf[i]-48;

        }

        for(int i = 0; i < 9 ; i++) {

            soma += cpfTrans[i]*(10-i);

        }

        res1 = soma % 11;

        if((res1 == 0) || (res1 == 1)) {

            dig1 = 0;

        } else {

            dig1 = 11 - res1;

        }


        soma = 0;

        for(int i = 0; i < 10 ; i++) {

            soma += cpfTrans[i]*(11-i);

        }

        restante = (soma/11) * 11;
        res2 = soma - restante;

        if((res2 == 0) || (res2 == 1)) {
            dig2 = 0;

        } else {

            dig2 = 11 - res2;

        }

        if((dig1 == cpfTrans[9]) && (dig2 == cpfTrans[10])) {

            return 1;

        }

        return 0;

    }

}

int validaNome(char nome[100]) {

    regex_t reg;

    if((strlen(nome)) > 100) {

        return 0;

    } else {

        if(regcomp(&reg, RE_NAME, REG_EXTENDED|REG_NOSUB) != 0) {

            return 0;

        } else {

            if((regexec(&reg, nome, 0, (regmatch_t*)NULL, 0)) == 0) {

                return 1;

            } else {

                return 0;

            }

        }

    }

}

int validaISBN(char isbn[17]) {

    regex_t reg;

    if((strlen(isbn)) > 17 && strlen(isbn) < 17) {

        return 0;

    } else {

        if(regcomp(&reg, RE_ISBN, REG_EXTENDED|REG_NOSUB) != 0) {

            return 0;

        } else {

            if((regexec(&reg, isbn, 0, (regmatch_t*)NULL, 0)) == 0) {

                return 1;

            } else {

                return 0;

            }

        }

    }

}

int validaLetrasNumeros(char string[100]) {

    regex_t reg;

    if((strlen(string)) > 100) {

        return 0;

    } else {

        if(regcomp(&reg, RE_MIX, REG_EXTENDED|REG_NOSUB) != 0) {

            return 0;

        } else {

            if((regexec(&reg, string, 0, (regmatch_t*)NULL, 0)) == 0) {

                return 1;

            } else {

                return 0;

            }

        }

    }

}

int bissexto(int ano) {

    if((ano % 4 == 0) && (ano % 100 != 0)) {

        return 1;

    } else if(ano % 400 == 0) {

        return 1;

    } else {

        return 0;

    }

}

int validaData(int dia, int mes, int ano) {

    int maiorDia;

    if(ano < 0 || mes < 1 || mes > 12) {

        return 0;

    }

    if(mes == 2) {

        if(bissexto(ano)) {

            maiorDia = 29;

        } else {

            maiorDia = 28;

        }

    } else if(mes == 4 || mes == 6 || mes == 9 || mes == 11) {

        maiorDia = 30;

    } else {

        maiorDia = 31;

    }

    if(dia < 1 || dia > maiorDia) {

        return 0;

    }

    return 1;

}

int validaPreco(char preco[3]) {

    regex_t reg;

    if(strlen(preco) > 3) {

        return 0;

    }

    else {

        if(regcomp(&reg, RE_NUMBER, REG_EXTENDED|REG_NOSUB) != 0) {

            return 0;

        } else {

            if((regexec(&reg, preco, 0, (regmatch_t*)NULL, 0)) == 0) {

                return 1;

            } else {

                return 0;

            }

        }

    }

}

int validaEdicao(char edicao[2]) {

    regex_t reg;

    if(strlen(edicao) > 2) {

        return 0;

    }

    else {

        if(regcomp(&reg, RE_NUMBER, REG_EXTENDED|REG_NOSUB) != 0) {

            return 0;

        } else {

            if((regexec(&reg, edicao, 0, (regmatch_t*)NULL, 0)) == 0) {

                return 1;

            } else {

                return 0;

            }

        }

    }

}

int clean_stdin() {

    while(getchar() != '\n');

    return 1;

}

