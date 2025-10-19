/**
 * @file Exercicio14.c
 * @author Guilherme Castro
 * @date 2025-09-19
 * @brief
 * coding-exercise: 14. Faça um programa que leia um número indeterminado de valores inteiros. 
 * A leitura somente será interrompida quando o usuário informar o valor zero. 
 * Valores negativos devem ser ignorados para os cálculos. 
 * O programa deve gerar os seguintes resultados (ignorando valor 0 e negativos): 
 * Soma dos números lidos, Média simples dos números lidos, Maior e Menor valores, Percentual de números pares e o Percentual de Números ímpares.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	int numero=0, i=0, soma, maior=0, menor=0, par, impar;
	
	do
	{
		i +=1;
		printf("\nInsira o %dº número: ", i); 
		scanf ("%d", &numero);
		
		if (numero > 0)
		{
			soma+=numero;
			if (numero%2==0)
			{
				par+=1;
			}
			else
			{
				impar+=1;
			}
			
			if (menor == 0)
			{
				menor=numero;
			}
			else if (numero < menor)
			{
				menor=numero;
			}
			if (numero > maior)
			{
				maior=numero;
			}
		printf("\n\n * Insira o número \"0\" para finalizar a entrada de dados. \n(Valores negativos não são coletados)");
		}
		
		if (numero<=0)
		{
			i-=1;
		}
		
	} while (numero!=0);
	
	printf("\n\n** Resultados **\n");
	printf(" - Soma dos números: %d \n - Média simples dos números: %d \n - Maior valor coletado: %d \n - Menor valor coletado: %d \n - Percentual de números pares: %d%% \n - Percentual de números ímpares: %d%% \n - Total de valores lidos: %d", soma, soma/i, maior, menor, (100*par)/i, (100*impar)/i, i);
	
	

        return 0;


}

