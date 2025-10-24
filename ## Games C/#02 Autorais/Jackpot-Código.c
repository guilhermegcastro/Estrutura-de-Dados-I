/**
 * @file Jackpot.c
 * @author Guilherme Castro
 * @date 2025-10-04
 * @brief
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {	
	
	srand(time(NULL));
	char  moneyName[] = "pontos";
	char icon [19] = {'*', '#', '%', '@', '!', '$', '*', '#', '%', '@', '#', '*', '@', '#', '%', '@', '!', '$', '7'}, icon1=icon[18], icon2=icon[18], icon3=icon[18], bicon1=icon[17], bicon2=icon[17], bicon3=icon[17], aicon1=icon[0], aicon2=icon[0], aicon3=icon[0];
	int  menu=1, money = 3000, moneyAll=0, first, spin=1, jp1=0, jp2=0, jp3=0, jp4=0, jp5=0, jp6=0, jp7=0, win=0, multiplier, jpX=1, moneyX=1; 
	/*O Programa sempre inicia com o jackpot em 7 7 7. */
	do {
		
		while (menu)
		{
				printf(" =================================== JACKPOT ===================================\n\n Insira o número da lista de acordo com os valores desejados\n\n\t(Valor padrão do giro: 10 %s)\n\n 1 - Multiplica o valor do giro por  1.0x e o valor dos prêmios por  1.0x  \n 2 - Multiplica o valor do giro por  2.0x e o valor dos prêmios por  3.0x  \n 3 - Multiplica o valor do giro por  5.0x e o valor dos prêmios por  7.0x  \n 4 - Multiplica o valor do giro por 10.0x e o valor dos prêmios por 15.0x  \n > ", moneyName);
					scanf("%d", &multiplier); /*Solicita um valor de 1 a 4*/
					
			
			if((multiplier < 1) || (multiplier > 4)) {
				while(getchar()!='\n'); /* Tratamento de erro contra símbolos/letras */
				system("clear");
				continue;
			}
				switch (multiplier) { /* Lista executa caso a opção esteja entre 1 a 4 */
					case 4: moneyX= 10; jpX = 15; break;
					case 3: moneyX= 5;  jpX = 7;  break;
					case 2: moneyX= 2;  jpX = 3;  break;
					case 1: moneyX= 1;  jpX = 1;  break;
					/* moneyX é o valor que irá multiplicar sobre o preço do giro; jpX é o valor que irá multipicar sobre as recompensas do jackpot.*/
				}	
			
			menu=0; /* O menu não executará daqui pra frente, a não ser que o usuário solicite futuramente.*/
			first=1;/* A variavél first recebe verdade. O jackpot congela enquanto ela for verdadeira e não altera os valores dos símbolos/saldo. */
			system("clear"); /*Limpa a tela do menu*/
		}
				
		for (int i = 0; i < spin; i++) {
			 if(!first) { /*Só executa quando first for falso*/
				 int i1 = rand()%19, i2 = rand()%19, i3 = rand()%19;
					 icon1 = icon[i1]; icon2 = icon[i2]; icon3 = icon[i3];
			
				bicon1 = (i1 == 0) ? icon[18] : icon[i1-1];
				bicon2 = (i2 == 0) ? icon[18] : icon[i2-1];
				bicon3 = (i3 == 0) ? icon[18] : icon[i3-1];
				
				aicon1 = (i1 == 18) ?  icon[0] : icon[i1+1];
				aicon2 = (i2 == 18) ?  icon[0] : icon[i2+1];
				aicon3 = (i3 == 18) ?  icon[0] : icon[i3+1];
				
				}
				
			printf(" =================================== JACKPOT ===================================\n"); 
			printf("	+---------------------------------+        __________________________ \n");
			printf("	|   Giro | %3d | de | %3d |       |       | TABELA DO JACKPOT        |\n", i+1, spin);
			printf("	|   +-------------------------+   |       |------------------------- |\n");
			printf("	|   |    | %c | | %c | | %c |    |   |       | * * *   --> %5d %s |\n", bicon1, bicon2, bicon3, 20*jpX, moneyName);
			printf("	|   | -- [ %c ] [ %c ] [ %c ] -- |   |       | # # #   --> %5d %s |\n", icon1, icon2, icon3, 40*jpX, moneyName);
			printf("	|   |    | %c | | %c | | %c |    |   |       | %% %% %%   --> %5d %s |\n", aicon1, aicon2, aicon3, 100*jpX, moneyName);
			printf("	|   +-------------------------+   |       | @ @ @   --> %5d %s |\n", 200*jpX, moneyName);
			printf("	|                                 |       | ! ! !   --> %5d %s |\n", 400*jpX, moneyName);
			printf("	|     "); ((icon1 == icon2) && (icon2==icon3) && (icon1 == icon[18]))  ? printf("!!!  J A C K P O T  !!!     |       "): printf("                            |       "); printf("| $ $ $   --> %5d %s |\n", 800*jpX, moneyName);           
			printf("	|                                 |       | 7 7 7   --> %5d %s |\n", 1000*jpX, moneyName);
			printf("	+---------------------------------+        __________________________ \n");
			putchar('\n'); /* Jackpot + Tabela de valores (os valores são definidos de acordo com o multiplicador selecionado com antecedência.)*/
				 
			if(!first) {
				money-=10*moneyX;  /* Tira um valor referente ao preço do giro do saldo atual*/
			
				if ((icon1 == icon2) && (icon2==icon3) &&(!first)) { /* Executa quando as três variáveis tiverem o mesmo símbolo*/
					
					switch(icon1) { /*Switch de atribuição dos valores sobre o saldo total ganho, o saldo atual, contagem de ganhos por símbolo e mensagem de ganho de acordo com o char*/
						case '*' : money+= 20*jpX; moneyAll+=20*jpX; jp1+=1; printf("       Você GANHOU %d %s!\n", 20*jpX, moneyName); break;
						case '#' : money+= 40*jpX; moneyAll+=40*jpX; jp2+=1; printf("       Você GANHOU %d %s!!\n", 40*jpX, moneyName); break; 		
						case '%' : money+= 100*jpX; moneyAll+=100*jpX; jp3+=1; printf("       Você GANHOU %d %s!!!\n", 100*jpX, moneyName); break; 
						case '@' : money+= 200*jpX; moneyAll+=200*jpX; jp4+=1; printf("       Você GANHOU %d %s!!!!\n", 200*jpX, moneyName); break; 
						case '!' : money+= 400*jpX; moneyAll+=400*jpX; jp5+=1; printf("       Você GANHOU %d %s!!!!!\n", 400*jpX, moneyName); break; 
						case '$' : money+= 800*jpX; moneyAll+=800*jpX; jp6+=1; printf("       Você GANHOU  %d %s!!!!!!\n", 800*jpX, moneyName); break; 
						case '7' : money+= 1000*jpX; moneyAll+=1000*jpX; jp7+=1; printf("       Você GANHOU %d %s!!!!!!!\n", 1000*jpX, moneyName); break; 
					}
					
					win=1; /* controle do sleep. Caso verdadeiro, o terminal adormece por 3 segundos. Caso falso, o terminal adormece por 1 segundo. Necessário para o usuário conseguir ter mais tempo de visualização caso ocorra um ganho, e não precisar esperar muito caso o resultado não seja ganho. */
				}
		
			}
			 
			 first=0;

			
			printf("\t\t\t\t\t\t      (1 giro = %d %s)\n ____________________________________________________________________________\n\n",moneyX*10, moneyName); /* Mostra o preço do giro de acordo com o multiplicador selecionado inicialmente*/
			printf("   CONTAGEM DE COMBINAÇÕES:                              SALDO: %d %s\n\n  [***]: %02d  [###]: %02d  [%%%%%%]: %02d  [@@@]: %02d  [!!!]: %02d  [$$$]: %02d  [777]: %02d\n\n", money, moneyName, jp1, jp2, jp3, jp4, jp5, jp6, jp7); /*Mostra o saldo atual, mais uma linha com cada ganho obtido por símbolo.*/
			 
			 if(!first) { /*Executa somente se first for falso*/
				 (win) ? system("sleep 3") : system("sleep 1");
				 win=0; /* Torna win falso, para o sleep do próximo giro (caso não seja feito por uma combinação) ser 1 segundo. */
				 if (i+1!=spin) { /* Evita que o último giro do loop seja apagado pelo system clear.*/
						  system("clear");
				 }	 		 
		     }
		}
		
		printf(" Digite -1 para voltar ao menu de seleção do multiplicador;\n Digite  0 para finalizar o jogo;\n Digite um número positivo para escolher a quantidade de giros;\n >  ");
		scanf("%d", &spin); /* Solicita ao usuário um menu de opções.*/
	

		if(spin==-1) { /* Opção do menu do multiplicador*/
			menu=1; /* O menu inicial executa novamente para a escolha de um  outro multiplicador */
			spin=1; /* Evita que o jackpot e a tabela não apareça após o system clear do menu*/
			system("clear");
			continue;
		}
		
		if (!spin) /* Quebra o laço do quando o usuário digitar 0*/
			break;
			
		if((spin < -1) || (spin*10*moneyX > money)) { /*Tratamento de erro para quando o usuário inserir um número negativo menor que -1, ou quando o saldo não for suficiente para os giros solicitados.*/
			(spin < -1) ? printf(" Número de giros inválido.") : printf(" Saldo insuficiente para os giros."); printf(" Aperte ENTER e tente novamente."); /*Mensagem muda dependo de qual dos erros foram tratados.*/
			spin=1; /*spin torna verdadeiro para mostrar o jackpot juntamente com a tabela */
			first=1; /*first torna verdadeiro para congelar os valores do jackpot e evitar decremento do saldo atual*/
			getchar(); /* Solicita um char para o usuário inserir ENTER*/ 
			while(getchar()!='\n');
			system("clear");
			continue;

		}	 
		system("clear");

	} while (1); /*O loop só termina quando o usuário inserir o valor 0 em spin.*/ 
	
	while(getchar()!='\n'); /*Limpa qualquer char que foi solicitado anteriormente*/
	printf("\n Você obteve %d %s no jackpot e terminou com %d %s no total.\n Você obteve %d combinações no jackpot.", moneyAll, moneyName, money, moneyName, jp1+jp2+jp3+jp4+jp5+jp6+jp7); /*Mostra quanto o usuário recebeu do jackpot, o saldo final, e a soma de quantas vezes ele obteve combinações durante a partida.*/
        return 0;


}

