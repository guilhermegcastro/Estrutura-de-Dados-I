/**
 * @file    string04.c
 * @author  @guilhermegcastro
 * @date    2025-10-31
 * @brief   Enunciado: 24. Escreva um programa em C para ler uma frase. A seguir, imprima a frase com: 
 * (a) todas as letras maiusculas. 
 * (b) todas as letras minúsculas. 
 * (c) início de cada palavra em maiusculo.
 *  Em todos os casos, retirar os espaços em branco em excesso, que são desnecessários. 
 * Algoritmo deve ser in-place.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	
	char frase[100];
	printf(" Insira uma frase:\n > ");
	scanf(" %[^'\n']s", frase);
	size_t F = strlen(frase);
	
	int j = 0;
	for (int i = 0; i < F; i++) {
	
		if (frase[i]!=' '){
			frase[j] = frase[i];
			j++;
		} else {
			if (j> 0 && frase[j-1]!=' ') {
				frase[j] = frase[i];
				j++;
			}
		}
		
	}
	if (frase[j-1]==' ') j--;
	frase[j]= 0;

	 F = j;
	
	
	for (int i = 0; i < F; i++) {
		if(frase[i] > 96 && frase[i] <123)
			frase[i]-= 32;
	}
	
	printf("\n - %s", frase);
	
	for (int i = 0; i < F; i++) {
		if(frase[i] > 64 && frase[i] <91)
			frase[i]+= 32;
	}
	
	printf("\n - %s", frase);
	
	for (int i = 0; i < F-1; i++) {
		if(!i) frase[i]-= 32;
		if(frase[i]== ' ' && frase[i+1] > 96  && frase[i+1] < 123)
			frase[i+1]-= 32;
	}
	
	printf("\n - %s", frase);
	
	
	
	
    return 0;
}
