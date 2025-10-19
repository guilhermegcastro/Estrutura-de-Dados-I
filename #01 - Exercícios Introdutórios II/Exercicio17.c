/**
 * @file Exercicio17
 * @author Guilherme Castro
 * @date 2025-09-20
 * @brief
 *  coding-exercise:  17. Escreva um programa que lê um número N, e então imprima o primeiro número primo imediatamente anterior e o primeiro primo imediatamente posterior à N.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
		int numero, primo=0; 
		
		printf("Insira um número: ");
		scanf("%d", &numero);
		
		for ( int i = numero-1; primo == 0 ; i--)
		{
			
			primo = 1;
				if (i==1)
				{
					printf("O primeiro primo imeditamente anterior a %d é: %d\n", numero, i);
					break;
				}
			for (int j = 2; j <= i; j++)
			{
				if(i==j)
				{
					printf("O primeiro primo imeditamente anterior a %d é: %d\n", numero, i);
					break;
				}
				if(i%j==0)
				{
					primo=0;
					break;
				}
				if(i%j!=0)
				{
					continue;
				}
			}
		 }
			
			primo = 0;
			
			for ( int i = numero+1; primo == 0 ; i++)
		{
			primo = 1;
			
			for (int j = 2; j <= i; j++)
			{
				
				if(i==j)
				{
					printf("O primeiro primo imeditamente posterior a %d é: %d", numero, i);
					break;
				}
				if(i%j==0)
				{
					primo=0;
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


