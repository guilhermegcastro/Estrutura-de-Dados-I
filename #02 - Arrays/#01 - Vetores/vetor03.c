/**
 * @file vetor03.c
 * @author @guilhermegcastro
 * @date 2025-10-15
 * @brief
 * Enunciado: 3. Faça um programa que preencha um vetor com N números inteiros aleatórios, sorteados no intervalo entre 0 e X. 
 * O programa deve imprimir os números sorteados, e ao final o seguinte resumo:
 * a) Quantos números distintos foram sorteados.
 * b) As posições (índices) do maior e do menor valor.
 * c) O(s) número(s) mais vezes sorteado, e quantas vezes.
 * d) O(s) número(s) menos vezes sorteado, e quantas vezes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	
	srand(time(NULL));
	int X, cont=0;
	
	printf("Insira o número do intervalo: ");
	scanf(" %d", &X);
	int vetor[X];
	
	printf(" Sorteio de números entre 0 e %d\n ", X);
	for (int i = 0; i < X; i++){
		vetor[i] = 1 + rand()%(X-1);
		printf("[%d] ", vetor[i]);
	}
	
	for (int i = 0; i < X; i++){
		int flag = 1;
		for (int j = 0; j < X; j++){
			
			if ((vetor[i]==vetor[j]) && (i!=j))	{
				flag = 0;
				break;
			}
		}
		if (flag){
			cont+=1;
		}
	}
	printf("\n Quantidades de números distintos: %d\n", cont);
	
	int maior=0, menor=0;
	for (int i = 0; i < X; i++) {
		if (!i) {
			maior = i;
			menor = i;
			continue;
		}
		maior = (vetor[i] > maior) ? i : maior;
		menor = (vetor[i] < menor) ? i : menor;	
	}
	
		printf("\n Índice do maior número: %d\n Índice do menor número: %d", maior, menor);
        return 0;
}

