/**
 * @file    vetor18.c
 * @author  @guilhermegcastro
 * @date    2025-10-22
 * @brief  
 * Enunciado: 18. Faça um programa que alimente um vetor com N números aleatórios sorteados no intervalo entre X e Y.
 * Faça a ordenação deste vetor, mas considerando a frequência de cada número sorteado.
 * P.Ex.: 5 - 5 - 5 - 5 - 8 - 8 - 8 - 3 - 3 - 6 - 6 - 9 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	
	srand(time(NULL));
	int N, X, Y;
	printf("Insira a quantidade de números sorteados:");
	scanf("  %d", &N);
	
	int vetor[N];
	
	do {
		printf("Insira o intervalo (não inclusive) mínimo do sorteio:");
		scanf("  %d", &X);
	
		printf("Insira o intervalo (não inclusive) máximo do sorteio:");
		scanf("  %d", &Y);
		if(X!=Y) break;
		printf("Os números dos intervalos não podem ser o mesmo!\n");
	} while (1);
	
	if(X > Y) {
		int Z = X;
		X = Y;
		Y = Z;
	}
	
	int intervalo = Y-X-1;
	int contador[intervalo];
	for (int i = 0; i < intervalo; i++) contador[i] = 0;
	
	printf(" Vetor:\n");
	for (int i = 0; i < N; i++) {
		vetor[i]=(X+1) + rand()%(Y-X-1);
		printf(" %d", vetor[i]);
	 }
	
	for (int i = 0; i < N; i++) {
		int n = vetor[i];
		contador[n-X-1]++;
	 }
	 
	int cont=0, maior=0;
	
	printf("\n Reogarnizado de acordo com a frquência:\n");
	do {
	
		int first = 1;
	for (int i = 0; i < intervalo; i++) {
		if(contador[i]==0) continue;
		if (first) {
			maior = i;
			first = 0;
			continue;
		 }
		if (contador[maior] < contador[i]) 
		maior = i;
	}


	for (int i = 0; i < contador[maior]; i++) {
		vetor[cont+i] = maior+1+X;
	}
	
	cont+= contador[maior];
	contador[maior] = 0;
	maior=0;
	
	} while (cont<N);
	
	for (int i = 0; i < N; i++) {
		printf(" %d", vetor[i]);
	 }

	

	
    return 0;
}
