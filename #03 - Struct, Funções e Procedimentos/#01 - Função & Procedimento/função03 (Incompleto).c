/**
 * @file função03.c
 * @author @guilhermegcastro
 * @date 2025-11-25
 * @brief Faça um programa que sorteie N nºs entre 0 e X. 
 * Faça a ordenação do Array na função main(), mas levando em consideração a qtde. de bits 1 que os números formam em binário.
 * 	(crie função específica para calcular isso).
 * Imprima o resultado em decimal e binário.
 * 	(crie outra função para isso).
 **/
//NOTE: Terminar o código. 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>


	typedef struct {
		int decimal;
		int binario;
		} Numeral;				
		else
		{
			_
		}
		
	int byte1(int numero) {
		int decimal = numero, binario = 0, multx = 1, prestigio = 0;
		while (decimal){
			int resto = decimal%2; 
			binario = (binario + (multx * resto));
			decimal= decimal/2;
			multx*=10;
			if(resto)
				prestigio++;
		}
		return prestigio;
		
	}
	int main() {
	    
	  
	    srand(time(NULL));
	    int N, X;
	    printf("Informe o tamanho do array:\n - > ");
	    scanf(" %d", &N);
	    printf("Informe o intervalo máximo de numeros a serem sorteados:\n - > ");
	    scanf(" %d", &X);
		Numeral num[N];
		
		for (int i = 0; i < N; i++) 
			num[i].decimal = rand()%X;
			
		
		for (int i = 0; i < N-1; i++){
			for (int j = 0; j < N-i-1; j++){
				if(byte1(num[i].decimal) < byte1(num[i+1].decimal)) {
					Numeral troca = num[i];
					num[i] = num[i+1];
					num[i+1] = troca;
				}
		
			}
		}
		
		for (int i = 0; i < N; i++) {
			
			int decimal =  num[i].decimal;
			int binario = 0;
			int multx = 1;
			while (decimal){
				int resto = decimal%2; 
				binario = (binario + (multx * resto));
				decimal= decimal/2;
				multx*=10;
			}
			num[i].binario = binario;
		}
		
		for (int i = 0; i < N; i++) {
			printf("%d - %d \n", num[i].decimal, num[i].binario);
		
		}
			
	
		
		
		
		
		
		
		
		
		
		
        return 0;
 	}
