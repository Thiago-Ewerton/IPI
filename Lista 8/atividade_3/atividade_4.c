#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float sl, sw, pl, pw;
    char sp[50];
} Iris;

int main() {
    int qtd_arquivos;
    printf("Digite a quantidade de arquivos: ");
    if (scanf("%d", &qtd_arquivos) != 1) return 1;

    for (int f_idx = 1; f_idx <= qtd_arquivos; f_idx++) {
        char nome[30];
        sprintf(nome, "iris%d.csv", f_idx);

        // LEITURA E EXIBIÇÃO
        FILE *f = fopen(nome, "r");
        
        // Verifica o nome do arquivo (tava dando erro porque tava na pasta errada)
        if (f == NULL) {
            printf("\nO arquivo '%s' nao foi encontrado. \n", nome);
            continue; 
        }

        char linha[256];
        if (!fgets(linha, sizeof(linha), f)) {
            printf("\n[AVISO] O arquivo '%s' esta totalmente vazio. Pulando...\n", nome);
            fclose(f);
            continue;
        }

        printf("\n=== %s ===\n%s", nome, linha);

        Iris *dados = NULL;
        int total = 0;

        while (fgets(linha, sizeof(linha), f)) {
            printf("%s", linha);
            
            Iris *temp = realloc(dados, (total + 1) * sizeof(Iris));
            if (temp == NULL) {
                printf("Erro de memoria!\n");
                free(dados);
                fclose(f);
                return 1;
            }
            dados = temp;
            
            sscanf(linha, "%f,%f,%f,%f,%[^,\n\r]", 
                   &dados[total].sl, &dados[total].sw, 
                   &dados[total].pl, &dados[total].pw, dados[total].sp);
            total++;
        }
        fclose(f);

        // CÁLCULO DAS MÉDIAS
        float som_sl = 0, som_sw = 0, som_pl = 0, som_pw = 0;
        for (int i = 0; i < total; i++) {
            som_sl += dados[i].sl; som_sw += dados[i].sw;
            som_pl += dados[i].pl; som_pw += dados[i].pw;
        }

        // CÁLCULO DA MODA
        char moda[50] = "";
        int max_freq = -1;
        for (int i = 0; i < total; i++) {
            int freq = 0;
            for (int j = 0; j < total; j++) {
                if (strcmp(dados[i].sp, dados[j].sp) == 0) freq++;
            }
            if (freq > max_freq || (freq == max_freq && strcmp(dados[i].sp, moda) < 0)) {
                max_freq = freq;
                strcpy(moda, dados[i].sp);
            }
        }

        // GRAVAÇÃO NO FINAL DO ARQUIVO ORIGINAL
        f = fopen(nome, "a");
        if (f != NULL) {
            fprintf(f, "\n--- Estatisticas ---\n");
            fprintf(f, "Media sepal_length: %.2f\n", som_sl / total);
            fprintf(f, "Media sepal_width: %.2f\n", som_sw / total);
            fprintf(f, "Media petal_length: %.2f\n", som_pl / total);
            fprintf(f, "Media petal_width: %.2f\n", som_pw / total);
            fprintf(f, "Moda species: %s\n", moda);
            fclose(f);
            printf("\nEstatisticas salvas com sucesso em '%s'!\n", nome);
        }

        free(dados);
    }
    return 0;
}