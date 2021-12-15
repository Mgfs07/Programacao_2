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
	*b = aux;
}

int filhoEsquerda(int raiz){
	return 2*raiz + 1;
}

int filhoDireita(int raiz){
	return 2*raiz + 2;
}

void heapify (fabri *vetor, int n, int indice_raiz){
	int esquerda = filhoEsquerda(indice_raiz);
	int direita = filhoDireita(indice_raiz);
	int max;
	if (esquerda>n-1){
		return;
	} 
	else if (direita>n-1){
		max = esquerda;
	}
	else {
		if (strcmp(vetor[esquerda].nome, vetor[direita].nome) > 0){
			max = esquerda;
		} else if (strcmp(vetor[esquerda].nome, vetor[direita].nome) < 0){
			max = direita;
		} else {
			if (strcmp(vetor[esquerda].nacio, vetor[direita].nacio) > 0){
				max = esquerda;
			} else if (strcmp(vetor[esquerda].nacio, vetor[direita].nacio) < 0){
				max = direita;
			} else {
				if (vetor[esquerda].ano_fundacao > vetor[direita].ano_fundacao){
					max = esquerda;
				} else if (vetor[esquerda].ano_fundacao < vetor[direita].ano_fundacao)
					max = direita;
			}
		}
	}
	if (strcmp(vetor[max].nome, vetor[indice_raiz].nome) > 0){
		troca(&vetor[max], &vetor[indice_raiz]);
		heapify(vetor, n, max);
	} else if (strcmp(vetor[max].nome, vetor[indice_raiz].nome) == 0){
		if (strcmp(vetor[max].nacio, vetor[indice_raiz].nacio) > 0){
			troca(&vetor[max], &vetor[indice_raiz]);
			heapify(vetor, n, max);
		} else if (strcmp(vetor[max].nacio, vetor[indice_raiz].nacio) == 0){
			if (vetor[max].ano_fundacao > vetor[indice_raiz].ano_fundacao){
				troca(&vetor[max], &vetor[indice_raiz]);
				heapify(vetor, n, max);
			}
		}
	}
}

void construirHeap(fabri *vetor, int n){
	int i = 0;
	for(i = n/2-1; i >= 0;i--){
		heapify(vetor, n, i);
	}
}

void heapSort(fabri *vetor, int n){
	construirHeap(vetor, n);
	int i;
	for(i =n-1; i> 0;i--){
		troca(&vetor[i], &vetor[0]);
		heapify(vetor, i, 0);
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
	heapSort(fabri, 5);
	escreverVetor(fabri, 5);
}
