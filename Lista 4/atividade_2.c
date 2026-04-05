#include <stdio.h>

// Função recursiva para trajeto da ágia
void simular_gota(int m, int n, char parede[m][n+1], int l, int c) {
    // caso base, chegou ao final, ou já tiver água
    if (l < 0 || l >= m || c < 0 || c >= n || parede[l][c] == 'o') {
        return;
    }

    // Marca o espaço atual com a gota d'água
    parede[l][c] = 'o';

    // Caso base (chegar ao final)
    if (l + 1 == m) {
        return;
    }

    // Caso tenha obstaculo
    if (parede[l + 1][c] == '#') {
        simular_gota(m, n, parede, l, c - 1); // Espalha para a esquerda
        simular_gota(m, n, parede, l, c + 1); // Espalha para a direita
    } else {
        // Caso não tenha obstáculo, prossegue a gota entrando na função novamente
        simular_gota(m, n, parede, l + 1, c);
    }
}

int main() {
    int m, n;

    scanf("%d %d", &m, &n);

    char parede[m][n+1];
    int inicio_l = -1, inicio_c = -1;

    // Lê a matriz inicial
    for (int i = 0; i < m; i++) {
        scanf("%s", parede[i]);
    }

    // Procura o ponto de origem da goteira
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (parede[i][j] == 'o' || parede[i][j] == 'O') {
                inicio_l = i;
                inicio_c = j;
                // Substitui por '.' temporariamente para que a recursão processe 
                parede[i][j] = '.';
            }
        }
    }

    // Se a goteira foi encontrada inicia a função
    if (inicio_l != -1) {
        simular_gota(m, n, parede, inicio_l, inicio_c);
    }

    // Imprime o resultado final da matriz atualizada
    for (int i = 0; i < m; i++) {
        printf("%s\n", parede[i]);
    }

    return 0;
}