/**
 * @file Exercicio24.c
 * @author Guilherme Castro
 * @date 2025-09-20
 * @brief
 * coding-exercise: 24. Faça um programa que receba um número e verifique se ele é ou não um número perfeito.
 * Um número é perfeito quando a soma de todos os seus divisores inteiros – excluindo ele mesmo – é igual ao próprio número.
 *  Ex: 28 = 1 + 2 + 4 + 7 + 14
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	int numero, soma=0;
	
	printf("Insira um valor inteiro para verificar se o número é perfeito ou não: "); 
	scanf("%d", &numero);
	
	for ( int i = 1; i < numero; i++)
	{
		if(i==1)
		{
			printf(" %d " , i); 
			soma+=i;
			continue;
		}
		if(numero%i==0)
		{
			printf("+ %d " , i); 
			soma+=i;
		}
	}
	
	printf("= %d\n", soma); (soma==numero) ? printf(" O número %d é um número perfeito, pois todos os seus divisores inteiros (exceto ele mesmo) somados, é igual a ele mesmo.", numero) : printf("O número %d não é um número perfeito, pois todos os seus divisores inteiros (exceto ele mesmo) somados, não é igual a ele mesmo.", numero);

        return 0;


}

