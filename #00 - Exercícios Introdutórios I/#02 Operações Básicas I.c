/**
 * @file Exercicio02.c
 * @author Guilherme Castro
 * @date 2025-09-06
 * @brief
 * coding-exercice: 2 - Operações Básicas : Faça um programa em C (em função única) que solicite 2 número inteiros do usuário e imprima:
 * a) O resultado das quatro operações básicas (soma, adição, subtração e multiplicação).
 * b) O quadrado da subtração do primeiro pelo segundo.
 **/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{

	int n1, n2;
	printf("Insira 2 números inteiros:\n");
	scanf("%d %d", &n1, &n2);
	
	printf("%d + %d = %d\n", n1, n2, n1+n2);
	printf("%d - %d = %d\n", n1, n2, n1-n2);
	printf("%d x %d = %d\n", n1, n2, n1*n2);
	printf("%d / %d = %d\n", n1, n2, n1/n2); 
	printf("%d - %d = %d -> %d² = %d\n", n1, n2, n1-n2, n1-n2, (n1-n2)*(n1-n2));
	        return 0;
} 
