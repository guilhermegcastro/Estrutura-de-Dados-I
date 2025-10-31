/**
 * @file    destroy_bombs.c
 * @author  @guilhermegcastro
 * @date    2025-10-31
 * @brief   
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gconio.h"

int main() {
	
	
	char molde[70] = { "                                                                      "} ;
	char linha[17][71];
	char chao[211]  = { "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾"} ;
	cursor(0);
	for (int i = 0; i < 16; i++) strcpy(linha[i], molde);
	
	putchar('\n');
	
	int X= 37, ciclo=0, movimentos=0;
	do {
	
		system("clear");
		int fimdejogo=0;
		if (ciclo==7) {
				for (int i = 15; i > 0; i--) {
					strcpy(linha[i], linha[i-1]);
				}
				
			for (int i = 0; i < 70; i++) {
				if (linha[15][i]=='!') {
					fimdejogo=1;
					break;
				}
				
			}
		
		}
	
		
		for (int i = 0; i < 16; i++) {
			linha[i][X] = ' ';
		}
		
		for (int i = 0; i < 16; i++) {
		
			if (i==3 && ciclo == 7) {
				linha[0][rand()%70] = '!';
		
				ciclo=0;
			}
			printf("%s", linha[i]);
			printf(":%02d:70\n",i);
		}
		printf("%s", chao);
		gotoxy(X,16);
		printf("⏏︎");
		
		gotoxy(2, 19);
		if(fimdejogo) {
			printf("Você perdeu! ☹︎︎\n Movimentos: %d", movimentos);
			return 0;
		} else printf("Não deixe os misséis caírem na Terra!\n Movimentos: %d", movimentos);
		
		
	
			
			
		
		int mov = getch();
		int erro = 0;
		
		switch (mov) {
			case 'a':
			case 'A': X--; ciclo++; movimentos++; break;
			case 'd':
			case 'D': X++; ciclo++; movimentos++; break;	 
			default: erro = 1;
		}
		
		if(X>69) {
			X--;
			movimentos--;
		}
		if(X<0) { 
			X++;
			movimentos--;
		}
		if (erro) continue;
		

		
	} while (1);
}

