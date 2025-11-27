#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DB 100
//sistema pdv (ponto de venda)

typedef struct{
	int codigo;   //chave
	char descricao[100];
	float valor;
	int estoque;
}Produto;

/* REQUISITOS DA APLICAÇÃO

1- DEVE SER POSSÍVEL CADASTRAR ATÉ 100 PRODUTOS.
2- TODO PRODUTO DEVE TER CODIGO ÚNICO (GARANTIDO PELO SW).
3- SAÍDA DO CADASTRO DE PRODUTOS SERÁ CODIGO <= 0;

FASE DE VENDAS!
1- SOLICITAR CODIGO DE ITEM PARA VENDA:
	1.1- VERIFICAR SE ITEM EXISTE
		1.1.1- IMPRIMIR TODOS OS DADOS DO PRODUTO, OU
		1.1.2- CODIGO NÃO EXISTENTE! TENTAR NOVAMENTE.

	1.2. SOLICITAR QUANTIDADE DESTE MESMO ITEM NO CARRINHO
		1.2.1- VERIFICAR SE A QTDE. ESTÁ DISPONÍVEL
		1.2.2- ATUALIZAR ESTOQUE DO ITEM
		
2. REPETIR TODO PROCESSO DE VENDA DO CARRINHO ATÉ CÓDIGO <=0

3. INFORMAR TOTAL DA VENDA
4. INFORMAR VALOR PAGO
5. INFORMAR TROCO DA VENDA

6. PERGUNTAR SE HÁ NOVO CARRINHO DE COMPRAS
	6.1. REPETIR TODO PROCESSO PARA NOVO CARRINHO.

7. NÃO HAVENDO...
	7.1 RELATÓRIO ATUALIZADO DE TODOS OS PRODUTOS
	7.2 FATURAMENTO DO DIA (TOTAL DE VENDAS)
*/

