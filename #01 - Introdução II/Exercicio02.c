/**
 * @file Exercicio02.c
 * @author Guilherme Castro
 * @date 2025-09-16
 * @brief
 * coding-exercise: 2. Faça um programa que receba do usuário o comprimento de três retas. 
 * O programa deve informar ao usuário se é possível ou não formar um triângulo com essas retas.
 * NOTAS: Para saber se um três retas formam um triângulo, a soma das duas menores retas não pode ser menor que o comprimento da maior reta.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(int argc, char **argv)

{

	int reta1, reta2, reta3, ponte;
	
	puts("\tVerificador de retas de um triângulo.");
	printf("Insira o comprimento de três retas:\n");
	scanf("%d %d %d", &reta1, &reta2, &reta3);
	
	if (((reta1 > reta3) && (reta1 > reta2)) || ( (reta1 == reta2) && (reta1 > reta3) ) )//MAIOR,--, --  ou  MAIOR, MAIOR, --
		{
			 ponte = reta1;
			 reta1 = reta3;
			 reta3 = ponte;
		}
	
	 if ((reta2 > reta3) && (reta2 > reta1)) //--,MAIOR, --
		{
			 ponte = reta2;
			 reta2 = reta3;
			 reta3 = ponte;
		}
	
	
	if(reta1+reta2>=reta3)
		{
			printf("As retas formam um triângulo.");
		}
	else 
		{ 
			printf("As retas não formam um triângulo.");
		}
			
		

	

        return 0;


}

