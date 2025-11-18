/**
 * @file DC Coding 04 (Jogo da Memória).c
 * @author @guilhermegcastro
 * @date 2025-10-15
 * @brief
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int quant, quantdouble, simboloint, cont=0, posicao1, posicao2, n1, n2;
	do{
		system("clear");
		printf("================= JOGO DA MEMÓRIA [PARES DE CARTAS] =================\n\n Com quantos pares de cartas deseja jogar? (LIMITE: 26)\n > ");
		scanf(" %d", &quant);
	} while (quant<1||quant>26);
	
	quantdouble = quant*2;
	
	int simbolo[quant], baralho[quantdouble], posicao[quantdouble];
	
	for (int i = 0; i < quant; i++)
		simbolo[i] = 0;	
	for (int i = 0; i < quantdouble; i++) {
		baralho[i]= -1;
		posicao[i]= -1;
		}
		
	do {
		int valido = 1;
		simboloint= 1 + rand()%26;
		for (int i = 0; i < cont; i++) {
			if (simboloint==simbolo[i])	{
				valido=0;
				break;
			}
		}	
		if (valido)  {
			simbolo[cont] = simboloint;
			cont++;
		}
		
	} while (cont<quant);
	
	
		cont = 0;

	do {
		int valido = 1; 
		posicao1 = rand()%quantdouble;
		
		do {
			posicao2 = rand()%quantdouble;
		} while (posicao1==posicao2);
		
		
		for (int i = 0; i < quantdouble; i++) {
			
			if ((posicao1==posicao[i]) || (posicao2==posicao[i])){
			   valido = 0;
			   break;
			}
		}
			if(valido) {
			posicao[posicao1] = posicao1;
			posicao[posicao2] = posicao2;
			baralho[posicao1] = baralho[posicao2] = simbolo[cont];
			cont++;
			}
			
	} while (cont < quant);
	
	cont = 0;
	int endgame = 0;
	do {
		system("clear");
		printf("================= JOGO DA MEMÓRIA [PARES DE CARTAS] =================\n\n\t");
		
		for (int i = 0; i < quantdouble; i++) {
			
			if (i == quant)
				printf("\n\t");		
			if(!baralho[i]) {
				printf("       ");
				continue;
			}
			printf("[%02d]   ", posicao[i]);
			
		}	
		printf("\n");
		

		printf("\n Digite 2 números (visíveis acima) correspondentes as cartas para virar:\n > ");
		scanf(" %d %d", &n1, &n2);
		
		if (((quant%2==0)) && ((n1==n2) || (n1 < 0) || (n1 > quantdouble) || (n2 < 0) || (n2 > quantdouble) || (!baralho[n1]) || (!baralho[n2]))) {
			printf("\nNúmero(s) inválido(s)! Aperte Enter e tente novamente.\n");
			while(getchar()!='\n');
			getchar();
			continue;
		}
		
		system("clear");
		printf("================= JOGO DA MEMÓRIA [PARES DE CARTAS] =================\n\n\t");
		
		for (int i = 0; i < quantdouble; i++) {
			if (i == quant)
				printf("\n\t");
				
			if(!baralho[i]) {
				printf("       ");
				continue;
			}
			if ((i ==n1)||(i==n2)) {
			printf("[%c%c]   ", baralho[i]+64, baralho[i]+64);
			continue;
			}
			printf("[%02d]   ", posicao[i]);
		}
		printf("\n");
		cont++;
		if (baralho[n1] == baralho[n2]){
			printf(" Você encontrou um par! \\o/\n");
			baralho[n1] = baralho[n2] = 0;
			endgame++;
		}	
		else printf(" Não formou um par! ¯\\(ツ)/¯\n");
		printf(" Aperte ENTER para prosseguir...");
		while(getchar()!='\n');
		getchar();
		
	} while (endgame<quant);
	
	system("clear");
	printf("================= JOGO DA MEMÓRIA [PARES DE CARTAS] =================\n\n");
	printf(" FIM DE JOGO!\n Você encontrou todos os pares com %d tentativas!", cont);
	
	
        return 0;
        
}

