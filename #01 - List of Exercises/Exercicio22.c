/**
 * @file Exercicio22.c
 * @author Guilherme Castro
 * @date 2025-09-20
 * @brief
 * coding-exercise: 22. Crie um programa que calcule o M.M.C (mínimo múltiplo comum) e o M.D.C (máximo divisor comum) entre dois números lidos. 
 * (p. ex.: MMC (10, 15) = 30 e MDC (10, 15) = 5)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)
 
{

	int numero1, numero2; 
	printf("Insira o valor de dois números: ");
	scanf("%d %d", &numero1, &numero2);
	
	if (numero2 < numero1)
	{
		int ponte = numero1;
			numero1 = numero2;
			numero2 = ponte;
	}
	
		int A = numero2;
		int B = numero1;
		
		while(B!=0)
		{
			int resto = A%B;
			A = B;
			B = resto;
		}
		
		long long int mmc =((long long)numero1*numero2)/A;
		
		printf("\nMMC: %lld\n", mmc);
		printf("MDC: %d\n", A);
		
        return 0;


}

