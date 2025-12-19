/*
 * 2º Prova ED1
 * Questão #01 [PLAYLIST MUSICAL]
 * Utilizando técnicas e boas práticas de programação modular (funções e procedimentos) desenvolva um programa em C para atender aos requisitos do seguinte problema…
 * 🎶 P L A Y L I S T M U S I C A L 🎶
 * Uma playlist é uma coleção organizada de músicas, vídeos, ou outros tipos de mídia, que pode ser reproduzida em sequência determinada ou de forma aleatória. 
 * Faça um programa que simule a implementação de uma playlist musical. Neste sentido, atenda aos seguintes requisitos:
 * Menu Inicial da Aplicação:
 * 
 * = MINHA PLAYLIST =
 * 1) Adicionar Música
 * 2) Excluir Música
 * 3) Tocar Playlist (Ordem da Inserção)
 * 4) Tocar por Artista (Agrupar por Artistas)
 * 5) Tocar Aleatório
 * 
 * Requisitos e Restrições: 
 * 
 * ● A opção 1 (Adicionar Música) deve permitir o cadastro de uma nova música na playlist. 
 * As informações mínimas exigidas para cada música são:
 * id  - Identificador único de música (não necessita leitura, gerado por auto-incremento).
 * titulo  - Título/Nome da música a ser cadastrada.
 * artista  - Nome do artista ou banda intérprete da música.
 * tempo  - Tempo (em segundos) de duração da faixa.
 * 
 * ● A opção 2 (Excluir Música) deverá realizar a exclusão do registro de uma música e a reorganização da playlist (compactação do Array). 
 * O usuário deverá selecionar a música excluída através do seu ID.
 * Músicas excluídas da playlist não deverão mais aparecer nas reproduções.
 * 
 * ● A opção 3 (Tocar Playlist) deve apresentar a lista de músicas ativas na playlist.
 *  A lista deve ser exibida em formato de tabela, na mesma ordem em que foram cadastradas.
 *  O tempo da música deve ser exibido no formato MIN:SEG. Ao final da listagem, deve ser exibido o tempo total de execução da Playlist.
 * 
 * ● A opção 4 (Tocar por Artista) deve realizar o agrupamento da playlist por artistas, e realizar a impressão das músicas da playlist.
 * 
 * ● A opção 5 (Tocar Aleatório) deve realizar a impressão das músicas em ordem aleatória. Cada chamada à opção 5 deve resultar na geração de uma ordem de execução aleatória.
 */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MSC 100

typedef struct {
	int id;
	char titulo[100];
	char artista [100];
	int tempo;
} Musica;

//Assinaturas 
int interface();
int music(Musica m);
void next(char* label) ;
void novaMsc(Musica* m, int* c, int* in);
void removerMsc(Musica* m, int* c);
void cabecalhoplaylist(char* label);
void allTemp(int t);	
void playlist(Musica m[], int c);
void playlistArtista(Musica m[], int c);
void modoAleatorio(Musica m[], int c);

int main() {
	srand(time(NULL));
	Musica m[MSC];
	int cont=0, indice=0;
	
	while (1) {
		switch (interface()){
			case 0: printf("Programa finalizado!");
				return 0;
			case 1: novaMsc(&m[cont], &cont, &indice);
				break;
			case 2: removerMsc(m, &cont);
				break;
			case 3: playlist(m, cont);
				break;
			case 4: playlistArtista(m, cont);
				break;
			case 5: modoAleatorio(m, cont);
				break;
			default: next("[!] - Opção inválida! Aperte ENTER para tentar novamente.");
		}
		
	}
}

void next(char* label) { //Função para limpar o buffer, requesitar char do usuario e adicionar mensagem informando qual ação foi precedida.
		if(label!=NULL) //Printa mensagem apenas se for diferente de NULL.
			printf("%s", label);
		while(getchar()!='\n');
		getchar();
		system("clear");
}

int interface(){ //menu 
		int op;
		printf(" = MINHA PLAYLIST =\n"
		"1 - Adicionar Música\n"
		"2 - Excluir Música\n"
		"3 - Tocar Playlist\n"
		"4 - Tocar por Artista\n"
		"5 - Modo Aleatório\n"
		"0 - Finalizar Programa\n"
		" >> Informe a opção desejada: > ");
		scanf(" %d", &op);
		return op;
}

