/**
 * @file Exercicio07.c
 * @author Guilherme Castro
 * @date 2025-09-08
 * @brief
 * coding-exercice:7 - Typecast : Faça um programa em C que leia dois valores do tipo inteiro X e Y. 
 * Após isso, faça a impressão da divisão entre X e Y (teste valores que não dê divisão exata). 
 * Imprima também o resultado do resto da divisão (mod) entre X e Y. 
 * Pesquise o conceito de typecast e porque foi necessário aplicá-lo.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	int X, Y; 	
	
	printf("INSIRA 2 VALORES\n"); scanf("%d %d", &X, &Y); //Uma divisão entre números inteiros sempre resultará em um resultado inteiro. 
	
	printf(" %d / %d = %d (com resto %d)", X, Y, X/Y, X%Y);
	
	printf("\n\n %d / %d = %f", X, Y, (double)X/(double)Y); //Utilizando typercast (que é a troca de valores temporária), o resultado da divisão passa a ser REAl, e não INTEIRO, aparecendo no formato de leitura '%f' a divisão com resultado fracionado, caso não seja exata.

        return 0;


}

