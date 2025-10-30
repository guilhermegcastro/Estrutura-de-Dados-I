/**
 * @file    stringfunction02.c
 * @author  @guilhermegcastro
 * @date    2025-10-30
 * @brief   Programa parar ler sempre em ordem alfabética. Descarta o nome caso ele vier antes do ultimo nome registrado. Digitar EXIT encerra a coleta de nomes e imprime todos os nomes aprovados.
 */

#include <stdio.h>
#include <string.h>

int main() {
	
	char nome[100][100], clone[100], exit[]={"EXIT"};
	int cont=0;
	printf("\n Insira a lista de nomes sempre em ordem alfabética.\n Nomes inseridos fora da ordem serão descartados. \n Digite EXIT para encerrar a leitura de nomes:\n");
	do {
		printf(" > ");
		scanf(" %[^'\n']s", nome[cont]);
		
		
		if (strcmp(nome[cont], exit)==0) //Se o usuário inserir "EXIT" o programa encerra a leitura. 
			break;
			
		if(!cont) { //Exuta na primeira vez, para que o primeiro nome não compare com a string vazia do clone e seja clonado para a próxima verificação.
			strcpy(clone, nome[cont]);
			cont++;
			continue;
		}
		
		if(strcmp(nome[cont], clone) <= 0)  // Se o nome inserido for igual ao anterior ou vier antes na ordem alfabética, ele é descartado e inicia novamente uma leitura.
			continue;
			
		strcpy(clone, nome[cont]); // Se o nome vier depois na ordem alfabética, ele é clonado e o cont aumenta mais um para manter-lo guardado na lista.
		cont++;
		
	} while (cont<100);
	
	for (int i = 0; i < cont; i++) { //printa todos os nomes que seguiram a regra da ordem alfabética.
		printf(" %s\n", nome[i]);
	}
    return 0;
}
