/**
* @file Rede Social do BSI.c
* @author @guilhermegcastro
* @date 02.12.2025 12:06:53 -03
* @brief
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USERNAME 15
#define NOME 100
#define SENHA 20
#define MAX_USUARIO 100
#define POST_SIZE_USER 50
#define POST_SIZE MAX_USUARIO*POST_SIZE_USER
#define POST_CHAR 280


typedef struct {
    int postId;
    int userID;
    char usernamePost[USERNAME];
    char conteudo[POST_CHAR];
    } Post;
    
typedef struct {
    int id;
    char username[USERNAME];
    char nome[NOME];
    char senha[SENHA];
    int postcont;
    } Usuario;

int interface() {
    int opcao;
    printf("= REDE SOCIAL =\n"
            "1) Novo Usuário\n"
            "2) Fazer Login\n"
            "3) Fechar Aplicação\n");
    scanf(" %d", &opcao);
    return opcao;
}


void cadastro(Usuario* user, int id, int cont) {
    do {
        printf("Informe o nome do usuário:");
        scanf(" %[^\n]s", user[id].nome);
        if(strlen(user[id].nome) > NOME) {
            printf("\n Nome muito extenso! Tente de novo.\n");
            continue;
        }
        break;
    } while (1);
   
    do {
        printf("Informe o username desejado:");
        scanf(" %s", user[id].username);
        if(strlen(user[id].username)> USERNAME) {
            printf("\n Username muito extenso! Tente de novo.\n");
            continue;
        }
        
        int userDisponivel = 1;
        for (int i = 0; i < cont; i++) {
            if(strcmp(user[i].username, user[id].username)==0 && user[i].id != user[id].id) {
                printf("\n Username indisponível! Tente de novo.\n");
                userDisponivel=0;
                break;
            }
        }
        if (!userDisponivel)
            continue;
        break;
    } while (1);
    
    do {
        printf("Informe a senha desejada:");
        scanf(" %[^\n]s", user[id].senha);
        if(strlen(user[id].senha)> SENHA) {
            printf("\n Senha muito extensa! Tente de novo.\n");
            continue;
        }
        break;
    } while (1);
}
void registrar(Usuario* user, int cont) {
   
    user[cont].id = cont;
    user[cont].postcont = 0;
    cadastro(user, user[cont].id, cont);
    }
    
void alterarDados(Usuario* user, Usuario* allUsers, Post* post, int cont, int pcont) {
    cadastro(allUsers, user->id, cont);
    
    for (int i = 0; i < pcont; i++) {
        if(user->id == post[i].userID) 
            strcpy(post[i].usernamePost, user->username); 
        
    }
}
Usuario* login(Usuario* user, int cont) {
    char username[USERNAME], password[SENHA];
    printf("= LOGIN =\n"
        "Informe os dados de login:\n"
        "Username: ");
    scanf(" %s", username);
    printf("Senha: ");
    scanf(" %s", password);
    
    for (int i = 0; i < cont; i++) {
        if (strcmp(user[i].username, username) == 0 &&
            strcmp(user[i].senha, password) == 0) {
            return &user[i];
        }
    }
   
        return NULL;

}


void novoPost(Usuario* user, int* pcont, Post* post) {
    system("clear");
    do {
        printf("Digite o contéudo do post: ");
        scanf(" %[^\n]s", post[*pcont].conteudo);
        if(strlen(post[*pcont].conteudo) > POST_CHAR) {
            printf("Publicação muito longa! Digite o conteúdo do post em até %d caracteres.", POST_CHAR);
            continue;
        } 
        user->postcont++;
        strcpy(post[*pcont].usernamePost, user->username);
        post[*pcont].userID = user->id;
        post[*pcont].postId = *pcont;
       (*pcont)++;
        break;
        
    } while(1);
    
    
}

void profile(Usuario* user, Post* post, int pcont) {
    system("clear");
    printf("= Seus posts =\n");
    for (int i = pcont-1; i >= 0; i--) {
        if(user->id == post[i].userID) {
            printf("\n Post #%d\n", post[i].postId);
            printf("\"%s\"\n", post[i].conteudo);
            printf("\n============================\n");
        }
    }
    while(getchar()!='\n'); 
    printf("\n Aperte ENTER para voltar a tela inicial.");
    getchar();
}
  
void timeline(Usuario* user, Post* post, int pcont) {
    system("clear");
    printf("= Timeline =\n");
    for (int i = pcont-1; i >= 0; i--) {
        if(user->id != post[i].userID) {
            printf("\n Post #%d\n Autor(a): @%s\n", post[i].postId, post[i].usernamePost);
            printf("\"%s\"\n", post[i].conteudo);
            printf("\n============================\n");
        }
    }
    while(getchar()!='\n'); 
    printf("\n Aperte ENTER para voltar a tela inicial.");
    getchar();
}
    
void excluirPost(Usuario* user, Post* allPosts, int* pcont) {
    system("clear");
    int idpost;
    printf("Informe o número do seu post para ser excluido: > ");
    scanf(" %d", &idpost);
    if(idpost < 0 || idpost > *pcont || allPosts[idpost].userID!= user->id) {
        printf("Post inexistente ou não é de sua autoria. Aperte Enter para prosseguir...\n");
        while(getchar()!='\n');
        getchar();
        return;
    }
    
    for (int id = idpost; id < *pcont-1; id++){
        allPosts[id] = allPosts[id+1];
        allPosts[id].postId--;
    }
    (*pcont)--;
    user->postcont--;
    
    
}
    
void telaPrincipal(Usuario* allUsers, Usuario* user, int cont, int* pcont, Post* allPosts){
    if (user==NULL) {
        printf("Usuário ou senha inválido(s)! Aperte ENTER para prosseguir.");
        while(getchar()!='\n');
        getchar();
        return;
    }
    
    do {
        int opcao;
        system("clear");
        printf("Seja Bem Vindo(a) <<%s>>>\n"
        "4) Novo Post\n"
        "5) Timeline\n"
        "6) Profile\n"
        "7) Excluir Post\n"
        "8) Alterar Dados do Usuário\n"
        "9) Logout\n\n", user->nome);
        printf("Insira a opção desejada: > ");
        scanf(" %d", &opcao);
    
        switch (opcao) {
            case 4: novoPost(user, pcont, allPosts);
                break;
            case 5: timeline(user, allPosts, *pcont);
                break;
           case 6: profile(user, allPosts, *pcont);
                break;
           case 7: excluirPost(user, allPosts, pcont);
               break;
           case 8: alterarDados(user, allUsers, allPosts, cont, *pcont);
                break;
            case 9: return;
                break;
            default:printf("Opção inválida. Aperte Enter para tentar novamente.");
                    while(getchar()!='\n');
                    getchar();
        }
        
    } while (1);
    
    
}
    
int main(){
    Usuario user[100];
    Post postdb[POST_SIZE];
    int cont=0, postcont=0;
    do {
        system("clear");
        switch (interface()) {
        case 1: registrar(user, cont);
                cont++;
            break;
        case 2: telaPrincipal(user, login(user, cont), cont, &postcont, postdb);
                
            break;
        case 3: system("clear");
            printf("Aplicação Finalida.");
            return 0;
        default: printf("Opção inválida. Aperte Enter para tentar novamente.");
            while(getchar()!='\n');
            getchar();
        }
    } while (1);
    return 0;
}


