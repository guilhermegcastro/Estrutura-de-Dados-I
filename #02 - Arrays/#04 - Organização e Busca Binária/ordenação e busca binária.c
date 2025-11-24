
/**
 * @file ordenação e busca binária.c
 * @author @guilhermegcastro
 * @date 2025-11-12
 * @brief
 **/

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #define COLUNA 2


	void enter();
	void sorteio(int vet[][COLUNA], int linhas);
	void bubble(int vet[][COLUNA], int linhas);
	void selection(int vet[][COLUNA], int linhas);
	void insertion(int vet[][COLUNA], int linhas);
	void printa(int vet[][COLUNA], int linhas);
	void desorganiza(int vet[][COLUNA], int linhas);
	void buscabinaria(int vet[][COLUNA], int linhas, int coluna, int numero);
	
	
	int main() {
	    
	    srand(time(NULL));
	    int t;
	    printf("Insira o tamanho do array: ");
	    scanf(" %d", &t);
	    int sort[t][COLUNA]; // Na matriz,  0  é organizado, 1 é desorganizado;
	    
	    sorteio(sort, t);
	    printf("Vetor original:\n ");
		printa(sort, t);
		
		bubble(sort, t); //bubble shot
		printf("Vetor organizado pelo bubble shot :\n ");
		printa(sort, t);
		desorganiza(sort, t);
		enter();
		
		selection(sort, t);
		printf("Vetor organizado pelo selection shot :\n ");
		printa(sort, t);
		desorganiza(sort, t);
		enter();
		
		insertion(sort, t);
		printf("Vetor organizado pelo insertion shot :\n ");
		printa(sort, t);
		enter();
		
		system("clear");
		
		printf(" Busca binária sequêncial. Insira um número negativo para finalizar o programa.\n\n");
		int numero=0;
		while(1) {
			printf("Insira o número que você deseja buscar: ");
			scanf(" %d", &numero);
			if(numero<0) break;
			putchar('\n');
			
			printf("Busca binária sem ordenação: ");
			buscabinaria(sort, t, 1, numero);
			printf("Busca binária com ordenação: ");
			buscabinaria(sort, t, 0, numero);
			enter();
		}
		
        return 0;
 	}
 	
 
	void enter() {
		printf("Aperte ENTER para prosseguir...");
		while(getchar()!='\n');
		getchar();
	}
 	void sorteio(int vet[][COLUNA], int linhas) {
 	
		for (int i = 0; i < linhas; i++) {
			int num = rand()%100;
			for (int j = 0; j < COLUNA; j++)
				vet[i][j] = num;
		}
 	}
 	
 	void bubble(int vet[][COLUNA], int linhas) {
		int perm=0, comp=0;
		for (int i = 0; i < linhas; i++) {
			for (int j = 0; j < linhas-i-1; j++) {
				comp++;
				if(vet[j][0] > vet[j+1][0]) {
					int trade = vet[j][0];
					vet[j][0] = vet[j+1][0];
					vet[j+1][0] = trade; 
					perm++;
				}
			}
		}
	    printf("\nCom o método bubble shot, foi realizado %d comparações e %d permutações.\n ", comp, perm);
 	}
 	
 	void selection(int vet[][COLUNA], int linhas) {
		int perm = 0, comp = 0;
		for (int i = 0; i < linhas; i++) {
			int menor = i;
			for (int j = i+1; j < linhas; j++) {
				comp++;
				menor = (vet[j][0] < vet[menor][0]) ? j : menor;
			}
			
			if(menor!=i) {
				int trade = vet[menor][0];
				vet[menor][0] = vet[i][0];
				vet[i][0] = trade;
				perm++;
			}
			
		}
		printf("\nCom o método selection shot, foi realizado %d comparações e %d permutações.\n ", comp, perm);
 	}
 	
 	void insertion(int vet[][COLUNA], int linhas) {
		int perm = 0, comp = 0;
		for (int i = 1; i < linhas; i++) {
			int key = vet[i][0];
			int j = i-1;
			
			while (j>= 0) {
				comp++;
				if(vet[j][0] > key) {
					vet[j+1][0] = vet[j][0];
					j--;
					perm++;
				} else break;
				
			}
			vet[j+1][0] = key;
			
		}
		printf("\nCom o método insertion shot, foi realizado %d comparações e %d permutações.\n ", comp, perm);
 	}
 	
 	void printa(int vet[][COLUNA], int linhas) {
		
		for (int i = 0; i < linhas; i++) {
			printf("%d ", vet[i][0]);
		}
		putchar('\n');
 	}
 	
 	void desorganiza(int vet[][COLUNA], int linhas) {
 	
		for (int i  = 0; i < linhas; i++) 
			vet[i][0] = vet[i][1];
		
 	}
 	
 	void buscabinaria(int vet[][COLUNA], int linhas, int coluna, int numero) {
		
		int inic = 0, fim = linhas-1, encontrado=0;
		
		while (inic <= fim){
			int meio = (inic+fim)/2;
			if (vet[meio][coluna]==numero) {
				printf("O número %d foi encontrado no índice %d\n\n", numero, meio);
				encontrado=1;
				break;
			}
			
			if(vet[meio][coluna] > numero) {
				fim = meio - 1;
			} else {
				inic = meio + 1;
			}
			
		} 
		
		if(!encontrado)  
				printf("O número %d não foi encontrado no vetor\n\n", numero);
		
 	}
