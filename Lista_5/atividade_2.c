#include <stdio.h>
#include <stdlib.h>

// ---------- FUNÇÕES ----------

// Média
float media(float *v, int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) soma += v[i];
    return soma / n;
}

// Maior nota + índice
void maior(float *v, int n, float *valor, int *indice) {
    *valor = v[0];
    *indice = 0;

    for (int i = 1; i < n; i++) {
        if (v[i] > *valor) {
            *valor = v[i];
            *indice = i;
        }
    }
}

// Menor nota + índice
void menor(float *v, int n, float *valor, int *indice) {
    *valor = v[0];
    *indice = 0;

    for (int i = 1; i < n; i++) {
        if (v[i] < *valor) {
            *valor = v[i];
            *indice = i;
        }
    }
}

// Contar acima da média
int acima_media(float *v, int n, float m) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > m) cont++;
    }
    return cont;
}

// Ordenar (bubble sort simples)
void ordenar(float *v, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                float temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

// Mediana
float mediana(float *v, int n) {
    float *copia = malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) copia[i] = v[i];

    ordenar(copia, n);

    float med;
    if (n % 2 == 1) {
        med = copia[n / 2];
    } else {
        med = (copia[n / 2 - 1] + copia[n / 2]) / 2;
    }

    free(copia);
    return med;
}

// Moda
void moda(float *v, int n) {
    int maxFreq = 0;
    float moda = 0;
    int unica = 1;

    for (int i = 0; i < n; i++) {
        int freq = 0;
        for (int j = 0; j < n; j++) {
            if (v[i] == v[j]) freq++;
        }

        if (freq > maxFreq) {
            maxFreq = freq;
            moda = v[i];
            unica = 1;
        } else if (freq == maxFreq && v[i] != moda) {
            unica = 0;
        }
    }

    if (maxFreq <= 1 || !unica) {
        printf("Moda: Nao ha moda unica\n");
    } else {
        printf("Moda: %.2f\n", moda);
    }
}

// Relatório
void relatorio(float *v, int n) {
    float m = media(v, n);

    float max, min;
    int iMax, iMin;

    maior(v, n, &max, &iMax);
    menor(v, n, &min, &iMin);

    printf("Media: %.2f\n", m);
    printf("Maior nota: %.2f (aluno %d)\n", max, iMax + 1);
    printf("Menor nota: %.2f (aluno %d)\n", min, iMin + 1);
    printf("Acima da media: %d\n", acima_media(v, n, m));
    printf("Mediana: %.2f\n", mediana(v, n));
    moda(v, n);
}

// ---------- MAIN ----------

int main() {
    int n;
    scanf("%d", &n);

    float *notas = malloc(n * sizeof(float));

    for (int i = 0; i < n; i++) {
        scanf("%f", &notas[i]);
    }

    // Relatório inicial
    printf("Relatorio inicial\n");
    relatorio(notas, n);

    int k;
    scanf("%d", &k);

    // Realloc para novas notas
    float *temp = realloc(notas, (n + k) * sizeof(float));
    if(!temp){
        free(notas);
        exit(1);
    }
    notas = temp;

    for (int i = 0; i < k; i++) {
        scanf("%f", &notas[n + i]);
    }

    n += k;

    printf("\nRelatorio atualizado\n");
    relatorio(notas, n);

    free(notas);
    return 0;
}