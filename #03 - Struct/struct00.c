
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
	int cd = 0;
	
	while(cd<10) {
		printf(" : CADASTRO DA %dª PESSOA (digite 'EXIT' no nome para finalizar) : \n", cd+1);
		printf("Insira o nome\n > ");
		scanf(" %[^\n]s", cadastro[cd].nome);
		if(strcmp(cadastro[cd].nome, "EXIT") == 0)
			break;
		printf("Insira o CPF\n > ");
		scanf(" %s", cadastro[cd].cpf);
		printf("Insira a idade\n > ");
		scanf(" %d", &cadastro[cd].idade);
		printf("Insira a altura\n > ");
		scanf(" %f", &cadastro[cd].altura);
		printf("Insira o peso \n > ");
		scanf(" %f", &cadastro[cd].peso);
		printf("Insira o nome da rua\n > ");
		scanf(" %[^\n]s", cadastro[cd].residencia.rua);
		printf("Insira o número de residência \n > ");
		scanf(" %d", &cadastro[cd].residencia.numero);
		printf("Insira o nome do bairro \n > ");
		scanf(" %[^\n]s", cadastro[cd].residencia.bairro);
		printf("Insira o nome da cidade\n > ");
		scanf(" %[^\n]s", cadastro[cd].residencia.cidade);
		system("clear");
		cd++;
	}
	

	for (int i = 0; i < cd-1; i++) {
		for (int j = 0; j < cd-i-1; j++) {
			if (strcmp(cadastro[j].nome, cadastro[j+1].nome) > 0 ) {
				Pessoa troca;
				troca = cadastro[j];
				cadastro[j] = cadastro[j+1];
				cadastro[j+1] = troca;
			}
		}
	}
		


	system("clear");
	for (int i = 0; i < cd; i++) {
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

