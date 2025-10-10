/**
 * @file Exercicio12.c
 * @author Guilherme Castro
 * @date 2025-09-18
 * coding-exercise: 12. Faça um programa que gere um número aleatório entre 0 e 1000.
 *  O programa deve imprimir o número sorteado e a quantidade de centenas, dezenas e unidades que ele possui.
 * Observe os termos no plural/singular e a necessidade de impressão de vírgulas ou conectivos ‘e’.
 * P.Ex.: 326 = 3 centenas, 2 dezenas e 6 unidades.
 * 150 = 1 centena e 5 dezenas.
 * 2 = 2 unidades.
 * @brief
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)
{
	
	srand(time(NULL));

	
	int numero = rand()%1001; 
	int unidade = numero%10; 
	int centena = numero/100;
	printf(" Um número dentre 0 e 1000 foi sorteado: %d\n\t %d = ", numero,numero);
	
	
	
		if (numero == 1000) 
		{
			printf(" 1 unidade de milhar, 0 centenas, 0 dezenas e 0 unidades");
		}
		else if (numero > 99)
		{
			printf("%d centena", centena), (centena==1) ? printf(", ") : printf("s, ");
			int dezena = (numero/10)%10;
			printf("%d dezena", dezena), (dezena==1) ? printf(" e ") : printf("s e ");
	    }
		else if (numero > 9)
		{
			int dezena = numero/10;
			printf("%d dezena", dezena), (dezena==1) ? printf(" e ") : printf("s e ");
		}
		if (numero!=1000)
		{
			printf("%d unidade", unidade), (unidade==1) ? printf(" ") : printf("s ");	
		}

        return 0;


}

