/**
 * @file Exercicio28.c
 * @author Guilherme Castro
 * @date 2025-09-21
 * @brief
 * coding-exercise: 28. Sabia que a sequência Fibonacci está ligada intimamente à natureza? Os números da série são facilmente encontrados nos seres vivos e no meio ambiente. 
 * Essa série é infinita e se inicia com os valores: 1, 1, 2, 3, 5, 8, 13, 21, 34, (...), onde o próximo valor sempre será a soma dos dois valores anteriores.
 * Faça um programa que leia um valor N, e imprima todos N primeiros termos da série Fibonacci.
 * Após isso, imprima o resultado da divisão do último termo pelo penúltimo termo.
 * Repita essa mesma operação para diversos valores de N diferentes, e veja o que acontece de interessante... (Dica: Pesquise na Internet o conceito de “Proporção Áurea" ou “Proporção Divina”.)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	long long int sequencia; 
	long double n1 = 0, n2 = 0, n3 = 1;
	
	printf("Digite a quantidade de números que você deseja imprimir da sequência Fibonacci:");
	scanf("%lld", &sequencia);
	
	for (long long int i=0; i <= sequencia;  )
	{	
	
		if (i == 0)
		{
			printf(" 1 ");
			i+=1;
		}
		if (sequencia==1)
		{ break; }
		n1 = n3 + n2;
		printf(" %.0Lf ", n1);
		i+=1;
		if (sequencia == i)
		{ break; }
		n2 = n1 + n3;
		printf(" %.0Lf", n2);
		i+=1;
		if (sequencia == i)
		{ break; }
		n3 = n2 + n1;
		i+=1;
		printf(" %.0Lf ", n3);
		if (sequencia == i)
		{ break; }
	}
	putchar('\n');
	
	long double divisao;
	if (n1 > n2)
	{
		if (n2 > n3) { divisao = n1/n2; }
		else { divisao = n1/n3; }
	}
		
		if (n2 > n1)
	{
		if (n1 > n3) { divisao = n2/n1; }
		else { divisao = n2/n3; }
	}
		if (n3 > n2)
	{
		if (n2 > n1) { divisao = n3/n2; }
		else { divisao = n3/n1; }
	}
	
	if (sequencia > 1)
	{
		printf("Divisão do último termo pelo penúltimo %.4Lf", divisao);
	}
	
	return 0;
}

