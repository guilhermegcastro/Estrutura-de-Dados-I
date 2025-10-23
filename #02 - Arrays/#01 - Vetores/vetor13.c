/**
 * @file    vetor13.c
 * @author  @guilhermegcastro
 * @date    2025-10-22
 * @brief   Enunciado: 13. Gere um vetor de tamanho aleatório (no máximo 30) e preencha-o com valores também aleatórios entre 0 e 10. 
 * Sabe-se que o ponto de equilíbrio de um vetor é o índice no qual, partindo deste índice o lado esquerdo possui exatamente o mesmo valor de soma do que o lado direito. 
 * Gere e imprima inúmeros vetores até encontrar algum que possua ponto de equilíbrio, e qual é este ponto.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	
	srand(time(NULL));
	int pontoE=0, cont=0;
	
	do {
		int N = 1+ rand()%30;
		int vetor[N];
		for (int i = 0; i < N; i++)  vetor[i] = rand()%11;	
		
		for (int i = 0; i < N; i++) {
			
			int esquerdo=0, direito=0; 
			for (int j = 0; j < i; j++) esquerdo+= vetor[j];
			for (int j = N-1; j > i; j--) direito+= vetor[j];
			
			if(esquerdo==direito) {
				pontoE = i;
				break;
			}
			
		}
		
		printf("%dº Vetor:\n", cont+1);
		for (int i = 0; i < N; i++) printf(" [%d]",vetor[i]);
		
		if(pontoE) {
		printf("\n O vetor possui ponto de Equilíbrio! Este é o número [%d] na posição |%d|\n A soma do lado esquerdo e do lado direito são iguais.\n\n FIM DO PROGRAMA!", vetor[pontoE], pontoE);
		break;
		}
		printf("\n Este vetor não possui um ponto de Equilíbrio. Tentando Novamente...\n\n");
		cont++;
	} while (1);
	

	
    return 0;
    
}
