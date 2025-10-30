/**
 * @file    stringfunction01.c
 * @author  @guilhermegcastro
 * @date    2025-10-29
 * @brief   Programa verificador de email válido.
 */

#include <stdio.h>
#include <string.h>

int main() {
	
	char email[100], fim[] = {"FIM"};

	do {
		printf(" \n\nInsira um email para verificar se ele é válido. \n Digite FIM para finalizar o programa:\n > ");
		scanf(" %[^'\n']s", email);
		
		size_t tamanho = strlen(email);
		if (strcmp(email, fim)==0)
			return 0;
		
		int emailValido=1;
		if(email[0]=='@') { //Teste direto se o email começar com @
				printf("\n - Falta a parte local antes do '@'!");
				emailValido=0;
			}
			if(email[0]=='.' || email[0]=='-' || email[tamanho-1]=='.' || email[tamanho-1]=='-') { //Teste direto para se o email começa ou termina com '.' ou '-'.
				printf("\n - Não pode iniciar ou finalizar com '.' ou '-'!");
				emailValido=0;
			}
		
		int arroba = 0, dominio=0;
		for (int i = 0; i < tamanho; i++){ // for para verificar toda a string do email.
	
			if(email[i]=='.' && email[1+i]=='.') { //Teste para '.' consecutivos.
				printf("\n - Não pode conter '.' consecutivos!");
				emailValido=0;
			}
			if (email[i]<45 || email[i]==47 || (email[i] > 57 && email[i] < 64) || (email[i]>90 && email[i] < 97) || email[i]> 122) { //Filtro de caracteres inválidos.
				printf("\n - O email possui caractere(s) inválido(s)!");
				emailValido=0;
			}
			if(!dominio && email[i] == '@') { // Se encontrou um @, o domínio é definido.
				arroba  = 1;
				dominio = i+1;
			}
		}
		if(!arroba) { // Se o email inserido não passou no primeiro teste, volta o código para inserir um novo email.
			printf("\n - Precisa conter o '@'!");
			emailValido=0;
		}
		if(email[dominio-2]=='.' || email[dominio-2]=='-') { //Verifica se a parte local termina com '.'
				printf("\n - Não pode terminar a parte local com '.' ou '-'!");
				emailValido=0;
			}
		int ponto = 0;	
		
		if (email[dominio]=='.')
		{
			printf("\n - Não pode haver um '.' seguido de um '@'!");
			emailValido=0;
		}
		for (int i = dominio; i < tamanho; i++) { //Teste relacionado ao domínio.
	
			if(email[i]=='@') {
				printf("\n - Não pode conter mais de um '@'!");
				emailValido=0;
			}
			if(email[i]=='.')
				ponto = 1;	
				
		}
		
		if(!ponto) {
			printf("\n - Precisar ter no mínimo um '.' após o '@'!");
			emailValido=0;
		}
		
		if (!emailValido) {
			printf("\n * O email inserido é inválido!");
			continue;
		}
		
			printf("\n - O email atende todos os critérios.\n * O email inserido é válido!");
			
	} while (1);
}
