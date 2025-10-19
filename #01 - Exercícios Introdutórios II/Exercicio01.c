/**
 * @file Exercicio01.c
 * @author Guilherme Castro
 * @date 2025-09-16
 * @brief
 * coding-exercise: 1. Implemente um programa que simule o sistema de emissão de notas de um caixa eletrônico. 
 * O usuário deve informar um valor para saque (sendo obrigatoriamente par) e você deve imprimir como resultado a menor quantidade de notas emitidas que totaliza este valor.
 * NOTAS: R$2.00, R$10.00, R$20.00, R$50.00, R$100.00, R$200.00 (R$5.00 não vai entrar por ser um valor ímpar.)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void linha();
int main(int argc, char **argv)

{
	int saque, somatorio=0, nota;
	
	linha();
	printf("\tSistema de emissão de notas\n Por favor, informe o valor do saque (precisa ser um número PAR):\n\tR$");
	scanf("%d", &saque);
	
	
	if (saque%2!=0)
		{
			while(saque%2!=0) 
				{
					printf(" ERRO: O sistema não permite números ímpares. Por favor, insira um valor PAR:\n\tR$");
					scanf("%d", &saque);
				}
		}
		
	if (saque < 0)
		{ 
			printf(" * O valor foi convertido para um número positivo.\n");
			saque*=(-1);
		}
	linha();
	printf("\n\tQuantidade mínima de notas que resultam no valor R$%.2f", (float)saque);
	putchar('\n');
	  if(200 <= saque)
		{
			for(nota=200; nota <= saque; )
				{ 
					somatorio+=1;
					saque-=nota;
				 }
			printf("\n %d Nota(s) de R$200.00", somatorio);
			somatorio=0;
		}
		if(100 <= saque)
		{
			for(nota=100; nota <= saque; )
				{ 
					somatorio+=1;
					saque-=nota;
				 }
			printf("\n %d Nota(s) de R$100.00", somatorio);
			somatorio=0;
		}
		if(50 <= saque)
		{
			for(nota=50; nota <= saque; )
				{ 
					somatorio+=1;
					saque-=nota;
				 }
			printf("\n %d Nota(s) de R$50.00", somatorio);
			somatorio=0;
		}
		if(20 <= saque)
		{
			for(nota=20; nota <= saque; )
				{ 
					somatorio+=1;
					saque-=nota;
				 }
			printf("\n %d Nota(s) de R$20.00", somatorio);
			somatorio=0;
		}
		if(10 <= saque)
		{
			for(nota=10; nota <= saque; )
				{ 
					somatorio+=1;
					saque-=nota;
				 }
			printf("\n %d Nota(s) de R$10.00", somatorio);
			somatorio=0;
		}
		if(2 <= saque)
		{
			for(nota=2; nota <= saque; )
				{ 
					somatorio+=1;
					saque-=nota;
				 }
			printf("\n %d Nota(s) de R$2.00", somatorio);
			somatorio=0;
		}
				
				


	

        return 0;


}

void linha( )
{
 puts("================================================================================");
}


