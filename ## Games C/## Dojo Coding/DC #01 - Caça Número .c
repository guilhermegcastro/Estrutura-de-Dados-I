
/**
 * @file Dojo Coding 01 (Caça ao Número).c
 * @author Guilherme Castro, Eleissa Oliveira, Maria Vitória Medrado, Arthur
 * @date 2025-10-02
 * @brief
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()

{
	srand(time(NULL));
	int n1, n2, n3, resposta, acertos=0, dificuldade; 
	
	do
	{
		system("clear");
		printf("================================ CAÇA AO NÚMERO ================================\n\n Este é um jogo de concentração e agilidade mental!\n\n Será apresentado um painel de 35x20 (700) números repetitivos, exceto por UM!\n\n Você deve ser capaz de localizar o ÚNICO número diferente mostrado na tela.\n\n Você terá um tempo em segundos de acordo com a dificuldade para localizar o único número que é diferente!\n\n O jogo é composto por 10 tentativas!\n\n VOCÊ CONSEGUE ACHAR TODOS??");
		printf(" Escolha a dificuldade:\n 1 - Fácil (07 segundos) \n 2 - Médio (04 segundos) \n 3 - Difícil (02 segundos)\n\nInsira o número correspondente da lista: ");
		scanf("%d", &dificuldade);
	} while ((dificuldade < 1) ||(dificuldade > 3));
	
	
	
	
	system("clear");
	
	for (int contador = 0; contador < 10; contador++)
	{
		
		n1 = rand()%9 + 1;
		do
		{
			n2 = rand()%9 + 1;
		} while (n1 == n2);
		n3 = rand()%700 + 1;
		
		printf("\n\n     ");
		
		for (int i = 1; i < 701; i++) {
		

			(n3!=i) ? printf(" %d", n1): printf(" %d", n2);
			
				if (i % 35 == 0)
					printf("\n     ");
				
					}
		
		if (dificuldade == 1)
			system("sleep 7");
		if (dificuldade == 2)
			system("sleep 4");
		if (dificuldade == 3)
			system("sleep 2");
		system("clear");
		printf("Você conseguiu encontrar o número diferente? Digite-o:\n ");
		scanf(" %d", &resposta);
		
		if (resposta==n2) {
			acertos+=1;
			printf("Você ACERTOU! Era o número %d! :D \n", n2);
		}
		else 
			printf("Você ERROU... Era o número %d. :C Melhore!!\n", n2);
		
		
		printf("Aperte ENTER para a "); (contador!=9) ? printf("%dº", contador+2) : printf("finalizar a");
		printf(" rodada.");
		getchar();
		while(getchar()!='\n');
		system("clear");
		
	}
		
		printf("================================ FIM DE JOGO ================================\n\n\nVocê acertou %d/10\n", acertos);
		if (acertos==10) 
			printf("10/10? O seu olho é muito bom, ein?! :O\n");
		(acertos<5) ? printf("Você foi devagar! Mais sorte na próxima.\n") : printf("Você foi bem! Continue assim.\n");
		
				
				return 0;

}

