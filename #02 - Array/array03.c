/**
 * @file array03.c
 * @author Guilherme Castro
 * @date 2025-10-13
 * @brief 
 * Enunciado: Crie um vetor contendo N números aleatórios (sendo N múltiplo de 4). Imprima-o.
 *  Após isso, troque a metade inicial pela metade final. Imprima-o.
 *  Por fim, para cada metade inicial, troque também as sub-metades. Imprima-o.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( ) {
	
	srand(time(NULL));
	int numero; 
	
	do {
		system("clear");
		printf("Informe o tamanho do vetor (Precisa ser múltiplo de 4!)\n  > ");
		scanf(" %d", &numero);
	} while (numero%4!=0);
	
	int vetor[numero];
	
	printf(" 1º Lista:\n  |");
	
	for (int i = 0; i < numero; i++) { // IMPRESSÃO DA PRIMEIRA LISTA
		vetor[i] = rand()%(numero+1); 
		printf(" %d ", vetor[i]);
		if(i+1 == numero/2) {
			printf("| <- -> |"); //Faz a divisão da metade inicial e da metade final da primera lista, para melhor visualização.
			continue;
		}
		if(i == numero-1) //Se i for o último do loop, não imprime o separador '-'
			break;
		putchar('-');
	}
	
	printf("|\n 2º Lista:\n  |");
	
	for (int i = 0, j; i < numero; i++) { // IMPRESSÃO DA SEGUNDA LISTA
	
		if (i < numero/2) { // Se o contador for menor que a metade do número inserido pelo usuário, ele fára a troca de lugar dos vetores da primeira metade pela segunda metade.
			j = vetor[i]; 
			vetor[i] = vetor[(numero/2)+i]; 
			vetor[(numero/2)+i] = j;
		}
		
		printf(" %d ", vetor[i]);
		if(i+1 == numero/2) {
			printf("| |"); //Faz a divisão central da segunda lista, para melhor visualização.
			continue;
		}
		if((i+1 == numero/4) || (i+1 == numero/2 + numero/4)){
			printf("| <- -> |"); //Faz a divisão entre sub-metades da segunda lista, para melhor visualização.
			continue;
		}
		if(i == numero-1)
			break;
		putchar('-');
	}
	
	printf("|\n 3º Lista:\n ");
	
	for (int i = 0, j; i < numero/2; i++) {
		if(i < numero/4) {
			j = vetor[i];
			vetor[i] = vetor[numero/4+i];
			vetor[numero/4+i] = j; 
		}
		printf(" %d ", vetor[i]);
		if(i == numero-1)
			break;
		putchar('-');
		
	}
	
	for (int i = 0, j; i < numero/2; i++) {
		
		if((i+numero/2)< numero/4 + numero/2) {
			
			j = vetor[i+numero/2];
			vetor[i+numero/2] = vetor[numero/4+numero/2+i];
			vetor[numero/4+numero/2+i] = j; 
		}
		printf(" %d ", vetor[i+numero/2]);
		if(i + numero/2 == numero-1)
			break;
		putchar('-');
	}
	
		
		        return 0;
	}
	
	
