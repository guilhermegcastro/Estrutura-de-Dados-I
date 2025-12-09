//REVISÃO FINAL PARA A PROVA #02
//---- SISTEMA ACADÊMICO -------

//1 - CADASTRAR ALUNO
	//MATRICULA(I: AUTOINCREMENTO) 
	//NOME(S)

//2 - CADASTRAR DISCIPLINA
	//CODIGO(I: AUTOINCREMENTO)
	//NOME(S)
	//PERIODO(I)
	//MATRICULAS(I[50])

//3 - MATRICULAR ALUNO
	//MATRICULAR UM ALUNO EM UMA DETERMINADA DISCIPLINA
	//BUSCAR DISCIPLINA E ALUNO ATRAVÉS DE NOMES.
	//SOMENTE 1 MATRICULA POR ALUNO/DISCIPLINA (VALIDAR!)

//4 - CANCELAR MATRICULA (EXCLUIR MATRICULA)
	//EXCLUIR A MATRICULA DE UM DETERMINADO ALUNO 
	//EM UMA DISCIPLINA.

//5 - FAZER CHAMADA
	//SOLICITAR NOME DE DISCIPLINA.
	//LISTAR (EM ORDEM ALFABETICA) OS NOMES DOS ALUNOS
	//MATRICULADOS.
	//NÃO É NECESSÁRIO SALVAR DADOS. APENAS LISTAGEM.

//6 - HISTORICO DO ALUNO
	//SOLICITAR NOME DO ALUNO.
	//LISTAR TODAS AS DISCIPLINAS MATRICULADAS
	//(EM ORDEM DE PERIODO)
	//NÃO É NECESSÁRIO SALVAR DADOS. APENAS LISTAGEM.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MATRI_MAX 50
#define QTD_ALUNO 50
#define QTD_DISCIPLINA 50

typedef struct {
    int matricula;
    char nome[100];
} Aluno;

typedef struct {
    int codigo;
    char nome[100];
    int periodo;
    int matriculas[MATRI_MAX]; 
    int nM;
} Disciplina;


void next(char* message){
    if(message!=NULL)
        printf("%s", message);
    while(getchar()!='\n');
    getchar();
    system("clear");
}

int interface() {
    int op;
    system("clear");
    printf(" 1 - Cadastrar Aluno\n");
    printf(" 2 - Cadastrar Disciplina\n");
    printf(" 3 - Matricular Aluno\n");
    printf(" 4 - Cancelar Matricula\n");
    printf(" 5 - Fazer Chamada\n");
    printf(" 6 - Histórico do Aluno\n");
    printf("Insira a opção desejada: > ");
    scanf(" %d", &op);
    return op;
}

Aluno nomeAluno(Aluno* a) {
   Aluno name;
   printf("Informe o nome do/a aluno/a: ");
   scanf(" %[^\n]", name.nome);  
   return name;
}

void cadastroAluno(Aluno* a, int* mtrc) {

    *a = nomeAluno(a);
    a->matricula = *mtrc; 
    (*mtrc)++;
}

Disciplina nomeDisciplina(Disciplina* d) {
    
    Disciplina name;
    printf("Informe o nome da disciplina: ");
    scanf(" %[^\n]", name.nome);
    return name;
}

void cadastroDisciplina(Disciplina* d, int* disc ){
    system("clear");
    *d = nomeDisciplina(d);
    printf("Informe o número referente ao período da disciplina: ");
    scanf(" %d", &d->periodo);
    d->codigo = *disc;
    (*disc)++;
    d->nM=0;
}

int procurarAluno(Aluno* alvo, Aluno ListaA[], int contA) {
    
    int indiceA = -1;
    for (int i = 0; i < contA; i++) {
        if(!strcmp(alvo->nome, ListaA[i].nome)) {
            indiceA = i;
            break;
        }
    }
    
    return indiceA;
}

int procurarDisciplina(Disciplina* alvo, Disciplina ListaD[], int contD) {
    
    int indiceD = -1;
    for (int i = 0; i < contD; i++) {
        if(!strcmp(alvo->nome, ListaD[i].nome)) {
            indiceD = i;
            break;
        }
    }
    
    return indiceD;
}

void matricularAluno(Aluno* a, Disciplina* d, int contA, int contD ){
    Aluno aluno = nomeAluno(a);
    int iA = (procurarAluno(&aluno,a, contA));
        if(iA<0) {
        next("Aluno não encontrado. Aperte ENTER para voltar ao menu principal.");
        return;
    }
    
    Disciplina disciplina = nomeDisciplina(d);
  
    int iD = (procurarDisciplina(&disciplina,d, contD));
    if(iD<0) {
        next("Disciplina não encontrada. Aperte ENTER para voltar ao menu principal.");
        return;
    }
    
    int jaMatriculado = 0;
    for (int i = 0; i < d[iD].nM; i++){
        if(a[iA].matricula == d[iD].matriculas[i]) {
            jaMatriculado = 1;
            break;
        }
    }
    
    if(jaMatriculado) {
        next("Aluno/a já matriculado/a nessa disciplina. Aperte ENTER para voltar ao menu principal.");
        return;
    }
    
    d[iD].matriculas[d[iD].nM] = a[iA].matricula;
    d[iD].nM++;
    
}

