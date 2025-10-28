/**
 * @file    matriz02.c
 * @author  @guilhermegcastro
 * @date    2025-10-24
 * @brief   
 * Enunciado: 42. Gere aleatoriamente uma matriz N x N de inteiros sorteados no intervalo entre X e Y (inclusive).
 * Imprima-a em formato de tabela, e os valores que compõem a coluna que resulta na maior soma, e os valores da linha que resulta na menor soma.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

	srand(time(NULL));
	int N, X, Y;
	
	printf("Informe o tamanho NxN da matriz:");
	scanf(" %d", &N);
	printf("Insira o intervalo mínimo e o intervalo máximo (inclusive) do sorteio.");
	scanf(" %d %d", &X, &Y);
	
	system("clear");
	
	while (X > Y) {
		int troca = X; X = Y; Y = troca;
	}
	printf("      ");
	for (int i = 0; i < N; i++) printf("|C.%2d ", i);
	printf("|\n");
	int matriz[N][N];
	for (int i = 0; i < N; i++) {
		printf("L. %2d ", i);
		for (int j = 0; j < N; j++) {
			matriz[i][j] = X + rand()%(Y-X+1);
			printf("| %3d ", matriz[i][j]);
		}
			printf("|\n");
	}
	
	int Coluna, maiorSoma, Linha, menorSoma;
	for (int i = 0; i < N; i++) {
		int somatorioC=0;
		for (int j = 0; j < N; j++) somatorioC+= matriz[j][i];// Compara coluna
		
		int somatorioL=0;
		for (int j = 0; j < N; j++) somatorioL+= matriz[i][j];// Compara linha
		
		if(!i) {
			Linha = Coluna = i;
			menorSoma = somatorioL;
			maiorSoma = somatorioC;
			continue;
		} 
		
		if(somatorioL < menorSoma) {
			Linha = i; menorSoma = somatorioL;
		}
		
		if(somatorioC > maiorSoma) {
			Coluna = i; maiorSoma = somatorioC;
		}
		
	}
	
	printf("\n Valores que compõe a coluna |%d| (que possuí a maior soma = %d):\n ", Coluna, maiorSoma);
	for (int i = 0; i < N; i++) printf(" [%d]", matriz[i][Coluna]); 
	printf("\n Valores que compõe a linha |%d| (que possuí a menor soma = %d):\n ", Linha, menorSoma);
	for (int i = 0; i < N; i++) printf(" [%d]", matriz[Linha][i]);
	
    return 0;
}
