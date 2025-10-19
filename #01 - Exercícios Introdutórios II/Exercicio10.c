/**
 * @file Exercicio10.c
 * @author Guilherme Castro
 * @date 2025-09-17
 * @brief
 * coding-exercise: 10. O imposto de importação sobre produtos estrangeiros é de 20% (até U$ 50.00) e 60% (> U$ 50.00).
 * Sobre esse valor, ainda aplica-se o imposto estadual (ICMS), que em MG é de 18%.
 * Faça um programa que leia o preço de um produto no exterior (em U$), o valor do câmbio (U$ para R$) e calcule o preço final ao consumidor (em R$).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	float valor, imposto, cambio;
	
	printf("Insira o valor da importação sobre o(s) produto(s) estrangeiro(s) em dólar:\n U$");
	scanf("%f", &valor);
	if (valor > 50)
	{
		imposto = 60*0.01*valor;
	}
	else
	{
		imposto = 20*0.01*valor;
	}
	float icms = 0.18*(valor+imposto);
	printf("Insira o valor do cãmbio (Quanto vale 1 dólar em real):\nR$");
    scanf("%f", &cambio);
    
    printf("Valor da importação: U$%.2f\n", valor);
    printf("Valor do imposto: U$%.2f\n", imposto);
    printf("Valor do ICMS: U$%.2f\n", icms);
    printf("Valor total: U$%.2f\n",  valor+icms+imposto);
    printf("Preço final do consumidor: R$%.2f", (valor+icms+imposto) * cambio);
    
    
        return 0;
   
    
    


}

