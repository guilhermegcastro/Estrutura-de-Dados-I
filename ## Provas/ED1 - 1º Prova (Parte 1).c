/* 1º PROVA ED1
 * Questão #01 [Paradoxo do Aniversário]
 * No campo da teoria das probabilidades, o Paradoxo do Aniversário é um curioso problema apresentado pela primeira vez pelo matemático polonês Richard von Mises.
 * Imagine uma turma de 30 alunos matriculados em ED-1… A chance do professor acertar um dia do ano em que pelo menos um dos alunos faz aniversário, é algo por volta de 8%.
 * No entanto, a probabilidade de que pelo menos dois estudantes nesta turma tenham a mesma data de aniversário é por volta de 70%.
 * Apesar da curiosidade, esse paradigma é muito importante em áreas da ciência da computação, como por exemplo na definição funções hash eficientes que evitem o problema de colisões de chaves… Mas isso ainda não é nosso assunto de estudo (retomaremos isso em ED-2).
 * Sua tarefa hoje é desenvolver um programa que comprove por experimentação o Paradoxo do Aniversário…
 * Faça um programa que receba um valor inteiro N, que representa a quantidade de alunos em uma turma.
 * Sabendo que todo aluno possui uma data de aniversário (por simplificação, considere o dia 1 ao dia 365), verifique se há alunos que fazem aniversário no mesmo dia.
 * Para comprovar a probabilidade demonstrada pelo Paradoxo, seu programa deverá executar essa simulação 100.000 vezes, e calcular o percentual (%) de vezes em que os cenários aleatórios indicaram a coincidência de aniversários.
 * Para cada experimento de N pessoas, seu programa deverá informar como resultado a seguinte frase:
 * Para um grupo de 23 pessoas, em 50.14% por cento dos 100K cenários foram encontrados aniversariantes na mesma data!
 * Seu programa deve executar várias simulações, para diferentes valores de N informados pelo usuário, eencerrar quando o valor de N for igual ou menor que 0.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define QT 100000

int main() {
	
	int N;
	
	do{
		printf("Quantas pessoas há na festa?\n > ");
		scanf(" %d", &N);
		if(N<1) break; //Quebra o loop ao digitar um número menor que 1!
		int pessoa[N], paradoxo=0;
		for (int idc = 0; idc < QT; idc++) { //Simulação de 100k cenários!
			for (int i = 0; i < N; i++)  // sorteio do aniversário!
				pessoa[i]= 1 + rand()%365; 
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
		printf("Para um grupo de %d pessoas, em %.2f%% por cento dos 100K cenários foram encontrados aniversariantes na mesma data!\n", N, perc);
	}while (1);
	
	printf("Programa Finalizado..!"); 
	return 0; // Progama finaliza. 
}

