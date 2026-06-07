#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char[50] nome;
    int numero;
} produto;

int main(){

    FILE *arquivo = fopen("teste.txt", "r");
    produto *produto = NULL;

    int id, numero;
    char[50] nome;
    int total = 0;

    while(fscanf(arquivo,"%d %s %d", &id, nome, &numero)==3){
        produtos = realloc(produtos, sizeof(produto) * (total + 1));

        produto.produto[total].id = id;

    }
    fclose(arquivo);


    
    return 0;

}