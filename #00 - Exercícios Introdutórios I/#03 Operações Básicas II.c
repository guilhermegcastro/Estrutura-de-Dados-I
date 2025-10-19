/**
 * @file Exercicio03.c
 * @author Guilherme Castro
 * @date 2025-09-06
 * @brief
 * coding-exercice: 3- Operações Básicas : Faça um programa em C (função única) que simule o software de uma bomba de combustível: 
 * O usuário informar o preço do litro de combustível e o valor que o motorista deseja abastecer (ambos float). 
 * Imprima como resposta a quantidade de combustível que a bomba irá dispensar com 3 casas decimais.
 **/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	float preco, quanti;
	printf("Insira o preço do litro de combustível e o valor que o motorista vai pagar:\n"); 
	scanf(" %f  %f", &preco, &quanti);
	
	printf("Quantidade de combustível que a bomba irá dispensar: %fL", quanti/preco);
        return 0;


}

