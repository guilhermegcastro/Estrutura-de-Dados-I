/**
 * @file    vetor15.c
 * @author  @guilhermegcastro
 * @date    2025-10-23
 * @brief   
 * Enunciado:  15. A bandeira da Itália possui três cores, nesta sequência: VERDE | BRANCO | VERMELHO
 * Faça um programa que sorteia aleatoriamente um vetor de tamanho N com valores que representam as 03 cores da bandeira italiana. 
 * Seu programa deve gerar como resultado a quantidade de bandeiras que podem ser formadas a partir desse Array. 
 * Todas operações devem ser in-place (Não é permitido usar arrays auxiliares). 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	
	srand(time(NULL));
	int N; 
	
	printf("Insira o tamanho do vetor:");
	scanf(" %d", &N);
	
	int cores[N], V=0, B=0, R=0, bandeiras=0; // 1 - Verde 2 - Branco 3 - Vermelho.
	
	printf("Cores sorteadas: (V - Verde, B - Branco, R - Vermelho.)\n");
	for (int i = 0; i < N; i++) { 
		cores[i] = 1 + rand()%3;
		switch(cores[i]) {
		
		case 1 : printf(" V "); 
			     V++; break;
		case 2 : printf(" B "); 
			     B++; break;	
		case 3 : printf(" R "); 
			     R++; break;     
		}
		
	}
	
	printf("\n %d Cor(es) Verde(s)\n %d Cor(es) Branca(s)\n %d Cor(es) Vermelha(s)\n", V, B, R);
	for (int i = 0; i < N; i++) {
		if(V && B && R) {
			bandeiras++;
			V--; B--; R--;
		}
	}
	
	printf("\nÉ possível fazer %d bandeiras com as cores sorteadas.", bandeiras);
	
	// Como a regra era só pra arrays auxiliares e não variáveis eu fiz usando variáveis ;)
	
    return 0;
}
