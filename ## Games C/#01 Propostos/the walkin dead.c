
/**
 * @file the walkin dead.c
 * @author @guilhermegcastro
 * @date 2025-11-03
 * @brief
 **/

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
 #include "gconio.h"
 #define CABECALHO 24
	
	void introducao();
	void sorteio(char sort[10][11]);
	void mapa(char zumb[10][11]);
	
	int main() {
		cursor(0);
	    srand(time(NULL));
		introducao();
		char zumbis[10][11];
		
		system("clear");
		sorteio(zumbis);
		mapa(zumbis);
		
        return 0;
 	}
 	
	void introducao() {
	
	
		for (int i = 0; i < CABECALHO; i++) putchar('=');
		printf(">> THE WALKING DEAD MINIGAME <<");
		for (int i = 0; i < CABECALHO; i++) putchar('=');
		
		printf("\n\n");
		

		printf(" Alô, Rick Grimes!\n Você precisa atravessar a cidade repleta de zumbis assassinos com apenas um rifle e 50 munições.");
		printf(" Cada quarteirão da cidade possui a quantidade de zumbis indicado pelo número impresso, e você deve percorrer cada quarteirão uma única vez!\n");
		printf(" Mas atenção... Há também um quarteirão (#) com munições extras.\n");
		printf(" SEJA ESTRATÉGICO! Você será capaz de sair vivo desse desafio?\n\n");
		printf("\tTeclas de navegação:\n\n");
		printf("\t\t'w'         \n");
		printf("\t'a'		 'd'\n");
		printf("\t\t's'       \n\n");
		printf(" Pressione  a tecla 'x' para encerrar o jogo.\n");
		printf(" * Pressione ENTER para começar... *");
		getchar();
	}
	
	void sorteio(char sort[10][11]) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				sort[i][j] = rand()%10 + '0';
			}
		}
		
		sort[rand()%10][rand()%10] = '#';
	}
	
	void mapa(char zumb[10][11]) {
		
		int X=2, Y=0, muni=0, total=50;
		
		do {
			system("clear");
			gotoxy(2,0);
			putchar('*');
			putchar('\n');
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if(i == Y-1 && j== X-2) {
						muni+= zumb[i][j] - '0';
					}
					
					printf(" %c", zumb[i][j]);
				}
				putchar('\n');
			}
			
			gotoxy(19,12);
			printf("[@]");
			gotoxy(X,Y);
			putchar('_');
			gotoxy(2,14);
			printf("MUNIÇÃO UTILIZADA: %d/%d",muni, total);
			
			
			
				char mov;
				mov = getch();
				
				switch (mov)
				{
					case 's': Y++; break;
					case 'w': Y--; break;
					case 'd': X+=2; break;
					case 'a': X-=2; break;
				}
				if (X<2) X+=2;
				if (X>20) X-=2;
				if (Y<2) Y++;
				if (Y>11 && X!=20) Y--;
				
		
		} while (1);
		
	}
	
