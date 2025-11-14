
/**
 * @file vetor14.2.c
 * @author @guilhermegcastro
 * @date 2025-11-05
 * @brief  Enunciado: 14.​A bandeira da Itália possui três cores, nesta sequência: VERDE | BRANCO | VERMELHO
 * Faça um programa que sorteia aleatoriamente um vetor de tamanho N com valores que representam as 03 cores da bandeira italiana. 
 * Seu programa deve gerar como resultado:
 * a)​ A quantidade de bandeiras que podem ser visualizadas a partir do conteúdo original do array.
 * b)​ A quantidade total de bandeiras que podem ser formadas, após substituições estratégicas.
 **/

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>


	int main() {
	    
	    srand(time(NULL));
	    int N;
	    printf("Insira a quantidade de números do sorteio :\n > ");
	     scanf(" %d", &N);
	    
	    int cor[N];
	    
	    //Sorteio das cores; 0 - Verde, 1 - Branco, 2 - Vermelho
	    
	    int contv, contb, contr;
	    contv = contb = contr = 0;
	    
	    for (int i = 0; i < N; i++) {
			cor[i] = rand()%3;
			switch (cor[i])
						{
				case 0: printf(" 🟩"); contv++; break;
				case 1: printf(" ⬜"); contb++; break;
				case 2: printf(" 🟥"); contr++; break;
			}
	    }
	    
	    
	    //Verifica quantas bandeiras sao formadas na ordem original: 
	    int bandeira1=0;
	    for (int i = 2; i < N; i++) 
			if(cor[i-2]==0 && cor[i-1]==1 && cor[i]==2) bandeira1++;
		
		printf("\nForam formadas %d bandeira(s) da Itália no sorteio.\n\n", bandeira1);
	    //Organizando...
		
		int cont=0, bandeira2=0;
		while (cont<N){
			if(contv && contb && contr) {
				cor[cont] = 0;
				cor[cont+1] = 1;
				cor[cont+2] = 2;
				cont+=3; contv--; contb--; contr--; bandeira2++;
				continue;
			}
			
			if(contv) {
				cor[cont] = 0;
				cont++;
				contv--;
			}
			
			if(contb) {
				cor[cont] = 1;
				cont++;
				contb--;
			}
			
			if(contr) {
				cor[cont] = 2;
				cont++;
				contr--;
			}
		}
			
		
	    
	   
	   
	    //Impressão das cores ordenadas;
	    for (int i = 0; i < N; i++) {
			switch (cor[i])
			{
				case 0: printf(" 🟩"); contv++; break;
				case 1: printf(" ⬜"); contb++; break;
				case 2: printf(" 🟥"); contr++; break;
			}
			
		}
		printf("\nOrganizando, foram formadas %d bandeira(s) da Itália no sorteio.", bandeira2);
		putchar('\n');
		

        return 0;
 	}
