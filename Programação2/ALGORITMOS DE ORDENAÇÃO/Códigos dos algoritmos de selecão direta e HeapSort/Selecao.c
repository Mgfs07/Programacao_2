#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#define TAM 5000

typedef struct Fabricante{
	char nome[TAM];
	char nacio[TAM];
	int ano_fundacao;
} fabri;

void troca(fabri *a, fabri *b){
	fabri aux;
	aux = *a;
	*a = *b;
	*b =aux;
}

int indice_valor_minimo(fabri *vetor, int inicio, int fim){
	int j = 0;
	int min = inicio;
	for(j = inicio + 1; j < fim; j++){
		if(strcmp(vetor[j].nome, vetor[min].nome) < 0){
			min = j;
		} else if (strcmp(vetor[j].nome, vetor[min].nome) == 0){
			if (strcmp(vetor[j].nacio, vetor[min].nacio) < 0){
				min = j;
			} else if (strcmp(vetor[j].nacio, vetor[min].nacio) == 0){
				if (vetor[j].ano_fundacao < vetor[min].ano_fundacao)
					min = j;
			}
		}
	}
	return min;
}

void selecaoDireta(fabri *vetor, int n){
	int i = 0, min;
	for(i=0; i<n-1; i++){
		min = indice_valor_minimo(vetor, i, n);
		troca(&vetor[i], &vetor[min]);
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
	selecaoDireta(fabri, 5);
	escreverVetor(fabri, 5);
}
