#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

typedef struct{
	char nome[100];
	int idade;
	float altura;
}Pessoa;

#define MAX 100

void printPessoa(Pessoa p){
	printf("Nome: %s\n", p.nome);
	printf("Idade: %d\n", p.idade);
	printf("Altura: %.2f\n", p.altura);
}

//versao procedural para cadastro de struct
/*
void cadastrarPessoa(Pessoa* p){
	input(STR, "Nome: ",p->nome);
	input(INT, "Idade: ",&p->idade);
	input(FLOAT, "Altura: ",&p->altura);	
}*/

//versao com retorno de funcao
Pessoa cadastrarPessoa(){
	Pessoa nova;
	printf("== CADASTRO ==\n");
	input(STR, "Nome: ",nova.nome);
	input(INT, "Idade: ",&nova.idade);
	input(FLOAT, "Altura: ",&nova.altura);
	system("clear");
	return nova;		
}

void ordenarPessoas(int cont, Pessoa* p) {
	int opcao, erro=0;
	do {
		system("clear");
		printf("== MENU DE ORDENAÇÃO ==\n");
		printf("1 - Nome\n2 - Idade\n3 - Altura\n");
		if(erro) 
			printf("- Opção \"%d\" inexistente! Tente Novamente.\n",opcao);
		printf("- Escolha como deseja ordenar: ");
		int charErro = scanf(" %d", &opcao);
		if (!charErro) {
			while(getchar()!='\n'); 
			continue;
		}
		if(opcao>3 || opcao < 1) {
			erro=1;
			continue;
		}
		
		break;
	} while(1);
	while (opcao==1){ //Ordena pelo nome.
		for (int i = 1; i < cont; i++) {
			char key[100];
			strcpy(key, p[i].nome);
			Pessoa posicao = p[i];
			int j = i - 1;
			while (j >= 0 && strcmp(p[j].nome, key) > 0 ) {
				p[j+1] = p[j];
				j--;
			}
			p[j+1] = posicao;
		}
		break;
	}
	
	while (opcao==2){ //Ordena pela idade.
		for (int i = 1; i < cont; i++) {
			int key = p[i].idade;
			Pessoa posicao = p[i];
			int j = i - 1;
			while (j >= 0 && p[j].idade > key) {
				p[j+1] = p[j];
				j--;
			}
			p[j+1] = posicao;
		}
		break;
	}
	
	while (opcao==3){ //Ordena pela altura.
		for (int i = 1; i < cont; i++) {
			float key = p[i].altura;
			Pessoa posicao = p[i];
			int j = i - 1;
			while (j >= 0 && p[j].altura > key) {
				p[j+1] = p[j];
				j--;
			}
			p[j+1] = posicao;
		}
		break;
	}
	system("clear");
	
}


void divisoria(char simb, int tam) {
	putchar('\n');
	for (int i = 0; i < tam; i++)
		printf("%c", simb);
	putchar('\n');
	}
void listarPessoas(int cont, Pessoa* p){
	divisoria('-', 70);
	for (int i = 0; i < cont; i++) {
		printf("%-29s CADASTRO Nº%d\n", " ", i+1);
		printPessoa(p[i]);
		divisoria('-', 70);
	}
	if(!cont) 
		printf("Não há pessoas cadastradas para listar.\n\n");
	printf("Aperte ENTER para prosseguir. ");
	while(getchar()!='\n');
	getchar();
	system("clear");
}
int interface(){
		int opt, erro=0;
	do {
		system("clear");
		printf("== MENU PRINCIPAL ==\n");
		printf("1 - Cadastrar Pessoa\n");
		printf("2 - Ordenar Pessoas\n");
		printf("3 - Listar Pessoas\n");
		printf("0 - Encerrar Programa\n");
		if(erro) 
			printf("Opção \"%d\" inexistente! Tente Novamente.\n", opt);
		printf("Digite o número da ação desejada: ");
		int charErro = scanf(" %d", &opt);
		if (!charErro) {
			while(getchar()!='\n'); 
			continue;
		}
		if(opt>3 || opt < 0) {
			erro=1;
			continue;
		}
		break;

	} while (1);
	
	
	
	//tratar a opcao escolhida
	return opt;
}

//FAÇA  UM PROGRAMA UTILIZANDO ESTE CODIGO
//PARA PERMITIR O CADASTRO DE ATÉ 100 PESSOAS
//A FUNCAO DE CADASTRO REALIZA 1 CADASTRO POR VEZ  

int main(){
	Pessoa p[MAX];
	int cont = 0;
	do{
		switch(interface()){
			case 1: p[cont++] = cadastrarPessoa();
					break;
			case 2: ordenarPessoas(cont, p);
					break;
			case 3: listarPessoas(cont, p);
					break;
			case 0: printf("FIM DO PROGRAMA.");	
					return 0;
		}
	}while(1);
	
}
