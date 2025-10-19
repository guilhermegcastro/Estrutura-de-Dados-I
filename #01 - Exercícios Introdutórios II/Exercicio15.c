/**
 * @file Exercicio15.c
 * @author Guilherme Castro
 * @date 2025-09-19
 * @brief
 * coding-exercise: 15. Faça um programa que receba um número informado pelo usuário e imprima a informação se este é um número primo ou não. Imprima também quantas divisões você teve que fazer até confirmar a resposta (se é número primo ou não). 
 * O programa deve testar vários números, até que o usuário digite qualquer valor negativo.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	int numero=0, divisao;
	
	while(numero<= 0)
	{
		printf("Insira um número para verificar se é ou não primo: ");
		scanf("%d", &numero);
		
		for (int i = 2; i <= numero; i++)
		{
			if (numero == 1)
			{
				printf("O número 1 é primo, sem necessidade de divisão");
			}
			
			if (numero==i) 
			{
               printf("O número %d é primo (foi realizada %d divis", numero, divisao); (divisao > 1) ? printf("ões)") : printf("ão)"); break;
			}
			
						divisao+=1; 
			
			if (numero%i != 0)
			{
				continue;
			}
			else
			{
				printf("O número %d não é primo (foi realizada %d divis", numero, divisao); (divisao > 1) ? printf("ões)") : printf("ão)"); break;
			}
		} 
	}

        return 0;


}

