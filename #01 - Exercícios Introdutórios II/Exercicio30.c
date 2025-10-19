/**
 * @file Exercicio30.c
 * @author Guilherme Castro
 * @date 2025-09-21
 * @brief
 * coding-exercise: 30. Dada a renda salarial anual de um trabalhador, calcule o imposto de renda devido.
 * A tabela de IR do ano 2024 é a seguinte…
 * Renda anual até R$ 24.511,92   .   Isento
 * Faixa até R$ 9.407,88          .   07,5%
 * Faixa até R$ 11.092,80         .   15,0%
 * Faixa até R$ 10.963,56         .   22,5%
 * Faixa acima de R$ 55.976,16    .   27,5%
 * Informe como resultado o valor total do imposto a ser pago e a alíquota efetiva do imposto de renda.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	float renda, rendarestante;
	float imposto1=0, imposto2=0, imposto3=0, imposto4=0;
	printf("Insira o valor da renda anual: R$");
	scanf("%f", &renda);
	
	if (renda <= 24511.92)
	{
	  printf(" ");
	}
	
	else
	{
		rendarestante = renda - 24511.92;
			if (rendarestante < 9407.80)
		{
			imposto1 = rendarestante * 0.075;
			printf(" Faixa 1: %.2f\n", imposto1);
		}
		else 
		{
			rendarestante -= 9407.88;
			imposto1 = 9407.88 * 0.075;
			printf(" Faixa 1: %.2f\n", imposto1);
				if (rendarestante < 11092.80)
			{
				imposto2 = rendarestante * 0.15;
				printf(" Faixa 2: %.2f\n", imposto2);
			}
			else
			{
				rendarestante -= 11092.80;
				imposto2 = 11092.80 * 0.15;
				printf(" Faixa 2: %.2f\n", imposto2);
				if (rendarestante < 10963.56)
			{
				imposto3 = rendarestante * 0.225;
				printf(" Faixa 3: %.2f\n", imposto3);
			}
			else
			{
				rendarestante -= 10963.56;
				imposto3 = 10963.56 * 0.225;
				printf(" Faixa 3: %.2f\n", imposto3);
				
					if (rendarestante >= 55976.16)
				{
					imposto4 = rendarestante * 0.275;
					printf(" Faixa 4: %.2f\n", imposto4);
				} 
			}
				
			}
		}
			
	}
		
	   
	
	printf("Valor total do imposto: %.2f\n", imposto1+imposto2+imposto3+imposto4);
	printf("Alíquota efetiva do imposto de renda: %.2f", (imposto1+imposto2+imposto3+imposto4)/renda * 100);
        return 0;

}

