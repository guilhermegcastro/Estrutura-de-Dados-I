/**
 * @file Exercicio19.c
 * @author Guilherme Castro
 * @date 2025-09-20
 * @brief
 * coding-exercise: 19. Faça um programa que gere N números de matrícula no formato ABCD-V, onde V é um dígito verificador, no qual: V = | A – B + C – D |
 * se V >= 10, então V == d1+d2 (a soma dos dois dígitos).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	srand(time(NULL));
	int N;
	
	printf("Insira a quantidade de números de matrícula que você deseja gerar: ");
	scanf("%d", &N);
	
	for (int i = 1; i <= N ; i++)
	{
		int A = rand()%10;
		int B = rand()%10;
		int C = rand()%10;
		int D = rand()%10;
		int V = A - B + C - D;
		
		if(V<0)
		{
			V*=(-1);
		}
		while(V>=10)
		{
		V = V%10 + V/10;	
		}
		
		printf(" - Matrícula Nº %2d: %d%d%d%d-%d\n", i, A, B, C, D, V);
		
	}
        return 0;


}

