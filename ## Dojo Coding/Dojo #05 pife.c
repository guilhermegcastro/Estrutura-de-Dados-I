
/**
 * @file pife.c
 * @author @guilhermegcastro, @mvmedrados, @pkzim-debug
 * @date 2025-11-13
 * @brief
 **/

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>


	int main() {
	    
	    srand(time(NULL));
		int baralho[9], trinca=0, cont=0;
		printf("====================================  PIFE  ====================================\n\n   %% - Cartas sorteadas: ");
		for (int i = 0; i < 9; i++)  {
			baralho[i] = 1 + rand()%13;
			printf("[%02d] ", baralho[i]);
		}
		putchar('\n');
		do {
			for (int i = 1; i < 9; i++)  {
				int key = baralho[i], j = i-1;
				
				while (j>= 0 && baralho[j]>key) {
					baralho[j+1] = baralho[j];
					j--;
				}
				baralho[j+1] = key;
			}
			
			printf("\n   ## - Cartas na Mesa: ");
			for (int i = 0; i < 9; i++)  {
				if(!baralho[i]) 
					continue;
				printf("[%02d] ", baralho[i]); 
			}
				putchar('\n');
				
				int deuTrinca = 0;
			for (int i = 0; i < 7; i++) {
				if(!baralho[i]) 
					continue;
				if((baralho[i] == baralho[i+1] && baralho[i] == baralho[i+2]) ||(baralho[i+1] == baralho[i]+1 && baralho[i+2] == baralho[i]+2)) {
					printf("\n     <<< Trinca formada com [%02d] [%02d] [%02d] >>>\n", baralho[i], baralho[i+1], baralho[i+2]);
					baralho[i] = baralho[i+1] = baralho[i+2] = 0;
					trinca++;
					deuTrinca = 1;
					continue;
				}
			}
			
			if(trinca==3)
				break;
			
			if(deuTrinca) 
				continue;
			
			int carta;
			
			printf("\n\n    >> Escolha uma Carta para Substituir: ");
			 scanf(" %d", &carta);
			 
			
			if (carta > 13 || carta < 1) {
				while(getchar()!='\n');
				printf("\n    ! - Carta Não Existe no Baralho.\n");
				continue;
			}
		
			int inc=0, fim=8, meio, encontrada=0;
			
			while (inc<=fim){
				
				meio = (inc+fim)/2;
				
				if(baralho[meio]==carta) {
					encontrada = 1;
					break;
				}
				
				if(baralho[meio]>carta) {
					fim = meio-1;
				} else inc = meio+1;
				
			}
			
			if(!encontrada) {
				while(getchar()!='\n');
				printf("\n    ! - Carta Não Disponível na Mesa.\n");
				continue;
			}
			
			baralho[meio] = 1 + rand()%13;
			
			printf("\n    * - Carta %d substituída pela Carta %d\n", carta, baralho[meio]);
			cont++;
			
		} while (1);
		
		printf("\n\n FIM DO PIFE!!\n\n O jogo terminou após %d rodadas! ", cont);
	     
		    
        return 0;
 	}
