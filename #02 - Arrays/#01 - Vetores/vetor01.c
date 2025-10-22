
/**
 * @file vetor01.c
 * @author @guilhermegcastro
 * @date 2025-10-15
 * @brief
 * Enunciado: 1. Gere um vetor com 30 valores inteiros que representam a umidade relativa do ar em cada dia deste período. 
 * Alimente o vetor com valores aleatórios entre 12 e 80. Conte e escreva os dias com maior e menor umidade relativa, a média mensal, e a quantidade de dias acima da média.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

	srand(time(NULL));
	int dia[30], maiorTemperatura, menorTemperatura, media=0, diaAcimaMedia=0;
	printf("\n Umidade relativa do ar em cada dia do mês:\n");
	for (int i = 0; i < 30; i++) {
		dia[i] = 12 + rand()%69;
		media+= dia[i];
		printf("  Dia %02d: %d%%", i+1, dia[i]);
		if (!i)	{
			maiorTemperatura = i;
			menorTemperatura = i;
			continue;
		}
		menorTemperatura = (dia[i] < dia[menorTemperatura]) ? i : menorTemperatura;
		maiorTemperatura = (dia[i] > dia[maiorTemperatura]) ? i : maiorTemperatura;
		if ((i+1)%5==0)
		printf("\n");
	}
	
	for (int i = 0; i < 30; i++) {
		if (dia[i] > media/30) {
			diaAcimaMedia+=1;
		}
	}
	
	printf("\n O dia %02d teve a maior umidade relativa (%d%%)", maiorTemperatura+1, dia[maiorTemperatura]);
	printf("\n O dia %02d teve a menor umidade relativa (%d%%)", menorTemperatura+1, dia[menorTemperatura]);
	printf("\n A média mensal das temperaturas foi de %d%%", media/30);
	printf("\n Há %d dias que estão acima da média mensal.", diaAcimaMedia );
        return 0;
}

