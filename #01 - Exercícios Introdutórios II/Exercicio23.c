/**
 * @file Exercicio23.c
 * @author Guilherme Castro
 * @date 2025-09-20
 * @brief
 * coding-exercise: 23. Crie um programa que receba um número e verifique se ele é um número triangular. 
 * Um número é triangular quando é resultado do produto de três números consecutivos. Exemplo: 120 = 4 x 5 x 6.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	int numero, X = 1, Y = 2, Z = 3, valor; 
	
	printf("Insira um número para verificar se o mesmo é triangular: ");
	scanf("%d", &numero);
	
	for ( ; X*Y*Z <= numero; X++, Y++, Z++)
	{
		valor = X * Y * Z;
		if (valor == numero)
		{
			break;
		}
		
	}

	
	
	(valor==numero) ? printf("\n O número inserido é triangular (%d x %d x %d = %d)", X, Y, Z, numero) : printf("\n O número inserido não é triângular, pois não há uma sequência de trés números consecutivos que multiplicados entre si, resulta em %d", numero);
	

        return 0;


}

