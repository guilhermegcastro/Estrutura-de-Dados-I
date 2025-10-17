/**
 * @file dojo.c
 * @author  @guilhermegcastro, @mvmedrados, @taynara6, Eleissa Oliveira
 * @date 2025-10-15
 * @brief
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	
	srand(time(NULL));
	int numero[100], contador=0, n=0,flag = 1;
		int resposta[100];
	
	printf("============================= MEMÓRIA NUMÉRICA =============================\n");
	printf(" Você é bom para memorizar números? Vamos testar!\n A cada rodada um novo número é gerado (você tem 1 SEGUNDO para memorizar!).\n Você deve ser capaz de lembrar TODOS os números gerados anteriormente e inserir na ordem correta.\n Ao digitar um único errado, o jogo finaliza.\n Preparado para o desafio? Aperte ENTER para começar!\n");
	getchar();
	
	do {
		system("clear");
		numero[n] = rand()%10;
		printf("Número sorteado: %d\n", numero[n]);
		system("sleep 1");
		system("clear");
		
		printf("Digite a sequência: \n ");
	
		for (int i = 0; i <= n; i++) {
			scanf(" %d", &resposta[i] );
		}
		for (int i = 0; i <=n; i++){
			if (resposta[i]!= numero[i]){
				flag = 0;
				break;
			}
		}
		n++;
		if (flag) {
			contador+=1;
			continue;
		}
		break;
	} while(flag);
	system("clear");
	(contador<100)? printf("Fim de Jogo! Você errou :c"): printf("Tá com tempo heim desocupado(a)! Você chegou ao final, PARABÉNS!!!!!!!!!!!!!!!!!!!!!!!");
	printf("\n\nA sequência é:\n");
	
	for (int i = 0; i < n; i++)
		printf("[%d] ", numero[i]);
	printf("\n Você fez %d pontos!\n\n",contador);
	
	printf("Os números que você digitou errado foram:\nNúmero:  ");
	for (int i = 0; i < n; i++){
		if (numero[i]!= resposta[i])
			printf("[%d] ", resposta[i]);
	}
	printf("\nPosição: ");
	for (int i = 0; i < n; i++){
		if (numero[i]!= resposta[i])
			printf("[%d] ", i);
	}
        return 0;
}

