/**
 * @file array01.c
 * @author Guilherme Castro
 * @date 2025-10-13
 * @brief 
 * Enunciado: Faça um programa que sorteie um array com 100 números aleatórios entre 1 e 20. 
 * Depois, peça ao usuário um valor X e imprima todos os números e quantas vezes o valor X foi sorteado 
 * (Marque o símbolo * ao lado de cada aparição do valor X). Repita toda essa operação para o mesmo conjunto de dados até X <= 0.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( ) {
	
	srand(time(NULL));
	int X, contador=0, array[100];

	for (int i = 0; i < 100 ; i++) 
			array[i] =  1 + rand()%20;
	do  {
		 printf("Insira um valor entre 01 e 20 (Valores <= 0 finaliza o programa)\n > ");
		 scanf(" %d", &X);
		 
		 if(X < 1)
			break;
			
		 for (int i = 0; i < 100 ; i++) {
			printf("\n %02d", array[i]);
			if(array[i] == X) {
			   printf(" *");
			   contador+=1;
			}
		}
		 printf ("\n O número %d foi sorteado %d vezes.\n", X, contador);
		 contador=0;
	} while (1);

        return 0;
}

