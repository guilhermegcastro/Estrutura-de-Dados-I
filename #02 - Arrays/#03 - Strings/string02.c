/**
 * @file    string02.c
 * @author  @guilhermegcastro
 * @date    2025-10-30
 * @brief   
 * Enunciado: 22. Faça um programa que leia, em formato de string, um valor numérico representado na base binária. 
 * O programa deve validar se o valor informado pelo usuário realmente é um número binário. 
 * Em caso positivo, o programa deve informar o valor correspondente na base decimal.
 */

#include <stdio.h>
#include <string.h>

int main() {
	
	char numero[100];
	
	printf("Insira um número para validar um número binário: ");
	scanf(" %s", numero);
	
	size_t N = strlen(numero);
	for (int i = 0; i < N; i++) {
		if(numero[i]!='0'&& numero[i]!='1') {
			printf("O número náo é binário. Inicie o programa e tente novamente!");
			return 0;
		}
	}
	
	printf("O número inserido é binário! Seu valor em número decimal corresponde a: ");
	int  decimal=0, cont=0, x=1;
	do{
		int calculo = (numero[N-1-cont] - '0') * x;
		decimal+= calculo;
		cont++;
		x*=2;
	} while (cont<N);
	
	printf("%d", decimal);
	
    return 0;
    
}
