
/**
 * @file string11.c
 * @author @guilhermegcastro
 * @date 2025-11-03
 * @brief Enunciado: 31. O código de barras é essencial na automatização do processo de vendas. 
 * Esse código possui um formato conhecido por EAN-13, contendo 13 dígitos numéricos, sendo que os 3 primeiros identificam o País de origem (Brasil == 789)
 * Os 9 dígitos seguintes identificam a empresa fabricante e o produto em si
 * O último - 13º dígito - é um validador, chamado de “Dígito Verificador - DV”  calculado com base na sequência anterior
 * O cálculo do DV no EAN-13 é o seguinte:
 * 
 * Considerando do 1º ao 12º dígito, somar todas as posições pares e multiplicar a soma pelo valor 3.
 *  Ao resultado do passo anterior, somar todas as posições ímpares da sequência. 
 * O DV deverá ser o valor que tornará toda a soma alcançada em um múltiplo de 10.
 * Faça um programa que valide vários Códigos de Barras lidos pelo usuário.
 **/

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>


	int main() {
	    
	    do {
			char codigo[100], FIM[]={"FIM"};
			printf("\n Insira um código de barras para verificação. Digte FIM para parar a leitura:\n > ");
			 scanf(" %s", codigo);
			 
			 if(strcmp(codigo, FIM)==00) {
				printf("Programa finalizado.");
				return 0;
			 }
			 
			 size_t N = strlen(codigo);
			 if (N != 13)  {
				printf("Código inválido! Deve conter 13 dígitos numéricos.");
				continue;
			 }
			 
			 int par=0, impar=0;
			 for (int i = 0; i < 12; i++) {
				int n = codigo[i] - '0';
				if ((i+1)%2==0) {
					par+=(n*3);
				} else {
					impar+=n;
				}
			 }
			 
			 int somatorio= par + impar;
			 int verificador = somatorio%10;
			 if(verificador) 
				verificador = 10 - verificador;
			 (verificador==codigo[12]-'0') ? printf(" O Código é válido!") : printf(" O código não é válido!");
			 
			 
		} while (1);
		
        return 0;
 	}
