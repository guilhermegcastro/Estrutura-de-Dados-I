/**
 * @file Exercicio29.c
 * @author Guilherme Castro
 * @date 2025-09-21
 * @brief
 * coding-exercise: 29. Diz-se que um número inteiro N é um quadrado perfeito se existirem M números ímpares consecutivos a partir do valor 1 cuja soma é igual a N. 
 * Neste caso N=M2. Exemplo: 16=1+3+5+7 (16 é igual à soma dos quatro primeiros ímpares a partir de 1) e 16=42. 
 * Logo 16 representa um quadrado perfeito. 
 * Faça um programa que verifique se um valor inteiro positivo fornecido pelo usuário é um quadrado perfeito.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{

	int numero, somatorio=0, impar=-1, base = 1, contador=0; 
	printf(" Insira um valor e verifique se este é ou não um quadrado perfeito: ");
	scanf("%d", &numero);
	
	printf("Somando ímpares consecutivos menores que %d ...\n", numero);
	while (somatorio < numero)
	{
		
		if (impar==-1)
		{
			impar+=2;
			contador+=1;
			somatorio+=impar;
			printf(" %d", impar);
			continue;
		}
		
		impar+=2;
		contador+=1;
		somatorio+=impar;
		printf(" + %d", impar);
		
		
	}
	
	while (base*base < numero)
	{
		base+=1;
	}
	
	
		printf( " = %d\n", somatorio);
		
	if (somatorio == numero)
	{
			printf( " %d² = %d", base, base*base);
			printf("\nO número é um quadrado perfeito. pois existe %d números ímpares consecutivos a partir do valor 1 cuja soma é igual a %d.", contador, numero);
	}
	else
	{
		printf("\nO número não é um quadrado perfeito, pois não existe uma quantidade de números ímpares consecutivos a partir do valor 1 cuja soma é igual a %d. (Pela sequência, o número perfeito posterior é %d)", numero, somatorio);
	}
	

        return 0;


}

