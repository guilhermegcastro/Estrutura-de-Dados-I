/**
 * @file    string03.c
 * @author  @guilhermegcastro
 * @date    2025-10-31
 * @brief   Enunciado: 23. Números romanos são representados por letras, sendo:
 * 'I' == 1    'L' == 50    'M' == 1000
 * 'V' == 5    'C' == 100   'X' == 10
 * 'D' == 500
 * Faça um programa que leia uma string em formato de número romano, verifique se é válida (não possui caracteres inválidos).
 * Estando válida, converta para o número decimal respectivo. Repita a operação até ser informada a string "exit" para encerrar a execução do programa.
 * P.Ex.: "MCMXCIX" => 1999    "MMMDLXVIII" => 3568    "XXZVII" => Inválido.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	
	do {
		
		char nRomano[100], exit[] = {"EXIT"};
		printf(" Digite um número romano (\" EXIT \" para finalizar o programa):\n > Número romano: ");
		scanf(" %s", nRomano);
		
		if(strcmp(nRomano, exit)==0)
			return 0;
		
		size_t N = strlen(nRomano);
		int numeroValido=1;
		for (int i = 0; i < N-1; i++) {
		
			if (nRomano[i] != 'I' && nRomano[i] != 'V' && nRomano[i] != 'X' && nRomano[i] != 'L' && nRomano[i] != 'C' && nRomano[i]!='D' && nRomano[i]!='M')	{
				numeroValido = 0;  //Trata o erro se o número for diferente da lista possível de números romanos.
				break;
			}
			if ((nRomano[i] == 'V' && nRomano[i+1] == 'V') || (nRomano[i] == 'L' && nRomano[i]=='L') || (nRomano[i] == 'D' && nRomano[i]=='D')) {
				numeroValido = 0;  //Trata o erro se tiver repetições de V, L ou D.
				break;
			} 
			if (nRomano[i] == nRomano[i+1] && nRomano[i] == nRomano[i+2] && nRomano[i] == nRomano[i+3] && i < N-3) {
				numeroValido = 0; //Trata o erro se tiver mais de 3 repetições  de qualquer Letra (Porém V, L, D já são tratados anteriormente)
				break;
			}	
			if (nRomano[i] == 'I' && nRomano[i+1]!='X' && nRomano[i+1]!='V' && nRomano[i+1]!='I') {
				numeroValido = 0; //Trata o erro de precedência do I
				break;
			}
			if (nRomano[i] == 'X' && (nRomano[i+1]=='D' || nRomano[i+1]=='M')) {
				numeroValido = 0; //Trata o erro de precedência do X
				break;
			}
			
			
			
			
			
			
			
			
		}
		
		if(!numeroValido) {
				printf("Número inválido, aperte ENTER e tente novamente!");
				while(getchar()!='\n');
				getchar();
				continue;
			}
		
		int valor=0;
		for (int i = 0; i < N; i++) {
			switch (nRomano[i]) {
				case 'M': valor+= 500;
				case 'D': valor+= 400;
				case 'C': valor+= 50;
				case 'L': valor+= 40;
				case 'X': valor+= 5;
				case 'V': valor+= 4;
				case 'I': valor+= 1;
					break;
			}
			
			if(nRomano[i]=='I' && (nRomano[i+1]=='X' || nRomano[i+1]=='V')) valor-=2;
			if(nRomano[i]=='X' && (nRomano[i+1]=='L' || nRomano[i+1]=='C')) valor-=20;
			if(nRomano[i]=='C' && (nRomano[i+1]=='D' || nRomano[i+1]=='M')) valor-=200;
			
			
		}
		
		printf(" > Número decimal: %d\n\n", valor);
		
	} while (1);
	
	
	
    return 0;
}
