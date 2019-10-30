#include <stdio.h>


int validaCPF(char cpf[12]){  
   
int cpfTrans[12], soma = 0, dig1, res1, res2, dig2, restante;  

  
  
for(int i = 0; i < 11 ; i++){  
	cpfTrans[i] = cpf[i]-48;  

}  
 
  
for(int i = 0; i < 9 ;i++){  
	soma += cpfTrans[i]*(10-i);  

	}  
  
res1 = soma % 11;  
  
if((res1 == 0) || (res1 == 1)){  
	dig1 = 0;  

	}else{  
		dig1 = 11 - res1;  
	
	}  
   
  
soma = 0;  
  
for(int i = 0; i < 10 ;i++){  
soma += cpfTrans[i]*(11-i);  

	}  
  
restante = (soma/11) * 11;  
res2 = soma - restante;  
  
if((res2 == 0) || (res2 == 1)){  
dig2 = 0;  

	}else{  
		dig2 = 11 - res2;  

	}  
  
  
if((dig1 == cpfTrans[9]) && (dig2 == cpfTrans[10])){  
return 1;

	}return 0;     

}  




int main(void){

	char cpf[12];

	printf("Digite o CPF: ");  
	scanf(" %[^\n]s",cpf); 
	while (validaCPF(cpf) == 0){
		printf("Digite o CPF: ");  
		scanf(" %[^\n]s",cpf);
	}	
}