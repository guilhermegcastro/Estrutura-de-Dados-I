/**
 * @file pedrapapeltesoura.c
 * @author Guilherme Castro
 * @date 2025-10-10
 * @brief
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()

{
	srand(time(NULL));
	int ppth, pptm, pontosh=0, pontosm=0, empate=0, rodada=0, melhorde;
	
	do	{
			system("clear");
			printf("============================== PEDRA PAPEL TESOURA =============================\n Boas-vindas ao Jogo de Pedra, Papel, Tesoura!\n Veja se você ganha ou não da máquina!\n Pedra ganha de Tesoura\n Papel ganha de Pedra\n Tesoura ganha de Papel.\n\n Digite qual a pontuação máxima para encerrar o jogo:");
			scanf("%d",&melhorde);
			if (melhorde > 0) break; 
			printf(" Digite um número válido!\n");
			system("sleep 1");
	} while (1);
	
	while (1) {
	
		do {	
		system("clear");
		printf("============================== PEDRA PAPEL TESOURA =============================\n\n O jogo termina quando você ou o PC ganhar %d vez(es) primeiro!\n\n\n  Escolha uma opção abaixo:          \t\t Humano: %d\n   1. Pedra                         \t\t Máquina: %d\n   2. Papel                         \t\t Empates: %d\n   3. Tesoura\n                                                 Rodada: %d\n\n >> ", melhorde, pontosh, pontosm, empate, rodada+1);
		scanf("%d", &ppth);
		if ((ppth > 0) && (ppth < 4))
			break;
		
		} while (1);	
		
		pptm = rand()%3 + 1;
		rodada+=1;
		
		switch (ppth)
		{
			case 1: printf("\n Você escolheu PEDRA! O PC escolheu ");
					
					if (pptm == 3) {
						printf("TESOURA! Você GANHOU!"); pontosh+=1; break;
					} 
					if (pptm == 2) {
						 printf("PAPEL! Você PERDEU!"); pontosm+=1; break;
					} 
						printf("PEDRA! Deu EMPATE!"); empate+=1; break;
						
						
			case 2: printf("Você escolheu PAPEL! O PC escolheu ");
				
					if (pptm == 1) {
						printf("PEDRA! Você GANHOU!"); pontosh+=1; break;
					} 
					if (pptm == 2) {
						 printf("TESOURA! Você PERDEU!"); pontosm+=1; break;
					}
						printf("PAPEL! Deu EMPATE!"); empate+=1; break;
						
						
			case 3: printf("Você escolheu TESOURA! O PC escolheu ");
					
					if (pptm == 2) {
						printf("PAPEL! Você GANHOU!"); pontosh+=1; break;
					} 
					if (pptm == 1)
					{
						printf("PEDRA! Você PERDEU!"); pontosm+=1; break;
					}	
						printf("TESOURA! Deu EMPATE!"); empate+=1; break;			 
		}
		
		putchar('\n');
		printf("\n\n Aperte ENTER para prosseguir. ");
		while(getchar()!='\n');
		getchar();
		if ((pontosh==melhorde) || (pontosm==melhorde)) {
			system("clear");
			printf("============================== PEDRA PAPEL TESOURA =============================\n\n  RESULTADOS DO JOGO!\n\n   Total de Rodadas: %d\n   Pontuação: Humano %d x %d PC    (Empates: %d) \n\n ", rodada, pontosh, pontosm, empate);
			(pontosh>pontosm) ? printf(" Você GANHOU DA MÁQUINA! \\o/") : printf(" Você PERDEU PRA MÁQUINA... :/");
			break;
		}
	}
        return 0;


}

