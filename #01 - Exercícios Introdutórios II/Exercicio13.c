/**
 * @file Exercicio13.c
 * @author Guilherme Castro
 * @date 2025-09-18
 * @brief
 * coding-exercise: 13. Numa eleição existem três candidatos. Faça um programa que peça o número total de eleitores. 
 * Peça para cada eleitor votar e ao final mostrar: a classificação e o número de votos de cada candidato, quantidade de votos brancos/nulos e se haverá ou não segundo turno (para não haver, um candidato deve obter 50% votos+1).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(int argc, char **argv)

{

	int eleitores, totalvoto;
	
	printf(" Informe o número total de eleitores: "); 
	scanf("%d", &eleitores); 
	putchar('\n');
	int urna[5];
	for ( int i = 1; i <= eleitores ; i++)
	{
		char voto; 
		printf("\t\t\t CANDIDATOS\n\n\t\t 1 - Candidato 1 \n\t\t 2 - Candidato 2 \n\t\t 3 - Candidato 3\n\n\t\t Outro Número - Voto Nulo\n\t\t 0 - Voto Em Branco\n\n Insira o número do %dº voto: ", i);
		scanf(" %c", &voto); 
		
		if (voto=='1')
		{
			urna[1] = urna [1] + 1;
		}
		if (voto=='2')
		{
			urna[2] = urna[2] + 1;
		}
		if (voto=='3')
		{
			urna[3] = urna[3] + 1;
		}
		if (voto =='0')
		{
			urna[0]+=1;
		}
		if ((voto>'3') || (voto<'0'))
		{
			urna[4]+=1;
		}
		
		
	}

	totalvoto = urna[1] + urna[2] + urna[3];
	int top1;
	printf("Classificação:\n"); 

	if (urna[1] >= urna[2])
	{
		printf("1º - Candidato 1 com %d votos\n", urna[1]);
		top1 = urna[1];
			 (urna[3] > urna[2]) ? printf("2º - Candidato 3 com %d votos \n3º - Candidato 2 com %d votos\n", urna[3], urna[2]) : printf("2º - Candidato 2 com %d votos \n3º - Candidato 3 com %d votos\n", urna[2], urna[3]) ;
	}
	
	else if (urna[2] >= urna[3])
	{
		printf("1º - Candidato 2 com %d votos\n", urna[2]);
		top1 = urna[2];
			 (urna[1] > urna[3]) ? printf("2º - Candidato 3 com %d votos \n3º - Candidato 2 com %d votos\n", urna[1], urna[3]) : printf("2º - Candidato 3 com %d votos \n3º - Candidato 1 com %d votos\n", urna[3], urna[1]);
	}
	
	else if (urna[3] >= urna[1])
	{
		printf("1º - Candidato 3 com %d votos\n", urna[3]);
		top1 = urna[3];
			 (urna[2] > urna[1]) ? printf("2º - Candidato 2 com %d votos \n3º - Candidato 1 com %d votos\n", urna[2], urna[1]) :  printf("2º - Candidato 1 com %d votos \n3º - Candidato 2 com %d votos\n", urna[1], urna[2]);
	}
	
	printf("\nQuantidade de votos nulos: %d\nQuantidade de votos em branco: %d\n", urna[0], urna[4]);
	printf("\nTotal de votos válidos: %d\n", totalvoto);
	(top1 >= totalvoto/2 + 1) ? printf("Não haverá necessidade de um segundo turno.") : printf("Haverá necessidade de um segundo turno.");
	
        return 0;
        
     
}

