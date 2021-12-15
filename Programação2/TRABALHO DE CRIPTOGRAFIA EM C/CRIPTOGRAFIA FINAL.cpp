#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAM 5000

char * conversaoLeao(char * frase){
	char * cripto = (char*)malloc(TAM* sizeof(char));
	strcpy(cripto,""); 
	int maior,menor, subtracao;
	int i;
	maior =  frase[i];
	menor =  frase[i];
	for (i=0; i<strlen(frase);i++){
		if (int (frase[i]) >= maior){
			if (frase[i] >= 65 && frase[i] <= 122){
				maior = int (frase[i]);
			}
		} else { 
			if (int (frase[i]<menor)){
				if(frase[i] >= 65 && frase[i] <= 122){
					menor = int(frase[i]);
				}
			}	
		}	
	}
	subtracao = maior - menor;
	int digito = 0;
	char dig[1];
	itoa(digito,dig,10);
	char * frase2 = (char*)malloc(TAM * sizeof(char));
	if (subtracao == 1 || subtracao == 2 || subtracao == 3 || subtracao == 4 || subtracao == 5 || subtracao == 6 || subtracao == 7 || subtracao == 8 || subtracao == 9){
		strcat(frase,dig);
	}
	sprintf(frase2, "%d", subtracao);
	strcat(frase, frase2);
	return frase;
}

char * inversao(char * frase){
	int i, index = 0;
	char * cripto = (char*)malloc(TAM* sizeof(char));
	strcpy(cripto,""); 
	
	for(i=0; i<strlen(frase); i++){
   		cripto[i] = frase[strlen(frase)-i-1];   		
	}
	
	cripto[i] = '\0';       
	int tamString = strlen(cripto);
	int div = tamString/2;        
	char * partDois = (char*)malloc(TAM * sizeof(char));                          
	
	if (tamString % 2 == 0){
		for(i=div;i<tamString;i++){
			partDois[index] = cripto[i];
			index++; 
		}
		cripto[div] = '\0';
		partDois[index] = '\0';
		strcat(cripto, "LDP");
		strcat(cripto,partDois);
	}
	
	return cripto;
}

char * myfrn(char* frase){
	int i;
	char * cripto = (char*)malloc(TAM* sizeof(char));
	char frn1[100];
	strcpy(frn1, "");
	strcpy(cripto,"");
	
	for(i=0;i<strlen(frase);i++){
		if (frase[i] == 'a' || frase[i] =='m' || frase[i] == 'A' || frase[i] =='M'){
			strcat(frn1,"FRN");
	}
	 
	}
	strcat(frn1, frase);
	strcpy(cripto, frn1);
	return cripto;
}

char * massould(char * frase){
	int i, j = 0;
	char * cripto = (char*)malloc(TAM* sizeof(char));
	strcpy(cripto,""); 
	int tam_frase = strlen(frase);
	for(i=0;i<tam_frase;i++){
		if(frase[i] == 'P'){
			strcat(cripto, "M@ssoud");
			j = j + 7;
		}
		else if (frase[i] == 'a'){
			strcat(cripto, "M@ssoud1");
			j = j + 8;
		}
		else if (frase[i] == 'A'){
			strcat(cripto, "M@ssoud1P");
			j = j + 9;
		}
		else if (frase[i] == 'e'){
			strcat(cripto, "M@ssoud2");
			j = j + 8;
		}
		else if (frase[i] == 'E'){
			strcat(cripto, "M@ssoud2P");
			j = j + 9;
		}
		else if (frase[i] == 'i'){
			strcat(cripto, "M@ssoud3");
			j = j + 8;
		}
		else if (frase[i] == 'I'){
			strcat(cripto, "M@ssoud3P");
			j = j + 9;
		}
		else if (frase[i] == 'o'){
			strcat(cripto, "M@ssoud4");
			j = j + 8;
		}
		else if (frase[i] == 'O'){
			strcat(cripto, "M@ssoud4P");
			j = j + 9;
		}
		else if (frase[i] == 'u'){
			strcat(cripto, "M@ssoud5");
			j = j + 8;
		}
		else if (frase[i] == 'U'){
			strcat(cripto, "M@ssoud5P");
			j = j + 9;
		}
		else{
			cripto[j] = frase[i] ;
			j++;
			cripto[j] = '\0';
		}
	}
	return cripto;
}

