/**
 * @file teste.c
 * @author Guilherme Castro
 * @date 2025-09-18
 * @brief
 * coding-exercise: 11. Faça um programa que usando o símbolo asterisco (*) desenhe na tela uma pirâmide cuja base tenha um tamanho de N símbolos (O valor N deve ser informado pelo usuário e obrigatoriamente deve ser ímpar).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{

	int numero; 
	
	printf("Insira um número ímpar positivo para a base da pirâmide: ");
	scanf("%d", &numero); 
	
	if (numero<0)
	{
		numero*=(-1);
		printf("\nO número inserido é negativo. \nPor conviniência, ele foi convertido para positivo: (%d).", numero);
	}
	if (numero%2==0)
	{
		numero+=1;
		printf("\nO número inserido é par. \nPor conviniência, ele foi convertido para o próximo ímpar: (%d).\n", numero);
	}
	
	char piramide[numero];
	
	for(int i = 0; i < numero; i++)
	 {
		 piramide[i] = ' ';
	 }
	
	 putchar('\n');
	 
	 for(int N = 0; N < (numero / 2) + 1; N++)
	  {
		  
		  piramide[numero/2+N] = '*';
		  piramide[numero/2-N] = '*';
		  putchar('\t');
		  

			
		  for(int i = 0 ; i < numero; i++)
			{
				printf("%c", piramide[i]);
				
			}
			putchar('\n');
	  }
        return 0;


}

