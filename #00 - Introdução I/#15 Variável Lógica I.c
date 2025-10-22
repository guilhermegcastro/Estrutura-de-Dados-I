/**
 * @file Exercicio15.c
 * @author Guilherme Castro
 * @date 2025-09-15
 * @brief
 * coding-exercise: 15- Variável Lógica : Faça um programa em C (em única função) que leia um valor inteiro Ne verifica se o número N é primo ou não (ou seja, só possui 1 e o próprio N como divisores possíveis). 
 * Estude sobre o conceito e utilidade de "variável lógica e porque é muito útil neste problema.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	int numero, i;
	
	printf(" Insira um número para verificar se ele é primo ou não: "); 
	scanf("%d", &numero); 
	
	for(i=2;i<=numero;i++)
		{
			if((numero%i != 0) && (numero != i) )
				continue;
			if ((numero%i == 0) && (numero != i) )
			{
				printf("O número %d não é primo", numero);
					break;
			}
			printf("O número %d é primo", numero);
			
		
	}
	
	return 0;
}
		
			        
        



