/**
 * @file Exercicio26.c
 * @author Guilherme Castro
 * @date 2025-09-21
 * @brief
 * coding-exercise: 26. Sabendo que o valor de pi pode ser calculado através da série Gregory-Leibniz:
 * π = (4/1) - (4/3) + (4/5) - (4/7) + (4/9) - (4/11) + (4/13) - (4/15) …
 * Faça um algoritmo para calcular e imprimir o valor de pi, com 15 casas decimais, obtido até o 999.999.999º termo da série. 
 * (Resposta correta: 3.141596794128418)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

	
int main(int argc, char **argv)
{
	
	float pipi = 0.0, sinal = 1.0;
	long long int i = 0, n = 999999999;
	
	for(float divisor=1; i < n; divisor+=2, i++)
	{
		pipi+=(4.0/divisor)*sinal;
		sinal*=(-1.0);
	}
	printf(" π = %.15f", pipi);
        return 0;


}

