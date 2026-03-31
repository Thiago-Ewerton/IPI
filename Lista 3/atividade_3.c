#include <stdio.h>

#define MAX 101

int main() {
    char frase[MAX];
    fgets(frase, MAX, stdin);

    int i, j, k;
    int pares = 0;

    // Percorrer primeira palavra
    for (i = 0; frase[i] != '\0'; i++) {

        // Verifica início de palavra
        if ((i == 0 || frase[i-1] == ' ') && frase[i] != ' ' && frase[i] != '\n') {

            int ini1 = i;

            // achar fim da palavra 1
            int fim1 = i;
            while (frase[fim1] != ' ' && frase[fim1] != '\0' && frase[fim1] != '\n') {
                fim1++;
            }

            // Percorrer segunda palavra
            for (j = fim1 + 1; frase[j] != '\0'; j++) {

                if ((j == 0 || frase[j-1] == ' ') && frase[j] != ' ' && frase[j] != '\n') {

                    int ini2 = j;

                    // achar fim da palavra 2
                    int fim2 = j;
                    while (frase[fim2] != ' ' && frase[fim2] != '\0' && frase[fim2] != '\n') {
                        fim2++;
                    }

                    // calcular tamanhos
                    int tam1 = fim1 - ini1;
                    int tam2 = fim2 - ini2;

                    if (tam1 != tam2)
                        continue;

                    int freq[26] = {0};

                    // contar palavra 1
                    for (k = 0; k < tam1; k++) {
                        char c = frase[ini1 + k];
                        if (c >= 'A' && c <= 'Z') c += 32;
                        freq[c - 'a']++;
                    }

                    // subtrair palavra 2
                    for (k = 0; k < tam2; k++) {
                        char c = frase[ini2 + k];
                        if (c >= 'A' && c <= 'Z') c += 32;
                        freq[c - 'a']--;
                    }

                    int eh = 1;
                    for (k = 0; k < 26; k++) {
                        if (freq[k] != 0) {
                            eh = 0;
                            break;
                        }
                    }

                    if (eh) {
                        if (pares == 0) {
                            printf("Pares de anagramas encontrados:\n");
                        }

                        // imprimir palavra 1
                        for (k = ini1; k < fim1; k++)
                            printf("%c", frase[k]);

                        printf(" e ");

                        // imprimir palavra 2
                        for (k = ini2; k < fim2; k++)
                            printf("%c", frase[k]);

                        printf("\n");

                        pares++;
                    }
                }
            }
        }
    }

    if (pares > 0) {
        printf("\nTotal de pares: %d\n", pares);
    } else {
        printf("Nao existem anagramas na frase.\n");
    }

    return 0;
}