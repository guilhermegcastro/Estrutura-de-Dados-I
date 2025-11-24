
/**
 * @file insertionshot.c
 * @author @guilhermegcastro
 * @date 2025-11-11
 * @brief
 **/

 #include <stdio.h>
 #include <stdlib.h>
 

	int main() {
		// 1. Definição dos dados
		int arr[] = {12, 11, 13, 5, 6};
		int n = sizeof(arr) / sizeof(arr[0]);
		
		// Variáveis que o algoritmo de ordenação usará
		int i, j, key;

		// 2. Imprimir o array original (lógica do printArray)
		printf("Array original: \n");
		for (i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");

		// 3. O ALGORITMO INSERTION SORT (lógica do insertionSort)
		// --------------------------------------------------------
		// Loop principal: começa do SEGUNDO elemento (índice 1)
		for (i = 1; i < n; i++) {
			
			// 'Pega' o elemento atual para ser inserido
			key = arr[i];
			
			// 'j' aponta para o elemento ANTERIOR
			j = i - 1;

			// Loop secundário: move os elementos maiores que a 'key'
			// uma posição para a direita para "abrir espaço"
			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j]; // Desloca para a direita
				j = j - 1;           // Move para a esquerda
			}
			
			// Insere a 'key' no espaço correto
			arr[j + 1] = key;
		}
		// --------------------------------------------------------
		// Fim do algoritmo

		// 4. Imprimir o array ordenado (lógica do printArray novamente)
		printf("Array ordenado: \n");
		for (i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");

		return 0;
	}
