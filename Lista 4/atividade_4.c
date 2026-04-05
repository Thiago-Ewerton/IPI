#include <stdio.h>

void buscar(int m, int n, char mapa[m][n+1], int visitado[m][n],
            int l, int c, int dist, int *menor_dist,
            const int dl[], const int dc[]) {

    // fora da matriz
    if (l < 0 || l >= m || c < 0 || c >= n) return;

    // parede ou já visitado
    if (mapa[l][c] == '#' || visitado[l][c]) return;

    // chegou no destino
    if (mapa[l][c] == 'd') {
        if (dist < *menor_dist) {
            *menor_dist = dist;
        }
        return;
    }

    // poda
    if (dist >= *menor_dist) return;

    visitado[l][c] = 1;

    for (int i = 0; i < 4; i++) {
        buscar(m, n, mapa, visitado,
               l + dl[i], c + dc[i],
               dist + 1, menor_dist,
               dl, dc);
    }

    visitado[l][c] = 0; // backtracking
}

int main() {
    int m, n;

    scanf("%dx%d", &m, &n);

    char mapa[m][n+1];
    int visitado[m][n];

    int inicio_l = -1, inicio_c = -1;

    for (int i = 0; i < m; i++) {
        scanf("%s", mapa[i]);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visitado[i][j] = 0;

            if (mapa[i][j] == 'o') {
                inicio_l = i;
                inicio_c = j;
            }
        }
    }

    // vetores de movimento agora no main
    const int dl[] = {-1, 1, 0, 0};
    const int dc[] = {0, 0, -1, 1};

    int menor_dist = m * n;

    buscar(m, n, mapa, visitado, inicio_l, inicio_c, 0,
           &menor_dist, dl, dc);

    if (menor_dist != m * n) {
        printf("Apos correr %d metros e quase desistir por causa da distância, Rebeka conseguiu escapar!\n", menor_dist);
    } else {
        printf("Poxa... Parece que nao foi dessa vez que Rebeka conseguiu fugir\n");
    }

    return 0;
}