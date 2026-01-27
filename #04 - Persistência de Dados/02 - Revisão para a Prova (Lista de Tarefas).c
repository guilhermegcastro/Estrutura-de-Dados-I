/**
* @file simulado.c
* @author @guilhermegcastro
* @date 24.01.2026 17:37:07 -03
* @brief
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int id; //auto incremento. id == -1 significa que está apagado
    int status; // False - Não finalizada; True - Finalizada
    char descricao[100]; // Descrição da Tarefa
    char responsavel[100]; // Nome da pessoa
}Task;

const int TASKSIZE = sizeof(Task);

void next(char label[]) {
    if(label!=NULL){
        printf("%s", label);
    }
    while(getchar()!='\n');
    getchar();
    system("clear");
}

FILE* openFile(char fileName[]){
    FILE* f = fopen(fileName, "rb+");
    if (f == NULL)
        f = fopen(fileName, "wb+");
    if (f == NULL) {
        next("Não foi possível acessar/criar o arquivo de tarefas.");
        return 0;
        }
    return f;
}

void cabecalho(char* title, char simbol, int size){
    for (int i = 0; i < size; i++) {
        if (i == size/2 && title != NULL){
            printf("%s", title);
            continue;
        }
        putchar(simbol);
    }
    putchar('\n');
}
int interface(){
    cabecalho(" MEU TO-DO LIST ", '=', 3);
    int opcao;
    printf(
        "1) Nova Tarefa\n"
        "2) Listar Tarefas\n"
        "3) Editar Tarefa\n"
        "4) Excluir Tarefa\n"
        "* - Escolha uma opção: > ");
    if(scanf(" %d", &opcao) == 0)
        opcao = 0;
    return opcao;
}

int quantidadeTarefa(FILE* f) {
    fseek(f, 0, SEEK_END);
    int c = ftell(f);
    fseek(f, 0, SEEK_SET);
    return c;
}

void  novaTarefa(FILE* f){
    system("clear");
    cabecalho(" NOVA TAREFA ", '=', 20);
    Task nova;
    printf("Descrição da Tarefa: > ");
    scanf(" %99[^\n]", nova.descricao);
    printf("Responsável pela Tarefa: > ");
    scanf(" %99[^\n]", nova.responsavel);
    nova.id = quantidadeTarefa(f)/TASKSIZE + 1;
    nova.status = 0;
    fseek(f, 0, SEEK_END);
    fwrite(&nova, TASKSIZE, 1, f);
    fflush(f);
    next("[ + ] - Tarefa criada com sucesso! Aperte ENTER para prosseguir...");
}

void listaTarefa(FILE* f){
    system("clear");
    int b = quantidadeTarefa(f);
    int t = b/TASKSIZE;
    Task lista[t];
    fseek(f, 0, SEEK_SET);
    fread(lista, b, 1, f);
    for (int i = 0; i < t-1; i++){
        for (int j = 0; j < t-i-1; j++){
            if((lista[j].status && !lista[j+1].status)|| (lista[j].status == lista[j+1].status && lista[j].id < lista[j+1].id)) {
                Task troca = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = troca;
            }
        }
    }
    cabecalho(" LISTA DE TAREFAS ", '=', 3);
    printf("ID %-30s  %-20s%-10s\n","DESCRIÇÃO","RESP","STATUS");
    for (int i = 0; i < t; i++) {
        if(!lista[i].id)
            continue;
        printf("%02d %-30s%-20s%-10s\n", lista[i].id, lista[i].descricao, lista[i].responsavel, (lista[i].status)? "CONCLUÍDO" : "PENDENTE");
    }
    next("Aperte ENTER para continuar...");
}

char escolha(char* pergunta){
    char op;
    while (1){
        printf("%s [S/N]: > ", pergunta);
        scanf(" %c", &op);
        if(op != 'S' && op != 'N' && op != 's' && op != 'n') {
            printf("Opção inválida!\n");
            continue;
        }
        break;
    }
    if(op == 's')
        op = 'S';
    return op;
}

Task verificarID(char* mensagem, FILE* f){
    int op;
    int t = quantidadeTarefa(f)/TASKSIZE;
    Task tarefa;
    printf("%s", mensagem);
    scanf(" %d", &op);
    if(op > 0 && op < t+1){
        fseek(f, (op-1)*TASKSIZE, SEEK_SET);
        fread(&tarefa, TASKSIZE, 1, f);
    }
    if(tarefa.id == 0 || op < 1 || op > t){
        next("[ ! ] - O ID informado não existe! Aperte ENTER para prosseguir...");
        tarefa.id = 0;
    }
    return tarefa;
}




void editarTarefa(FILE* f){
    system("clear");
    cabecalho(" EDITAR TAREFA ", '=', 3);
    Task tarefa = verificarID("Digite o ID da tarefa que deseja editar: > ", f);
    if(!tarefa.id)
        return;
    if(escolha("Você deseja mudar a descrição da tarefa?")=='S'){
        printf("Informe a nova descrição: > ");
        scanf(" %99[^\n]", tarefa.descricao);
    }
    if(escolha("Você deseja mudar o responsável da tarefa?")=='S'){
        printf("Informe o novo responsável: > ");
        scanf(" %99[^\n]s", tarefa.responsavel);
    }
    if(!tarefa.status && escolha("Você marcar a tarefa como concluída?")=='S')
        tarefa.status = 1;
    fseek(f, (tarefa.id-1)*TASKSIZE, SEEK_SET);
    fwrite(&tarefa,TASKSIZE, 1, f);
    fflush(f);
    next("[ * ] - Dados atualizados com sucesso! Aperte ENTER para prosseguir...");
}

void excluirTarefa(FILE* f){
    system("clear");
    cabecalho(" EXCLUIR TAREFA ", '=', 3);
    Task tarefa = verificarID("Insira o ID da tarefa que você deseja excluir: > ", f);
    if(!tarefa.id)
        return;
    fseek(f, (tarefa.id-1)*TASKSIZE, SEEK_SET);
    tarefa.id = 0;
    fwrite(&tarefa, TASKSIZE, 1, f);
    next("[ - ] - Tarefa excluída com sucesso! Aperte ENTER para prosseguir...");
    
    
}


int main() {
	    
    FILE* fileTasks = openFile("TAREFAS");
        
        
    while (1){
        switch (interface()){
            case 1: novaTarefa(fileTasks);
                break;
            case 2: listaTarefa(fileTasks);
                break;
            case 3: editarTarefa(fileTasks);
                break;
            case 4: excluirTarefa(fileTasks);
                break;
            default: next("[ ! ] - Opção inválida! Aperte ENTER para prosseguir...");
        }
        
    }
    return 0;
}


