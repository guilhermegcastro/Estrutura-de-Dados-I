/**
 * @file    matriz01.c
 * @author  @guilhermegcastro
 * @date    2025-10-24
 * @brief   
 * Enunciado: 41. Gere aleatoriamente uma matriz N x N de inteiros sorteados no intervalo entre X e Y (inclusive).
 * Imprima-a em formato de tabela (linhas e colunas) e informe a localização do maior e do menor valor da matriz.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int N, X, Y;
	
	printf("Informe o tamanho NxN da matriz:");
	scanf(" %d", &N);
	printf("Insira o intervalo mínimo e o intervalo máximo (inclusive) do sorteio.");
	scanf(" %d %d", &X, &Y);
	
	system("clear");
	while (X > Y) {
		int troca = X; X = Y; Y = troca;
	}
	printf("      ");
	for (int i = 0; i < N; i++) printf("|C.%2d ", i);
	printf("|\n");
	int matriz[N][N];
	for (int i = 0; i < N; i++) {
		printf("L. %2d ", i);
		for (int j = 0; j < N; j++) {
			matriz[i][j] = X + rand()%(Y-X+1);
			printf("| %3d ", matriz[i][j]);
		}
			printf("|\n");
	}
	
	int iMa, jMa, iMe, jMe;
	iMa = jMa = iMe = jMe = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(matriz[i][j] > matriz[iMa][jMa]) {
				iMa = i; jMa = j;
				continue;
			}
			if(matriz[i][j] < matriz[iMe][jMe]) {
				iMe = i; jMe = j;
			}
		}
	}
	
	printf("\n A localização do maior número da tabela está na linha [%d] coluna [%d]", iMa, jMa);
	printf("\n A localização do menor número da tabela está na linha [%d] coluna [%d]", iMe, jMe);
	
	
    return 0;
}