void * lerDados(char * palavra){
	printf("\nInforme a String: "); 
	gets(palavra);
}

int qtd_espacos(char *str){
    int espacos = 0;
    while(*str){
        if (*str == ' '){
           espacos++;
        }
        str++;
    }
    return espacos;
}

char * juncao(char * frase){
	char * cripto = (char*)malloc(TAM* sizeof(char));
	strcpy(cripto,"");
	cripto = frase;
	cripto = massould(cripto);
	cripto = myfrn(cripto);
	cripto = inversao(cripto);
	cripto = conversaoLeao(cripto);
	return cripto;	
}

char * criptografaDados(char * frase, int estrategia){
	switch (estrategia){
		case 1: 
			return massould(frase);
		case 2:
			return myfrn(frase);
		case 3:
			return inversao(frase);
		case 4:
			return conversaoLeao(frase);
		case 5:
			return juncao(frase);
		break;
	}	
}

char * mostraCriptografia(char * frase){
    int i=0;
    int estrategia = 1;
    
    int qtd_strings = qtd_espacos(frase) + 1;
    char strings_separadas[qtd_strings][strlen(frase)];
    char *pch = strtok (frase," ");
    while (pch != NULL){
        strcpy(strings_separadas[i++], pch); //copiar cada string para a posição correta
        pch = strtok (NULL, " ");
    }
    
    char * strings_aux = (char *)malloc(TAM *sizeof(char));
    strcpy(strings_aux, "");
    
	int j = 0;
    
   	for (i = 0; i < qtd_strings;i++){
   		strcat(strings_aux, (criptografaDados(strings_separadas[i], estrategia)));
   		strcat(strings_aux, " ");
   		estrategia++;
   		if (estrategia > 5){
   			estrategia = 1;
		   }	 
	}
	int tamanho = strlen(strings_aux);
	strings_aux[tamanho - 1] = '\0';
	return strings_aux;
}

char * desconversaoLeao(char * criptografia){
	int tamFrase = strlen(criptografia) - 2;
	criptografia[tamFrase] = '\0';
	return criptografia;
}

char * desinversao(char * criptografia){
	char * parteDois = (char *)malloc(TAM *sizeof(char));
	char * descripto = (char *)malloc(TAM *sizeof(char));
	int i;
	int index = 0, aux1 = 0;
	int div = strlen(criptografia)/2;
	for(i=0; i<strlen(criptografia); i++){
		if(criptografia[i] == 'L' && criptografia[i+1] == 'D' && criptografia[i+2] == 'P'){
			for(aux1=div+2; aux1<strlen(criptografia); aux1++){
			parteDois[index] = criptografia[aux1];
			index++;	
			}
			criptografia[div - 1] = '\0';
			parteDois[index] = '\0';
			strcat(criptografia,parteDois);
		}
	}
	
	for(i=0; i<strlen(criptografia);i++){
		descripto[i] = criptografia[strlen(criptografia)-i-1];
	}
	descripto[i] = '\0';
	return descripto;
}

char * desmyfrn(char * criptografia){
	int i,count = 0, j=0, total;
	char * descripto = (char *)malloc(TAM *sizeof(char));
	strcpy(descripto, "");
	for(i=0;i<strlen(criptografia);i++){
		if (criptografia[i] == 'a' || criptografia[i] =='m' || criptografia[i] == 'A' || criptografia[i] =='M'){
			count += 1;
		}
	}
	
	total = count * 3;
	
	for(i=total;i<strlen(criptografia);i++){
		descripto[j] = criptografia[i];
		j++;
	}
	descripto[j] = '\0';
	return descripto;
}