void novaMsc(Musica* m, int* c, int* in) { //adicionar musica
	if(*c>=MSC) {
		printf("[!] - Limite de %d músicas na playlist atingido!\n"
		"      Utilize a opção 2 para remover músicas, caso queira adicionar novas.\n      Aperte ENTER.", MSC);
		next(NULL);
		return;
	}
	system("clear");
	printf("= ADICIONAR NOVA MÙSICA NA PLAYLIST =\n\n");
	printf(">> Insira o nome da Música: > ");
	scanf(" %[^\n]", m->titulo);
	printf(">> Insira o nome do Artista: > ");
	scanf(" %[^\n]", m->artista);
	
	do {
		printf(">> Insira a Duração (em segundos): > ");
		int leitura = scanf(" %d", &m->tempo);
		if(leitura!=1) {
			printf("[!] - Insira apenas dígitos! \n\n");
			while(getchar()!='\n');
			continue;
		}
		
		if(m->tempo<0) {
			printf("[!] - A música não pode ter Duração negativa!\n\n");
			continue;
		}
		break;
	} while (1);
	
	m->id = *in;
	(*in)++; //Indice da prox msc
	(*c)++; //Contador de mscs
	
	next("\n[+] - Música cadastrada! Aperte ENTER para voltar ao menu.");
}


void removerMsc(Musica* m, int* c) { // remover musica por indice
	if(!*c) {
		next("[!] - Não há músicas para remover! Aperte ENTER para voltar ao menu.");
		return;
	}
	system("clear");
	int in;
	printf(">> Insira o índice da música que deseja remover: > ");
	scanf(" %d", &in);
	int found=0;
	
	for (int i = 0; i < *c; i++) {
		if(in == m[i].id) {
			for (int j = i; j < *c-1; j++)
				m[j] = m[j+1];
			found=1;
		}
	}
	
	if(!found) {
		next("[!] - Música não encontrada. Aperte ENTER para voltar ao menu.");
		return;
	}
	
	(*c)--;
	next("[-] - Música deletada com sucesso! Aperte ENTER.");
}


int music(Musica m){
	printf(" %-2d %-33s%-25s %02d:%02d\n",
	m.id, m.titulo, m.artista, m.tempo/60, m.tempo%60);
	return m.tempo;
}

void cabecalhoplaylist(char* label) {
	printf(" = %s =\n", label);
	printf(" %-2s %-33s %-25s %s\n", "ID", "TÍTULO", "ARTISTA", "TEMPO");
}

void allTemp(int t) 
	{ printf("\n%s %-38s%02d:%02d\n", "Tempo Total da Playlist:", " ", t/60, t%60); }
	
void playlist(Musica m[], int c) { //playlist listada por indice/inserção
	if(!c) {
		next("[!] - Não há músicas para tocar! Aperte ENTER para voltar ao menu.");
		return;
	}
	system("clear");
	int tempoTotal=0;
	cabecalhoplaylist("PLAYLIST");
	for (int i = 0; i < c; i++)
		tempoTotal+= music(m[i]);
		
	allTemp(tempoTotal);
	next("[*] - Fim da Playlist! Aperte ENTER.");
}

void playlistArtista(Musica m[], int c) { //playlist listada por ordem de artistas
	if(!c) {
		next("[!] - Não há músicas para tocar! Aperte ENTER para voltar ao menu.");
		return;
	}
	system("clear");
	Musica clone[MSC];
	
	for (int i = 0; i < c; i++)
		clone[i] = m[i];
	
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c-i-1; j++){
			if (strcmp(clone[j].artista, clone[j+1].artista) > 0) {
				Musica swap = clone[j];
				clone[j] = clone[j+1];
				clone[j+1] = swap;
			}
		}
	}
	
	cabecalhoplaylist("PLAYLIST POR ARTISTA");
	int tempoTotal=0;
	for (int i = 0; i < c; i++)
		tempoTotal+= music(clone[i]);
		
	allTemp(tempoTotal);
	next("[*] - Fim da Playlist! Aperte ENTER.");
}

void modoAleatorio(Musica m[], int c){ // Playlist listada de forma aleatória
	if(!c) {
		next("[!] - Não há músicas para tocar! Aperte ENTER para voltar ao menu.");
		return;
	}
	system("clear");
	int posicoes[MSC];
	for (int i = 0; i < c; i++)
		posicoes[i] = -1;
		
	int sorteados=0;
	while (sorteados<c) {
		posicoes[sorteados] = rand()%c;
		int jasort = 0;
		for (int i = 0; i < sorteados; i++){
			if(posicoes[sorteados] == posicoes[i] && 
			sorteados!=i) {
				jasort=1;
				break;
			}
		}
		if(jasort)
			continue;
		sorteados++;
	}
	
	cabecalhoplaylist("PLAYLIST ALEATÓRIA");
	int tempoTotal=0;
	for (int i = 0; i < c; i++) {
			int j = posicoes[i];
			tempoTotal = music(m[j]); //pra ficar mais legivel.
		}
		
	allTemp(tempoTotal);
	next("[*] - Fim da Playlist! Aperte ENTER.");
}

