/**
 * @file vetor06.c
 * @author @guilhermegcastro
 * @date 2025-10-19
 * @brief
 * Enunciado: 6. Gere um array de N números inteiros sorteados no intervalo entre X e Y (inclusive). Imprima o array sorteado e depois elimine deste array os valores repetidos, mantendo a ordem original. 
 * A solução deve ser in place, ou seja, todas as operações devem acontecer diretamente no mesmo array de entrada (in-place), não sendo permitido portanto utilizar outros arrays auxiliares para ajudar na tarefa.
 * Imprima o array resultante após as exclusões. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	srand(time(NULL));
	
	int X, Y, N, cont=0;
	do {
		system("clear");
		printf("Insira um número maior que 0 para o tamanho do vetor: ");
		scanf(" %d", &N);
	} while (N<0);
	
		system("clear");
		printf("Tamanho do vetor: %d espaços.\n",N);
		printf("Insira o intervalo mínimo e o intervalo máximo (inclusive) dos números sorteados:");
		scanf(" %d %d", &X, &Y);
		
		if (Y < X) {
			int valor = Y;
			Y = X;
			X = valor;
		}
		system("clear");
		
	int array[N];
	printf("Sequência de números sorteados:\n\n");
	for (int i = 0; i < N; i++){
		array[i] = X + rand()%(Y-X+1);
		printf("[%d]", array[i]);
	}
	printf("\n\nArray sem números repetidos:\n\n");
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			if ((array[i]==array[j]) && (i!=j))
				array[j]= Y+1;
		}
		if(array[i]!=Y+1)
			printf("[%d]", array[i]);
	}
        return 0;


}

