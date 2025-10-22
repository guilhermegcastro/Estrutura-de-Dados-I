/**
 * @file vetor09.c
 * @author @guilhermegcastro
 * @date 2025-10-22
 * @brief
 * Enunciado: 9. Implemente a solução do mesmo problema anterior, mas agora considerando que o algoritmo adotado seja o LFU (Least Frequently Used).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

		srand(time(NULL));
	int N, X, Y; 
	
	printf("Tamanho do vetor: ");
	scanf(" %d", &N);
	printf("Intervalo mínimo: ");
	scanf(" %d", &X);
	printf("Intervalo máximo: ");
	scanf(" %d", &Y);
	
	int memoria[N];
	
	for (int i = 0; i < N; i++) memoria[i] = X+ rand()%(Y-X+1);
		
		printf("LFU : Vetor inicial. ");
		for (int i = 0; i < N; i++) 
			printf("[%d]", memoria[i]);
	
	do {
		printf("\n Aperte Enter para próxima iteração.\n");
		while(getchar()!='\n');
		getchar();
		
		int menorfrequencia=Y+1, numero=N;
		
		for (int i = 0; i <N; i++) {
			if(memoria[i]==Y+1) continue;
			int frequencia=0;
			for (int j = 0; j < N; j++) {
				
				if (memoria[j]==memoria[i]) {
					frequencia++;	
				}	
			}
			if (frequencia < menorfrequencia) {
				numero = memoria[i];
				menorfrequencia = frequencia; 
			}
		}
		
		for (int i = 0; i < N; i++) {
			if (memoria[i]==numero) {
				memoria[i]= Y+1;
			}
		}
	
		if(numero == N) {
			printf("FIM");
			break; 
		}
		printf("Mémoria de Cache: ");
		for (int i = 0; i < N; i++) {
			if (memoria[i]==Y+1) continue;
			printf("[%d]", memoria[i]);
		}
	
	} while (1);
	

        return 0;
}

