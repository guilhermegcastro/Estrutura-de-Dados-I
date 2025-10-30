/**
 * @file    vetor17.c
 * @author  @guilhermegcastro
 * @date    2025-10-24
 * @brief   
 * Enunciado: 17. Faça um programa que gere um vetor com K números aleatórios entre 0 e N.
 *  Após isso, peça um número X ao usuário, e consulte pelo valor de PISO (maior número menor ou igual a X) e valor de TETO (menor número maior ou igual a X). 
 * Faça várias buscas, sempre utilizando o algoritmo de Pesquisa Binária.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

	int K, N;
	
	printf("Insira a quantidade de números sorteados:");
	scanf("  %d", &K);
	
	int vetor[K];
	
	printf("Insira o intervalo (não inclusive) máximo do sorteio:");
	scanf("  %d", &N);
	
	for (int i = 0; i < K; i++) vetor[i] = rand()%N;
	
	int fim;
	do {
		fim = 1;
		for (int i = 0; i < K-1; i++) {
			if(vetor[i] > vetor[i+1]) {
			int troca = vetor[i];
			vetor[i] = vetor[i+1];
			vetor[i+1] = troca;
			fim=0;
			}
		}
	} while (!fim);

	int X;
	do {
		system("clear");
		printf("Vetor: ");
		for (int i = 0; i < K; i++) printf("%d ", vetor[i]);
		printf("\n\n Insira um número de %d a %d para começar a busca. Insira -1 para encerrar:\n > ", vetor[0],vetor[K-1]);
		scanf(" %d", &X);
		
		if(X==-1) {
			system("clear");
			printf("\n\n\t FIM DO PROGRAMA.");
			return 0;
		} else if (X < vetor[0] || X > vetor[K-1]){
			printf("O número inserido está fora do intervalo. Aperte ENTER e tente novamente.");
			while(getchar()!='\n');
			getchar();
			continue;
		}
		
		int inicio=0, fim=K-1, piso=0, teto=0;
		
	
		
		inicio = 0; fim = K-1;
		while (inicio<=fim){ //Busca do teto
			
			int meio = (inicio+fim)/2;
			
			if (X==vetor[meio]){
				teto=vetor[meio];
				piso=vetor[meio];
				break;
			}
		
			if (X < vetor[meio]) {
				teto=vetor[meio];
				fim = meio - 1; 
			} else {
				piso=vetor[meio];
				inicio = meio + 1; 
			}
			
		}
		
		if (piso!=teto) printf("Piso: %d\n Teto: %d\n", piso, teto);
		if (piso==teto) printf("Piso e teto: %d\n", X);
		printf("\n Aperte ENTER para prosseguir...");
		while(getchar()!='\n');
		getchar();
		
		
	} while (1);
}
