/**
 * @file    vetor20.c
 * @author  @guilhermegcastro
 * @date    2025-10-28
 * @brief   
 * Enunciado: 20. Faça um programa que alimenta um array de N inteiros sorteados entre 1 e 10, e onde cada valor representa o número de chocolates em um pacote. 
 * Considerando que existam M alunos (M < N) na turma, a tarefa do seu programa é informar quais pacotes de chocolate devem ser distribuídos de forma que:
 *  (i) cada aluno deve receber apenas um pacote; 
 * (ii) A diferença entre a quantidade de chocolates que cada aluno irá receber deve ser a mínima possível.
 *  Em caso de empate (como o prof é gente boa) a distribuição deve ser dos pacotes que contiverem mais chocolates.
 * P.Ex.: Pacotes == [2, 5, 1, 4, 9, 6, 9], sendo M = 3. 
 * Resultado Esperado: Distribuir pacotes contendo 4, 5, 6.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	
	srand(time(NULL));
	int N, M; 
	printf("Insira a quantidade de pacotes de chocolate: ");
	scanf(" %d", &N);
	
	do {
		printf("Insira a quantidade de alunos: ");
		scanf(" %d", &M);
		if (M < N) break;
		printf("A quantidade de alunos tem que ser menor que a quatindade de pacotes!\n");
	} while (1);
	
	int pacotes[N];
	
	printf("\n Pacotes sorteados:\n [");
	for (int i = 0; i < N; i++) {
		pacotes[i] = 1 + rand()%10;
		printf(" %d", pacotes[i]);
		(i!=N-1) ? putchar(',') : printf(" ]");
	}
	
		
	int flag;
	do {
		flag = 1;
		for (int i = 0; i < N-1; i++) {
			if (pacotes[i] < pacotes[i+1]) {
				flag = 0;
				int troca = pacotes[i];
				pacotes[i] = pacotes[i+1];
				pacotes[i+1] = troca;
			}
		}
		
	} while (!flag);
	
	for (int i = 0; i < N-M; i++) { 
	
	}
	
		

	int menorDiferenca=11, firstI;
	for (int i = 0; i < N-M; i++) {
		if (pacotes[i]-pacotes[i+(M-1)]<menorDiferenca) {
			menorDiferenca = pacotes[i] - pacotes[i+(M-1)];
			firstI = i;
		}
	}
	
	printf("\n\n Distribuição dos pacotes entre os %d alunos:\n [", M);
	for (int i = 0; i < M; i++) {
		printf(" %d", pacotes[firstI+i]);
		(i!=M-1) ? putchar(',') : printf(" ]");
	}
	
	
	
	
	
    return 0;
}
