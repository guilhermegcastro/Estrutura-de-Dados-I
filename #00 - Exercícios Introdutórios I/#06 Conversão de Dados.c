/**
 * @file Exercicio06.c
 * @author Guilherme Castro
 * @date 2025-09-08
 * @brief
 * coding-exercice: 6- Conversão de Dados : Faça um programa em C que leia um símbolo numérico em formato CHAR (%c) entre '0' e '9', e um valor número INTEIRO N. 
 * Faça a multiplicação dos valores e imprima o resultado (que deve ser correto).
 * Por exemplo o char '5' multiplicado ao nº. inteiro 8 deve totalizar 40. 
 * Analise o porquê do problema não ser tão trivial quanto parece.
 **/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{

	char valorc;
	int valorn;
	
	puts("Insira um valor (De 0 a 9) e um valor sem restrições:");
	scanf(" %c %d", &valorc, &valorn);
	
	switch (valorc) //O número de 0 a 9 inserido na variável em char é puramente "visual" para o código. O valor numérico  de char segue como base o ASCII (48 a 57), tornando as contas "erradas" se seguirmos a lógica visual.
	{
	case '0' : valorc = 0; break; 
	case '1' : valorc = 1; break;
	case '2' : valorc = 2; break;
	case '3' : valorc = 3; break;
	case '4' : valorc = 4; break; 
	case '5' : valorc = 5; break;
	case '6' : valorc = 6; break;
	case '7' : valorc = 7; break;
	case '8' : valorc = 8; break;
	case '9' : valorc = 9; break;
} // utilizamos o switch para atribuir o valor númerico correto.
	printf(" %d * %d = %d ", /* O (int) serve para o "0" aparecer corretamente.*/(int)valorc, valorn, valorc*valorn); //utilizamos o formato de leitura '%d' para que o número em ASCII (já convertido) apareça ao invés do caractere correspondente.
        return 0;


}

