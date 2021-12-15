#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#define TAM 5000
#define F 0
#define V 1

typedef struct Fabricante{
	char nome[TAM];
	char nacio[TAM];
	int ano_fundacao;
} fabri;

int max(int a, int b){
	if (a > b) return a;
	else return b;
}

void combSort(fabri *vetor, int n){
	fabri aux;
	int h = n;
	int troca,i = 0;
	do{
		h = max( (int) (h/1.3), 1);
		if ((h == 9) || (h == 10)) h = 11;
		troca = F;
		for(i = 0; i < n-h; i++){
			if(strcmp(vetor[i].nome, vetor[i+h].nome) > 0){
				aux = vetor[i];
				vetor[i] = vetor[i+h];
				vetor[i+h] = aux;
				troca = V;
			}else if(strcmp(vetor[i].nome, vetor[i+h].nome) == 0){
				if(strcmp(vetor[i].nacio, vetor[i+h].nacio) > 0){
					aux = vetor[i];
					vetor[i] = vetor[i+h];
					vetor[i+h] = aux;
					troca = V;
				}else if (strcmp(vetor[i].nacio, vetor[i+h].nacio) == 0){
					if (vetor[i].ano_fundacao > vetor[i+h].ano_fundacao){
						aux = vetor[i];
						vetor[i] = vetor[i+h];
						vetor[i+h] = aux;
						troca = V;
					}
				} 
			}
		}
	} while (troca || (h != 1));
}

void escreverVetor(fabri *vetor, int n){
	int i = 0;
	for(i = 0; i < n; i++){
		printf("\n%s   %s   %d\n",vetor[i].nome,vetor[i].nacio,vetor[i].ano_fundacao);
	}
}



int main(int argc, char *argv[]) {
	struct Fabricante fabri[5] = {
		{"Coca Cola", "Estadunidense", 1886},
		{"Pepsi", "Estadunidense", 1893},
		{"Toyota", "Japonesa", 1937},
		{"Ford", "Estadunidense", 1903},
		{"Xiaomi", "Chinesa", 2010},
	};
	combSort(fabri, 5);
	escreverVetor(fabri, 5);
}
