
/**
 * @file string10.c
 * @author @guilhermegcastro
 * @date 2025-11-02
 * @brief Enunciado: 30. Faça um algoritmo de "Pattern Search". 
 * Dada uma string "text" e outra string "pattern", imprima a quantidade de vezes que a sub-string "pattern" pode ser encontrada dentro da string "text".
 * P.Ex.:
 * 
 *  Text = "ABBACABBABBABBAABB" 
 * Pattern = "ABBA" ==> 04 Ocorrências partindo de: [0, 5, 8, 11]
 **/

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>


	int main() {
	    
	    char Text[100], Pattern[100];
	    
	    printf("Insira o Text:\n > ");
	     scanf(" %[^'\n']s", Text);
	     
	    do {
			printf("Insira o Pattern:\n > ");
			 scanf(" %[^'\n']s", Pattern);
			 if (strlen(Pattern)<=strlen(Text))
				break;
			 printf(" * O pattern precisa ser menor que o Text. ");
		} while (1);
		
	    
	    size_t T = strlen(Text);
	    size_t P = strlen(Pattern);
	     
	    int ocorrencias[T/P+1];
	    int c=0, cont=0;
	    
	    for (int i = 0; i < T; i++) {
			char Clone[100];
			Clone[P] = 0;
			
			for (int j = 0; j < P; j++) 
				Clone[j] = Text[j+i];
	
			if (!strcmp(Clone, Pattern)) {
				ocorrencias[c]=i;
				cont++;
				c++;
			}
		}
	
		printf(" %d Ocorrências partindo de: [", cont);
		
		for (int i = 0; i < c; i++) {
			printf(" %d", ocorrencias[i]);
			if(i!=c-1) printf(",");
		}
		printf(" ]");
		
	    
	    
	    
        return 0;
 	}
