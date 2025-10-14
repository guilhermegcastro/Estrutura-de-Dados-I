/**
 * @file array02.c
 * @author Guilherme Castro
 * @date 2025-10-13
 * @brief 
 * Enunciado: Um apostador joga um dado para o ar N vezes (N definido pelo usuário). 
 * Sabendo que um dado possui 6 faces, faça um programa que simula o experimento. 
 * Como resultado, imprima quantas vezes que cada face (não quais faces) caiu para cima e o % de cada face.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( ) {
	
	srand(time(NULL));
	int vezesN, dado[6] = {0}, face;
	
	printf("Digite o número de vezes que o apostador jogará o dado:");
	scanf(" %d", &vezesN);
	
	for (int i = 0; i < vezesN; i++) {
		face = rand()%6 + 1;
		switch (face) {
			case 1: dado[0] += 1; break;
			case 2: dado[1] += 1; break;
			case 3: dado[2] += 1; break; 
			case 4: dado[3] += 1; break;
			case 5: dado[4] += 1; break;
			case 6: dado[5] += 1; break;
		}
	}
	printf("\n O dado foi jogado %d vezes! Confira os resultados: \n\n", vezesN);
	
	for (int i = 0; i < 6; i++)
		printf(" A face %d caiu para cima %d vezes (%.2f%%)\n", i+1, dado[i], 100*((float)dado[i]/vezesN));

	
		
        return 0;
}

