/**
 * @file    vetor12.c
 * @author  @guilhermegcastro
 * @date    2025-10-22
 * @brief	
 * Enunciado: 12. Métodos: map, filter e reduce são bastante comuns em linguagens de alto nível para tratamento de Arrays. 
 * Faça um programa que implemente o método…
 * REDUCE => Dado um vetor V, com N números inteiros sorteados aleatoriamente (entre 0 e 9), imprima a maior sequência crescente do vetor (em caso de empate, imprima a primeira sequência).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	srand(time(NULL));
	long int N; 
	printf("Digite a quantidade desejada de números que serão sorteados:");
	scanf(" %ld", &N);
	int V[N+1];
	
	printf("Sequência Atual:\n ");
	for (int i = 0; i < N; i++) {
		V[i]= rand()%10;
		printf(" [%d]", V[i]);
	}
	
		V[N] = -1;
	putchar('\n');
	
	int indiceRecorde=0, tamanhoRecorde=0;
	
	
		for (int  i = 0; i < N; i++) {
			
			int indiceAtual = i, tamanhoAtual = 0;
			
			for (int j = indiceAtual; j < N; j++) {
				if(V[j] < V[j+1]) {
					tamanhoAtual++;
					continue;
				}
				break;
			}
			if (tamanhoAtual > tamanhoRecorde) {
				indiceRecorde = indiceAtual;
				tamanhoRecorde = tamanhoAtual;
			}
		}
	
	printf("Maior sequência crescente do vetor:\n ");
	
	for (int i = indiceRecorde; i < indiceRecorde+tamanhoRecorde+1; i++) printf(" [%d]", V[i]);
	
    return 0;
}
