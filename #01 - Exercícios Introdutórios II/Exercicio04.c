/**
 * @file Exercicio04.c
 * @author Guilherme Castro
 * @date 2025-09-16
 * @brief
 * coding-exercise: 4. Em relação ao problema anterior, o que aconteceria se o usuário solicitasse uma operação como: “A * 9”, ou “7 ** 8”? R: A calculadora dá erro. O scanf espera um valor inteiro, um char e mais um valor inteiro, nesta ordem. Qualquer coisa que foge disso faz o scanf não conseguir efetuar a leitura correta do texto inserido, "quebrando" o código da calculadora.
 * Como seria possível tratar esse problema de forma satisfatória ao usuário? Implemente uma versão da mesma calculadora que previne e trata qualquer tipo de erro de entrada de dados.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	
	int A, B, acumulador;
	char operacao, SorN='S';
	
	while((SorN=='S') || (SorN=='s'))
	{
		acumulador=1;
	printf("\n\tCalculadora\n   Sinais permitidos:\n + Adição \n / Divisão \n %% Percentual \n - Subtração \n * Multiplicação \n ^ Exponenciação\n Insira uma operação matemática: (Exemplo: 2 + 3): ");
	if (scanf("%d %c %d", &A, &operacao, &B)== 3)
	{
	putchar('\n');
	switch (operacao) 
		{
			case '+' : printf("Resultado: é igual a %d", A+B); break;
			case '-' : printf("Resultado: é igual a %d", A-B); break;
			case '*' : ;
			case 'x' : ;
			case '.' : printf ("Resultado: é igual a %d", A*B); break;
			case '\\' :
			case '|' :
			case '/' :  (B==0) ? printf("Essa operação não é permitida.") : printf("Resultado: é igual a %d", A/B);
						if ((A%B!=0) && (B!=0))
							{
								printf(", com resto igual a %d", A%B);
							} break;
			case '%' : printf (" = %.0f", B*(double)A*0.01); break;
			case '^' : for(int i = 1; i<= B; i++)
							{
								acumulador *=A;
							}; printf("Resultado: É igual a %d", acumulador); break;
			default : printf("O operador inserido (%c) é inválido!", operacao); 
		}
	putchar('\n');	
	printf("\nDeseja realizar uma nova operação? (S/n): ");
		scanf(" %c", &SorN);
		
	switch (SorN) 
			{
				case 'S' :
				case 's' : getchar(); break;
				case 'N' : 
				case 'n' : printf("Calculadora Finalizada."); break;
				default : printf("Resposta inesperada, a Calculadora foi Finalizada.");
			}
		}
	else 
	printf("\nA operação foi inserida de maneira inesperada, tente novamente.\n");
	while (getchar() != '\n'); // Limpa o buff de memória do scanf, para evitar loop infinito.
	} 

		
			
        return 0;


}

