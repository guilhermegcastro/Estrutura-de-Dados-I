/**
 * @file Exercicio08.c
 * @author Guilherme Castro
 * @date 2025-09-17
 * @brief
 * coding-exercise: 8. Sabendo-se que um mês começou na quarta-feira, e tem 31 dias, faça um programa que leia um valor inteiro N correspondente a um dia deste mês, e imprima o respectivo dia da semana. 
 * Repita essa operação várias vezes até o usuário informar uma data inválida.
 *  (Dica: Use switch-case).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{

	int dia; 
	printf(" Um calendário de 31 dias começou em uma quarta-feira.\n");
	do
	{
			printf(" Insira um dia do mês para saber qual o dia da semana respectivo: ");
			scanf("%d", &dia);
			if (dia < 1 || dia > 31)
			{
				puts(" - Dia inválido. Programa encerrado.");
			}
			else
			{
				putchar('\n');
				 printf(" - O dia %d do mês cai em uma ", dia);
				switch (dia)
				{
					 case 1: // deixando os case em branco e sem break, posso utilizar o efeito cascata ao meu favor.
					 case 8: //aumenta sempre mais 7...
					case 15:
					case 22:
					case 29: printf("Quarta-feira."); break; //O break impede que os próximos cases executem, pois eu quero que apareça apenas um dia da semana.
				
					 case 2: // próximo dia da semana: Quinta
				     case 9: //posso usar a lógica de aumentar mais um em relaçao as cases anteriores
					case 16:
					case 23:
					case 30: printf("Quinta-feira."); break; 
					
				     case 3: // próximo dia da semana: Sexta
					case 10:
					case 17:
					case 24:
					case 31: printf("Sexta-feira."); break; 
				
					 case 4: // próximo dia da semana: Sábado
					case 11: 
					case 18:
					case 25: printf("Sábado."); break; // Não existe dia 32, então sábado (domingo, segunda e terça também) possui menos cases.
					
					 case 5: // '' Domingo
					case 12: 
					case 19:
					case 26: printf("Domingo."); break; 
					
					 case 6: // '' Segunda
					case 13: 
					case 20:
					case 27: printf("Segunda-feira."); break; 
					
					 case 7: // '' Terça
					case 14: 
					case 21:
					case 28: printf("Terça-feira."); break; 
					default: printf("Dia inválido. Programa finalizado...");
				}
				putchar('\n');
				puts(" * Para finalizar o programa, insira um dia inválido.");
				putchar('\n');
			}
	} while (dia <= 31 && dia >= 1);
	
	
        return 0;


}

