/**
 * @file snake.c
 * @author Guilherme Castro
 * @date 2025-10-10
 * @brief
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gconio.h"



void tabela(int a);
int main() {
	
	srand(time(NULL));
	int x = 2, y = 12, move, passos=0, captura=0, totalapple, xa = rand()%78+2, ya = rand()%19+4;
	char snake = '>', apple = '@';
	float media=0.0;
	cursor(0);
	
	textcolor(BLUE);
	do {
		system("clear");
		printf("== SNAKE GAME  ==  \nDigite (acima de 0) a quantidade de maçãs que você deseja capturar: ");
		scanf("%d", &totalapple);
	} while (totalapple < 1);
	
	do {
		system("clear");
		textcolor(BLUE);
		
		media = (float)passos/captura;	
		printf("== SNAKE GAME  ==   Passos: %d   Maçãs: %d/%d   Média: %.2f\n", passos, captura, totalapple, media);
		textcolor(PURPLE);
		printf("Controles: (W) - Cima (S) - Baixo (A) - Esquerda (D) - Direita\n");
		textcolor(GREEN);
			
		if(captura == totalapple) {
			tabela(15);
			snake = ' ';
			apple = ' ';
			gotoxy(34,8);
			textcolor(BROWN);
			printf("FIM DE JOGO!");
			gotoxy(0, 18);
			break;
		}
			
		tabela(20);
		textcolor(YELLOW);
		gotoxy(x, y);  printf("%c", snake);
		textcolor(RED);
		gotoxy(xa, ya);  printf("%c", apple);
		move = getch();

		switch (move) {
			case 'w':
			case 'W': snake = '^'; y--; passos+=1; break;
			case 's':
			case 'S': snake = 'v'; y++; passos+=1; break;
			case 'a':
			case 'A': snake = '<'; x--; passos+=1; break;
			case 'd':
			case 'D': snake = '>'; x++; passos+=1; break;
		}
				
		if (y==03) y=23;
		if (y==24) y=04;
		if (x==01) x=79;
		if (x==80) x=02;
		
		if ((x==xa) &&(y==ya)) {
			xa = rand()%78+2;
			ya = rand()%19+4;
			captura+=1;
		}
		
	} while (1);
	
        return 0;
}


void tabela(int a) {
	
		for(int i = 0; i < 80; i++) {
			printf("-");
		}
			printf("\n");
		for(int i = 0; i < a; i++) {
			for(int j = 0; j < 80; j++) {
				if((!j)|| (j==79)) {
					printf("|");
					continue;
				}
				printf(" ");
			}
			printf("\n");
		}

		for(int i = 0; i < 80; i++) {
			printf("-");
		}
	}
