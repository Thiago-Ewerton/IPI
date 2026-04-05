#include <stdio.h>

int main() {
    // Matriz 4x4 representando a cidade
    int cidade[4][4] = {0};
    

    //Variaveis de controle de posição
    int x = 0, y = 0; 
    int max_visitas = 0;
    int manuela_x = 0, manuela_y = 0;
    
    char passo;

    // For principal
    for (int i = 0; i < 20; i++) {
        // Lê cada caractere ignorando os espaços
        scanf(" %c", &passo);
        
        // Atualiza as coordenadas de acordo com a direção
        if (passo == 'c') {
            y--; 
        } else if (passo == 'b') {
            y++; 
        } else if (passo == 'e') {
            x--; 
        } else if (passo == 'd') {
            x++; 
        }
        
        // Limites de segurança da matriz 4x4 
        if (x < 0) x = 0;
        if (x > 3) x = 3;
        if (y < 0) y = 0;
        if (y > 3) y = 3;

        // Adiciona +1 ao local visitado no passo atual
        cidade[y][x]++;
    }

    // Procura na matriz qual foi a coordenada com mais visitas
    for (int i = 0; i < 4; i++) { 
        for (int j = 0; j < 4; j++) { 
            if (cidade[i][j] > max_visitas) {
                max_visitas = cidade[i][j];
                manuela_x = j;
                manuela_y = i;
            }
        }
    }

    // Imprime o resultado final 
    printf("Coordenada X:%d, Y:%d\n", manuela_x, manuela_y);

    return 0;
}