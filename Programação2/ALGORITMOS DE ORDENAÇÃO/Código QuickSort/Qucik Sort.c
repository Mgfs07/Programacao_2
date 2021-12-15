#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#define TAM 5000

typedef struct Fabricante{
	char nome[TAM];
	char nacio[TAM];
	int ano_fundacao;
} fabri;

void swap(fabri *a, fabri *b){
	fabri tmp;
	tmp = *a;
	*a = *b;
	*b =tmp;
}

int particao(fabri *vetor, int inicio, int fim){
	fabri pivo = vetor[inicio];
	
	int i=inicio+1,  f=fim;
	while (i <= f){
		if(strcmp(vetor[i].nome, pivo.nome) < 0)
			i++;
		else if (strcmp(pivo.nome, vetor[f].nome) < 0)
			f--;
		else if (strcmp(vetor[i].nome, pivo.nome) == 0){
			if(strcmp(vetor[i].nacio, pivo.nacio) < 0)
				i++;
			else if (strcmp(pivo.nome, vetor[f].nome) < 0)
				f--;
			else if (strcmp(vetor[i].nacio, pivo.nacio) == 0){
				if (vetor[i].ano_fundacao < pivo.ano_fundacao)
					i++;
				else if (strcmp(pivo.nome, vetor[f].nome) < 0)
					f--;
				else {
					swap(&vetor[i], &vetor[f]);
					i++;
					f--;
				}
			} else {
				swap(&vetor[i], &vetor[f]);
				i++;
				f--;
			}
		} else {
			swap(&vetor[i], &vetor[f]);
			i++;
			f--;
		}
	}
	
	vetor[inicio] = vetor[f];
	vetor[f] = pivo;
	return f;
}

void quickSort(fabri *vetor, int ini, int fim){
	int meio;
	if (ini < fim){
		meio = particao(vetor, ini, fim);
		quickSort(vetor, ini, meio);
		quickSort(vetor, meio+1, fim);
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
	quickSort(fabri,0, 4);
	escreverVetor(fabri, 5);
}
