#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#define TAM 5000
#define VERDADEIRO 1
#define FALSO 0

typedef struct Fabricante{
	char nome[TAM];
	char nacio[TAM];
	int ano_fundacao;
} fabri;

int min (int a, int b){
	return (a > b) ? b : a;
}

void simplemerge(fabri *vetor, int is1, int fs1, int is2, int fs2, fabri *resultado, int r){
	int i = 0;
	int ini_seg1 = is1;
	int fim_seg1 = fs1;
	int ini_seg2 = is2;
	int fim_seg2 = fs2;
	int k =r;
	while((ini_seg1 <= fs1) && (ini_seg2 <= fs2)){
		if (strcmp(vetor[ini_seg1].nome, vetor[ini_seg2].nome) < 0){
			resultado[k] = vetor[ini_seg1];
			ini_seg1++;
		} else if (strcmp(vetor[ini_seg1].nome,  vetor[ini_seg2].nome) > 0){
			resultado[k] = vetor[ini_seg2];
			ini_seg2++;
		} else {
			if(strcmp(vetor[ini_seg1].nome, vetor[ini_seg2].nome) == 0){
				if (strcmp(vetor[ini_seg1].nacio, vetor[ini_seg2].nacio) < 0){
					resultado[k] = vetor[ini_seg1];
					ini_seg1++;
				} else if (strcmp(vetor[ini_seg1].nacio, vetor[ini_seg2].nacio) > 0){
					resultado[k] = vetor[ini_seg2];
					ini_seg2++;
				} else {
					if (vetor[ini_seg1].ano_fundacao <vetor[ini_seg2].ano_fundacao){
						resultado[k] = vetor[ini_seg1];
						ini_seg1++;
					} else {
						resultado[k] = vetor[ini_seg2];
						ini_seg2++;
					}
				}
			}	
		}
		k++;
	}
	
	if (ini_seg1 > fs1){
		for(i =ini_seg2; i<= fs2; i++){
			resultado[k] = vetor[i];
			k++;
		}
	} else {
		for(i =ini_seg1; i<= fs1; i++){
			resultado[k] = vetor[i];
			k++;
		}
	}
}

void mergepass(fabri *vetor, fabri *resultado, int n, int L){
	int p= 0;
	int q= p + L;
	int r= 0;
	int i;
	while(q < n){
		simplemerge(vetor, p, q-1, q, min(q+L-1, n-1), resultado, r);
		r= r + 2 * L;
		p= q + L;
		q= p + L;
	}
	
	if (p < n){
		for(i= p; i <n; i++){
			resultado[i] = vetor[i];
		}
	}
}

void mergeSort(fabri *vetor, int n){
	int i = 0;
	fabri *resultado = (fabri*)malloc(5* sizeof(fabri));
	int L = 1;
	int eh_par = VERDADEIRO;
	while (L < n){
		if (eh_par){
			mergepass(vetor, resultado, n, L);
			eh_par = FALSO;
		} else {
			mergepass(resultado, vetor, n, L);
			eh_par = VERDADEIRO;
		}
		L = L* 2;
	}
	
	if (!eh_par){
		for(i=0; i<n; i++){
			vetor[i] = resultado[i];
		}
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
	mergeSort(fabri, 5);
	escreverVetor(fabri, 5);
}
