/**
 * @file    string01.c
 * @author  @guilhermegcastro
 * @date    2025-10-30
 * @brief   
 * Enunciado: 21. Faça um programa em C que leia um valor inteiro correspondente ao seu número de matrícula no curso.
 *  Gera e imprime a string formada pelos dígitos deste número. P.Ex.: 2024 == “2024”.
 */

#include <stdio.h>
#include <string.h>

int main() {

	int matricula;
	char sMatricula[100];
	
	printf("Insira o número da matricula do seu curso:");
	scanf(" %d", &matricula);
	
	int cont=0, numero=matricula;
	do {
		int n = matricula%10;
		sMatricula[cont] = n +'0';
		matricula/=10;
		cont++;
	} while (matricula>0);
	
	size_t N = strlen(sMatricula);
	for (int i = 0; i < N/2; i++) {
		char troca = sMatricula[i];
		sMatricula[i] = sMatricula[N-1-i];
		sMatricula[N-1-i] = troca;
	}
	printf("%d == \"%s\"", numero, sMatricula);
	
	
	
	
	
    return 0;
}
