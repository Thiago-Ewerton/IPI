#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000  // tamanho máximo de cada string

// Função para fusão de caracteres
void fusao(char *str) {
    int i = 0;
    
    //Procura um igual
    while (str[i] && str[i + 1]) {
        if (str[i] == str[i + 1]) {
            if (str[i] == 'z')
                str[i] = 'a';
            else
                str[i] = str[i] + 1;

            
            int j = i + 1;
            //Puxa a matriz pra esquerda
            while (str[j]) {
                str[j] = str[j + 1];
                j++;
            }

            if (i > 0) i--;
        } else {
            i++;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); // consumir '\n'

    //Fazendo a matriz com memoria estatica ainda por impossibilidade de fazer ponteiro de ponteiro
    char strings[N][MAX];
    int tamanhos[N];

    // leitura das strings
    int c;
    for (int i = 0; i < N; i++) {
        int j = 0;

        while((c = fgetc(stdin)) != '\n' && c != EOF){
            if(j < MAX - 1){
                strings[i][j++] = (char)c;
            }
        }
        strings[i][j] = '\0'; // finaliza a string
        tamanhos[i] = j;
    }

    // Mesclagem por coluna
    char *merged_string = NULL;
    int tamanho = 0;

    int max = 0;
    for (int i = 0; i < N; i++) {
        if (tamanhos[i] > max)
            max = tamanhos[i];
    }

    for (int col = 0; col < max; col++) {
        for (int i = 0; i < N; i++) {
            if (col < tamanhos[i]) {
                char *temp = realloc(merged_string, (tamanho + 1));
                if (!temp) {
                    free(merged_string);
                    exit(1);
                }
                merged_string = temp;
                merged_string[tamanho++] = strings[i][col];
            }
        }
    }

    // adiciona '\0'
    char *temp = realloc(merged_string, (tamanho + 1));
    if (!temp) {
        free(merged_string);
        exit(1);
    }
    merged_string = temp;
    merged_string[tamanho] = '\0';

    printf("%s\n", merged_string);

    //Função da fusão
    fusao(merged_string);

    printf("%s\n", merged_string);
    
    //liberar espaços
    free(merged_string);
    

    return 0;
}