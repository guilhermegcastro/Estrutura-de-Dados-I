
/**
 * @file string07.c
 * @author @guilhermegcastro
 * @date 2025-11-01
 * @brief Enunciado: 27. Desenvolva um programa em C que faça a geração de senhas fortes. 
 * Uma senha forte é uma string contendo entre 8 e 16 caracteres, com obrigatoriamente: 1 caractere numérico, 1 caractere maiusculo, 1 minúsculo e 1 caractere especial. 
 * Imprima 10 senhas fortes geradas aleatoriamente.
 **/

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
	int main() {
	    
	    srand(time(NULL));
	    char senhaForte[10][17];
	    char especial[]="!\"#$%\'()*+,-./:;<=>?@[\\]^_{|}~";
	    size_t E = strlen(especial);
	    for (int i = 0; i < 10; i++) senhaForte[i][0] = (char)(48 + rand()%10); //garante 1 caractere numérico em todas as senhas.
		for (int i = 0; i < 10; i++) senhaForte[i][1] = (char)(65 + rand()%26); //garante 1 caractere maiúsculo em todas as senhas.
		for (int i = 0; i < 10; i++) senhaForte[i][2] = (char)(97 + rand()%26); //garante 1 caractere minúsculo em todas as senhas.
		for (int i = 0; i < 10; i++) senhaForte[i][3] = especial[1+rand()%E]; //garante 1 caractere especial em todas as senhas.
		
		for (int i = 0; i < 10; i++) {
			for (int j = 4; j < (8+rand()%9); j++) {
				senhaForte[i][j] = (char)(33 + rand()%94); //Adiciona os outros caracteres aleatórios.
			}
		}
		
		printf(" GERADOR DE SENHAS FORTES:\n Cada senha possuí de 8 a 16 caracteres. Dentre estes, há no mínimo...\n - Um número \n - Uma letra maiúscula\n - Uma letra minúscula\n - Um caractere especial\n\n");
		for (int i = 0; i < 10; i++) {
			size_t T = strlen(senhaForte[i]);
			for (int j = T-1; j > 0; j--) { //Método "Fisher-Yates" para embaralhar os char e quebrar o "padrão" inicial.
				int k = (rand()%j+1);
				int troca = senhaForte[i][j];
				senhaForte[i][j] = senhaForte[i][k];
				senhaForte[i][k] = troca;
			}
			printf(" Senha %02d (%02zu caracteres) : %s \n",i+1, T, senhaForte[i]);
		} 

	
        return 0;
 	}
