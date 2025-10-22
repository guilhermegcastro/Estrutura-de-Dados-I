/**
 * @file Exercicio04.c
 * @author Guilherme Castro
 * @date 2025-09-08
 * @brief
 * coding-exercice: 4- Operações Básicas : O custo final de um produto numa fábrica qualquer é a soma do custo de produção (float), acrescido de X% de impostos e, acumuladamente, Y% de custos do distribuidor.
 * Sendo X e Y valores inteiros informados pelo usuário, faça um programa em C (função única) que imprime o custo final de um produto após a incidência das taxas.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	float custo;
	int imposto, distri;
	
	printf("Insira (separando por <space> ou <enter>) o custo de produção do produto, o imposto e a taxa do vendedor:\n");
	scanf("%f ", &custo);
	scanf(" %d", &imposto);
	scanf(" %d", &distri);
	
	custo = custo + (custo*((imposto+distri)*0.01));
	
	printf("Valor final do produto após incidência de taxas: R$%.2f", custo );

        return 0;


}

