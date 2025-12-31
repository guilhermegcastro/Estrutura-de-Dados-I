/**
* @file dojo07.c
* @author @guilhermegcastro
* @date 30.12.2025
* @brief
**/

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char nome[100];
    int tempo;
} Jogador;


void cabecalho (char* title, int t, char c) {

	for (int i = 0; i < t; i++) {
		if (t/2 == i) printf("%s", title);
		else putchar(c);
	}
	putchar('\n');


}
void next(char* label){
	printf("%s", label);
	while(getchar()!='\n');
	getchar();
	system("clear");
}

int interface(){
	cabecalho(" JOGO MATEMÁTICO ", 40, '=');
	printf(" 1 - Jogar\n"
	" 2 - Ranking\n"
	" Insira a opção desejada:");
	int op;
	scanf(" %d", &op);
	return op;
}


 void soma(int* n1, int* n2, int* res) {	 
	 *n1 = 10 + rand()%90;
	 *n2 = 10 + rand()%90;
	 *res = *n1 + *n2;
}


void sub(int* n1, int* n2, int* res) {	 
	 *n1 = 10 + rand()%90;
	 *n2 = 10 + rand()%90;
	 if(*n1 < *n2) {
		 int troca = *n1;
		 *n1 = *n2;
		 *n2 = troca; 
	 }
	 *res = *n1 - *n2;
}

void mult(int* n1, int* n2, int* res) {	 
	 *n1 = 10 + rand()%90;
	 *n2 = rand()%10;
	 *res = *n1 * *n2;
}

void divi(int* n1, int* n2, int* res) {	 
	 *n1 = 10 + rand()%90;
	 *n2 = 1 +  rand()%9;
	 *res = *n1 / *n2;
}

void mod(int* n1, int* n2, int* res) {	 
	 *n1 = 10 + rand()%90;
	 *n2 = 1 + rand()%9;
	 *res = *n1 % *n2;
}

void problema(int* n1, int* n2, int* res, char op) {
	int resposta;
    
    for (int i = 0; i < 2; i++) {
        switch (op) {
            case '+': soma(n1, n2, res); 
            break;
            case 'x': mult(n1, n2, res); 
            break;
            case '-': sub(n1, n2, res);
            break;
            case '/': divi(n1, n2, res); 
            break;
            case '%': mod(n1, n2, res); 
            break;
        }
        while(1) {
            printf("  > %d %c %d = ", *n1, op, *n2);
            scanf(" %d", &resposta);
            if(resposta==*res)  {
                printf("  Correto!\n\n");
                break;
            }
            printf("  Tente novamente!\n\n");
        }
    }
	
}


int tamanho(FILE* r) {
    fseek(r, 0, SEEK_END);
    int tamanho = ftell(r)/sizeof(Jogador);
    fseek(r, 0, SEEK_SET);
    return tamanho;
}
void registrar(FILE* r, int tempo) {
    Jogador novo;
    novo.tempo = tempo;
    int cont = tamanho(r);
    int e = sizeof(Jogador);
    cabecalho(" REGISTRO DE JOGADOR ", 40, '=');
    fseek(r, 0, SEEK_SET);
    while(1) {
        int registrado = 0;
        printf("Insira o seu nome: > ");
        scanf(" %[^\n]", novo.nome);
        for (int i = 0; i < cont; i++) {
            Jogador lista;
            fread(&lista, e, 1, r);
            if(!strcmp(novo.nome, lista.nome)) {
                registrado = 1;
                char op;
                printf(" ! - Esse nome já existe! Deseja sobrescrever o record atual? [S/n]");
                scanf(" %c", &op);
                if(op == 'S' || op == 's') {
                    if(novo.tempo > lista.tempo) {
                        printf(" ! - Seu tempo atual (%d:%d) é maior que o seu tempo no ranking (%d:%d)!\nSeu menor tempo permance.\n", novo.tempo/60, novo.tempo%60, lista.tempo/60, lista.tempo%60);
                        return;
                    }
                    fseek(r, -e, SEEK_CUR);
                    fwrite(&novo, e, 1, r);
                    fflush(r);
                    printf(" * - Seu ranking foi atualizado e seu tempo atual (%d:%d) foi adicionado!\n(Antigo ranking : %d:%d)\n", novo.tempo/60, novo.tempo%60, lista.tempo/60, lista.tempo%60);
                    return;
                } else break;
            }
        }
        if(!registrado)
            break;
    }
    printf(" * - Boas-vindas ao ranking, %s! \nSeu tempo de (%d:%d) foi adicionado!\n", novo.nome, novo.tempo/60, novo.tempo%60);
    fwrite(&novo, e, 1, r);
    fflush(r);
    return;
}

void game(FILE* r) {
	
	int t1 = time(NULL);

	int n1, n2, res;
    system("clear");
    cabecalho(" JOGO MATEMÁTICO ", 40, '=');
    printf("\n : Resolva 2 problemas de adição:\n\n");
    problema(&n1, &n2, &res, '+');
    printf("\n : Resolva 2 problemas de multiplicação:\n\n");
    problema(&n1, &n2, &res, 'x');
    printf("\n : Resolva 2 problemas de subtração:\n\n");
    problema(&n1, &n2, &res, '-');
    printf("\n : Resolva 2 problemas de divisão (ignore o resto):\n\n");
    problema(&n1, &n2, &res, '/');
    printf("\n : Resolva 2 problemas de módulo (somente o resto):\n\n");
    problema(&n1, &n2, &res, '%');
    int t2 = time(NULL);
    next("Parabéns! Você finalizou todas as operações. Aperte ENTER para prosseguir");
    registrar(r, t2-t1);
}


FILE* abrirArquivo(char fileName[]) {
    FILE* file = fopen(fileName, "rb+");
    if(file == NULL)
        file = fopen(fileName, "wb+");
    if(file == NULL) {
        printf("O arquivo do programa não pode ser acessado.");
        return 0;
    }
    return file;
     
}

void rank(FILE* r){
    system("clear");
    int cont = tamanho(r);
    if(!cont) {
        next("Não há jogadores no ranking atualmente! Aperte Enter para prosseguir.");
        return;
    }
    Jogador jogadores[cont];
    for (int i = 0; i < cont; i++) 
        fread(&jogadores[i], sizeof(Jogador), 1, r);
    
    for (int i = 0; i < cont-1; i++){
       for (int j = 0; j < cont-1-i; j++){
           if(jogadores[j].tempo > jogadores[j+1].tempo) {
               Jogador troca = jogadores[j];
               jogadores[j] = jogadores[j+1];
               jogadores[j+1] = troca;
            }
        }
    }
    
    cabecalho(" RANK DO JOGO MATEMÁTICO ", 40, '=');
    printf("\nPOS.    %-30s TEMPO\n\n", "NOME");
    for (int i = 0; i < cont; i++){
        printf("%02dº     %-30s %02d:%02d\n", i+1, jogadores[i].nome, jogadores[i].tempo/60, jogadores[i].tempo%60);
    }
    next("\n\n > Pressione ENTER para voltar ao menu.");
}

int main() {
	srand(time(NULL));
    FILE* ranking = abrirArquivo("mathgameranking");
	while(1) {
		switch (interface())
		{
			case 1: game(ranking);
				break;
			case 2: rank(ranking);
				break;
            case 999: next("CHEAT 999: O ranking foi reiniciado!");
                ranking = freopen("mathgameranking", "wb+", ranking);
                break;
			case 0: printf("PROGRAMA FINALIZADO");
				return 0;
			default: next("Opção inválida. Aperte ENTER!");
		}
	}
	
}

