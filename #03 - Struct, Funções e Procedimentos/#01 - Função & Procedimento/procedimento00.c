
/**
 * @file função02.c
 * @author @guilhermegcastro
 * @date 2025-11-24
 * @brief
 **/

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>

	int primo(int X) {
		
		int num = X;
		while(1) {
			
			int pri = 1;
			
			for (int i = 2; i < num-1; i++) {
				if((num%i)==0) {
					pri = 0;
					break;
				} else continue;
			}
		
			if(!pri) {
				num++;
				continue;
			} else 
				return num;
		}
	}

	int main() {
	    
	    srand(time(NULL));
	    int N;
	    printf("Informe o tamanho do vetor:\n - > ");
	    scanf(" %d", &N);
	    int numeros[N];
	    
	    for (int i = 0; i < N; i++) 
			numeros[i] = rand()%(N*2);
			
		for (int i = 0; i < N; i++) 
			printf("Primeiro nº primo maior ou igual a %d : %d\n", numeros[i], primo(numeros[i]));
				
        return 0;
 	}
