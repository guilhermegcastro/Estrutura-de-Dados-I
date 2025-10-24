/**
 * @file Dojo Coding 02 (Adivinhe o Número).c
 * @author Guilherme Castro
 * @date 2025-10-03
 * @brief
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	srand(time(NULL));
	
	int palpitehum, numeropc=rand()%100, tentativahum=0, palpitepc, tentativapc=0, intervalomaior=99, intervalomenor=0, fimdejogo=1;
	char controle;

	
 do {
		printf("====================== ADIVINHE O NÚMERO ======================\n\n======================== HUMANO vs. PC ========================\n\nO PC escolheu um número entre 0 e 99.\nTente adivinhá-lo o mais breve possível...\n\n");
		printf("Digite um número entre 0 e 99:\n > ");
		scanf(" %d", &palpitehum);
		
		tentativahum+=1;
		
		if (palpitehum != numeropc) {
			while(getchar()!='\n');
			putchar('\n');
			
			printf("O número sorteado é "); (palpitehum > numeropc) ? printf("MENOR que %d.\n", palpitehum) : printf("MAIOR que %d.\n", palpitehum);
			printf("Aperte a tecla ENTER para continuar...\n");
			getchar(); 
			
			system("clear");
			
			continue;
			}
			break;
			
	} while (1);
	
	while(getchar()!='\n');
	
	printf("Parabéns você acertou o número após %d tentativas!\nChegou a hora do PC competir com você...\n\nAGORA VOCÊ DEVE PENSAR EM UM NÚMERO ENTRE 0 E 99.\n\nTecle ENTER para continuar...", tentativahum);
	getchar();
	
	system("clear");
	
	do {
			palpitepc = intervalomenor + rand()%(intervalomaior-intervalomenor + 1);
			
			printf("====================== ADIVINHE O NÚMERO ======================\n\n======================== HUMANO vs. PC ========================\n\nO PC chutou que o seu número é... %d!\n\n", palpitepc);
			printf("Digite:\n ' = ' - Se o PC Acertou o número;\n ' > ' -  Se o seu número é maior;\n ' < ' - Se o seu número é menor.\n :");
			scanf(" %c", &controle);
			
			tentativapc += 1;
			
			switch (controle) {
				case '=': printf("O PC acertou seu número escolhido!\n Foram necessárias %d tentativas para o PC!\n\n", tentativapc); fimdejogo=0; while(getchar()!='\n'); break;
				case '>': intervalomenor = palpitepc + 1; system("clear"); break;
				case '<': intervalomaior = palpitepc - 1; system("clear"); break;
			}
	} while (fimdejogo);
	
	printf("Aperte ENTER para os resultados...");
	getchar();
	
	system("clear");
	
	printf("====================== ADIVINHE O NÚMERO ======================\n\n======================== HUMANO vs. PC ========================\n\n");
	printf("RESULTADO DO COMBATE: User %d x %d PC\n", tentativahum, tentativapc);
	
	do {
		if (tentativahum==tentativapc) {
			printf(" Você EMPATOU com a Máquina. ¯\\_(ツ)_/¯");
			break;
		}
		(tentativahum < tentativapc) ? printf("Você VENCEU a Máquina! \\o/") : printf("Você PERDEU pra Máquina... :c");
		break;
	} while (1);
	
}

