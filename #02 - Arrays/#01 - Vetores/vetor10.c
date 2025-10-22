/**
 * @file vetor10.c
 * @author @guilhermegcastro
 * @date 2025-10-22
 * @brief
 * Enunciado: 10. Métodos: map, filter e reduce são bastante comuns em linguagens de alto nível para tratamento de Arrays. 
 * Faça um programa que implemente o método…
 * MAP => Dado um vetor V1, com N números inteiros sorteados entre 0 e 1023, crie um novo vetor V2, preenchendo-o com os valores do primeiro array convertidos para a base binária. 
 * Imprima V1 e V2.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	
	srand(time(NULL));
	int N;
	printf("Insira a quantidade de números aleatórios entre 0 e 1023: ");
	scanf(" %d", &N);
	int V1[N], V2[N];
	

	for (int i = 0; i < N; i++) V1[i] = rand()%1024;
	
	printf("Conversão dos números Decimais --> Binários\n");
	printf("Nº Decimais ---- Nº Binários\n");
	
	for (int i = 0; i < N; i++) {

		int numero = V1[i], binario = 0, multiplicador = 1;
		
		do {
			int zeroUm = numero%2;
			numero /= 2;
			binario += zeroUm * multiplicador;
			multiplicador *= 10;
		} while (numero>0);
		
		V2[i] = binario;
		printf("    [%04d]  ---- [%010d]\n", V1[i], V2[i]);
	}
		
	
        return 0;
}

