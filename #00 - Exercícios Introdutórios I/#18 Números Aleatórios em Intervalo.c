/**
 * @file Exercicio18.c
 * @author Guilherme Castro
 * @date 2025-09-15
 * @brief 
 * coding-exercise: 18 - Números aleatórios em um intervalo : Faça um programa em C (função única) que imprima N números aleatórios gerados no intervalo entre X e Y (Os valores N, X e Y devem ser informados pelo usuário no início da execução).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	srand(time(NULL));
	int N, X, Y; 
	
	printf("Informe a quantidade de números aleatórios que você deseja que apareça no terminal, o intervalo mínimo (X) e o intervalo máximo (Y):");
	scanf("%d %d %d", &N, &X, &Y); 
	
	if ( Y < X)
		{
			int i = X;
				X = Y;
				Y = i;
		}
	
	for ( int i = 1 ; i <= N ; i++)	
		{
			if (i < N)  
				printf("%d, ", rand()%(Y-X+1)+X);
			else
				printf("%d", rand()%(Y-X+1)+X);
		 }
        return 0;


}

