/**
 * @file array05.c
 * @author Guilherme Castro
 * @date 2025-10-19
 * @brief
 * Enunciado: 5. Faça um programa que preencha um vetor com N números aleatórios, sorteados no intervalo entre X e Y.
 * O programa deve informar a posição (índice) onde se encontra o menor número sorteado, seguido da posição onde se encontra o segundo menor número sorteado, e assim sucessivamente…
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int X, Y, N, cont=0;
	do {
		system("clear");
		printf("Insira um número maior que 0 para o tamanho do vetor: ");
		scanf(" %d", &N);
	} while (N<0);
	
	do{
		system("clear");
		printf("Tamanho do vetor: %d espaços.\n",N);
		printf("Insira o intervalo mínimo e o intervalo máximo dos números sorteados.\n (O tamanho do intervalo não pode ser menor que o tamanho do vetor): ");
		scanf(" %d %d", &X, &Y);
		
		if (Y < X) {
			int valor = Y;
			Y = X;
			X = valor;
		}
		if ((Y-X-1) < N)
			continue;
		break;
	} while (1);
	
	int vetor[N]; 
	system("clear");
	for (int i = 0; i < N; i++) 
		vetor[i] = -1;
		
	do {
		int flag = 1;
		int valor = (X+1 + rand()%(Y-X-1));
		for (int i = 0; i < N; i++) {
			if (vetor[i]==valor) {
				flag = 0;
				break;
			}
		}
			if (flag) {
			vetor[cont] = valor;
			cont++;
			}
	} while (cont < N);
	
	 int j = 0;
	 cont = 0;
	do {	
		for (int i = 0, menor = X+1+j ; i < N; i++) {
			if (menor == vetor[i]) {
				printf(" - %2dº menor nº sorteado: (%02d) | Posição no vetor: [%02d] \n", cont+1, vetor[i], i);
				cont++;
				break;
			}
		}
		j++;
	} while (j < (Y-X-1));
	
        return 0;
}

