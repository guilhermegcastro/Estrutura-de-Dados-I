/**
* @file SIMULADO PERSISTÊNCIA.c
* @author @guilhermegcastro
* @date 18.01.2026 16:10:39 -03
* @brief
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZECAB 54

typedef struct {
    char placa[8];
    char modelo[100];
    char proprietario[100];
    int estacionado;
} Veiculo;

void next(char* label){
    if (label != NULL) {
        printf("%s"
            "\n", label);
    while(getchar()!='\n');
    getchar();
    system("clear");
    }
}

FILE* openFile(char name[]){
   
    FILE* f = fopen(name, "rb+");
    if (f == NULL)
        f = fopen(name, "wb+");
    if (f == NULL)
        printf("Não foi possível criar o arquivo de persistência!");
    return f;
}


void cabecalho(int t, char s, char* title) {
    system("clear");
    for(int i = 0; i < t; i++){
        if(i==t/2 && title!=NULL) {
            printf("%s", title);
            continue;
        }
        putchar(s);
    }
    putchar('\n');
}

int interface(){
    int option;
    cabecalho(SIZECAB, '=', " ESTACIONAMENTO PARTICULAR ");
    printf(
        "1 - Entrada de Carro\n"
        "2 - Saída de Carro\n"
        "3 - Utilização Atual\n"
        "> > Escolha a opção desejada: > ");
    scanf(" %d", &option);
    return option;
}

int veiculosTotais(FILE* f) {
    fseek(f, 0, SEEK_END);
    int size = ftell(f)/sizeof(Veiculo);
    fseek(f, 0, SEEK_SET);
    return size;
}



void dadosVeiculo(Veiculo c){
    printf(
        "- DADOS DO CARRO - \n"
        "Modelo/Cor: %s\n"
        "Proprietário: %s\n", c.modelo, c.proprietario);
}
void entradaCarro(FILE* f){
    char placa[8];
    int c = veiculosTotais(f);
    Veiculo lista;
    cabecalho(SIZECAB, '=', " 1 - ENTRADA DE CARRO ");
    printf("Informe a placa do veículo que dará entrada no estacionamento: > ");
    scanf(" %7s", placa); // como na prova não pede tratamento de erro, o scanf só irá ler os 7 caracteres necessários.
    while(getchar()!='\n');
    int existe = 0;
    for (int i = 0; i < c; i++) {
        fread(&lista, sizeof(Veiculo), 1, f);
        if(!strcmp(lista.placa, placa)){
            existe = 1;
            break;
        }
    }
    if (!existe || !c) {
        Veiculo novoCarro;
        printf("Carro não encontrado na Base de Dados. Faça o cadastro:\n");
        printf("Modelo/Cor: ");
        scanf(" %[^\n]", novoCarro.modelo);
        printf("Proprietário(a): ");
        scanf(" %[^\n]", novoCarro.proprietario);
        strcpy(novoCarro.placa, placa);
        novoCarro.estacionado = 1;
        fseek(f, 0, SEEK_END);
        fwrite(&novoCarro, sizeof(Veiculo), 1, f);
        fflush(f);
        printf("Carro %s cadastrado e estacionado com sucesso!\n", novoCarro.placa);
    } else {
        dadosVeiculo(lista);
        if(lista.estacionado == 1) {
            printf("Este carro já encontra-se estacionado. Operação Inválida.\n");
        } else {
        lista.estacionado = 1;
        fseek(f, -sizeof(Veiculo), SEEK_CUR);
        fwrite(&lista, sizeof(Veiculo), 1, f);
        printf("Entrada do Veículo Confirmada!\n");
        }
    }
    next("Aperte ENTER para prosseguir...");
    fflush(f);
}


void saidaCarro(FILE* f){
    char placa[8];
    cabecalho(SIZECAB, '=', "2 - SAÍDA DE CARRO");
    printf("Informe a placa do carro que dará saída no estacionamento: ");
    scanf(" %7s", placa);
    int c = veiculosTotais(f);
    Veiculo lista;
    int existe = 0;
    for (int i = 0; i < c; i++) {
        fread(&lista, sizeof(Veiculo), 1, f);
        if(!strcmp(lista.placa, placa)){
            existe = 1;
            break;
        }
    }
    if(!existe) {
        printf("Carro Não Encontrado na Base de Dados. Cadastre a placa utilizando a opção 1 do menu.\n");
    } else {
        dadosVeiculo(lista);
        if(!lista.estacionado) {
            printf("Este carro não encontra-se estacionado. Operação Inválida\n");
        } else {
            lista.estacionado = 0;
            fseek(f, -sizeof(Veiculo), SEEK_CUR);
            fwrite(&lista, sizeof(Veiculo), 1, f);
            printf("Saída do Veículo confirmada!\n");
        }
    }
    next("Aperte ENTER para continuar...");
    fflush(f);

}

void utilizacaoAtual(FILE* f){
    cabecalho(SIZECAB, '=', " 3 - UTILIZAÇÃO ATUAL ");
    int c = veiculosTotais(f);
    Veiculo lista;
    int estacionados = 0;
    for (int i = 0; i < c; i++){
        fread(&lista, sizeof(Veiculo), 1, f);
        if(lista.estacionado==1) {
            printf("| %-7s | - %s - Proprietário(a): %s\n", lista.placa, lista.modelo, lista.proprietario);
            estacionados++;
        }
    }
    printf("%d Veículos estacionados!\n", estacionados);
    next("Aperte ENTER para prosseguir...");
}
int main() {
    
    FILE* file = openFile("Estacionamento");
    while(1){
        switch (interface()) {
            case 1: entradaCarro(file);
                break;
            case 2: saidaCarro(file);
                break;
            case 3: utilizacaoAtual(file);
                break;
            default:  next("Opção inválida.");
        }
    }
     return 0;
    
}


