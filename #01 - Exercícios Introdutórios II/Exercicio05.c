/**
 * @file Exercicio05.c
 * @author Guilherme Castro
 * @date 2025-09-17
 * @brief
 * coding-exercise: 5. Faça um programa que leia dois valores inteiros X e Y, tal que Y >= X. 
 * O programa deverá sortear N valores no intervalo entre X e Y (inclusive).
 * Obs.: Os números sorteados entre X e Y não devem ser obtidos por método de tentativa e erro!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	srand(time(NULL));
	
	int N, X, Y;
	
	printf("Qual a quantidade de números que você deseja sortear? ");
	scanf("%d", &N);
	printf("Qual o intervalo mínimo dos números sorteados (X)? ");
	scanf("%d", &X);
	printf("Qual o intervalo máximo dos números sorteados (Y)? ");
	scanf("%d", &Y);
	
	if (Y<X)
		{
			printf("O intervalo mínimo (X) precisa ser menor ou igual ao intervalo máximo (Y). Reinicie o programa e tente novamente.\n");
			return 0;
		}
	if (N>Y-X+1)
		{
			printf("A quantidade de números sorteados não pode ser maior que os números disponíveis no intervalo. Reinicie o programa e tente novamente.\n");
			return 0;
		}
	
	int tamanho = Y-X+1;
	int sorteio[tamanho];
	
	for(int i = 0; i < tamanho ; i++)
		{
			sorteio[i] = X + i;
		}
	
	for(int i = tamanho - 1; i > 0 ; i--)
		{ 
			int j = rand() % (i+1);
			int temp = sorteio[i];
			sorteio[i] = sorteio[j];
			sorteio[j] = temp;
			
		}
	printf(" %d  Numero(s) sorteado(s) de %d e %d (inclusive):\n", N, X, Y);
	for(int i = 0; i < N; i++)
		{
			printf("% d ", sorteio[i]);
		}
			
        return 0;


}

