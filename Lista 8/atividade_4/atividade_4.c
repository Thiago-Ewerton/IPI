#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float sl, sw, pl, pw; // sepal_length, sepal_width, petal_length, petal_width
    char sp[50];          // species
} Iris;

int main() {
    int qtd_arquivos;
    scanf("%d", &qtd_arquivos);

    for (int f_idx = 1; f_idx <= qtd_arquivos; f_idx++) {
        char nome[30];
        sprintf(nome, "iris%d.csv", f_idx);

        // 1. LEITURA E EXIBIÇÃO
        FILE *f = fopen(nome, "r");
        char linha[256];
        
        fgets(linha, sizeof(linha), f); // Ignora/Lê o cabeçalho
        printf("\n=== %s ===\n%s", nome, linha);

        Iris *dados = NULL;
        int total = 0;

        while (fgets(linha, sizeof(linha), f)) {
            printf("%s", linha); // Exibe a linha no terminal
            
            // Realoca a memória para +1 elemento a cada linha lida
            dados = realloc(dados, (total + 1) * sizeof(Iris));
            
            // Extrai os dados da linha CSV
            sscanf(linha, "%f,%f,%f,%f,%[^,\n\r]", 
                   &dados[total].sl, &dados[total].sw, 
                   &dados[total].pl, &dados[total].pw, dados[total].sp);
            total++;
        }
        fclose(f); // Fecha logo após a leitura

        // 2. CÁLCULO DAS MÉDIAS
        float som_sl = 0, som_sw = 0, som_pl = 0, som_pw = 0;
        for (int i = 0; i < total; i++) {
            som_sl += dados[i].sl; som_sw += dados[i].sw;
            som_pl += dados[i].pl; som_pw += dados[i].pw;
        }

        // 3. CÁLCULO DA MODA (Com desempate alfabético)
        char moda[50] = "";
        int max_freq = -1;
        for (int i = 0; i < total; i++) {
            int freq = 0;
            for (int j = 0; j < total; j++) {
                if (strcmp(dados[i].sp, dados[j].sp) == 0) freq++;
            }
            // Se achar maior frequência, ou mesma frequência mas menor alfabeticamente
            if (freq > max_freq || (freq == max_freq && strcmp(dados[i].sp, moda) < 0)) {
                max_freq = freq;
                strcpy(moda, dados[i].sp);
            }
        }

        // 4. GRAVAÇÃO NO FINAL DO ARQUIVO ORIGINAL
        f = fopen(nome, "a");
        fprintf(f, "\n--- Estatisticas ---\n");
        fprintf(f, "Media sepal_length: %.2f\n", som_sl / total);
        fprintf(f, "Media sepal_width: %.2f\n", som_sw / total);
        fprintf(f, "Media petal_length: %.2f\n", som_pl / total);
        fprintf(f, "Media petal_width: %.2f\n", som_pw / total);
        fprintf(f, "Moda species: %s\n", moda);
        fclose(f);

        free(dados); // Libera a memória para o próximo arquivo do loop
    }
    return 0;
}