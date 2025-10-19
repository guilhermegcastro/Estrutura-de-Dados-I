/**
 * @file array04.c
 * @author Guilherme Castro
 * @date 2025-10-18
 * @brief
 * Enunciado: 4. Faça um programa C para ler do usuário dois valores inteiros X e Y. 
 * Alimente dois vetores de tamanhos X e Y com números inteiros aleatórios, não repetitivos, sorteados no intervalo entre 0 e X+Y (inclusive).
 * Faça a impressão das seguintes informações:
 * a) Vetores X e Y;
 * b) Todos os números exclusivos do vetor X;
 * c) Todos os números exclusivos do vetor Y;
 * d) Os números existentes nos dois vetores;
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int X, Y; 
	printf("Insira doi valores inteiros:");
	scanf(" %d %d", &X, &Y);
    int	vetorX[X], vetorY[Y], cont=0;
    
    for (int i = 0; i < X; i++) vetorX[i] = -1;
    for (int i = 0; i < Y; i++) vetorY[i] = -1;
	
    printf("Vetor de X:\n");
	
	do {
		int flag = 1;
		int valor = rand()%(X+Y+1);
		for (int i = 0; i < X; i++) {
			if (valor == vetorX[i]){
				flag = 0;
				break;
			}
		}
		if (flag){
			vetorX[cont]=valor;
			printf("[%d]", vetorX[cont]);
			cont++;
		}
	} while (cont<X);
	cont=0;
	printf("\n\nVetor de Y:\n");
	do {
		int flag = 1;
		int valor = rand()%(X+Y+1);
		for (int i = 0; i < Y; i++) {
			if (valor == vetorY[i]){
				flag = 0;
				break;
			}
		}
		if (flag){
			vetorY[cont]=valor;
			printf("[%d]", vetorY[cont]);
			cont++;
		}
	} while (cont<Y);
	
	printf("\n\nNúmeros exclusivos do vetor de X:\n");

    for (int i = 0; i < X; i++) {
		int flag=1;
		for (int j = 0; j < Y; j++) {
			if (vetorX[i]==vetorY[j]){
				flag = 0;
				break;
				}
		}
		if (flag)
		printf("[%d]", vetorX[i]);
	}
	
	printf("\n\nNúmeros exclusivos do vetor de Y:\n");

    for (int i = 0; i < Y; i++) {
		int flag=1;
		for (int j = 0; j < X; j++) {
			if (vetorX[j]==vetorY[i]){
				flag = 0;
				break;
				}
		}
		if (flag)
		printf("[%d]", vetorY[i]);
	}
	
	printf("\n\nNúmeros existentes em ambos:\n");

    for (int i = 0; i < X; i++) {
		int flag=0;
		for (int j = 0; j < Y; j++) {
			if (vetorX[i]==vetorY[j]){
				flag = 1;
				break;
				}
		}
		if (flag)
		printf("[%d]", vetorX[i]);
	}
	
        return 0;
}

