/**
 * @file array05.c
 * @author Guilherme Castro
 * @date 2025-10-14
 * @brief 
 * Enunciado: Sorteie nºs aleatórios entre 1 e X para preencher uma tabela N x N 
 * (valor de N e X definidos pelo usuário). 
 * Imprima os nºs na tela em formato de tabela (linhas e colunas).
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( ) {
	
	srand(time(NULL));
	int N, X; 
	
	do {
		system("clear");
		printf("Insira o valor intervalo máximo: ");
		scanf(" %d", &X);
	} while (X<1);
	
	do {
		system("clear");
		printf("Insira o tamanho da tabela quadriculada: ");
		scanf(" %d", &N);
	} while (N<1);
	
	system("clear");
	printf("\n TABELA %dx%d COM NÚMEROS ALEATÓRIOS DE 1 A %d\n", N,N,X);
	int tabela[N][N];
	
	printf("|    |");
	for (int i = 0; i < N; i++) printf(" %2d |", i+1);
		
		printf("\n");
	
	for (int i = 0; i < N; i++){
		printf("| %2d |", i+1);
		for (int j = 0; j < N; j++) {
			tabela[i][j] = rand()%X+1;
			printf(" %02d |", tabela[i][j]);
		}
		printf("\n");
	}
	
	
		        return 0;
	}
	
	
