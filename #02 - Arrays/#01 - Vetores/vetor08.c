/**
 * @file vetor08.c
 * @author @guilhermegcastro
 * @date 2025-10-19
 * @brief
 * Enunciado: 8. O algoritmo LRU (Least Recently Used) é uma política de gerenciamento de memória cache que invalida o item que foi acessado menos recentemente. 
 * Isso significa que se um item não foi acessado há muito tempo, ele terá prioridade na remoção. Considere um vetor com N elementos, sorteados no intervalo entre X e Y (inclusive). 
 * Considerando que os primeiros índices foram os acessados recentemente, exclua da lista o elemento conforme algoritmo LRU (todos os itens iguais devem ser excluídos na mesma iteração). 
 * Solução in-place (não deve-se usar vetor auxiliar). 
 * Execute essa operação N vezes, ou seja, até que o array esteja vazio novamente. Imprima o conteúdo da “memória cache” em cada iteração.
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
	
	int memoria[N], menosusado;
	
	for (int i = 0; i < N; i++) 
		memoria[i] = X+ rand()%(Y-X+1);
		
	do {
		printf("Memória de Cache:");
		for (int i = 0; i < N; i++) {
			if (memoria[i]==Y+1)
				continue;
			printf("[%d]", memoria[i] );
		}
		printf("\n");
	

		for (int i = 0; i < N; i++){
			int flag = 1;
			if(memoria[i]==Y+1) continue;
			
				for (int j = 0; j <= i-1; j++) {
					if(memoria[j]==Y+1)  continue;
					if (memoria[j]==memoria[i]) {
						flag = 0;
						break;
					}
				}
				
				if(flag) {
				 menosusado = memoria[i];
				}
			
		}
		
		for (int i = 0; i < N; i++){
			if (memoria[i]==menosusado)
				memoria[i]= Y+1;
		}
		if (menosusado==Y+1) {
			 printf("VAZIA!"); 
			 break;
		}
		
		menosusado = Y+1;
		getchar();
		
	} while (1);
	
        return 0;
}

