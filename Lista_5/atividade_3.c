#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v = NULL;
    int tamanho = 0;
    int x;

    // Leitura até EOF
    while (scanf("%d", &x) == 1) {
        int *temp = realloc(v, (tamanho + 1) * sizeof(int));
        if (!temp) { //Boas práticas
            free(v);
            return 1;
        }

        v = temp;
        v[tamanho] = x;
        tamanho++;
    }

    printf("Mais um bom dia de trabalho!\n");

    // Ímpares
    for (int i = 0; i < tamanho; i++) {
        if (v[i] % 2 != 0) {
            printf("%d\n", v[i]);
        }
    }

    // Pares
    for (int i = 0; i < tamanho; i++) {
        if (v[i] % 2 == 0) {
            printf("%d\n", v[i]);
        }
    }

    printf("Vou visitar esses lugares de novo... algum dia.\n");

    free(v);
    return 0;
}