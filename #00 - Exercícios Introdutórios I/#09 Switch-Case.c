/**
 * @file Exercicio09.c
 * @author Guilherme Castro
 * @date 2025-09-08
 * @brief
 * coding-exercice: 9-Switch-Case : Faça um programa em C (função única) que através da estrutura switch-case implementa um menu interativo de opções que vai do valor 1 até 5.
 *  Cada opção quando acionada deve imprimir o valor da opção em extenso. 
 * O menu interativo deve ser executado indefinidamente, até o usuário informar o valor 0, que é a opção para encerrar o programa.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main(int argc, char **argv)

{
	int opcao; 
	
	do {
		puts("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\nInsira uma opção de 1 a 5\n");
	puts("1 - Imprima \"UM\"");
	puts("2 - Imprima \"DOIS\"");
	puts("3 - Imprima \"TRÊS\"");
	puts("4 - Imprima \"QUATRO\"");
	puts("5 - Imprima \"CINCO\"");
	puts("0 - FINALIZA");
	puts("");

	scanf(" %d", &opcao);
	
	switch (opcao) 
		{
			case 1 : printf(" 1- UM"); break; 
			case 2 : printf(" 2- DOIS"); break;
			case 3 : printf(" 3- TRÊS"); break;
			case 4 : printf(" 4- QUATRO"); break;
			case 5 : printf(" 5- CINCO"); break;
			case 0 : printf("FINALIZADO"); break;
			default  : printf("OPÇÃO DE MENU INVÁLIDA."); break;
		}

	} while (opcao != 0);


        return 0;


}

