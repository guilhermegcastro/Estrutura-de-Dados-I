
/**
 * @file string08.c
 * @author @guilhermegcastro
 * @date 2025-11-02
 * @brief Enunciado: 28. Faça um programa que leia, em formato de string, dois números inteiros excepcionalmente grandes e imprima o valor da soma destes números.
 * P.ex.:
 *  
 *        "25996478547851225"
 *          + "1452565475541"
 *        -------------------
 *         25997931113326766
 * 
 * 
 **/

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>


	int main() {
	
		char numero[3][100];
		
		for (int i = 0; i < 2; i++) {
			printf("Insira o %dº número excepcionalmente grande:\n > ", i+1);
			 scanf(" %s", numero[i]);
		}
		
		long long int somatorio=0;
		
		for (int i = 0; i < 2; i++) {
			size_t N = strlen(numero[i]);
			long long int multiplicador = 1;
			for (int j = N-1; j >= 0; j--) {
				somatorio+=((long long int)numero[i][j]-48)*multiplicador;
				multiplicador*=10;
			}
		}
	
		printf("\n %lld", somatorio);
		
	    
        return 0;
 	}
