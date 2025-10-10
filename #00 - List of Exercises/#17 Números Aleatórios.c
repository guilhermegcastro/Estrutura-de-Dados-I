/**
 * @file Exercicio17.c
 * @author Guilherme Castro
 * @date 2025-09-15
 * @brief
 * coding-exercise: 17 - Números Aleatórios : Faça um programa em C (função única) que imprima N números aleatórios gerados no intervalo entre 0 e X (Os valores N e X devem ser informados pelo usuário no início da execução). 
 * Pesquise sobre o conceito de números pseudo-aleatórios e sementes (seeds) na computação.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
 srand(time(NULL));
 
 int X, N;
 
 printf("Insira a quantidade de números que você deseja, e o limite do intervalo:");
 scanf("%d %d", &N, &X);
 
for( int i = 1; i <= N; i++)
	{
		if (i < N)
			printf("%d, ", rand()%(X+1));
		else 
			printf("%d", rand()%(X+1));
	}
	

        return 0;


}

