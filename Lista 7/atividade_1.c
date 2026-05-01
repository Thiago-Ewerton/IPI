#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Struct para representar um jogo
typedef struct {
    char titulo[50];
    char genero[50];
    char estudio[50];
    char console[50];
    int nota;
    int ano;
} Jogo;


void printAno(Jogo *jogos, int n, int ano) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (jogos[i].ano == ano) {
            printf("%s\n", jogos[i].titulo);
            count++;
        }
    }
    if (count > 0)
        printf("Tenho %d jogos || %d.\n", count, ano);
    else
        printf("Nenhum jogo tem esse parâmetro Sr Sr Wilson.\n");
}

void printLetra(Jogo *jogos, int n, char letra) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (jogos[i].titulo[0] == letra) {
            printf("%s\n", jogos[i].titulo);
            count++;
        }
    }
    if (count > 0)
        printf("Tenho %d jogos || %c.\n", count, letra);
    else
        printf("Nenhum jogo tem esse parâmetro Sr Sr Wilson.\n");
}

void printStudio(Jogo *jogos, int n, char *studio) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(jogos[i].estudio, studio) == 0) {
            printf("%s\n", jogos[i].titulo);
            count++;
        }
    }
    if (count > 0)
        printf("Tenho %d jogos || %s.\n", count, studio);
    else
        printf("Nenhum jogo tem esse parâmetro Sr Sr Wilson.\n");
}

void printConsole(Jogo *jogos, int n, char *console) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(jogos[i].console, console) == 0) {
            printf("%s\n", jogos[i].titulo);
            count++;
        }
    }
    if (count > 0)
        printf("Tenho %d jogos || %s.\n", count, console);
    else
        printf("Nenhum jogo tem esse parâmetro Sr Sr Wilson.\n");
}

void printColecao(Jogo *jogos, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", jogos[i].titulo, jogos[i].nota);
    }
}


int main(){
    int N;

    scanf("%d", &N);

    Jogo jogos[MAX];

    //Cadastro no struct

    for(int i = 0; i < N; i++){
        scanf("%s %s %s %s %d %d", jogos[i].titulo, jogos[i].genero, jogos[i].estudio, jogos[i].console, &jogos[i].nota, &jogos[i].ano);


        if (jogos[i].nota > 7) printf("AWESOME! Mais um GOTY pra minha coleção!\n");
        if (jogos[i].nota < 4) printf("Era melhor jogar mais um jogo de Mahjong.\n");

    }

    char comando[30];

    // Leitura até EOF
    while (scanf("%s", comando) != EOF) {

        if(strcmp(comando, "printAno") == 0){
            int ano;
            scanf("%d", &ano);
            printAno(jogos, N, ano);
        }

        else if(strcmp(comando, "printLetra") == 0){
            char letra;
            scanf(" %c", &letra);
            printLetra(jogos, N, letra);
        }

        else if(strcmp(comando, "printStudio")==0){
            char studio[50];
            scanf("%s", studio);
            printStudio(jogos, N, studio);
        }

        else if (strcmp(comando, "printConsole")==0){
            char console[50];
            scanf("%s", console);
            printConsole(jogos, N, console);
        }
        else if (strcmp(comando, "printColecao") == 0) {
            printColecao(jogos, N);
        }
    }

    printf("Enjoei de jogar, agora vou ver TV.\n");



    return 0;
}

