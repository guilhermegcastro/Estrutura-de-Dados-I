
/**
 * @file string12.c
 * @author @guilhermegcastro
 * @date 2025-11-03
 * @brief Enunciado: 32. Semelhante ao problema anterior, implemente o algoritmo para checar a validade de um número de CPF (pergunte ao professor o melhor método de cálculo).
 **/

/**
 * @file    dojocoding06.c
 * @author  @guilhermegcastro
 * @date    2025-10-23
 * @brief   Dígitos verificadores
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

	srand(time(NULL));
	
	char cpf[13];
	int opcao = 0;
	
	do {
	
		while(!opcao) { // Tela inical. Só executa no inicio do programa.
			 do {
				system("clear");
				printf("Insira o número correspondente a opção desejada: \n 1 - Gerar um CPF. \n 2 - Validar um CPF. \n 3 - Encerrar o programa.\n > ");
				scanf(" %d", &opcao);
				while(getchar()!='\n');
			} while (opcao < 1 || opcao > 3);
		}
		
		
		
		while (opcao==1){ // Gerador de CPF, pode ser executado quantas vezes o usuario quiser.
			for (int i = 0; i < 9; i++) cpf[i] = '0' + rand()%10;
			cpf[11] = 0;
			
			
			int somadv1=0;
			for (int i = 0; i < 9; i++)  somadv1+= (cpf[i] - '0') * (i+1);
			
			int dv1 = somadv1%11;
			cpf[9]=(dv1 > 9)? '0' : dv1 + '0';
			
			int somadv2=0;
			for (int i = 0; i < 10; i++)  somadv2+= (cpf[i] - '0') * i;
			
			int dv2 = somadv2%11;
			cpf[10]=(dv2 > 9)? '0' : dv2 + '0';
	
			printf("\n CPF GERADO: %s", cpf);
				
				do {
					printf("\n\nInsira a opção desejada para prosseguir: \n 1 - Gerar um CPF.\n 2 - Validar um CPF. \n 3 - Finalizar o programa.\n > ");
					scanf(" %d", &opcao);
					while(getchar()!='\n');
				} while (opcao < 1 || opcao > 3);
		}
		
			while (opcao==2) { // Validação de CPF, pode ser executado quantas vezes o usuario quiser.
			int flag;
			do{
				printf("Insira o número de 11 dígitos do CPF, sem espaços:\n >  ");
				scanf(" %[^\n]s", cpf);
					for (int i = 0; i < 11; i++) {
						flag = 1;
						if (cpf[i]==0) {
							flag = 0;
							break; 
						}
					}
					
					for (int i = 0; i < 11; i++) {
						if (cpf[i] < '0' || cpf[i] > '9' || cpf[i]==0) {
							printf("Erro: Insira um CPF utilizando um número de 11 digitos. \n\n");
							flag = 0;
							break; 
						}
					}
			} while (!flag);
			
	
			int somadv1=0;
			for (int i = 0; i < 9; i++) somadv1+= (cpf[i] - '0') * (i+1);
		    char dv1 = somadv1%11 + '0';
		    dv1 = ((dv1 - '0') > 9)?  '0' : dv1;
		   
			
			if (dv1!=cpf[9]) printf("\nCPF Inválido! Verificador dv1 não bate.");
				
			if (dv1==cpf[9]) {
				int somadv2=0;
				for (int i = 0; i < 10; i++) somadv2+= (cpf[i] - '0') * i;
				char dv2 = somadv2%11 + '0';
				dv2 = ((dv2 - '0') > 9)?  '0' : dv2;
			
				if (dv2!=cpf[10]) printf("\nCPF Inválido! Verificador dv2 não bate.");
				if (dv2==cpf[10]) printf("\nCPF Válido! Os verificadores dv1 e dv2 batem!");
			}
			
			do {
					printf("\n\nInsira a opção desejada para prosseguir: \n 1 - Gerar um CPF.\n 2 - Validar um CPF. \n 3 - Finalizar o programa.\n > ");
					scanf(" %d", &opcao);
					while(getchar()!='\n');
				} while (opcao < 1 || opcao > 3);
		}
	
		if (opcao==3) {
			printf("\n Programa Finalizado...");
			return 0;
		}
		
	} while (1);
}
