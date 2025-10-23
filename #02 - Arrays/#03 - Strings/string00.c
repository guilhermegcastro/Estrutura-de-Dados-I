/**
 * @file    string00.c
 * @author  @guilhermegcastro
 * @date    2025-10-22
 * @brief   
 * Enunciado: Faça um programa que: 
 * - Leia a quantidade de N alunos:
 * - Leia a quantidade de N provas da disciplina.
 * - Preencha aleatoriamente a nota de cada prova de cada aluno (As provas possuem a mesma nota).
 * Ao final imprima: 
 * a) Nota final de cada aluno na disciplina.
 * b) Quem foi aprovado (soma >= 60)
 * c) Quem ficou de final (40 <= soma < 60
 * d) Quem ficou acima da média.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char cabecalho(char* nomeDaDisciplina);
int main() {
	
	srand(time(NULL));
	
	int qtdAluno, qtdProva, cont=0;
	char disciplina[15];
	
	printf("Qual o nome da disciplina  que você deseja registrar as notas?\n > "); // Define o nome que aparece no cabeçalho.
	scanf(" %[^\n]s", disciplina); 
	
	cabecalho(disciplina); // Limpa a tela e imprime o cabeçalho.
	
	printf("Quantos alunos você deseja registrar?\n > ");
	scanf(" %d", &qtdAluno);
	printf("Quantas provas a disciplina possui?\n > ");
	scanf(" %d", &qtdProva);
	
	char alunos[qtdAluno][30];
	int prova[qtdAluno][qtdProva], somaProva[qtdAluno], media=0; // o indice do aluno na string equivale ao indice da sua nota no vetor da prova.
	
	cabecalho(disciplina);
	
	do {
		printf("Insira o nome do %dº aluno:\n > ", cont+1);
		scanf(" %[^\n]s", alunos[cont]);
		cont++;
	} while (cont < qtdAluno);
	
	for (int i = 0; i < qtdAluno; i++) {
		for (int j = 0; j < qtdProva; j++) {
		prova[i][j] = rand()%((100/qtdProva)+1); // sorteia a nota das N provas de cada aluno.
		somaProva[i]= 0; // inicializa o vetor de somatoria para evitar lixo de memória.
		}
		for (int j = 0; j < qtdProva; j++) somaProva[i] += prova[i][j]; //somatório das N provas de cada aluno no vetor de somaProva.
			
	}

	media/= qtdAluno; // Calcula a média, divindindo a soma pela quantidade de alunos.
	cabecalho(disciplina);
	
	for (int i = 0; i < qtdAluno; i++){
		printf("%2dº Aluno: %s\n    Notas: ", i+1, alunos[i]);
		media+= somaProva[i]; //Soma a nota total de todos os alunos.
		for (int j = 0; j < qtdProva; j++) printf(" Prova %d [%02d]|", j+1, prova[i][j]);
		printf("\n\n");
	}
	media/= qtdAluno; // Divide a Soma pela quantidade de alunos para encontrar a média.
	
	printf("Aperte ENTER para prosseguir...\n");
	
	while(getchar()!='\n');
	getchar();

	cabecalho(disciplina);
	
	printf("\nSeção 1: Alunos Aprovados.\n");
	
	for (int i = 0; i < qtdAluno; i++) {
		if(somaProva[i] >= 60) printf(" %s com %d no Total.\n", alunos[i],somaProva[i]);
	}
	printf("\n\nSeção 2: Alunos que farão Prova Final.\n");
	for (int i = 0; i < qtdAluno; i++) {
		if(somaProva[i] >= 40 && somaProva[i] < 60) printf(" %s com %d no Total.\n", alunos[i],somaProva[i]);
	}
	printf("\n\nSeção 3: Alunos Reprovados.\n");
	for (int i = 0; i < qtdAluno; i++) {
		if(somaProva[i] < 40) printf(" %s com %d no Total\n", alunos[i],somaProva[i]);
	}
	
	printf("\n\nSeção 4: Alunos acima da Média (Média: %d) \n", media);
	for (int i = 0; i < qtdAluno; i++) {
		if(somaProva[i] > media) printf(" %s com %d no Total.\n", alunos[i],somaProva[i]);
	}
	
    return 0;
}

char cabecalho(char* nomeDaDisciplina) {
	system("clear");
	 return printf("=== Boletim geral de %s ===\n", nomeDaDisciplina);	
}
