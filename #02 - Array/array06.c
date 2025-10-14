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
	srand(time(NULL));
	
	int N;
	printf("Insire o tamanho da matriz: ");
	scanf(" %d", &N);

	int matriz[N][N]; 
	
	for (int i = 0 ; i < N; i++){
		for (int j = 0; j < N; j++) {
			
			matriz[i][j] = i + j;
			if (i == j) 
				matriz[i][j] = 0;
		}
		
	}
	
	printf("\n");
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (i!=j)
			matriz[i][i]+= 2* matriz[i][j];
			printf(" %02d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	
	
	
	
	
	   return 0;
	}
	
	
