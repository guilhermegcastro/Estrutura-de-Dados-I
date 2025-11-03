
/**
 * @file string09.c
 * @author @guilhermegcastro
 * @date 2025-11-02
 * @brief Enunciado: 29. Faça um programa que leia uma string A e outra string B. 
 * O programa deve informar a seguinte informação, conforme o caso: 
 * "String A está contida em B" ou "String B está contida em A" ou "As strings são incompatíveis".
 **/

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>


	int main() {
	    
	    char string[2][100];
	 
			printf("Insira a string A :\n > ");
			 scanf(" %[^'\n']s", string[0]);
			 
			printf("Insira a string B :\n > ");
			 scanf(" %[^'\n']s", string[1]);
			
			
		
				int contido = 0, cont=0;
				size_t T = (strlen(string[0]) <= strlen(string[1])) ? strlen(string[0]) : strlen(string[1]); //coleta a quantidade de char da menor string.
				int M = (strlen(string[0]) <= strlen(string[1])) ? 1 : 0 ; //coleta o indice da maior string.
				int m = (strlen(string[0]) <  strlen(string[1])) ? 0 : 1 ; //coleta o indice da menor string.
				
				do {
					for (int i = 0; i < T; i++) {
						if (string[m][i]==string[M][i+cont]) {
							contido = 1;
							continue;
						} else { 
							contido = 0;
							break;
						}
					}
					if(contido) { //se a string menor tiver uma sequencia correspondente dentro da string maior, o do while é quebrado. Se não, ele encerra quando cont for igual ao tamanho menor.
						cont=T;
						break;
					}
					cont++;
				
				} while(cont<T);
		
				if(contido) {
					(M)? printf(" - String A está contida em B.") : printf(" - String B está contida em A.");
				 } else {
					printf ("As strings são incopátiveis.");
				 }
				 
			
			
			
				
				
        return 0;
 	}
