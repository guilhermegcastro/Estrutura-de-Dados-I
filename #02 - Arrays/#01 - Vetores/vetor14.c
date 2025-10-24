/**
 * @file    vetor14.c
 * @author  @guilhermegcastro
 * @date    2025-10-23
 * @brief   
 * Enunciado: 14. Faça um programa que sorteie aleatoriamente N números, no intervalo entre X e Y (inclusive). 
 * Após o sorteio, o programa deve imprimir os números sorteados originalmente. 
 * Após isso, e a cada iteração, o programa deve imprimir novamente a relação, mas agora trocando as posições do MAIOR elemento pelo MENOR elemento.
 * Uma vez trocadas as posições, estes mesmos número não poderão ser mais trocados.
 * Repita essa operação até quando for possível...
 * Exemplo de Execução para: N = 8;X = 1; Y = 10; 
 * Original: 4 – 6 – 8 – 9 – 3 – 2 – 7 – 8
 * 1ª Iteração: 4 – 6 – 8 – 2 – 3 – 9 – 7 – 8
 * 2ª Iteração: 4 – 6 – 3 – 2 – 8 – 9 – 7 – 8
 * 3ª Iteração: 8 – 6 – 3 – 2 – 8 – 9 – 7 – 4
 * 4ª Iteração: 8 – 7 – 3 – 2 – 8 – 9 – 6 – 4
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	
	srand(time(NULL));
	int N, X, Y;
	printf("Insira a quantidade de números que serão sorteados: ");
	scanf(" %d", &N);
	printf("Insira o intervalo mínimo (inclusive) : ");
	scanf(" %d", &X);
	printf("Insira o intervalo máximo (inclusive) : ");
	scanf(" %d", &Y);
	
	while (X > Y) {
		int troca = X;
		X = Y;
		Y = troca;
	}
	
	int sorteio[N],flag[N], cont=0;
	
	for (int i = 0; i < N; i++) {
		sorteio[i] = X + rand()%(Y-X+1);
		flag[i] = 1;
	 }
		system("clear");
	do {
		while(getchar()!='\n');
		printf("\n  %dº iteração: ", cont+1);
		for (int i = 0; i < N; i++) {
			printf(" [%d]", sorteio[i]);
		}

		int flagMaiorMenor = 1, maior, menor;
		for (int i = 0; i < N; i++){
		
			if(!flag[i]) continue;
			if(flagMaiorMenor) {
				maior = i;
				menor = i;
				flagMaiorMenor = 0;
			}
			
			maior = (sorteio[i] > sorteio[maior]) ? i : maior;
			menor = (sorteio[i] < sorteio[menor]) ? i : menor;
		}
		
			if (!flagMaiorMenor){
			int troca = sorteio[maior];
			sorteio[maior] = sorteio[menor];
			sorteio[menor] = troca;
			if (maior!=menor) {
				printf("\n\n Próxima troca: "); (menor < maior) ? printf(" Posição [%d] <-- --> Posição [%d]", menor, maior) : printf(" Posição [%d] <-- --> Posição [%d]", maior, menor);
			 }
			flag[maior] = 0;
			flag[menor] = 0;
			}

		printf("\n         - Aperte Enter para prosseguir.");
		cont++;
		getchar();
		
		if (maior==menor || flagMaiorMenor)
			break;
		
	
	} while (1);
	
	
	
	
    return 0;
}