void cancelarMatricula(Aluno* a, Disciplina dis[], int contA, int contD) {
    
   Aluno aluno = nomeAluno(a);
    int iA = (procurarAluno(&aluno,a, contA));
        if(iA<0) {
        next("Aluno não encontrado. Aperte ENTER para voltar ao menu principal.");
        return;
    }
    
    Disciplina disciplina = nomeDisciplina(dis);
  
    int iD = (procurarDisciplina(&disciplina,dis, contD));
    if(iD<0) {
        next("Disciplina não encontrada. Aperte ENTER para voltar ao menu principal.");
        return;
    }
    
    int posicaoTurma = -1;
    
    for (int i = 0; i < dis[iD].nM; i++){
        if (a[iA].matricula == dis[iD].matriculas[i]) {
            posicaoTurma = i;
            break;
        }
    }
    
    if(posicaoTurma<0) {
        printf("Aluno não matriculado nessa disciplina!");
        return;
    }
    
    for (int i = posicaoTurma; i < dis[iD].nM-1; i++) {
        dis[iD].matriculas[i] = dis[iD].matriculas[i+1];
    }
    
    dis[iD].nM--;
    next("Aluno/a removido/a da disciplina com sucesso! Aperte ENTER para prosseguir.");
    return;
    
    
}

void ordenarAlunos(Aluno* a, int totalAluno, Disciplina d) {
  
    Aluno listaTurma[QTD_ALUNO];
    int contTurma=0;
    for (int i = 0; i < d.nM; i++) {
        int matriculaAlvo = d.matriculas[i];
        
           for (int j = 0; j < totalAluno; j++){
                if(matriculaAlvo==a[j].matricula) {
                listaTurma[contTurma] = a[j];
                contTurma++;
                break;
            }
            
        }
     
    }

    for (int i = 0; i < contTurma; i++){
        for (int j = 0; j < contTurma-1; j++){
            if (strcmp(listaTurma[j].nome, listaTurma[j+1].nome)>0){
                Aluno troca = listaTurma[j];
                listaTurma[j] = listaTurma[j+1];
                listaTurma[j+1] = troca;
            }
        }
    }
    
    for (int i = 0; i < d.nM; i++) 
        printf("%s\n", listaTurma[i].nome);
    
    
}

void chamada(Aluno* a, Disciplina* d, int contA, int contD){

    Disciplina disciplina = nomeDisciplina(d);
    int iD = (procurarDisciplina(&disciplina,d, contD));
    if(iD<0) {
        next("Disciplina não encontrada. Aperte ENTER para voltar ao menu principal.");
        return;
    }
    
    ordenarAlunos(a, contA, d[iD]);
    next("Aperte Enter para prosseguir...");
}

void historico(Aluno* a, Disciplina* d, int contA, int contD ) {
    
    Aluno aluno = nomeAluno(a);
    int iA = (procurarAluno(&aluno,a, contA));
        if(iA<0) {
        next("Aluno não encontrado. Aperte ENTER para voltar ao menu principal.");
        return;
    }
    
    Disciplina listaOrdenada[QTD_DISCIPLINA];
    for (int i = 0; i < contD; i++) 
        listaOrdenada[i] = d[i];
    
    
    for (int i = 0; i < contD; i++) {
        
        for (int j = 0; j < contD-1; j++) {
            if(listaOrdenada[j].periodo > listaOrdenada[j+1].periodo) {
                Disciplina troca = listaOrdenada[j];
                listaOrdenada[j] = listaOrdenada[j+1];
                listaOrdenada[j+1] = troca;
            }
        }
    }
    
    for (int i = 0; i < contD; i++){
        for (int j = 0; j < listaOrdenada[i].nM; j++){
            if(a[iA].matricula == listaOrdenada[i].matriculas[j]) {
                printf("%s\n", listaOrdenada[i].nome);
                break;
            }
        }
    }
    
    next("Aperte ENTER para prosseguir...");
    
}
int main(){
    Aluno a[QTD_ALUNO];
    Disciplina d[QTD_DISCIPLINA];
    int aCont=0, dCont=0;
    
    do {
        switch (interface()) {
        case 1: cadastroAluno(&a[aCont], &aCont);
            break;
        case 2: cadastroDisciplina(&d[dCont], &dCont);
            break;
        case 3: matricularAluno(a, d, aCont, dCont);
            break;
        case 4: cancelarMatricula(a, d, aCont, dCont);
            break;
        case 5: chamada(a, d, aCont, dCont);
            break;
        case 6: historico(a, d, aCont, dCont);
            break;
        case 0: printf("acabou.");
            return 0;
        default: next("Opção inválida! Aperte ENTER para prosseguir...");
            break;
        }
    } while (1);
    
    
    
}
