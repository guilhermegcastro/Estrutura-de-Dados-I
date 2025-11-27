
/**
 * @file função01.c
 * @author @guilhermegcastro
 * @date 2025-11-24
 * @brief Faça uma função interface() que imprime um menu de operações matemáticas na tela (1-soma, 2-subtração, 3-multiplicação, 4-divisão e 5-potência).
 * Obtenha a opção escolhida pelo usuário e retorne-a como resultado da interface.
 * Este valor deverá ser tratado pela função main(), que irá processar a escolha, encaminhando o usuário para função específica.
 **/

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>

	int interface();
	int soma(int A, int B);
	int subtracao(int A, int B);
	int multiplicacao(int A, int B);
	int divisao(int A, int B);
	int potencia(int A, int B);
	
	int main() {
	  
		int A, B;
		int resposta = interface();
		if (resposta > 5 || resposta < 1) {
			printf("Opção inválida.");
			return 0;
		}
		printf("Informe os dois valores da operação: ");
		scanf(" %d %d", &A, &B);
		switch (resposta) {
			case 1: printf("%d + %d = %d", A, B, soma(A, B)); break;
			case 2: printf("%d - %d = %d", A, B, subtracao(A, B)); break;
			case 3: printf("%d * %d = %d", A, B, multiplicacao(A, B)); break;
			case 4: printf("%d / %d = %d", A, B, divisao(A, B)); break;
			case 5: printf("%d ^ %d = %d", A, B, potencia(A, B)); break;
		}
		
	  
        return 0;
 	}

	int interface() {
		int opcao;
		printf("SISTEMA DE OPERAÇÕES:\n"
				" 1 - Adição\n "
				"2 - Subtração\n"
				" 3 - Multiplicação\n"
				" 4 - Divisão\n"
				" 5 - Potência\n"
				" * Insira a operação desejada\n - > ");
	    scanf(" %d", &opcao);
	    return opcao;
	}
	
	
	int soma(int A, int B){
		return A+B;
	}
	int subtracao(int A, int B) {
		return A-B;
	}
	int multiplicacao(int A, int B){
		return A*B;
	}
	int divisao(int A, int B) {
		return A/B;
	}
	int potencia(int A, int B) {
		if(!B)
			return 1;
		int resposta = A;
		for (int i = 0; i < B-1; i++)
			resposta*=A;
		return resposta;
	}
