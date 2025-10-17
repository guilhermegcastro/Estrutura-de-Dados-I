/**
 * @file array04.c
 * @author Guilherme Castro
 * @date 2025-10-13
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
	int numero[25]; 
	
	for (int i = 0; i < 25; i++) 
		numero[i] = i+1;
		
	printf("Números do lotafácil: ");
	
	for (int i = 24; i  > 9; i--)	{
		int j = rand()%(i+1);
		int temp = numero[i];
		numero[i] = numero[j];
		numero[j] = temp;
		
		
	/**/
		printf(" %d ", numero[i]);
	}
	
	printf("\nNúmeros não sorteados:");
	for (int i = 0; i < 10; i++) 
	printf(" %d ", numero[i]);
	
	
		
		        return 0;
	}
	
	
