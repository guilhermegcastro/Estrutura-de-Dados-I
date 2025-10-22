/**
 * @file Exercicio10.c
 * @author Guilherme Castro
 * @date 2025-09-08
 * @brief
 * coding-exercice: 10-Laços de Repetição
 * Faça um programa em C (função única) que leia 10 valores inteiros e imprima como resultado: o maior valor lido, o menor valor e a média simples dos valores inseridos.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{

	int maior, menor, valor, media, i;
	
	maior = -1;
	menor = -1;
	
	for (i=1; i<11; i=i+1)
	{
		printf("Insira o %dº valor inteiro:", i);
		scanf("%d", &valor);
		
		if (menor == -1)
			menor = valor;
		else if (menor > valor) 
				menor = valor;
		if (maior < valor) 
			maior = valor;
		media = media + valor;
	}
	
	printf("\nMaior valor: %d\nMenor valor: %d\nMédia:%d", maior, menor, media/i);
		

        return 0;


}

