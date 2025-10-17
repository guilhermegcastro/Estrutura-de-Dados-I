/**
 * @file array06.c
 * @author Guilherme Castro
 * @date 2025-10-14
 * @brief 
 * Enunciado: Gere uma matriz N x N onde os valores da diagonal principal sejam exatamente a soma dos demais valores existentes na sua linha e coluna
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( ) {
	
	int N;
	printf("Insire o tamanho da matriz: ");
	scanf(" %d", &N);

	int matriz[N][N]; 
	
	for (int i = 0 ; i < N; i++){   //Define os valores dos espaços que não seja a diagonal.
		for (int j = 0; j < N; j++) {
			
			matriz[i][j] = i + j;
			if (i == j) 
				matriz[i][j] = 0;
		}
	}
	
	printf("\n");
	
	for (int i = 0; i < N; i++){ // Atribui o valor da diagonal.
		for (int j = 0; j < N; j++){ 
			if (i!=j)
			matriz[j][j]+= 2 * matriz[i][j];
		}
	}
	
	printf("|");
	for (int i = 0; i < N; i++){ // Imprime a tabela.
		for (int j = 0; j < N; j++){
			printf(" %3d |", matriz[i][j]);
		}
		if(i!=N-1)
		printf("\n|");
	}
	   return 0;
	}
	
	
