/**
 * @file Exercicio07.c
 * @author Guilherme Castro
 * @date 2025-09-17
 * @brief
 * coding-exercise: 7. Faça um programa que leia um número inteiro “K” e verifique se ele é palíndromo. P.Ex.: 57875, 131, 5995, 9, etc…
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
 int numero, espelho, oremun=0;
 printf("Insira um número e verifique se ele é um palindromo:");
 scanf("%d", &numero);
 
 for (espelho = numero; espelho > 0; espelho = espelho/10) // para tirar o ultimo digito, basta dividir por 10
	{
		int ultimodigito = espelho%10; //para coletar o ultimo digito, basta pegar o módulo por 10
		oremun = (oremun * 10) + ultimodigito; //faz a multiplicao do valor anterior (promove unidade para dezena, dezena para centena, etc...) e soma com o novo digito (unidade)
	}
	
	(numero==oremun)? printf("O número é um palíndromo pois %d = %d", numero, oremun) : printf("O número  não é um palíndromo pois %d ≠ %d", numero, oremun);
        return 0;


}

