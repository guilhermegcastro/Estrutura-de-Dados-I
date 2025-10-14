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
		dado[face-1] += 1; 
		
	}
	printf("\n O dado foi jogado %d vezes! Confira os resultados: \n\n", vezesN);
	
	for (int i = 0; i < 6; i++)
		printf(" A face %d caiu para cima %d vezes (%.2f%%)\n", i+1, dado[i], 100*((float)dado[i]/vezesN));

	
		
        return 0;
}
