/**
 * @file Exercicio20.c
 * @author Guilherme Castro
 * @date 2025-09-20
 * @brief
 * coding-exercise: 20. Faça um programa que leia um par de valores inteiros (X,Y), tal que, obrigatoriamente Y >= X.
 * O programa deve calcular e imprimir o valor da soma de todos os números inteiros do intervalo [X, Y] (inclusive).
 * A operação deve ser repetida até que os dois valores (X e Y) sejam negativos.
 * P.ex.: (7,11) == 45; (53,68) == 968.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	int X, Y, somatoria, programa;
	
	do
	{
	
		printf("Insira um intervalo de dois valores inteiros: ");
		scanf("%d %d", &X, &Y);
		
		while (X > Y)
		{
			printf("\nErro: Insira um intervalo onde X é menor ou igual a Y: ");
			scanf("%d %d", &X, &Y);
		}
	
		if ((X > 0) || (Y > 0))
		{
			for (int i=X; i <= Y; i++)
			{
				somatoria+=i;
			}
			 
				printf("A soma de todos os números do intervalo de (%d, %d) é igual a: %d\n\n", X, Y, somatoria);
				printf(" * Para finalizar o programa, insira dois valores negativos nos intervalos.\n");
				somatoria=0;
				programa=0;
		}
		else
		{
			programa = 1;
		}
			
	 } while(programa==0);
	 
        return 0;


}

