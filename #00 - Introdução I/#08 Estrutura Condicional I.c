/**
 * @file Exercicio08.c
 * @author Guilherme Castro
 * @date 2025-09-08
 * @brief
 * coding-exercice: 8- Estrutura Condicional : Faça um programa em C (em função única) que lela 3 variáveis de valor inteiro e imprima-os em ordem crescente e depois em ordem decrescente. 
 * Analise porque é mais eficiente trocar o conteúdo das variáveis do que apenas comparar os valores entre si. 
 * (Faça o código apenas comparando os valores, sem realizar trocas, e veja a diferença entre os códigos).
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	int x, y, z, a; 
	
	printf("Insira 3 nº inteiros:");
	scanf("%d %d %d", &x, &y, &z); 
	
	if ((y < x) && (y < z))
		{
		 a = y;	 
		 if (x < z)
			{
				y = x; 
				x = a;
			}
		else 
			{
			  y = z; 
			  z = x; 
			  x = a; 
			}
		}
		
	if ((z < x) && (z < y))
		{
		 a = z;	 
		 if (x < y)
			{
				z = y; 
				y = x;
				x = a;
			}
		else 
			{
			  z = x;  
			  x = a; 
			}
		}
	if ((x < z) && (z < y)) 
		{ 
			a = y; 
			y = z; 
			z = a;
		}
	
			
			printf("Ordem crescente: %d, %d, %d\n", x, y, z); printf("Ordem decrescente: %d, %d, %d", z, y, x); 
	

        return 0;


}

