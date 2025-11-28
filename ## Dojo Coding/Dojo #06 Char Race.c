/**
* @file dojo.c
* @author @guilhermegcastro
* @date 27.11.2025 13:38:07 -03
* @brief
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define PILOT 15
#define SIZE 60


typedef struct {
    char simbol;
    char name[11];
    int number;
    } Player;
 
 
 
    
void linha(char sim, int tam){
    for (int i = 0; i < tam ; i++){
        printf("%c", sim);
        if(i == tam/2)
            printf(" CHAR RACE ");
    }
    putchar('\n');
}
int setNumPlayers() {
        int erro=0, players;
    do {
        system("clear");
        linha('=', 68);
        if(erro) {
            printf(" A quantidade de players não pode ser"); 
            (players < 2) ? printf(" menor que 2!\n") : printf(" maior que %d!\n", PILOT);
        }
        printf("Insira a quantidade de pilotos que participarão da corrida: > ");
        int charErro = scanf(" %d", &players);
        if(!charErro) {
            while(getchar()!='\n');
            continue;
        }
        if(players < 2 || players > PILOT) {
            erro = 1;
            continue;
        } 
            return players;
            } while (1);
    
   }
void loadingRace() { 
    system("clear");
    linha('=', 68);
    printf("\n>> Todos em seus lugares! A corrida já vai começar...! >>\n");
    system("sleep 2");
    system("clear");
}
Player setPlayer(int i) {
    Player novo;
    do{ 
        while(getchar()!='\n');
        printf(" Informe o nome (até 10 caracteres) e o símbolo do %dº piloto: > ", i);
        scanf(" %11s %c", novo.name, &novo.simbol);
        
        if(strlen(novo.name)>10) {
            printf("O nome não pode ter mais de 10 caracteres!\n");
            continue; //NOTE: Corrigir o erro de nome maior que 10 char.
        }
        break;
    } while (1);
    return novo;
}
void configPlayers(int cont, Player* p) {
        for (int i = 0; i < cont; i++){
            
            p[i] = setPlayer(i+1);
        }
        for(int i = 0; i < cont; i++)
            p[i].number = 0;
    }
void runPlayers(int min, int max, Player* p, int cont) {
    for (int i = 0; i < cont; i++) {
        p[i].number+= min + rand()%(max-min);
    }
}
void sortPlayers(Player* p, int cont) {
    for (int i = 1; i < cont; i++) {
        int j = i - 1;
        Player key = p[i];
        while (j >=0 && p[j].number < key.number) {
            p[j+1] = p[j];
            j--;
        }
        p[j+1] = key;
    }
}
void printRace(int time, Player* p, int cont) {
    system("clear");
    linha('=',68);
    for (int i = 0; i < cont; i++) {
        printf(" %-10s  |", p[i].name);
        for (int j = 1; j < SIZE; j++) {
            if(j <= p[i].number) 
                printf("%c", p[i].simbol);
            else printf(" ");
        }
        printf("|\n");
    }
    
    char timer[10];
    sprintf(timer, "sleep %d", time);
    system(timer);
}
int runRace(Player* p){
    
    if(p[0].number >=SIZE)
        return 0;
    else return 1;
}

void printResults(Player* p){
    putchar('\n');
    (p[0].number == p[1].number) ? printf(" HOUVE EMPATE!") : printf(" PILOTO %s GANHOU A CORRIDA!", p[0].name);
}
int main() {
    srand(time(NULL));
    int contPlayers = setNumPlayers();
    Player players[contPlayers];
    configPlayers(contPlayers, players);
    loadingRace();
    do{
        runPlayers(1, 4, players, contPlayers);
        sortPlayers(players, contPlayers);
        printRace(1, players, contPlayers);
      
    }while (runRace(players));
    printResults(players);
    
    return 0;
}


