/**
 * @file vetor07.c
 * @author @guilhermegcastro
 * @date 2025-10-19
 * @brief
 * Enunciado: 7. Gere dois vetores, V1 e V2, cada um com K valores aleatórios sorteados no intervalo entre 0 e X (0<K<X).
 * O usuário deve informar o valor de K e X, desde que K < X.
 *  O programa NÃO deverá aceitar números repetidos no mesmo vetor, e nem o mesmo número no mesmo índice dos dois vetores. 
 * Imprima os valores sorteados nos dois vetores, e o resultado da multiplicação dos valores dos índices de V1 e V2.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

	int K, X;
	
	do{
		system("clear");
		printf("Insira a quantidade de números aleatórios desejados:");
		scanf(" %d", &K);
	} while (K < 1);
	
		do{
			system("clear");
			printf("Insira o intervalo máximo do sorteio. \n(Não pode ser menor que a quantidade anterior): ");
			scanf(" %d", &X);
	} while (X < K);
	
	system("clear");
	int V1[K], V2[K], cont=0;
	
	for (int i = 0; i < K; i++) V1[i] = V2[i] = X;
	
		printf("Vetor 1:\n\n");
		do {
			int flag = 1;
			int valor, valor2;
			do {
				valor = rand()%X;
				valor2 = rand()%X;
			} while (valor==valor2);
			
			for (int i = 0; i < K; i++) {
				if ((V2[i] == valor2) || (V1[i]== valor)){
					flag = 0;
					break;
				}
			}
			if (flag) {
				V1[cont] = valor;
				V2[cont]= valor2;
				printf("[%d]", V1[cont]);
				cont++;
			}
		} while (cont < K);
		printf("\n\nVetor 2:\n\n");
		for (int i = 0; i < K; i++)
			printf("[%d]", V2[i]);
		
		printf("\n\nMultplicação do Vetor 1 pelo Vetor 2 de acordo com o índice:\n\n");
		for (int i = 0; i < K; i++)
			printf("[%d]", V1[i]*V2[i]);
		
		
	
        return 0;


}

