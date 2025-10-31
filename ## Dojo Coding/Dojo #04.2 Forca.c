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

		char nomes[100][100], forca[3][100];
		int c = 0;
		
		while(1){
			fscanf(arq," %[^\n]s",nomes[c]);
			if(feof(arq))
				break;		
			c++;
		
		}
		
			strcpy(forca[0], nomes[rand()%100]);	
		do {
			strcpy(forca[1], nomes[rand()%100]);
			strcpy(forca[2], nomes[rand()%100]);		
		} while (strcmp(forca[1], forca[2]) == 0 || strcmp(forca[1], forca[0]) == 0 || strcmp(forca[0], forca[2]) == 0);

		
		
		char respostas[26] = "0", palpite;
		int underline, cont=0, contErradas=-1;
		do {
			system("clear");
			printf("====================== JOGO DA FORCA ======================\n");
			printf(" - Tente adivinhar as palavras abaixo:\n");
		
			
			
			int incorreta=1;
			
			int palavra1 = 1;
			for (int i = 0; i < strlen(forca[0]); i++) { //Palavra 00;
				if (forca[0][i] == ' ') {
					putchar(' ');
					continue;
				}
				underline = 1;
				for (int j = 0; j < 26; j++) {
					if (forca[0][i] == palpite || palpite=='*') incorreta=0;
					if (forca[0][i] == respostas[j]) {
						printf("%c", forca[0][i]);
						underline = 0; 
						break;
					}
				}
					if(underline) {
						palavra1=0;
						putchar('_');	
					}

			}
			putchar('\n');
			int palavra2=1;
			for (int i = 0; i < strlen(forca[1]); i++) { //Palavra 01;
				if (forca[1][i] == ' ') {
					putchar(' ');
					continue;
				}
				underline = 1;
				for (int j = 0; j < strlen(respostas); j++) {
					if (forca[1][i] == palpite || palpite=='*') incorreta=0;
					if (forca[1][i] == respostas[j]) {
						printf("%c", forca[1][i]);
						underline = 0; 
						break;
					}
				}
					if(underline) {
						palavra2=0;
						putchar('_');	
					}

			}
			putchar('\n');
			int palavra3=1;
			for (int i = 0; i < strlen(forca[2]); i++) { //Palavra 02;
				if (forca[2][i] == ' ') {
					putchar(' ');
					continue;
				}
				underline = 1;
				for (int j = 0; j < 26; j++) {
					if (forca[2][i] == palpite || palpite=='*') incorreta=0;
					if (forca[2][i] == respostas[j]) {
						printf("%c", forca[2][i]);
						underline = 0; 
						break;
					}
				}
					if(underline) {
						palavra3=0;
						putchar('_');	
				}

			}
			
				if(incorreta) contErradas++;
				printf("\n\n");
				printf("|-----|   \n");
				(contErradas<1)? printf("|         \n") : printf("|     o   \n");
				
				if (contErradas<2) printf("|        \n");
				if (contErradas==2) printf("|    /   \n");
				if (contErradas==3) printf("|    /|  \n");
				if (contErradas>=4) printf("|    /|\\ \n");
				
				if (contErradas<5) printf("|        \n");
				if (contErradas==5) printf("|    /   \n");
				if (contErradas>=6) printf("|    / \\   \n");

				if(palavra1 && palavra2 && palavra3) break;
				if(contErradas==6) {
				printf("\n Você perdeu! :c As palavras eram:\n %s \n %s \n %s\n ", forca[0], forca[1], forca[2]);
				return 0;
				}		
			printf("\n - Palpites incorretos: %d/6", contErradas);
			printf("\n - Digite uma letra:\n > ");
			if(cont) printf("%s", respostas);
			scanf(" %c", &palpite);
			
			palpite = (palpite > 96) ? palpite - 32: palpite;
			if(palpite < 65 || (palpite >90 && palpite <97) || palpite > 122) {
				contErradas--;
				printf("Inválido! Aperte Enter e tente novamente...\n");
				while(getchar()!='\n');
				getchar();
				continue;
			}
			
			int repetido = 0;
			for (int i = 0; i < strlen(respostas); i++) {
				if(palpite==respostas[i]) { 
					repetido = 1;
					break;
				}
			}
			
			if(repetido) {
				palpite='*';
				printf("Você já inseriu essa letra! Aperte Enter para tentar outra letra...");
				while(getchar()!='\n');
				getchar();
				continue;
			}

			respostas[cont] = palpite;
			cont++;
			
		} while (1);
		
		printf("\n\n Fim de jogo! Você finalizou com %d tentativas e %d erros.", cont, contErradas);
	}
