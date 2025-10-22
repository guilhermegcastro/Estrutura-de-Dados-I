/**
 * @file vetor11.c
 * @author @guilhermegcastro
 * @date 2025-10-22
 * @brief
 * Enunciado: 11. Métodos: map, filter e reduce são bastante comuns em linguagens de alto nível para tratamento de Arrays. Faça um programa que implemente o método…
 * FILTER => Dado um vetor V1, com N números inteiros sorteados entre 0 e 99, e um outro valor inteiro X, crie um novo vetor V2, preenchendo-o apenas com valores do primeiro vetor que são múltiplos de X. 
 * Um mesmo valor não deve ser filtrado mais de 1 vez. 
 * Imprima V1 e V2.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main( ) {
	srand(time(NULL));
	int N, X;
	printf("Insira a quantidade de números sorteados de 0 a 99: ");
	scanf(" %d", &N);
	
	do {
		printf("Insira um número entre 0 e 99 será o filtro:");
		scanf(" %d", &X);
	
	} while (X < 0 || X > 99);
	
	int V1[N], V2[N];	
	
	printf("\n Números aleatórios sorteados de 0 a 99:\n\n");
	for (int i = 0; i < N; i++) {
		V1[i] = rand()%100;
		V2[i] = -1;
		printf(" [%d]", V1[i]);
	}
	
	putchar('\n');
	for (int i = 0; i < N; i++) {
		if (V1[i]%X!=0 || V1[i]==0) continue;
		int flag = 1; // flag que sinaliza se o número divisivel por X apareceu antes ou não
		for (int j = 0; j <= i; j++){
			if (V1[i]==V1[j] && j!=i) {
				flag = 0; //muda para 0 caso ele encontre um repetido;
				break;
			}
		}
		if(flag) V2[i] = V1[i];
	}
	
	
	printf("\n Números do sorteio que são divisíveis por %d:\n\n", X);
	for (int i = 0; i < N; i++) {
		if (V2[i]==-1) continue;
		printf(" [%d]", V2[i]);
	}
	
	
	


        return 0;
}

