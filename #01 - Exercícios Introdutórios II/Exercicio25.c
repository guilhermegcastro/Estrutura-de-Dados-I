/**
 * @file Exercicio25.c
 * @author Guilherme Castro
 * @date 2025-09-21
 * @brief
 * coding-exercise: 25. Faça um programa que leia um valor inicial N e uma razão R. Imprima uma sequência em P.A. contendo 10 valores, e uma sequência em P.G. contendo 10 valores.
 * P.Ex.: N == 3 e R == 2.
 * PA = 3 - 5 - 7 - 9 - 11 - 13 - 15 - 17 - 19 - 21
 * PG = 3 - 6 - 12 - 24 - 48 - 96 - 192 - 384 - 768 - 1536
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	long int numero, razao;
	
	printf("Insira o valor inicial e a razão para a impressão de uma P.A e uma P.G de 10 valores para ambas:");
	scanf("%ld %ld", &numero, &razao);
	
	printf("\t- - - Sequência de P.A - - -\n | %2ld", numero);
	for (long int pa = numero, i = 1; i <10; i++)
	{
		pa+=razao;
		printf(" | %2ld", pa);
	}
	
	printf(" |\n\n");
	
	printf("\t- - - Sequência de P.G - - -\n | %2ld", numero);
	for (long int pg = numero, i = 1; i <10; i++)
	{
		pg*=razao;
		printf(" | %2ld", pg);
	}
	printf(" |\n\n");

        return 0;


}

