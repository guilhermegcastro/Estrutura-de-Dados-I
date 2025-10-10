/**
 * @file Exercio12.c
 * @author Guilherme Castro
 * @date 2025-09-10
 * @brief
 * @coding-exercise 12 - Laços de Repetição
 * Faça um programa em C (função única) que leia dois valores inteiros, sendo que obrigatoriamente um deve ser par e outro impar (independente da ordem de entrada). O programa deve continuar solicitando valores que este requisito seja atendido. Após isso, o programa deve imprimir todos os números situados no intervalo entre os dois valores.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
 int x, i, j; 
 printf("Insira um número para imprimir uma lista decrescente de astericos: "); 
 scanf("%d", &x);
 
	for(i=x; i>=0; i--)
		{
			for(j=i; j>=1; j--)
			printf(" * "); 
			putchar('\n');
		} 
		
}
