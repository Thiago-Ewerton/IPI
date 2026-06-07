#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct para representar cada produto do arquivo mestre
typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

// Struct para registrar as inconsistências que vão para o relatório
typedef struct {
    int codigo;
    char tipo;
    int qtd;
    char motivo[30];
} Inconsistencia;

int main() {
    // ABERTURA E VALIDAÇÃO DOS ARQUIVOS DE ENTRADA

    FILE *f_produtos = fopen("produtos.txt", "r");
    FILE *f_movimentos = fopen("movimentos.txt", "r");

    if (f_produtos == NULL || f_movimentos == NULL) {
        printf("Erro ao abrir arquivo.\n");
        // Se um abriu e o outro não, garante o fechamento correto antes de fechar o programa
        if (f_produtos != NULL) fclose(f_produtos);
        if (f_movimentos != NULL) fclose(f_movimentos);
        return 1;
    }


    // LEITURA DO ARQUIVO MESTRE (produtos.txt)

    Produto *produtos = NULL;
    int total_produtos = 0;

    int prod_cod, prod_qtd;
    char prod_nome[50];
    float prod_preco;

    // Le linha por linha 
    while (fscanf(f_produtos, "%d %s %d %f", &prod_cod, prod_nome, &prod_qtd, &prod_preco) == 4) {
        produtos = realloc(produtos, (total_produtos + 1) * sizeof(Produto));
        
        produtos[total_produtos].codigo = prod_cod;
        strcpy(produtos[total_produtos].nome, prod_nome);
        produtos[total_produtos].quantidade = prod_qtd;
        produtos[total_produtos].preco = prod_preco;
        
        total_produtos++;
    }
    fclose(f_produtos); // Fechando o arquivo


    // PROCESSAMENTO DOS MOVIMENTOS

    Inconsistencia *inconsistencias = NULL;
    int total_inconsistencias = 0;

    int mov_cod, mov_qtd;
    char mov_tipo;

    // Contadores para o relatório
    int mov_aplicados = 0;
    int saidas_recusadas = 0;
    int mov_sem_cadastro = 0;

    /
    while (fscanf(f_movimentos, "%d %c %d", &mov_cod, &mov_tipo, &mov_qtd) == 3) {
        int indice_encontrado = -1;

        // Busca o produto correspondente no vetor em memória
        for (int i = 0; i < total_produtos; i++) {
            if (produtos[i].codigo == mov_cod) {
                indice_encontrado = i;
                break;
            }
        }

        // Regra: Movimento com código inexistente
        if (indice_encontrado == -1) {
            mov_sem_cadastro++;
            
            // Registra a inconsistência na lista
            inconsistencias = realloc(inconsistencias, (total_inconsistencias + 1) * sizeof(Inconsistencia));
            inconsistencias[total_inconsistencias].codigo = mov_cod;
            inconsistencias[total_inconsistencias].tipo = mov_tipo;
            inconsistencias[total_inconsistencias].qtd = mov_qtd;
            strcpy(inconsistencias[total_inconsistencias].motivo, "PRODUTO_INEXISTENTE");
            total_inconsistencias++;
        } 
        // Se o produto existir, processa as regras de negócio
        else {
            if (mov_tipo == 'E') {
                produtos[indice_encontrado].quantidade += mov_qtd;
                mov_aplicados++;
            } 
            else if (mov_tipo == 'S') {
                // Regra: Estoque suficiente para saída
                if (produtos[indice_encontrado].quantidade >= mov_qtd) {
                    produtos[indice_encontrado].quantidade -= mov_qtd;
                    mov_aplicados++;
                } 
                // Regra: Estoque insuficiente
                else {
                    saidas_recusadas++;
                    
                    // Registra a inconsistência na lista
                    inconsistencias = realloc(inconsistencias, (total_inconsistencias + 1) * sizeof(Inconsistencia));
                    inconsistencias[total_inconsistencias].codigo = mov_cod;
                    inconsistencias[total_inconsistencias].tipo = mov_tipo;
                    inconsistencias[total_inconsistencias].qtd = mov_qtd;
                    strcpy(inconsistencias[total_inconsistencias].motivo, "ESTOQUE_INSUFICIENTE");
                    total_inconsistencias++;
                }
            }
        }
    }
    fclose(f_movimentos); // Fechar arquivo dos movimentos


    // GRAVAÇÃO DO ESTOQUE ATUALIZADO 

    FILE *f_estoque = fopen("estoque_atualizado.txt", "w");
    for (int i = 0; i < total_produtos; i++) {
        fprintf(f_estoque, "%d %s %d %.2f\n", 
                produtos[i].codigo, produtos[i].nome, 
                produtos[i].quantidade, produtos[i].preco);
    }
    fclose(f_estoque);

  
    // GRAVAÇÃO DO RELATÓRIO (relatorio.txt)

    FILE *f_relatorio = fopen("relatorio.txt", "w");
    
    // (1) ao (4): Estatísticas gerais
    fprintf(f_relatorio, "PRODUTOS PROCESSADOS: %d\n", total_produtos);
    fprintf(f_relatorio, "MOVIMENTOS APLICADOS: %d\n", mov_aplicados);
    fprintf(f_relatorio, "SAIDAS RECUSADAS: %d\n", saidas_recusadas);
    fprintf(f_relatorio, "MOVIMENTOS SEM CADASTRO: %d\n", mov_sem_cadastro);
    
    // (5): Lista de estoque baixo
    fprintf(f_relatorio, "ESTOQUE BAIXO:\n");
    for (int i = 0; i < total_produtos; i++) {
        if (produtos[i].quantidade <= 5) {
            fprintf(f_relatorio, "%d %s %d\n", 
                    produtos[i].codigo, produtos[i].nome, produtos[i].quantidade);
        }
    }

    // (6): Lista de inconsistências encontradas
    fprintf(f_relatorio, "INCONSISTENCIAS:\n");
    for (int i = 0; i < total_inconsistencias; i++) {
        fprintf(f_relatorio, "%d %c %d %s\n", 
                inconsistencias[i].codigo, inconsistencias[i].tipo, 
                inconsistencias[i].qtd, inconsistencias[i].motivo);
    }
    fclose(f_relatorio);

    
    // LIMPEZA DE MEMÓRIA
    free(produtos);
    free(inconsistencias);

    printf("Processamento concluido com sucesso!\n");
    return 0;
}
