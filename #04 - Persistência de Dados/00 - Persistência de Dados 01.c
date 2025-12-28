/**
* @file 00 - Persistência de Arquivos.c
* @author @guilhermegcastro
* @date 27.12.2025 21:47:48 -03
* @brief
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
   char descricao[100];
   float valor;
   char dataVencimento[100];
   int quitada; 
} Despesa;


FILE* arquivo(char* arqN) {
  FILE* arq = fopen(arqN, "rb+");
   if(arq==NULL)
        arq = fopen(arqN, "wb+");
    if (arq==NULL){
        printf("O arquivo não pode ser acessado/criado.");
        return 0;
    }
   return arq;
   
}

void next(char* mensagem) {
    if (mensagem!=NULL) 
        printf("%s", mensagem);
    while(getchar()!='\n');
    getchar();
    system("clear");
}

int interface() {
    printf("1 - Cadastrar Despesa\n"
    "2 - Listar Todas as Despesas\n"
    "3 - Quitar uma Despesa\n"
    "4 - Saldo de Despesas a pagar\n"
    "> >  ");
    int op;
    scanf(" %d", &op);
    return op;

}

void cadastrar(FILE* arq){
    system("clear");
    Despesa nova;
    printf("Informe a descrição da despesa:");
    scanf(" %[^\n]", nova.descricao);
    printf("Informe o valor da despesa:");
    scanf(" %f", &nova.valor);
    printf("Informe a data de vencimento (dd/mm/aaaa, com as '/'):");
    scanf(" %[^\n]", nova.dataVencimento);
    nova.quitada = 0;
    fseek(arq, 0, SEEK_END);
    if(fwrite(&nova, sizeof(Despesa), 1, arq)) 
        next("Despesa cadastrada com sucesso! Aperte Enter para prosseguir.");
    fflush(arq);
}

int tamanho(FILE* arq) {
    fseek(arq, 0, SEEK_END);
    int sizeFile = ftell(arq)/sizeof(Despesa);
    return sizeFile;
    
}


void listar(FILE* arq){
    system("clear");
    Despesa leitura;
    int quantidade = tamanho(arq);
    fseek(arq, 0, SEEK_SET);
    for (int i = 0; i < quantidade; i++){
        fread(&leitura, sizeof(Despesa), 1, arq);
        printf(" DESPESA Nº %d \n Descrição: %s\n"
        "Valor: R$%.2f\n"
        "Vencimento: %s\n"
        "Status: %s\n\n",
        i+1, leitura.descricao, leitura.valor, leitura.dataVencimento, (leitura.quitada) ? "[PAGO]" : "[ABERTO]");
        
    }
}

void quitar(FILE* arq){
    system("clear");
    listar(arq);
    int n;
    printf("Informe o número da despesa a ser quitada: > ");
    scanf(" %d", &n);
    int total = tamanho(arq);
    if (n < 1 || n > total) {
        next("Número inválido! Aperte Enter para prosseguir");
        return;
    }
    long offset = (n - 1) * sizeof(Despesa);
    
    Despesa temp;
    
    fseek(arq, offset, SEEK_SET);
    
    fread(&temp, sizeof(Despesa), 1, arq);
    
    if(temp.quitada) {
        next("Essa despesa já foi paga! Aperte ENTER para prosseguir");
        return;
    }
    
    temp.quitada = 1;
    printf("Quitando: %s no valor de R%.2f...\n", temp.descricao, temp.valor);
    fseek(arq, offset, SEEK_SET);
    fwrite(&temp, sizeof(Despesa), 1, arq);
    fflush(arq);
    next("Despesa quitada com sucesso!");
}

void saldo(FILE* arq) {
    
    Despesa leitura;
    int qtd = tamanho(arq);
    fseek(arq, 0, SEEK_SET);
    float saldoTotal = 0;
    for (int i = 0; i < qtd; i++){
        fread(&leitura, sizeof(Despesa), 1, arq);
        if(!leitura.quitada)
            saldoTotal+= leitura.valor;
    }
    printf("Saldo  Total das despesas em aberto: R$ %.2f", saldoTotal);
    next("\nAperte ENTER para prosseguir.");
}

int main() {
    
    FILE* file = arquivo("despesas");
    
    while (1){
        switch (interface()){
            case 1: cadastrar(file);  
                break;
            case 2: listar(file);
                    next("FIM DA LISTA! Aperte ENTER para prosseguir");
                break;
            case 3: quitar(file);
                break;
            case 4: saldo(file);
                break;
            case 999: next("CHEAT 999 : Todos os dados foram apagados!");
               file = freopen("despesas", "wb+", file);
                break;
            default: next("Opção inválida. Aperte ENTER para tentar novamente.");
        }
        
    }
    return 0;
}


