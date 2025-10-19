/**
 * @file Exercicio16.c
 * @author Guilherme Castro
 * @date 2025-09-20
 * @brief
 * coding-exercise: 16. Faça um programa que leia do usuário dois números X e Y tal que Y >= X. 
 * Faça com que o programa imprima todos os números primos existentes entre X e Y, inclusive.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	int X, Y; 
	
	printf("Insira um intervalo de números X a Y: ");
	scanf("%d %d", &X, &Y);
	
		while (X>Y)
		{
			printf("O intervalo Y precisa ser maior ou igual a X: ");
			scanf("%d %d", &X, &Y);
		}
		printf(" Números primos de %d a %d (inclusive): ", X, Y);
		
	for (int i = X; i <= Y; i++)
	{
		if(i==1)
		{
				printf(" %d", i);
		}
		for(int j = 2; j <= i; j++)
		{
			if(i==j)
			{
				printf(" %d", i);
				break;
			}
			if(i%j==0)
			{
				break;
			}
			if(i%j!=0)
			{
				continue;
			}
		}
	}
        return 0;


}

