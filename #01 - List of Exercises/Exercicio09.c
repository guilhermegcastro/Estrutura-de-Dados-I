/**
 * @file Exercicio09.c
 * @author Guilherme Castro
 * @date 2025-09-17
 * @brief
 * coding-exercise: 9. Faça um programa que imprime o calendário de um mês (em formato de quadro). 
 * O usuário deve informar quantos dias possui o mês e o dia da semana em que se inicia (considere 1==domingo; 2==segunda; 3==terça, …).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
		int dias;
		char semana;
		printf("Informe quantos dias possui o mês (28, 29, 30 ou 31): ");
		scanf("%d", &dias);
		while(getchar()!='\n');
		if (( dias < 28) || (dias > 31))
			{
				puts("Dia inválido, reinicie o programa e tente novamente.");
			}
		else
			{
			printf("Informe o número respecetivo ao dia da semana que o mês inicia\n 1 - Domingo \n 2 - Segunda\n 3 - Terça\n 4 - Quarta\n 5 - Quinta\n 6 - Sexta\n 7 - Sábado\n ");
			scanf(" %c", &semana);
           if (semana >= '1' && semana <= '7') 
				{
					semana = semana - '0'; 
				} 
			else 
			{
				printf("Número de dia da semana inválido. Reinicie o programa e tente novamente.");
			}
		
			if ((semana >= 1)&&(semana <= 7))
				{
					printf(" | Dom | Seg | Ter | Qua | Qui | Sex | Sab |\n");
					
					for(int i = 1; i < semana; i++)
						{
							printf(" |    ");
						}
						
					for (int dia = 1; dia <= dias; dia++)
						{
							printf(" | %2d ", dia);
							if((dia+semana-1)%7==0)
								{
									printf(" | \n");
								}
			
						}
			if((dias>28)|| ((dias==28) && (semana > 1)))
					{
						printf(" | \n");
					}
				}
			}
			
        return 0;


}

