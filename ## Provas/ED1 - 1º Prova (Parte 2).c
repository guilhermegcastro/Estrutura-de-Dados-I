/* 1º PROVA ED1
 * Questão #02
 * Continuando o problema anterior, faça outro experimento baseado na mesma premissa do Paradoxo do Aniversário, e desenvolva um programa que faça simulações para responder a seguinte pergunta…
 * QUANTOS “DIAS” SERIAM NECESSÁRIOS EXISTIR PARA QUE UM DETERMINADO GRUPO ALEATÓRIO DE “N” PESSOAS TEREM PROBABILIDADE INFERIOR A 10% DE FAZER ANIVERSÁRIO NA MESMA DATA?
 * Observação! Para diminuir o tempo de processamento deste problema, reduza o número de cenários realizados para cada experimento de 100.000 para apenas 300 cenários de N pessoas aleatórias.
 * Seu programa deve rodar o experimento 10 vezes para cada valor de N informado. Para encerrar a execução, o valor de N deverá ser menor ou igual a 0.
 * Alguns resultados de referência (considerando 300 simulações para cada grupo de N pessoas)…
 * N: Qtde. Pessoas Qtde. de “Dias” Necessários
 * 10 Algo entre 200 e 400
 * 20 Algo entre 1000 e 1400
 * 25 Algo entre 1600 e 2000
 * 30 Algo entre 2300 e 2900
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define QT 300

int main() {
	
	int N;
	
	do{
		printf("Quantas pessoas há na festa?\n > ");
		scanf(" %d", &N);
		if(N<1) break;
		int day=1, cont=0;
		while (cont<10){ 	// Execução de 10 testes!
			int pessoa[N], paradoxo=0;
			for (int idc = 0; idc < QT; idc++) { //Simulação de 300 cenários!
				for (int i = 0; i < N; i++) // sorteio do aniversário!
					pessoa[i]= rand()%(day+1);
				int sameBth = 0;
				for (int i = 0; i < N; i++) { //Verificador de pessoas que fazem aniversario no mesmo dia!
					for (int j = i+1; j < N; j++) {
						if(pessoa[j]==pessoa[i]) {
							sameBth = 1;
							break;
						}
					}
				}
				if(sameBth) paradoxo++; //Se encontrou aniversariantes do mesmo dia, incrementa a contagem da variável!
			}	
				double perc = (100.00*paradoxo)/QT; // Cálculo do percentual!
				if(perc>=10.00) { // Se o percentual for maior ou igual a 10%, adiciona um dia e continua a verificação...
					day++;
					continue;
				}
				printf("Day : %d\n", day); // Imprime no terminal a quantidade de dias necessários para que o percentual seja menor que 10%
				cont++; //Aumenta o cont para o próximo teste.
				day=1; // Reseta o dia para um.
		}
	} while (1);
	
	printf("Progama Finalizado!");
	return 0; // Progama finaliza. 
}

