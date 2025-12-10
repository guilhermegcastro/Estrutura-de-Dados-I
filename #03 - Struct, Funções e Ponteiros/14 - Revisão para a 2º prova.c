/**
* @file Prova.c
* @author @guilhermegcastro
* @date 10.12.2025 09:08:15 -03
* @brief Você deve criar uma struct chamada Medicamento contendo os seguintes campos:

    Codigo (Inteiro - Gerado automaticamente ou inserido manualmente).

    Nome (String - Ex: "Dipirona 500mg").

    Preco (Float - Preço unitário).

    Estoque (Inteiro - Quantidade disponível na prateleira).

O sistema deve ter capacidade para armazenar até 50 medicamentos.
⚙️ FUNCIONALIDADES DO MENU (REQUISITOS)

O programa deve apresentar um loop infinito com as seguintes opções:
1. Cadastrar Medicamento

    Ler o nome, preço e quantidade inicial.

    O código deve ser sequencial (1, 2, 3...) ou inserido pelo usuário (validar para não repetir).

    Validação: Não permitir preço negativo ou quantidade negativa.

2. Listar Estoque

    Exibir uma tabela com todos os medicamentos cadastrados.

    Mostrar: Código, Nome, Preço e Quantidade.

    Se o vetor estiver vazio, avisar "Nenhum medicamento cadastrado".

3. Buscar Medicamento (Consulta)

    Solicitar o Nome do medicamento ao usuário.

    Procurar no vetor e exibir os dados do medicamento encontrado.

    Se não encontrar, exibir mensagem de erro.

4. Realizar Venda (Atualizar Estoque)

    Solicitar o Código do medicamento e a Quantidade que está sendo vendida.

    Localizar o medicamento.

    Verificar se há estoque suficiente:

        Se sim: Diminuir a quantidade do estoque e exibir o valor total da venda (Preço x Qtd Vendida).

        Se não: Exibir "Estoque insuficiente".

5. Remover Medicamento (Excluir)

    Solicitar o Nome do medicamento.

    Remover o item do vetor, reorganizando os dados para não deixar "buracos" (Shift Left).

0. Sair

    Encerrar o programa.

⚠️ REGRAS DE IMPLEMENTAÇÃO

    Uso obrigatório de Funções para cada item do menu.

    Uso de passagem de parâmetros por Referência (Ponteiros) quando necessário (ex: alterar contadores ou vetores).

    Uso da biblioteca string.h para manipulação de textos.

    Interface limpa (use system("cls") ou system("clear") para limpar a tela entre as operações).
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ESTOQUE_MAX 50

typedef struct {
    int cod;
    char nome[100];
    float preco;
    int estoque;
} Medicamento;

void next(char* mensagem) {
    if(mensagem != NULL)
        printf("\n %s", mensagem);
  while(getchar()!='\n');
  getchar();
  system("clear");
}

int interface(){
    int opcao;
    printf("1 - Cadastrar Medicamento\n"
        "2 - Listar Estoque\n"
        "3 - Buscar Medicamento\n"
        "4 - Realizar Venda\n"
        "5 - Remover Medicamento\n"
        "0 - Sair\n"
        " Insira a opção desejada: > ");
    scanf(" %d", &opcao);
    return opcao;
}

void nomeMedicamento(char* mensagem, Medicamento* me){
    printf("%s", mensagem);
    scanf(" %[^\n]", me->nome);
}

void cadastrarMedicamento(Medicamento* me, int* cont, int* codigo){
    nomeMedicamento("Insira o nome do medicamento: > ",me);    
     do {
        printf("Informe o preço do medicamento: >");
        scanf("%f", &me->preco);
        while(getchar()!='\n');
        if(me->preco<0)  {
            printf("! - O preço do medicamento não pode ser negativo.\n");
         
            continue;
        }
        break;
    } while (1);
    
     do {
        printf("Informe o estoque disponível do medicamento: >");
        scanf("%d", &me->estoque);
        
        if(me->estoque<0)  {
            printf("! - O estoque do medicamento não pode ser negativo.\n");
            continue;
        }
        break;
    } while (1);
    
    me->cod = *codigo;
    (*codigo)++;
    (*cont)++;
    printf("Medicamento %s cadastrado com sucesso (código : %d)\n", me->nome, me->cod);
    next("Aperte ENTER para prosseguir.");
    return;
}

