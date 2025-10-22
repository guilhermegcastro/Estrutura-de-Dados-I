/**
 * @file vetor02.c
 * @author @guilhermegcastro
 * @date 2025-10-15
 * @brief
 * Enunciado: Faça um programa que preencha um vetor com N números aleatórios, sorteados no intervalo entre 0 e N.
 * Imprima como resultado, todos os números sorteados e:
 * a) Os valores que coincidiram com o próprio índice do vetor.
 * b) Os valores que não foram sorteados.
 * c) Os valores sorteados repetidamente (mais de uma vez).
 * d) O menor valor da metade inicial e o maior valor da metade final.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	
	srand(time(NULL));
	int N, menor=0, maior=0;
	do{
		system("clear");
		printf("Insira o intervalo máximo do sorteio de números: ");
		scanf(" %d", &N);
	} while (N < 1);
	
	int sorteio[N];
	
	printf("Números sorteados:\n");
	for (int i = 0; i < N; i++) { //Impressão de números aleatórios de 0 a N.
		sorteio[i] = 1 + rand()%(N-1);
		printf("[%d] ", sorteio[i]);
	}
	
	printf("\n Valores que coincidiram com o próprio indíce do vetor:\n");
	for (int i = 0; i < N; i++) { // Loop para encontrar números que o índice e o valor sejam o mesmo.
		if (sorteio[i] == i) {
			printf("[%d] ", sorteio[i]);
		}
	}
	
	printf("\n Valores não sorteados pelo vetor:\n");
	
	for (int i = 1; i < N; i++) { // Loop para encontrar números não sorteados.
		
		int flag = 1; 
		
		for (int vetor = 0; vetor < N; vetor++) {
			
			if (i == sorteio[vetor]) {
				flag = 0; break;
			}
		}
		if (flag) {
			printf("[%d] ", i);
			}
	}

	printf("\n Valores que foram sorteados mais de uma vez:\n");
	for (int i = 0, rp = 0; i < N; i++) { // Loop para encontrar números repetidos.
		int repetido[N], flag = 0;
		
		for (int vetor = N-1, j=0 ; vetor > i; vetor--) {
			
			if (sorteio[i] == sorteio[vetor]) {
				flag = 1; 
				do { 
			     if (sorteio[i]==repetido[j]) {
					 flag = 0;  break;
				 }
				 j++;
				} while (i > j); //verifica se esse número apareceu antes. Caso sim, ele muda a flag para 0, para que a impressão do número repetido só aconteça uma vez.
				repetido[rp] = sorteio[i]; rp++; break; // Guarda o número repetido em outro vetor, para a verificação.
			}
			
		}
		if (flag) {
			printf("[%d] ", sorteio[i]);
			}
	}
	
	for (int i = 0; i < N; i++) {
		if (i < N/2) {
			if(!i)
				menor = sorteio[i];
			menor = (sorteio[i] < menor)? sorteio[i] : menor; 
			continue;
		}
		if(i==N/2)
			maior = sorteio[i];
		maior = (sorteio[i]>maior)? sorteio[i] : maior; 

		}
	
		printf("\n Menor valor da primeira metade do vetor: \n[%d]\n Maior valor da segunda metade do vetor: \n[%d]\n", menor, maior);
        return 0;
	}
		
	




