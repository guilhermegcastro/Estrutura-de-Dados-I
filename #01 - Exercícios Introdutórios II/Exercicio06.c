/**
 * @file Exercicio06.c
 * @author Guilherme Castro
 * @date 2025-09-17
 * @brief
 * coding-exercise: 6. Faça um programa que declare duas variáveis do tipo char, faça a leitura, validando a entrada para que seja aceito apenas símbolos numéricos (entre ‘0’ e ‘9’). 
 * Após isso, converta e imprima o valor da multiplicação dos números. P. Ex.: '8' * '3' == 24.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	char n1, n2;
	
 do
  {
	printf("\n Insira o 1º número de 0 a 9:");
	scanf(" %c", &n1);
	while(getchar()!='\n'); //Evita que digitar mais de um caractere no primeiro scanf interfira no segundo scanf.
	switch(n1) 
		{
			case '0' : n1 = 0; break;
			case '1' : n1 = 1; break;
			case '2' : n1 = 2; break;
			case '3' : n1 = 3; break;
			case '4' : n1 = 4; break;
			case '5' : n1 = 5; break;
			case '6' : n1 = 6; break;
			case '7' : n1 = 7; break;
			case '8' : n1 = 8; break;
			case '9' : n1 = 9; break;
			 default : printf("\n O caractere inserido não atendeu as especificações\n");
		}
	
		printf("\n Insira o 2º número de 0 a 9:");
	scanf(" %c", &n2);
	
	switch(n2) 
		{
			case '0' : n2 = 0; break;
			case '1' : n2 = 1; break;
			case '2' : n2 = 2; break;
			case '3' : n2 = 3; break;
			case '4' : n2 = 4; break;
			case '5' : n2 = 5; break;
			case '6' : n2 = 6; break;
			case '7' : n2 = 7; break;
			case '8' : n2 = 8; break;
			case '9' : n2 = 9; break;
			 default : printf("\n O caractere inserido não atendeu as especificações\n");
		}
		
		if(((n1 >= 0) && (n1 <= 9)) && ((n2 >= 0) && (n2 <= 9)))
			{
				printf(" %d * %d = %d ", (int)n1, (int)n2, (int)n1*(int)n2);
			}
		else
		{
			printf("\n Insira os valores novamente.");
		}
		
	} 
	while(((n1 < 0) || (n1 > 9) ) || ((n2 < 0) || (n2 > 9)));
		
        return 0;


}