int main(){


	
	Produto p[MAX_DB];
	int menu = 0, qtd=0, meio;
	
	
	//for (int i = 0; i < MAX_DB; i++) 
		//p[i].codigo = -1;
		
	while (1) {
		
		while (!menu) { //1. Cadastro  de até 100 produtos.
			system("clear");
			printf("== CADASTRO DE PRODUTOS ==\n");
			printf("* - Para encerrar o cadastro, insira um código igual ou menor a 0.\n\n");
			printf(" # - Insira o código do produto: ");
			scanf(" %d", &p[qtd].codigo);
			
			if(p[qtd].codigo <= 0 || qtd==MAX_DB) { // 3. Fim do cadastro.
				menu = 1; 
				if(qtd==MAX_DB)
					printf(" * - Limite de %d produtos atingido..\n.", MAX_DB);
				printf("! - Cadastro de produtos finalizado! Aperte Enter para prosseguir...");
				while(getchar()!='\n');
				getchar();
				break;
			}
			
			int inicio = 0, fim = qtd-1, repetido = 0;
			
		
			while (inicio <= fim && qtd) { //2 Verifica se o código já fora usado.
				int meio = (inicio+fim)/2;
				if (p[qtd].codigo == p[meio].codigo) {
					repetido = 1;
					break;
				}
				if (p[meio].codigo < p[qtd].codigo) {
					inicio = meio + 1;
					} 
					else {
						fim = meio - 1;
					 }
			}
			
			if(repetido) { 
				printf(" X - O código fornecido já existe para outro produto. Aperte Enter e tente novamente com outro código.");
				while(getchar()!='\n');
				getchar();
				continue;
			}
				putchar('\n');
				
				printf(" + - Código cadastrado!\n\n # - Informe o nome do produto: ");
				scanf(" %[^\n]s", p[qtd].descricao);
				
				do {
					printf("# - Informe o estoque disponível para o produto: ");
					scanf(" %d", &p[qtd].estoque);
					if(p[qtd].estoque >= 0) break;
					printf("\n ! - Quantidade não pode ser negativa.\n");
				} while (1);
				
				do {
					printf(" # - Informe o preço do produto: R$");
					scanf(" %f", &p[qtd].valor);
					if(p[qtd].valor >= 0) break;
					printf("\n ! - Preço não pode ser negativo.\n");
				} while (1);
				
			
			for (int i = 1; i < qtd+1; i++) {
				int key = p[i].codigo;
				Produto key2 = p[i];
				int j = i - 1;
				
				while (j >= 0 && p[j].codigo > key) {
					p[j+1] = p[j];
					j--;
				}
				p[j+1] = key2;
			}
			
			printf(" | - Produtos cadastrados até o momento:\n\n");
			printf(" =================================\n");
			for (int i = 0; i < qtd+1; i++) {
				printf("\n CÓDIGO: [%d]\n DESCRIÇÃO: %s\n",
					p[i].codigo,
					p[i].descricao);
				printf(" ESTOQUE: %d disponíve",  p[i].estoque);
				(p[i].estoque!=1)? printf("is") : printf("l");
				printf("\n PREÇO: R$%.2f\n\n", p[i].valor );
				printf(" =================================\n");
			}
			
			printf(" * - Pressione Enter para prosseguir.\n");
			while(getchar()!='\n');
			getchar();
			putchar('\n');
			qtd++; 
			
		}
		
		float subtotal=0, total=0, vendas=0;
		
		while(menu) { // Fase das vendas.
			int code;
			
			while (menu==1){
				system("clear");
				printf("== SISTEMA DE VENDAS ==\n\n");
				printf("* - Para encerrar o ciclo do carrinho, insira um código igual ou menor a 0.\n");
				if(subtotal)
					printf(" * - Subtotal: R$%.2f\n ", subtotal);
				printf("\n ~ - Informe o código do item para venda: ");
				scanf(" %d", &code);
				
				if(code <= 0) { // 3. Fim do cadastro.
					menu = 1; 
					printf("! - Ciclo do carrinho finalizado! Aperte Enter para prosseguir");
					while(getchar()!='\n');
					getchar();
					menu = 3;
					break; 
				}
			
				
				int busca = 0, inicio = 0, fim = qtd-1;
				while (inicio <= fim ) { //1.1 Verifica se o código do produto.
					meio = (inicio+fim)/2;
					if (code == p[meio].codigo) {
						busca = 1;
						break;
					}
					if (p[meio].codigo < code) {
						inicio = meio + 1;
						} 
					else {
						fim = meio - 1;
					}
				}
				
				if(!busca) { //1.1.2 Mensagem para quando o código não for encontrado.
					printf(" ! - Código inexistente. Aperte Enter para tentar novamente."); 
					while(getchar()!='\n');
					getchar();
					continue;
				}
			
				menu = 2;
			}
			while(menu==2) {
				system("clear");
				printf("== DADOS DO PRODUTO ==\n\n");
				// 1.1.1 Imprime todos os dados do produto.
				printf(" =================================\n"); 
				printf("\n CÓDIGO: [%d]\n DESCRIÇÃO: %s\n",
				p[meio].codigo,
				p[meio].descricao);
				printf(" ESTOQUE: %d disponíve",  p[meio].estoque);
				(p[meio].estoque!=1)? printf("is") : printf("l");
				printf("\n PREÇO: R$%.2f\n\n", p[meio].valor );
				printf(" =================================\n\n");
				printf("== CARRINHO ==\n\n");
				int carrinho;
				printf("* - Digite a quantidade desejada desse produto no carrinho: ");
				scanf(" %d", &carrinho);
				if (carrinho < 0) {
					printf("! - Quantidade inválida. Aperte Enter para tentar novamente.");
					while(getchar()!='\n');
					getchar();
					continue;
				}
				
				if (carrinho > p[meio].estoque) {
					printf("! - Estoque insuficiente. Aperte Enter para tentar novamente.");
					while(getchar()!='\n');
					getchar();
					continue;
				}
				
				(carrinho) ? printf("$ - Adicionado ao carrinho com sucesso! ") : printf(" * - "); 
				printf("Aperte Enter para prosseguir.");
				subtotal+= p[meio].valor * carrinho;
				p[meio].estoque-= carrinho;
				while(getchar()!='\n');
				getchar();
				menu=1;
				continue;
			
			}
			
			while (menu==3) {
				float pagamento;
				system("clear");
				printf("== TOTAL DO CARRINHO ==\n\n");
				do {
					printf("Insira o valor que será pago: R$");
					scanf(" %f", &pagamento);
					if(pagamento>=subtotal)
						break;
					printf("Não fazemos fiado! ");
				} while (1);
				
				system("clear");
				printf("== TOTAL DO CARRINHO ==\n\n");
				printf("* - Valor total da venda: R$%.2f\n * - Valor pago: R$%.2f\n * - Valor do troco: %.2f\n", subtotal, pagamento, pagamento-subtotal);
				char ciclo;
				total+= subtotal;
				subtotal=0;
				vendas++;
				printf("\n Digite + para o próximo ciclo de carrinho ou digite qualquer outra tecla para finalizar o dia: ");
				while(getchar()!='\n');
				scanf(" %c", &ciclo);
				if(ciclo=='+') {
					menu=1;
					continue;
				} else menu=4;
			}
		
			if(menu==4)
				break;
			
		}
		system("clear");
		printf("== RELATÓRIO ATUALIZADO DOS PRODUTOS ==\n");
		for (int i = 0; i < qtd; i++) {
				printf("\n CÓDIGO: [%d]\n DESCRIÇÃO: %s\n",
					p[i].codigo,
					p[i].descricao);
				printf(" ESTOQUE: %d disponíve",  p[i].estoque);
				(p[i].estoque!=1)? printf("is") : printf("l");
				printf("\n PREÇO: R$%.2f\n\n", p[i].valor );
				printf(" =================================\n");
			}
			
		printf(" FATURAMENTO DO DIA: R$%.2f", total);
			return 0;
			
	}
	
}

