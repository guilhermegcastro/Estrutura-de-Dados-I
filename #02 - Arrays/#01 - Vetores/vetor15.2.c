
/**
 * @file vetor15.2.c
 * @author @guilhermegcastro
 * @date 2025-11-05
 * @brief Enunciado: 15.​Dado um Array com N valores inteiros não-repetitivos sorteados no intervalo entre [X, Y] tal que (Y-X) > N
 * Faça um programa que sorteie e imprima o array, e apresente o par de valores consecutivos em que se obtém a maior diferença absoluta. 
 * Em caso de empate, a resposta será do par que, tendo seus valores somados, resulta o maior número.
 * 
 * P.Ex.: [4, 5, 8, 2, 1, 6, 9, 7, 3]​ ​
 * Resposta Gerada: [8, 2] == 6​ ​
 * 
 * P.Ex.: [4, 5, 8, 2, 1, 6, 9, 3, 7]
 * Resposta Gerada: [9, 3] == 6
 **/

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
 
	int main() {
	    
	    srand(time(NULL));
	    int N, X, Y;
	    
	    printf(" - Insira a quantidade de valores que serão sorteados:\n > ");
	     scanf(" %d", &N);
	     
		do {
			printf(" - Insira o intervalo mínimo e o intervalo máximo:\n > ");
			 scanf(" %d %d", &X, &Y);
			
			if(X>Y) {
				int troca = X;
				X = Y;
				Y = troca;
			}
			if(Y-X > N) break;
			printf("Erro : A diferença do intervalo maior e menor precisa ser maior que a quantidade de sorteios!\n");
			 
		} while (1);
		
	    // Sorteio e impressão do vetor;
	    int sorteio[N+1], cont=0;
			sorteio[N] = 0;
	    printf(" [");
	   
		while (cont < N)	{
			
			int organizado = 1;
			sorteio[cont] = X + rand()%(Y-X+1);
			
			for (int i = 0; i < cont; i++) {
				if(sorteio[cont]==sorteio[i]) {
				 organizado = 0;
				 break;
				}
			}
			
			if (organizado) {
				printf(" %d", sorteio[cont]);
				if(cont<N-1) printf(",");
				cont++;
			}
				
		}
	  
		printf("]");
		  
		 //Calculo 
		int in1=N, in2=N;
		for (int i = 0; i < N; i++)  {
		
			for (int j = 0; j < N-1; j++) {
			 
				if (i!=j && sorteio[i]-sorteio[j]==sorteio[in1]-sorteio[in2])
				{
					if(sorteio[i]+sorteio[j] > sorteio[in1] + sorteio[in2]) {
						in1 = i;
						in2 = j;
						continue;
					}
						
				}
				if (i!=j && sorteio[i] - sorteio[j] > sorteio[in1] - sorteio[in2]) {
					in1 = i;
					in2 = j;
				} 	
			}
		}
		 
		 printf("\n [%d, %d] == %d", sorteio[in1], sorteio[in2], sorteio[in1]-sorteio[in2]);
        return 0;
 	}
