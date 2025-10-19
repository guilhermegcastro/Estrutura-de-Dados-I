/**
 * @file Exercicio13.c
 * @author Guilherme Castro
 * @date 2025-09-15
 * @brief
 *  coding-exercise: 13- Laços de Repetição : Faça um programa em C que leia um valor inteiro N, e após isso, leia N números inteiros positivos -- valores 0 e negativos devem ser ignorados.
 *  Apresente como resultado: o menor e maior valor (válidos) inseridos, a soma e média simples (descartando os inválidos).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)
 {
	int i, j, n, nvalido, soma, maior=-1, menor=-1;
	
	printf("Insira o valor da quantidade de números que você deseja fazer o programa ler: "); 
	scanf("%d", &i);
	
	if (i <= 0)  
		{
			while (i <= 0) 
				{
					printf("Insira um valor positivo diferente de 0: ");
					scanf("%d", &i);
				}
		}
		
		for(j=1;j<=i;j++)
			{
				printf("Insira o %dº valor de %d valores: ", j, i); 
				scanf("%d", &n);
				if (n>0)
					{
						soma+= n;
						nvalido+=1;
						if (menor ==-1) 
							menor = n;
						else if (n < menor)
							menor = n ;
						if (n > maior)
							maior = n;
					}
				else 
				continue;	
			}
			
		printf(" Maior número: %d\n Menor número: %d\n Soma dos valores (0 e negativos foram ignorados): %d \n Média dos valores(0 e negativos foram ignorados): %d", maior, menor, soma, soma/nvalido);
	

        return 0;


}

