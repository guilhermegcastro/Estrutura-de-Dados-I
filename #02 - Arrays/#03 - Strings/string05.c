
/**
 * @file string05.c
 * @author @guilhermegcastro
 * @date 2025-11-01
 * @brief Enunciado: 25. Programe o sorteio de um “Amigo Oculto” com N participantes. 
 * Leia o nome de cada amigo e imprima o resultado do sorteio.
 * Lembre que um amigo não pode tirar ele mesmo (e cuidado com o último).
 **/

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>


	int main() {
	    
	    srand(time(NULL));
	    int N=1;
	    
	    while (N==1){
			 printf("Insira a quantidade ( > 1) de participantes do amigo oculto :\n > ");
			  scanf(" %d", &N);
		}
	   
	     
	    
	    char nome[N][100];
	    for (int i = 0; i < N; i++) {
			printf("Nome do %dº participante:\n > ", i+1);
			 scanf(" %[^'\n']s", nome[i]);
			 putchar('\n');
		}
		
		int sorteio[N];
		
		system("clear");
		int cont=0, repetido;
		do {
			repetido=0;
			do {
				sorteio[cont]= rand()%N;
				
				if(N%2!=0 && cont==N-1 && sorteio[cont]==cont) { // Trata o problema do último sorteado só ser permitido sortear a si mesmo por falta de números.
					sorteio[cont] = sorteio[cont-1];
					sorteio[cont-1] = cont;
					break;
				}
			} while (sorteio[cont]==cont);
			
			for (int i = 0; i < cont; i++) {
				if (sorteio[cont]==sorteio[i]){
					repetido=1;
					break;
				}
			}
			
			if(!repetido){
				cont++;		
			}
		} while (cont < N);
		
		
		for (int i = 0; i < N; i++) {
			printf("%s sorteou %s\n", nome[i], nome[sorteio[i]]);
		}
		
		
		
		
        return 0;
 	}
