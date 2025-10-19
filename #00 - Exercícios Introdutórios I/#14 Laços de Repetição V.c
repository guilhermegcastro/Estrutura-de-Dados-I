/**
 * @file Exercicio14.c
 * @author Guilherme Castro
 * @date 2025-09-14
 * @brief
 * coding-exercice: 14- Laços de Repetição : Faça um programa em C (função única) que dado um valor inicial (por exemplo 6), imprima o seguinte padrão na tela:
   ****** (6)
   *****
   ****
   ***
   **
   *
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

