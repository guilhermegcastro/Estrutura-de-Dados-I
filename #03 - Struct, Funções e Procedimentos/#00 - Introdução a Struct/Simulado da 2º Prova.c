
/**
 * @file simulado prova 2.c
 * @author @guilhermegcastro
 * @date 2025-11-20
 * @brief 
 * Simulado da Prova 2- ED1
 * Uma biblioteca deseja informatizar o arquivamento e a consulta do acervo de livros que possui.
 * Faça um programa que utilize structs do tipo Livro, contendo: Título (s), Autor (s), Área do Conhecimento (s), Ano (idc) e
 * Localização (idc), para cadastrar até 1000 Livros.
 * A informação de Localização não deve ser preenchida pelo usuário, mas pelo próprio sistema, dadas as seguintes regras...
 * Após o usuário cadastrar todos os Livros, o programa deverá ordená-los pela: “Área do conhecimento” e, dentro de cada
 * Área de conhecimento, pelo “Título do livro”, como o exemplo abaixo:
 * Área de Conhecimento: Análise de Sistemas
 * Título				Autor 		Ano 		Localização
 * Algoritmos 			José 		2012 		---
 * Banco de Dados 		Maria		2013 		---
 * Cálculo Numérico 	João 		2011 		---
 * Estrutura de Dados 	Adriano 	2016 		---
 * 
 * Área de Conhecimento: Biologia
 * Título				Autor 		Ano 		Localização
 * Citologia 			Antônio 	2016 		---
 * Genética 			Lucas 		2003 		---
 *
 *  Área de Conhecimento: Engenharia Civil
 * Título				Autor 		Ano 		Localização
 * Cálculo 				João 		2014 		---
 * Desenho 				Pedro 		2002 		---
 * 
 * Uma vez ordenados, o programa deverá distribuir os livros automaticamente nas prateleiras, seguindo a seguinte lógica:
 * 
 * 1. As prateleiras são sequenciais.
 * 2. Cada prateleira suporta no máximo (por simplificação) 03 livros. 
 * 3. Livros de “Áreas de Conhecimento” diferentes não podem ficar na mesma prateleira. 
 * 4. Deve haver prateleiras vazias (sem livros) para separar áreas de conhecimento da próxima. 
 * 5. A quantidade de prateleiras vazias seguirá a seguinte fórmula: 1 +(quantidade de prateleiras da área/2).
 * O resultado do cenário de exemplo acima seria, portanto… (Imprimir exatamente como no layout abaixo):
 * 
 * Área de Conhecimento: Análise de Sistemas
 * Título				Autor 		Ano 		Localização
 * Algoritmos 			José 		2012 		01
 * Banco de Dados 		Maria		2013 		01
 * Cálculo Numérico 	João 		2011 		01
 * Estrutura de Dados 	Adriano 	2016 		02
 * 
 * Área de Conhecimento: Biologia
 * Título				Autor 		Ano 		Localização
 * Citologia 			Antônio 	2016 		05
 * Genética 			Lucas 		2003 		05
 *
 *  Área de Conhecimento: Engenharia Civil
 * Título				Autor 		Ano 		Localização
 * Cálculo 				João 		2014 		07
 * Desenho 				Pedro 		2002 		07
 **/

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
 #define BIBLIOTECA 100

	typedef struct {
		char titulo[100], autor[100], area[100];
		int ano, local;
	}Livro;
	int main() {
	    
	    Livro l[BIBLIOTECA];
	    int idc=0;
	    
	    
	    while (1){ // CADASTRO DOS LIVROS.
			system("clear");
			printf(" == CADASTRO DE LIVROS ==\n ! - Para finalizar o cadastro, insira EXIT no título.\n\n");
			printf(" * - Informe o título do livro:\n  > ");
			scanf(" %[^\n]s", l[idc].titulo);
			if(strcmp(l[idc].titulo, "EXIT")==0) //O USUÁRIO FINALIZA O CADASTRO AO DIGITAR "EXIT".
				break;
			//printf(" * - Informe o autor do livro:\n  > ");
			//scanf(" %[^\n]s", l[idc].autor);
			printf(" * - Informe a área de conhecimento do livro:\n  > ");
			scanf(" %[^\n]s", l[idc].area);
			//printf(" * - Informe o ano do livro:\n  > ");
			//scanf(" %d", &l[idc].ano);
			idc++;
			
			if(idc==BIBLIOTECA) { // CASO O CONTADOR CHEGUE NO LIMITE DEFINIDO NA CONSTANTE BIBLIOTECA, O LOOP QUEBRA COM UM AVISO.
				printf("Limite de %d livros atingido. Aperte Enter para prosseguir.", BIBLIOTECA);
				while(getchar()!='\n');
				getchar();
				break;
			}
		} //FIM DO LOOP CADASTRO DOS LIVROS.
		
		for (int i = 0; i < idc-1; i++){ //ORGANIZANDO AS ÁREAS DE CONHECIMENTO E TÍTULOS POR ORDEM ALFABÉTICA.
			for (int j = 0; j < idc-i-1; j++) {
				if( (strcmp(l[j].area, l[j+1].area)> 0 ) || (!strcmp(l[j].area, l[j+1].area) &&  strcmp(l[j].titulo, l[j+1].titulo) > 0) ) {
					Livro trade = l[j]; 
					l[j] = l[j+1];
					l[j+1] = trade;
	
				}
			}
		}
		
		int cont = 1, pratileira=1, pratileiraArea=1, espaco=1;
		l[0].local = pratileira;
		while (cont <= idc) { // ORGANIZANDO A LOCALIZAÇÃO DOS LIVROS
			
			if(!strcmp(l[cont].area, l[cont-1].area) && espaco < 3) {
				l[cont].local = pratileira; 
				espaco++;
				cont++;
				pratileiraArea++;
				continue;
			} else if (!strcmp(l[cont].area, l[cont-1].area) && espaco == 3) {
				espaco=1;
				pratileira++;
				l[cont].local = pratileira; 
				cont++;
				pratileiraArea++;
				continue;
				}
			if(strcmp(l[cont].area, l[cont-1].area)!=0) {
				pratileira+= 1 +(pratileiraArea/2);
				espaco=0;
				pratileiraArea=1;
				l[cont].local = pratileira; 
				espaco++;
				cont++;
				continue;
			}
				
		}
		
		for (int i = 0; i < idc; i++) { //IMPRESSÃO DO CATÁLOGO CADASTRADO
			if(!i || strcmp(l[i].area, l[i-1].area)!=0) {
				printf("\n\n Área de Conhecimento: %s\n", l[i].area);
				printf(" %-30s %-20s %-6s %s\n", "TÍTULO", "AUTOR", "ANO", "LOCALIZAÇÃO");
			}
			printf(" %-30s%-20s %-6d %02d\n",
				l[i].titulo,
				l[i].autor,
				l[i].ano,
				l[i].local
				);
		}
		
	    
        return 0;
 	}
