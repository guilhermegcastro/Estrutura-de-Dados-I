
/**
 * @file struct00.c
 * @author @guilhermegcastro
 * @date 2025-11-17
 * @brief ENUNCIADO: FAÇA UM PROGRAMA QUE LEIA OS DADOS DE ATÉ 10 PESSOAS.
 * FINALIZE COM O NOME "EXIT".
 * APÓS A FASE DE CADASTRO, REALIZE A IMPRESSAO DE TODAS AS PESSOAS CADASTRADAS ORDENADAS PELO NOME.
 **/
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef	struct{
	char rua[100];
	int numero;
	char bairro[100];
	char cidade[100];
}Endereco;

typedef	struct{
	char nome[100];
	char cpf[12];
	int idade;
	float altura,peso;
	Endereco residencia;
}Pessoa;

int main(){
	Pessoa cadastro[10];
	int cadastrados = 0;
	
	for (int i = 0; i < 10; i++) {
		printf(" : CADASTRO DA %dª PESSOA (digite 'EXIT' no nome para finalizar) : \n", i+1);
		printf("Insira o nome\n > ");
		scanf(" %[^\n]s", cadastro[i].nome);
		if(strcmp(cadastro[i].nome, "EXIT") == 0)
			break;
		printf("Insira o CPF\n > ");
		scanf(" %s", cadastro[i].cpf);
		printf("Insira a idade\n > ");
		scanf(" %d", &cadastro[i].idade);
		printf("Insira a altura\n > ");
		scanf(" %f", &cadastro[i].altura);
		printf("Insira o peso \n > ");
		scanf(" %f", &cadastro[i].peso);
		printf("Insira o nome da rua\n > ");
		scanf(" %[^\n]s", cadastro[i].residencia.rua);
		printf("Insira o número de residência \n > ");
		scanf(" %d", &cadastro[i].residencia.numero);
		printf("Insira o nome do bairro \n > ");
		scanf(" %[^\n]s", cadastro[i].residencia.bairro);
		printf("Insira o nome da cidade\n > ");
		scanf(" %[^\n]s", cadastro[i].residencia.cidade);
		system("clear");
		cadastrados++;
	}
	
	int ordenado;
	do {
		ordenado=1;
		for (int i = 1; i < cadastrados; i++) {
			if (strcmp(cadastro[i].nome, cadastro[i-1].nome) < 0 ) {
				Pessoa troca;
				troca = cadastro[i];
				cadastro[i] = cadastro[i-1];
				cadastro[i-1] = troca;
				ordenado = 0;
			}
		}
	} while (!ordenado);
	system("clear");
	for (int i = 0; i < cadastrados; i++) {
		printf(" - DADOS - \n Nome: %s\n CPF: %s\n"
			   " Idade: %d\n Altura: %.2f\n Peso:%.2f\n"
			   " - ENDEREÇO - :\n Rua: %s\n Número: %d\n Bairro: %s\n Cidade: %s\n\n",
				cadastro[i].nome,
				cadastro[i].cpf,
				cadastro[i].idade,
				cadastro[i].altura,
				cadastro[i].peso,
				cadastro[i].residencia.rua,
				cadastro[i].residencia.numero,
				cadastro[i].residencia.bairro,
				cadastro[i].residencia.cidade);
	}
	
	
}

