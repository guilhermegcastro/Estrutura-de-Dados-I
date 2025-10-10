/**
 * @file Exercicio18.c
 * @author Guilherme Castro
 * @date 2025-09-20
 * @brief
 * coding-exercise: 18. A conjectura de Goldbach foi apresentada por Christian Goldbach em uma carta a Leonhard Euler no ano de 1742, e diz: 
 * “Todo número par maior do que dois pode ser representado pela soma de dois números primos.”
 *  Apesar de não ter sido provada até hoje, a conjectura funcionou para todos os casos que já foram experimentados. 
 * Faça um programa que lê um valor N (inteiro, par e maior que dois) e exiba os dois valores primos cuja soma é igual a N.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	int numero, p1=3, p2=3, primo=0;
	
	printf("Insira um número par maior que dois: ");
	scanf("%d", &numero);
	
	if (numero==4)
	{
		printf(" 2 + 2 = 4");
	}
	else
	{
		while(primo==0)
		{
		
		  for ( int i = numero-1; primo == 0 ; i--)
		  {
			
		  }
		  
	    }
        return 0;


}

