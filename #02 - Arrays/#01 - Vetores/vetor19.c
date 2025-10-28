/**
 * @file    vetor19.c
 * @author  @guilhermegcastro
 * @date    2025-10-25
 * @brief   
 * Enunciado: 19. Gere um array com N valores inteiros sorteados entre 0 e 99. Após isso, peça ao usuário um valor X e verifique se há no array um par de valores (V1 e V2), tal que:
 * V1 - V2 == X; ou V1 * V2 == X;
 * V1 + V2 == X; ou V1 / V2 == X;
 * Imprima todos os pares (V1 e V2) que satisfaça alguma dessas condições.
 * PS.: Pare, pense e analise qual seria a solução mais eficiente para este problema?
 *  Imagine as possíveis soluções considerando um valor muito alto para N.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	
	srand(time(NULL));
	int N, X;
	printf("Insira o tamanho do vetor:");
	scanf(" %d", &N);
	int vetor[N], contador[100]= {0};
	
	printf("VETOR:\n");
	for (int i = 0; i < N; i++) {
	vetor[i] = rand()%100;
	printf(" %d", vetor[i]);
	contador[vetor[i]]++;
	}
	
	printf("\n\nInsira um valor para verificar se há operações:");
	scanf(" %d", &X);
	
	
	
	int V1s=0, V2s=-1, V1v=0, V2v=-1, V1m=0, V2m=-1, V1d=0, V2d=-1;
	
	for (int i = 0; i < N; i++) {
		int V1 = vetor[i];
		int V2 = 0;
		if (V2s==-1 && V2v == -1 && V1 >= X){ 
			V2 = V1 - X;
			if (contador[V2]>0) {
				V1s = V1; 
				V2s = V2;
			}
		}
		
		if (V2s==-1 && V2v ==-1) { 
			V2 = X/V1 ;
			if (contador[V2]>0) {
				V1v = V1; 
				V2v = V2;
			}
		}
		
		if (V2m ==-1 && V2d==-1&& X>=V1) {
			V2 = X-V1 ;
			if (contador[V2]>0) {
				V1m = V1; 
				V2m = V2;
			}
		}
		
		if (V2m ==-1 && V2d==-1 && X!=0 && V1%X==0) {
				V2 = V1/X;
				if (contador[V2]>0) {
					V1d = V1; 
					V2d = V2;
				}
		}
		
		if((V1s || V1v) &&( V1m || V1d))break;
	
	}
	if(V1s || V1v) {
		(V1s) ? printf("\n %d - %d = %d", V1s, V2s, X) : printf("\n %d * %d = %d", V1v, V2v, X);
	} else printf("Não foi encontrado operações de subtração ou multiplicação que resulte %d", X);
	if(V1m || V1d) {
		(V1m) ? printf("\n %d + %d = %d", V1m, V2m, X) : printf("\n %d / %d = %d", V1d, V2d, X);
	} else printf("Não foi encontrado operações de adição ou divisão que resulte %d", X);
	

    return 0;
}
