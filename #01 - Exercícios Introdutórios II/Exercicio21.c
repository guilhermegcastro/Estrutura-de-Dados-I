/**
 * @file Exercicio21.c
 * @author Guilherme Castro
 * @date 2025-09-20
 * @brief
 * coding-exercise: 21. Faça um programa que leia um valor inteiro N não-negativo. 
 * O programa deve calcular e imprimir o valor de N! (N Fatorial).
 * P.Ex.: 6! == 720; 9! == 362880.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	
	long int entrada;
	unsigned long int numero, fatorial=1;
	
	do 
	{
		printf("Insira um número inteiro não negativo: ");
		scanf("%ld", &entrada);
	} while (entrada < 0);
	
	numero = entrada;
	
	for (int i = 1 ; i <= numero; i++)
	{
		fatorial*=i;
	}
		printf(" %lu! = %lu", numero, fatorial);
		

        return 0;

}

