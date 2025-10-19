/**
 * @file Exercicio27.c
 * @author Guilherme Castro
 * @date 2025-09-21
 * @brief
 * coding-exercise: 27. Um determinado material radioativo perde metade de sua massa a cada 50 segundos. 
 * Dada a massa inicial, em gramas, fazer um programa em C que calcule o tempo necessário para que essa massa se torne menor que 0,5 grama. 
 * O programa em C deve escrever a massa inicial, a massa final e o tempo calculado em horas, minutos e segundos.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)

{
	int segundos=0;
	double massainicial, massafinal; 
	
	printf("Insira a massa inicial (em gramas) do material radioativo:");
	scanf("%lE", &massainicial);
	
	massafinal = massainicial;
	while (massafinal >= 0.5)
	{
		massafinal/=2;
		segundos+=50;
	}
	
		printf(" - Massa inicial: %fg\n - Massa final: %fg\n - Tempo calculado: %d Hora(s), %d Minuto(s) e %d Segundos.\n", massainicial, massafinal, segundos/3600, segundos%3600/60, segundos%60);

        return 0;


}

