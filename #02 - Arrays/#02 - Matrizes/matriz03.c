/**
 * @file    matriz03.c
 * @author  @guilhermegcastro
 * @date    2025-10-24
 * @brief   
 * Enunciado: 43. Gere aleatoriamente uma matriz N x N de inteiros sorteados no intervalo entre 0 e N^2 (inclusive).
 * Todo número sorteado, obrigatoriamente deve ser exclusivo em sua linha e em sua coluna.  
 * Imprima a matriz em formato de tabela (linhas/colunas).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	
	srand(time(NULL));
	int N;
	
	printf("Informe o tamanho NxN da matriz:");
	scanf(" %d", &N);
	
	int matriz[N][N], intervalo=N*N+1;
	system("clear");
	
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matriz[i][j]= -1;
		}
	}
	
	
	
	
	
	
	
	for (int i = 0; i < N; i++) {

		int linha[N]; 			
		int cont=0;
		do {
			int flag = 1;
			for(int j=0; j<=cont; j++) {
				linha[cont] = rand()%intervalo;
				if (linha[cont]==linha[j]) {
					flag = 0;
					break;
				}
			}
			if (flag){
				cont++;
				break;
			}
			
		} while(1);
		
		printf("%d ", linha[i]);
	}
		
			
		
	
	printf("      ");
	for (int i = 0; i < N; i++) printf("|C.%2d ", i);
	
	printf("|\n");

	for (int i = 0; i < N; i++) {
		printf("L. %2d ", i);
		for (int j = 0; j < N; j++) {
			
			printf("| %3d ", matriz[i][j]);
		}
			printf("|\n");
	}
	
	
	
	
    return 0;
}
