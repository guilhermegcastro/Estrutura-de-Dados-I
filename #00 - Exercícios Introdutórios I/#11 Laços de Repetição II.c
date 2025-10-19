/**
 * @file Exercicio11.c
 * @author Guilherme Castro
 * @date 2025-09-10
 * @brief
 * @coding-exercise: 11. Laços de Repetição: Faça um programa em C (função única) que leia do usuário um valor inteiro N. Faça a impressão crescente de todos os valores pares de 0 até Ne a impressão decrescente de todos os valores ímpares de N até 0.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	int numb1, numb2, i;
	printf("Insira dois valores (ímpar e par, em qualquer ordem):");
	scanf("%d %d", &numb1, &numb2); 
	
	if ( ((numb1%2==0) && (numb2%2==0) ) || ((numb1%2!=0) && (numb2%2!=0)) ) 
	{
		while ( ((numb1%2==0) && (numb2%2==0) ) || ((numb1%2!=0) && (numb2%2!=0)) ) 
		{
			printf("Por favor, insira um valor par e um valor ímpar:");
			scanf("%d %d", &numb1, &numb2); 
		}
	}		
	
	
	printf("Números situados no intervalo entre %d e %d\n", numb1, numb2);
	if (numb2 > numb1)
	{ 
		for (i=numb1; i<=numb2; i++)
			{
				printf("%2d", i);	
					if (i == numb2)
					continue; 
				printf(", ");
			}
	}
	
	else
	{ 
		for (i=numb1; i>=numb2; i--)
			{
				printf("%2d", i);
				if (i == numb2)
					continue; 
				printf(", ");
			}
	}
}
