
/**
 * @file struct02.c
 * @author @guilhermegcastro
 * @date 2025-11-23
 * @brief Enunciado: 1. Faça um programa que define um novo tipo de dados chamado Aluno. 
 * Cada registro de Aluno deve conter:
 * 
 * Nome do Estudante (s), Número de Matrícula (i), Nome da Disciplina (s), Nota Final da Disciplina (i).
 * a) Leia os dados de vários alunos (até o nome informado for “exit”).
 * b) Após a fase de cadastro, pergunte ao usuário do sistema algum Número de Matrícula para ser pesquisado, e encontrando o registro, imprima todas as informações deste aluno.
 * c) Repita a operação da letra B acima, até que o usuário informe um Nº de matrícula negativo (para indicar a finalização do programa).
 * 
 * 2. Refatore o problema anterior. Agora, imagine que um mesmo aluno possa se matricular em (NO MÁXIMO) até 10 disciplinas distintas. 
 * Toda disciplina deve possuir uma nota final individualizada.
 * Como modelar a nova struct atendendo ao novo requisito? Implemente a solução.
 * 
 * 3. Imagine agora que cada aluno possa ter um número variável de disciplinas, (desde 1 até N).
 * Pense (e implemente) uma solução tecnicamente viável.
 **/

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
 #define MAX_DB 10
 
	typedef struct {
	char nome[100];
	Disciplina disciplinas[10];
	int matricula, disCont;
 } Estudante;

 
int main() {

	Estudante e[MAX_DB];
	int cont=0;
	while (1) {
		system("clear");
		printf("! - Para encerrar o cadastro, insira exit no nome do estudante.\n\n");
		printf("Insira o nome do/a estudante:\n  - > ");
		scanf(" %[^\n]s", e[cont].nome);
		if(!(strcmp(e[cont].nome, "exit"))) 
			break;
		printf("Insira o número da matrícula:\n  - > ");
		scanf(" %d", &e[cont].matricula);
		int contDis=0;
		while(1) {
		
			do {
				printf("Insira a %dº disciplina: (Digite exit para finalizar)\n  - > ", contDis+1);
				scanf(" %[^\n]s", e[cont].disciplinas[contDis].nome);
				if((strcmp(e[cont].disciplinas[contDis].nome, "exit")==0) && !contDis) {
					printf("É necessário cadastrar no mínimo 1 disciplina!\n\n");
					continue;
				}
				break;
			} while (1);
			
			if((strcmp(e[cont].disciplinas[contDis].nome, "exit")==0))
				break;
				
			
			printf("Insira a nota final da disciplina de %s:\n  - > ", e[cont].disciplinas[contDis].nome);
			scanf(" %d", &e[cont].disciplinas[contDis].notaFinal);
			contDis++;
			if(contDis > 9) {
				printf("Limite de 10 disciplinas atingido. Aperte ENTER para prosseguir.");
				while(getchar()!='\n');
				getchar();
				break;
			}
		}
		e[cont].disCont = contDis;
		cont++;
		if(cont > MAX_DB) {
			printf("Você atingiu o limite de %d cadastros. Aperte Enter para prosseguir.", MAX_DB);
			while(getchar()!='\n');
			getchar();
			break;
		}
	}
	
	for (int i = 0; i < cont-1; i++) {
		for (int j = 0; j < cont-i-1; j++) {
			if (e[j].matricula > e[j+1].matricula) {
				Estudante troca; 
				troca = e[j];
				e[j] = e[j+1];
				e[j+1] = troca;
			}
		}
	}
	
	
	while (1) {
		system("clear");
		int busca;
		printf("! - Para encerrar a busca, insira um valor negativo.\n\n");
		printf("Informe o número da matrícula do estudante desejado:\n - > ");
		scanf(" %d", &busca);
		if(busca < 0)
			break;
		int inicio = 0, fim = cont, encontrado = 0;
		while(inicio<=fim) {
			int meio = (inicio+fim)/2;
			if(busca == e[meio].matricula) {
				encontrado = 1;
				busca = meio;
				break;
			}
			if (e[meio].matricula > busca) 
				fim = meio - 1;
			else 
				inicio = meio + 1;
		}
		if(!encontrado) {
			printf(" - Matrícula inexistente. Aperte Enter para tentar novamente.");
			while(getchar()!='\n');
			getchar();
			continue;
		}
		system("clear");
		printf("  MATRÍCULA Nº%d\n Nome: %s\n\n", e[busca].matricula, e[busca].nome);
		for (int i = 0; i < e[busca].disCont; i++)  {
			printf(" Disciplina Nº%d : %s\n  Nota Final : %d\n\n", i+1, e[busca].disciplinas[i].nome, e[busca].disciplinas[i].notaFinal);
		}
		printf("\n - Aperte Enter para prosseguir");
		while(getchar()!='\n');
		getchar();
		continue;
		
		
	
		//3. definir um limite alto (100) e fazer o usuario finalizar com exit OU fazer o usuario predefinir a quantidade de disciplinas
	
	}
	
	
	
    return 0;
}
