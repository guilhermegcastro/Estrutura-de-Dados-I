/**
 * @file    {file}
 * @author  @guilhermegcastro
 * @date    2025-10-30
 * @brief   Programa que lê três nomes em uma matriz de char, ordena internamente e imprime em ordem alfabética.
 */

#include <stdio.h>
#include <string.h>
int main() {
	
	char nomes[3][100];
	
	for (int i = 0; i < 3; i++) {
		printf("Insira o %dº nome:\n > ", i+1);
		scanf(" %[^'\n']s", nomes[i]);
	}
	
	int flag;
	do {
		flag = 0;
		for (int i = 0; i < 2; i++) {
			if(strcmp(nomes[i], nomes[i+1]) >= 0) {
				char troca[100];
				strcpy(troca, nomes[i]);
				strcpy(nomes[i], nomes[i+1]);
				strcpy(nomes[i+1], troca);
				flag=1;
			}
		}
	} while (flag);
		printf("Nomes inseridos em ordem alfabética:\n\n");
		for (int i = 0; i < 3; i++)
			printf(" - %s\n", nomes[i]);
	
	
    return 0;
}
