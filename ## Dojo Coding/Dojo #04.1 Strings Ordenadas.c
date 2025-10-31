/**
 * @file    Dojo Coding 07 (Strings Ordenadas).c
 * @author  @guilhermegcastro, @mvmedrados
 * @date    2025-10-30
 * @brief   
 * Importante: O Executável do código depende do arquivo "wordlist.c" (disponível no github de @guilhermegcastro > Repositório: Estrutura-de-Dados-I > ##Dojo Coding > wordlist.txt). Instale-o para utilizar o program, executando no terminal: ./Dojo #04.1 String Ordenadas wordlist.txt
 */
 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <time.h> 

	int main(int args, char* arquivo[]){
		srand(time(NULL));
		
		if(args != 2){
			printf("Execute ./programa nome_arquivo");
			return 0;
		}
		
		FILE* arq = fopen(arquivo[1],"r");
		if(!arq){
			printf("Arquivo não existente\n");
			return 0;
		}

		char nomes[100][100];
		int c = 0;
		
		while(1){
			fscanf(arq," %[^\n]s",nomes[c]);
			if(feof(arq))
				break;		
			c++;
		
		}
			
		char sort[10][100];
		
		for (int i = 0; i < 10; i++)	{
			strcpy (sort[i], nomes[rand()%100]);
		}
		
		
		int ordenado, cont=0;
		do	{
			int t1, t2;
			system("clear");
			
			printf(" * Organize os títulos em ordem alfabética! * \n\n");
			for (int i = 0; i < 10; i++)  printf(" [%02d] %s \n", i+1, sort[i]);
			
			ordenado = 1;
			
			for (int i = 1; i < 10; i++) {
				if(strcmp(sort[i-1], sort[i]) == 0) continue;
				if(strcmp(sort[i-1], sort[i]) > 0) {
					ordenado = 0; 
					break;
				}
			}
			
			if(ordenado) break;		
			printf("\n\n Insira as duas posições para a troca:\n > ");
			scanf(" %d %d", &t1, &t2);
			
			if (t1 == t2 || t1 < 1 || t2 < 1 || t1 > 10 || t2 > 10) {
				printf(" Opção inválida! Aperte Enter para tentar novamente.\n\n");
				while(getchar()!='\n');
				getchar();
				continue;
			}
			
			char troca[100];
			strcpy(troca, sort[t1-1]);
			strcpy(sort[t1-1], sort[t2-1]);
			strcpy(sort[t2-1], troca);
			cont++;
			
		} while (1);
		
		printf("\n Parabéns! Você sabe o alfabeto...\n Foram %d jogadas para organizar os livros.", cont);
		
		
		
		
		
		


	}
