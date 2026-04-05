#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    char mat[100][101];
    for (int i = 0; i < m; i++)
        scanf("%s", mat[i]);
    
    //copia do vetor mat
    char res[100][101];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = mat[i][j];
            
            
    //Vetor para direções r(esquerda,direita,cima, baixo) c(diagonais)
    int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 'P') {
                // Marcar cruz
                for (int d = 0; d < 4; d++) {
                    int ni = i + dr[d], nj = j + dc[d];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && mat[ni][nj] == '-')
                        res[ni][nj] = '+';
                }
                // Marcar diagnonais
                for (int d = 4; d < 8; d++) {
                    int ni = i + dr[d], nj = j + dc[d];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && mat[ni][nj] == '-' && res[ni][nj] != '+')
                        res[ni][nj] = 'x';
                }
            }
        }
    }
    
    //print de linha por linha
    for (int i = 0; i < m; i++)
        printf("%s\n", res[i]);
    
    return 0;
}