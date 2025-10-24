/**
 * @file    dojocoding05.c
 * @author  @guilhermegcastro, 
 * @date    2025-10-23
 * @brief   Soma de Verificação (Checksun)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

	srand(time(NULL));
	
	char cartao[17];
	int opcao = 0;
	
	do {
	
		while(!opcao) { // Tela inical. Só executa no inicio do programa.
			 do {
				system("clear");
				printf("Insira o número correspondente a opção desejada: \n 1 - Gerar um Cartão de Crédito. \n 2 - Validar um Cartão de Crédito. \n 3 - Encerrar o programa.\n > ");
				scanf(" %d", &opcao);
				while(getchar()!='\n');
			} while (opcao < 1 || opcao > 3);
		}
		
		
		
		while (opcao==1){ // Gerador de Cartoes, pode ser executado quantas vezes o usuario quiser.
			for (int i = 0; i < 15; i++) cartao[i] = '0' + rand()%10;
			cartao[16] = 0;
			
			int somatorio=0;
			for (int i = 0; i < 15; i++) {
				int n = cartao[i] - '0';
				
				if(i%2==0) {
					n*=2;
					
					if (n>9) {
						int unidade = n%10, dezena = n/10;
						somatorio+= unidade + dezena; 
						continue;
					}
				}
				
				somatorio+= n;
			}
				do {
					cartao[15] = '0' + rand()%10;  //Adiciona o ultimo digito do cartão, e o sorteia novamente, caso o somatorio não seja divisível por 10.
					int n = cartao[15] - '0';
					if ((somatorio+n)%10==0)  break;
				} while (1);
			
				printf("\n CARTÃO DE CRÉDITO GERADO: %s\n BOAS COMPRAS! ;)", cartao);
				
				do {
					printf("\n\nInsira a opção desejada para prosseguir: \n 1 - Gerar Cartão de crédito.\n 2 - Validar um Cartão de crédito. \n 3 - Finalizar o programa.\n > ");
					scanf(" %d", &opcao);
					while(getchar()!='\n');
				} while (opcao < 1 || opcao > 3);
		}
	
		while (opcao==2) { // Validação de Cartao, pode ser executado quantas vezes o usuario quiser.
			int flag;
			do{
				printf("Insira o número de 16 dígitos do cartão de crédito, sem espaços:\n >  ");
				scanf(" %[^\n]s", cartao);
					for (int i = 0; i < 16; i++) {
						flag = 1;
						if (cartao[i]==0) {
							flag = 0;
							break; 
						}
					}
					
					for (int i = 0; i < 16; i++) {
						if (cartao[i] < '0' || cartao[i] > '9' || cartao[i]==0) {
							printf("Erro: Insira um número de 16 digitos. \n\n");
							flag = 0;
							break; 
						}
					}
			} while (!flag);
			
	
			int somatorio;
			
			for (int i = 0; i < 16; i++) {
				int n = cartao[i] - '0';
				
				if(i%2==0) {
					n*=2;
					
					if (n>9) {
						int unidade = n%10, dezena = n/10;
						somatorio+= unidade + dezena; 
						continue;
					}
				}
				somatorio+= n;
			}
			
			(somatorio%10==0) ? printf("Cartão Válido!") : printf("Cartão Inválido!");
			do {
					printf("\n\nInsira a opção desejada para prosseguir: \n 1 - Gerar Cartão de crédito.\n 2 - Validar um Cartão de crédito. \n 3 - Finalizar o programa.\n > ");
					scanf(" %d", &opcao);
					while(getchar()!='\n');
				} while (opcao < 1 || opcao > 3);
		}
	
		if (opcao==3) {
			printf("\n Programa Finalizado...");
			return 0;
		} // Finaliza o programa.
		
	} while (1);
}
