#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#define TAM 5000

typedef struct Fabricante{
	char nome[TAM];
	char nacio[TAM];
	int ano_fundacao;
} fabri;

void shakeSort(fabri *vetor, int n){
	int bottom, top, swapped, i = 0;
	fabri aux;
	bottom = 0;
	top = n - 1;
	swapped = 0;
	while(swapped == 0 && bottom < top)
	{
		swapped = 1;
		for(i = bottom; i < top; i = i+1){
			if(strcmp(vetor[i].nome, vetor[i+1].nome) > 0){
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
				swapped = 0;
			} else if (strcmp(vetor[i].nome, vetor[i+1].nome) == 0){
				if(strcmp(vetor[i].nacio, vetor[i+1].nacio) > 0){
					aux = vetor[i];
					vetor[i] = vetor[i+1];
					vetor[i+1] = aux;
					swapped = 0;
				} else if (strcmp(vetor[i].nacio, vetor[i+1].nacio) == 0){
					if(vetor[i].ano_fundacao > vetor[i+1].ano_fundacao){
						aux = vetor[i];
						vetor[i] = vetor[i+1];
						vetor[i+1] = aux;
						swapped = 0;
					}
				}		
			}
		}
		
		top = top - 1;
		
		for(i = top; i > bottom; i = i-1){
			if(strcmp(vetor[i].nome, vetor[i-1].nome) < 0){
				aux = vetor[i];
				vetor[i] = vetor[i-1];
				vetor[i-1] = aux;
				swapped = 0;
			} else if (strcmp(vetor[i].nome, vetor[i-1].nome) == 0){
				if(strcmp(vetor[i].nacio, vetor[i-1].nacio) < 0){
					aux = vetor[i];
					vetor[i] = vetor[i-1];
					vetor[i-1] = aux;
					swapped = 0;
				} else if (strcmp(vetor[i].nacio, vetor[i-1].nacio) == 0){
					if(vetor[i].ano_fundacao < vetor[i+1].ano_fundacao){
						aux = vetor[i];
						vetor[i] = vetor[i-1];
						vetor[i-1] = aux;
						swapped = 0;
					}
				} 
			}
		}
		
		bottom = bottom + 1;
	}
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
	shakeSort(fabri, 5);
	escreverVetor(fabri, 5);
}
