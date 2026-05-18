#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

union Pacote {

    uint32_t bruto;

    struct {
        unsigned id : 10;
        unsigned status : 3;
        unsigned bateria : 1;
        signed temperatura : 12;
        unsigned controle : 6;
    } campos;
};

int main() {

    int capacidade = 2;
    int quantidade = 0;

    union Pacote *vetor;

    vetor = malloc(capacidade * sizeof(union Pacote));

    if (vetor == NULL) {
        printf("Erro de memoria\n");
        return 1;
    }

    uint32_t entrada;

    while (1) {

        scanf("%x", &entrada);

        if (entrada == 0)
            break;

        // Vetor cheio
        if (quantidade == capacidade) {

            capacidade *= 2;

            union Pacote *temp;

            temp = realloc(vetor, capacidade * sizeof(union Pacote));

            if (temp == NULL) {
                printf("Erro de realloc\n");
                free(vetor);
                return 1;
            }

            vetor = temp;
        }

        vetor[quantidade].bruto = entrada;

        quantidade++;
    }

    // Processamento
    for (int i = 0; i < quantidade; i++) {

        printf("Pacote [%d] - Dado Bruto: 0x%08X\n",  i + 1, vetor[i].bruto);

        printf("ID do Sensor : %u\n", vetor[i].campos.id);

        printf("Status : %u\n", vetor[i].campos.status);

        printf("Bateria Baixa: ");

        if (vetor[i].campos.bateria)
            printf("SIM (ALERTA)\n");
        else
            printf("Nao\n");

        printf("Temperatura : %d graus\n", vetor[i].campos.temperatura);

        printf("--------------------------------------\n");
    }

    free(vetor);

    return 0;
}