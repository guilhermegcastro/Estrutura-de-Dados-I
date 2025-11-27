
/**
 * @file função00.c
 * @author @guilhermegcastro
 * @date 2025-11-24
 * @brief Implemente a função potencia() que retorna o valor de X elevado a N. 
 * Os valores de X e N devem ser enviados através de parâmetros.
 **/

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>



	
	
	int main() {
		int X, N;
	    printf("Informe a base X e o expoente N:\n - > ");
	    scanf(" %d %d", &X, &N);
	    printf(" %d^%d = %d", X, N, potencia(X, N));
        return 0;
 	}

	int potencia(int X, int N) {
		if(!N)
			return 1;
		int resultado=X;
		for (int i = 0; i < N-1; i++) 
			resultado*=X;
		return resultado;
	}
