/**
 * @file    vetor16.c
 * @author  @guilhermegcastro
 * @date    2025-10-23
 * @brief   
 * Enunciado: 16. Declare 03 arrays contendo 10 valores aleatórios. 
 * Faça a ordenação dos 03 arrays (utilizando o algoritmo de ordenação preferido).
 * Imprima os 03 arrays ordenados e, após isso, faça a operação “merge”, ou seja, mescle os valores dos 03 arrays em um único array, mantendo os valores ordenados.
 * Mas atenção… não deve-se realizar uma quarta ordenação para obter o resultado final.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



void gaveta(int i, int* vetor);
void organizar(int* vetor);
int main() {

	srand(time(NULL));
	int gaveta1[10], gaveta2[10], gaveta3[10];
	
	for (int i = 0; i < 10; i++) {
		gaveta1[i] = rand()%100;
		gaveta2[i] = rand()%100;
		gaveta3[i] = rand()%100;
	}
	printf("Números sorteados:\n\n");
	gaveta(1, gaveta1);
	gaveta(2, gaveta2);
	gaveta(3, gaveta3);
	
	printf("Vetores reorganizados em ordem crescente:\n\n");
	organizar(gaveta1);
	gaveta(1, gaveta1);
	organizar(gaveta2);
	gaveta(2, gaveta2);
	organizar(gaveta3);
	gaveta(3, gaveta3);
  
	int gavetao[30];
    int idx1, idx2, idx3;
    idx1 = idx2 = idx3 = 0;
    for (int i = 0; i < 30; i++) {
		
		if (idx1 < 10 && (idx2 >= 10 || (gaveta1[idx1] <= gaveta2[idx2]) && (idx3 >= 10 || gaveta1[idx1] <= gaveta3[idx3]))){
			gavetao[i] = gaveta1[idx1];
			idx1++;
		} else if (idx2 < 10  && (idx3 >= 10 || gaveta2[idx2] <= gaveta3[idx3])){
			gavetao[i] = gaveta2[idx2];
			idx2++;
		} else {
			gavetao[i] = gaveta3[idx3];
			idx3++;
		}
		printf("[%d] ", gavetao[i]);
	}
    
    
    
    
    
      return 0;
}

void gaveta(int i, int* vetor) {
    printf(" %dº Vetor:",i);
	for (int i = 0; i < 10; i++) printf("[%02d]", vetor[i]); 
	printf("\n\n");
}
void organizar(int* vetor) {
	int fim;
	do {
		fim = 1;
		for (int i = 0; i < 10; i++){
		if (i==9 || vetor[i] <= vetor[i+1]) continue;
				int troca = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = troca;
				fim = 0;
		}
	} while (!fim);
}
