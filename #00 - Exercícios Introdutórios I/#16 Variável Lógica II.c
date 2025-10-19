/**
 * @file Exercicio16.c
 * @author Guilherme Castro
 * @date 2025-09-15
 * @brief
 * coding-exercise: 16 - Variável Lógica : Aprimore o problema anterior... Faça um programa em C. (função única) que leia do usuário um valor inteiro N.
 *  Seu programa deve encontrar e imprimir como resposta: o maior número primo menor que N, e o menor número primo maior que N.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	int numero;
	
	printf ("Poe numero:");
	scanf("%d", &numero);
	
	for(int candidato = numero - 1 ; candidato > 0 ; candidato--)
		{
			int ehprimo = 1;
			for(int divisor=2; divisor < candidato ; divisor++)
				{
					if (candidato%divisor==0)
						{ 
							ehprimo = 0;
							break;
						}
				}
			if(ehprimo==1) 
				{ 
					printf("\n%d é o maior número primo menor que %d", candidato, numero);
					break;
		        }	
        }
        
     for(int candidato = numero + 1 ; candidato > 0 ; candidato ++)
		{
			int ehprimo = 1;
			for(int divisor=2; divisor < candidato ; divisor++)
				{ 
					if (candidato%divisor==0)
						{
							ehprimo = 0;
							break;
						}
				}
			if(ehprimo==1)
				{ 
					printf("\n%d é o menor número primo maior que %d", candidato, numero);
					break;
				}
		}
        return 0;

}