void  printMedicamento(Medicamento alvo) {
    printf("===========================\n"
        "Código: %d\n"
        "Nome: %s\n"
        "Preço: R$%.2f\n"
        "Quantidade disponível: %d\n\n",
        alvo.cod, alvo.nome, alvo.preco, alvo.estoque);
}

void listarEstoque(Medicamento* me, int cont) {
    system("clear");
    if (!cont) {
        next("\n\n Nenhum medicamento registrado. Aperte ENTER para prosseguir.");
        return;
    }
    for (int i = 0; i < cont; i++) 
        printMedicamento(me[i]);
    
    next("Aperte ENTER para prosseguir.");
    
}

void buscarMedicamento(Medicamento* me, int cont) {
    if(!cont) {
        next("Não há medicamentos para buscar. Aperte ENTER para prosseguir.");
        return;
    }
    
    Medicamento alvo;
    nomeMedicamento("Informe o nome do medicamento que deseja buscar: > ",&alvo);
    system("clear");
    int busca=0;
    for (int i = 0; i < cont; i++) {
        if(!strcmp(alvo.nome, me[i].nome)) {
                busca = 1;
                printMedicamento(me[i]);
            } // não tem break pq n há regra de medicamentos com nomes repetidos, logo ele imprime todos os que achar com o mesmo nome!
    }
    
    if(!busca) 
        printf("O medicamento informado não foi encontrado. ");
    
    next("Aperte ENTER para prosseguir.");
}

void realizarVenda(Medicamento* me, int cont){
    system("clear");
    int code, vendas;
    if(!cont) {
        next("Não há medicamentos registrados para vender. Aperte ENTER para voltar a tela inicial.");
        return;  
    }
    printf("Informe o código do medicamento: >");
    scanf(" %d", &code);
    
    int indice = -1;
    for (int i = 0; i < cont; i++) {
        if (code == me[i].cod) {
            indice=i;
            break;
        }
    }
    if(indice<0) {
        next("Medicamento não encontrado. Aperte ENTER para prosseguir.");
        return;
    }
    
    printf("Informe a quantidade de medicamentos vendidos: > ");
    scanf(" %d", &vendas);
    
    if(vendas<0) {
        next("Quantidade inválida. Aperte ENTER para voltar a tela inicial.");
        return;
    }

    if(me[indice].estoque < vendas) {
        next("O medicamento não possui estoque suficiente. Aperte ENTER para prosseguir.");
        return;
    }
    
    float valor = vendas * me[indice].preco;
    me[indice].estoque-= vendas;
    
    system("clear");
    printf("Transação concluída!\n"
        "Medicamento: %s\n"
        "Quantidade: %d\n"
        "Preço total: %.2f\n"
        "Estoque restante: %d\n",
        me[indice].nome, vendas, valor, me[indice].estoque);
}

void removerMedicamento(Medicamento* me, int* cont) {
    Medicamento alvo;
    nomeMedicamento("Informe o nome do medicamento que será excluído: > ",&alvo);
    int removido=0;
    for (int i = 0; i < *cont; i++){
     
        if(!strcmp(alvo.nome, me[i].nome)) {
        
            for (int j = i; j < *cont-1; j++)
                me[j] = me[j+1];

            (*cont)--;
            i--;
            removido++;
        }
    }
    if(!removido) {
        next("O medicamento solicitado não existe. Aperte ENTER para prosseguir.");
        return;
        }
    
    next("Medicamento deletado com sucesso! Aperte ENTER para prosseguir.");
    return;
}


int main() {
	Medicamento m[ESTOQUE_MAX];
    int codigo = 0, cont=0;
    
    while(1) {
        switch(interface()) {
            case 1: cadastrarMedicamento(&m[cont], &cont, &codigo);
                break;
            case 2: listarEstoque(m, cont);
               break;
            case 3: buscarMedicamento(m, cont);
               break;
             case 4: realizarVenda(m, cont);
                break;
            case 5: removerMedicamento(m, &cont);
               break;
            case 0: printf("\n\n Programa Finalizado!"); return 0;
            default: next("Opção inválida! Aperte ENTER para prosseguir...");
        }
    }
}


