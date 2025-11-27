
/**
 * @file struct01.c
 * @author @guilhermegcastro
 * @date 2025-11-23
 * @brief ENUNCIADO: 1. Faça um programa que define o tipo de dados Pessoa, contendo: 
 * nome, cpf, altura, peso e idade.
 * 
 * Leia do usuário os dados de uma Pessoa, e após isso:
 * a) Imprima todas as informações lidas.
 * b) Calcule o IMC (Índice de Massa Corpórea) dessa pessoa: 
 * IMC = Peso / Altura^2
 * c) Informe o resultado do IMC, conforme tabela abaixo:
 * < 18.5 Abaixo do Peso
 * 18.5 – 24.9 Saudável
 * 25.0 – 29.9 Acima do Peso
 * > 30 Obesidade
 **/

 #include <stdio.h>


 typedef struct {
	char nome[100], cpf[12];
	float altura, peso;
	int idade;
 } Pessoa;
int main() {
	Pessoa p;
	printf("Insira o nome da pessoa:\n  - > ");
	scanf(" %[^\n]s", p.nome);
	printf("Insira o CPF:\n  - > ");
	scanf(" %s", p.cpf);
	printf("Insira a altura:\n  - > ");
	scanf(" %f", &p.altura);
	printf("Insira o peso:\n  - > ");
	scanf(" %f", &p.peso);
	printf("Insira a idade:\n  - > ");
	scanf(" %d", &p.idade);
	
	printf(" - Nome: %s \n - CPF: %s \n"
		" - Altura: %2.f \n - Peso: %2.f \n"
		" - Idade: %d \n",
		p.nome, p.cpf,
		p.altura, p.peso,
		p.idade);
		float imc = p.peso/(p.altura*p.altura);
	printf("IMC = %.2f \n ", imc);
	
	 (imc < 18.5) ? printf("Abaixo do Peso.") : (imc < 25) ? printf(" Saudável.") : (imc < 30) ? printf(" Acima do peso.") : printf(" Obeso.");
	
	
	return 0;
}
