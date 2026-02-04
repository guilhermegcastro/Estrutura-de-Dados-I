/**
* @file dojo08.c
* @author @guilhermegcastro
* @date 29.01.2026 13:38:20 -03
* @brief
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
  int id;
  char descricao[50];
  float valor;
  int tipo;
  int dia;
  int status;  
}Lancamento;

const int size = sizeof(Lancamento);

void next(char* label){
    if (label != NULL)
        printf("%s", label);
    while(getchar()!='\n');
    getchar();
    system("clear");
}

void header(char* title, char symbol, int size) {
    
    for (int i = 0; i < size; i++){
        if (title != NULL && i == size/2) {
            printf("%s", title);
            continue;
        }
        putchar(symbol);
    }
    putchar('\n');
}


int interface(){
    int opcao;
    printf(
    "1 - Cadastrar Receita\n"
    "2 - Cadastrar Despesa\n"
    "3 - Pagar Despesa\n"
    "4 - Extrato Mensal\n"
    "> > Escolha uma opção: > ");
    int e = scanf(" %d", &opcao);
    if (e != 1)
        opcao = 0;
    return opcao;
}

FILE* abrirArquivo(char* nome){
    FILE* f = fopen(nome, "rb+");
    if (f == NULL)
        f = fopen(nome, "wb+");
    if (f == NULL)
        next("Houve um problema ao tentar criar/acessar o arquivo.");
    return f;
}

int tamanho(FILE* f){
    fseek(f, 0, SEEK_END);
    int t = ftell(f)/size;
    return t;
}
void cadastro(FILE* f, int tipo) {
    system("clear");
    Lancamento novo;
    novo.tipo = tipo;
    novo.status = tipo;
    novo.id = tamanho(f) + 1;
    printf("Insira a descrição da %s: > ", (!tipo)? "Despesa" : "Receita");
    scanf(" %49[^\n]", novo.descricao);
    printf("Informe o valor: > R$");
    scanf(" %f", &novo.valor);
    printf("Informe o dia referente: > ");
    while (1){
        scanf(" %d", &novo.dia);
        if(novo.dia > 0 && novo.dia < 32)
            break;
        printf("Dia inválido! Insira novamente: > ");
    }
    printf("[+] - %s cadastrada com sucesso! Aperte ENTER para continuar...", (!tipo)? "Despesa" : "Receita");
    fseek(f, 0, SEEK_END);
    fwrite(&novo, size, 1, f);
    fflush(f);
    next(NULL);
}

void pagarDespesa(FILE* f){
    system("clear");
    int t = tamanho(f);
    Lancamento lista[t];
    fseek(f, 0, SEEK_SET);
    fread(lista, (t+1)*size, 1, f);
    for (int i = 0; i < t-1; i++){
        for (int j = 0; j < t-i-1; i++){
            if(lista[j].dia > lista[j+1].dia) {
                Lancamento troca = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = troca;
            }
        }
    }
        
     printf("%s %s %-50s    %s\n", "ID", "DIA", "DESCRIÇÃO", "VALOR");
     int semDespesa = 0;
    for (int i = 0; i < t; i++){
        if(lista[i].tipo || lista[i].status)
            continue;
        printf("%2d %02d   %-50s R$%.02f\n", lista[i].id, lista[i].dia, lista[i].descricao, lista[i].valor);
        semDespesa = 1;
    }
    if (!semDespesa) {
        system("clear");
        next("[!] - Não há despesas atualmente! Aperte ENTER para prosseguir...");
        return;
    }
    int op;
    printf("> > Insira o ID da despesa que deseja pagar: > ");
    scanf(" %d", &op);
    Lancamento despesaPaga;
    long offset = (op - 1) * size;
    fseek(f, offset, SEEK_SET);
    fread(&despesaPaga, size, 1, f);
    if(op < 1 || op > t) {
        next("[!] - Não há cadastro com esse ID! Aperte ENTER para prosseguir...");
        return;
    }
    if(despesaPaga.status) {
        if(despesaPaga.tipo)
            next("[!] - O ID informado é de uma Receita! Aperte ENTER para prosseguir...");
        else
            next("[!] - Este ID é de uma Despesa já paga! Aperte ENTER para prosseguir...");
        return;
    }
    despesaPaga.status = 1;
    fseek(f, offset, SEEK_SET);
    fwrite(&despesaPaga, size, 1, f);
    fflush(f);
    next("[*] - Despesa paga com sucesso! Aperte ENTER para prosseguir...");
    
}

void extrato(FILE* f){
    system("clear");
    int t = tamanho(f);
    if(!t){
        next("[!] - Não há lançamentos registrados! Aperte ENTER para prosseguir...");
        return;
    }
    Lancamento lista[t]; 
    fseek(f, 0, SEEK_SET);
    fread(lista, (t+1)*size, 1, f);
    
    for (int i = 0; i < t; i++){
        for (int j = 0; j < t-i-1; j++){
            if((!lista[j].tipo && lista[j+1].tipo) || 
            (lista[j].tipo == lista[j+1].tipo && lista[j].dia > lista[j+1].dia)) {
                Lancamento troca = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = troca;
            }
        }
    }
    printf("%s %s %-54s %s  %s\n", "TIPO", "DIA", "DESCRIÇÃO", "STATUS", "VALOR");
    for (int i = 0; i < t; i++){
        printf(" %-3c %02d  %-50s %s R$%.2f\n", (lista[i].tipo) ? 'R' : 'D', lista[i].dia, lista[i].descricao, (lista[i].status) ? "    OK   " : "  PENDEN.", lista[i].valor);
    }
    next("FIM DA LISTA. Aperte ENTER para prosseguir...");
}


int main(){
    
    FILE* arquivo = abrirArquivo("controlefinanceiro");
    
    while (1){
        switch (interface())
        {
            case 1: cadastro(arquivo, 1);
                break;
            case 2: cadastro(arquivo, 0);
                break;
            case 3: pagarDespesa(arquivo);
                break;
            case 4: extrato(arquivo);
                break;
            case 999: next("[*] - Todos os cadastrados foram excluídos!");
                arquivo = freopen("controlefinanceiro", "wb+", arquivo);
                break;
            default: next("[!] - Opção inválida! Aperte ENTER para prosseguir...");
        }
        
    }
    return 0;
}


