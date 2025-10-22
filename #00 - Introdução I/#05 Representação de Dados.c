/**
 * @file Exercicio05.c
 * @author Guilherme Castro
 * @date 2025-09-08
 * @brief
 * coding-exercice: 5- Representação de Dados : Faça um programa em C (função única) que leia uma variável do tipo char e imprima o conteúdo dessa variável usando os formatos %ce%d. 
 * Estude o motivo da impressão de um mesmo conteúdo ser diferente. O que aconteceria se lêssemos uma variável do tipo char sob formato %d? Faça testes...
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	char chaar; 
	printf("Insira o valor da variável 'char'"); 
	chaar = getchar();
	printf("Formato de leitura %%c: %c \t Formato de leitura %%d: %d", chaar, chaar);  //usando o formato de leitura "%c", o caractere é mostrado de forma correta. Entretanto, ao utilizar o formato de leitura "%d" (decimal), é mostrado o valor equivalente do caractere em ASCII.

        return 0;


}