char * desmassoud(char * criptografia){
	int i, j=0;
	char * cripto = (char*)malloc(TAM* sizeof(char));
	strcpy(cripto,"");
	int tam = strlen(criptografia);
	for(i=0;i<=tam;i++){
		if((criptografia[i] == 'M') && (criptografia[i+1] == '@')){
				if((criptografia[i+8] == 'P')){
					if((criptografia[i+7] == '1')){
						cripto[j] = 'A';
						j++;
						i += 8;
					}else if (criptografia[i+7] == '2'){
						cripto[j] = 'E';
						j++;
						i += 8;
					}else if (criptografia[i+7] == '3'){
						cripto[j] == 'I';
						j++;
						i += 8;
					}else if (criptografia[i+7] == '4'){
						cripto[j] = 'O';
						j++;
						i += 8;
					}else if (criptografia[i+7] == '5'){
						cripto[j] = 'U';
						j++;
						i += 8;
					}
				}else if (criptografia[i+7] == '1'){
					cripto[j] = 'a';
					j++;
					i += 7;
				}else if (criptografia[i+7] == '2'){
					cripto[j] = 'e';
					j++;
					i += 7;
				}else if (criptografia[i+7] == '3'){
					cripto[j] = 'i';
					j++;
					i += 7;
				}else if (criptografia[i+7] == '4'){
					cripto[j] = 'o';
					j++;
					i += 7;
				}else if (criptografia[i+7] == '5'){
					cripto[j] = 'u';
					j++;
					i += 7;
				}else if (criptografia[i+6] == 'd'){
						cripto[j] = 'P';
						j++;
						i += 6;
				}
				
		}else {
			cripto[j] = criptografia[i];
			j++;
		}
	
	}

	cripto[j] = '\0';
	return cripto;
}

char * desjuncao(char * criptografia){
	char * descripto = (char*)malloc(TAM* sizeof(char));
	strcpy(descripto,"");
	descripto = criptografia;
	descripto = desconversaoLeao(descripto);
	descripto = desinversao(descripto);
	descripto = desmyfrn(descripto);
	descripto = desmassoud(descripto);
	return descripto;	
}

char * descriptografaDados(char * criptografia, int estrategia){
	switch (estrategia){
		case 1: 
			return desmassoud(criptografia);
		case 2:
			return desmyfrn(criptografia);
		case 3:
			return desinversao(criptografia);
		case 4:
			return desconversaoLeao(criptografia);
		case 5:
			return desjuncao(criptografia);
		break;
	}	
}

char * mostraDescriptografia(char * criptografia){
	//quebrar - split da string
    int i=0;
    int estrategia = 1;
    
    int qtd_strings = qtd_espacos(criptografia) + 1;
    char strings_separadas[qtd_strings][strlen(criptografia)];
    char *pch = strtok (criptografia," ");
    while (pch != NULL){
        strcpy(strings_separadas[i++], pch); //copiar cada string para a posição correta
        pch = strtok (NULL, " ");
    }
    
    char * strings_aux = (char *)malloc(TAM *sizeof(char));
    strcpy(strings_aux, "");
    
	int j = 0;
    
   	for (i = 0; i < qtd_strings;i++){
   		strcat(strings_aux, (descriptografaDados(strings_separadas[i], estrategia)));
   		strcat(strings_aux, " ");
   		estrategia++;
   		if (estrategia > 5){
   			estrategia = 1;
		   }	 
	}
	int tamanho = strlen(strings_aux);
	strings_aux[tamanho - 1] = '\0';
	return strings_aux;
}

int main () {
    setlocale(LC_ALL, "Portuguese");
    char * frase = (char*)malloc(TAM * sizeof (char));
	char * cripto = (char*)malloc(TAM * sizeof(char));
	char * descri = (char*)malloc(TAM * sizeof(char));
	
	int resposta = 1;

		/*printf("\nInforme qual das opções você deseja:\n");
		printf("\n\tCriptografar(1):\n");
		printf("\n\tDescriptografar(2):\n");
		printf("\n\tSair(3):\n");
		printf("\n\tOpção Escolhida: ");*/

	
		lerDados(frase);
		cripto = mostraCriptografia(frase);
		printf("\n A string Criptografada é: %s", cripto);
		printf("\no contem na string é: %c\n", cripto[strlen(cripto)]);
		printf("\ncontem %d letras a string\n", strlen(cripto));
		
		descri = mostraDescriptografia(cripto);
		printf("\n A string dps da descripto: %s", descri);			
}
