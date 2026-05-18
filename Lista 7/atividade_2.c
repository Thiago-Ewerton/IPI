#include <stdio.h>
#include <string.h> 

typedef struct {
    char nome[205];
    long long pop;
    int perigo;
    char funcao[205];
} Cidadela;

// Função para formatar
void arrumar_letras(char palavra[]) {

    // A primeira letra deve ser maiúscula
    if (palavra[0] >= 'a' && palavra[0] <= 'z') {
        palavra[0] = palavra[0] - 32;
    }
    // O resto deve ser minúscula
    for (int i = 1; palavra[i] != '\0'; i++) {
        if (palavra[i] >= 'A' && palavra[i] <= 'Z') {
            palavra[i] = palavra[i] + 32;
        }
    }
}

// Função do tipo Cidadela para leitura
Cidadela decodificar_mensagem(char linha[]) {
    
    Cidadela c;
    c.pop = 0;
    c.perigo = 0;
    
    int i_nome = 0;
    int i_func = 0;

    for (int i = 0; linha[i]; i++) {

        char letra = linha[i];

        if (i >= 2 && linha[i-1] == ' ' && linha[i-2] == ' ' && letra != ' ' && letra != '\n') {
            c.funcao[i_func++] = letra;
        } else if (letra >= 'A' && letra <= 'Z') {
            c.nome[i_nome++] = letra;
        } else if (letra >= '0' && letra <= '9') {
            c.pop = (c.pop * 10) + (letra - '0');
        } else if (letra == '*') {
            c.perigo++;
        }
    }

    c.nome[i_nome] = '\0';
    c.funcao[i_func] = '\0';

    arrumar_letras(c.nome);
    arrumar_letras(c.funcao);

    return c;
}
// Função para ordenar
void ordenar_lista(Cidadela lista[], int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            int trocar = 0;
            
            // Ordenar por população
            if (lista[j].pop < lista[j+1].pop) {
                trocar = 1;
            } 
            // Empate 1 (periculosidade)
            else if (lista[j].pop == lista[j+1].pop) {
                if (lista[j].perigo < lista[j+1].perigo) {
                    trocar = 1;
                } 
                // Empate 2 (alfabeticamente)
                else if (lista[j].perigo == lista[j+1].perigo) {
                    if (strcmp(lista[j].nome, lista[j+1].nome) > 0) {
                        trocar = 1;
                    }
                }
            }

            if (trocar == 1) {
                Cidadela temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }
    }
}

int main() {

    char linha[250];
    Cidadela lista[1000];
    int total_cidadelas = 0;
    
    long long chave = 0;
    int achou_chave = 0;

    // Lendo as entradas linha por linha
    while (fgets(linha, 250, stdin) != NULL) {
        
        // Verifica se a linha atual tem um '!'
        int eh_especial = 0;
        for (int i = 0; linha[i] != '\0'; i++) {
            if (linha[i] == '!') eh_especial = 1;
        }

        if (eh_especial == 1) {
            achou_chave = 1;
            // Pega apenas os números da mensagem especial para formar a chave
            for (int i = 0; linha[i] != '\0'; i++) {
                if (linha[i] >= '0' && linha[i] <= '9') {
                    chave = (chave * 10) + (linha[i] - '0');
                }
            }
        } else {
            // Se não é a especial, decodifica a cidadela e guarda na lista
            lista[total_cidadelas] = decodificar_mensagem(linha);
            total_cidadelas++;
        }
    }

    // Avaliar a missão
    if (achou_chave == 0) {
        printf("Gingrey ainda não foi achada, vamos esperar mais um pouco.\n");
        return 0;
    }

    ordenar_lista(lista, total_cidadelas);

    // Achar a cidadela que ele está
    Cidadela alvo = lista[chave - 1];

    // Imprimindo o resultado
    printf("Gingrey foi encontrada em %s, uma cidadela com %lld mil habitantes cuja função é %s e periculosidade ", 
            alvo.nome, alvo.pop, alvo.funcao);
            
    for (int i = 0; i < alvo.perigo; i++) {
        printf("*");
    }
    printf(".");

    // Avisos de perigo
    int denso = (alvo.pop >= 1000);
    int perigoso = (alvo.perigo > 3);

    if (denso && perigoso) {
        printf(" Talvez seja melhor desistir...\n");
    } else if (denso) {
        printf(" Um lugar denso, vai ser difícil achar ela.\n");
    } else if (perigoso) {
        printf(" Vai ser complicado entrar lá.\n");
    } else {
        printf("\n");
    }

    return 0;
}