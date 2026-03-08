#include <stdio.h>
#include <stdlib.h>

int main(){

    int x, y, c;

    scanf("%d %d %d", &x, &y, &c);

    // Calculamos a distância para todos os destinos de uma vez
    int passosX_pos = abs(1 - x);   // distância de x até 1  (destinos Q1 e Q4)
    int passosX_neg = abs(-1 - x);  // distância de x até -1 (destinos Q2 e Q3)
    int passosY_pos = abs(1 - y);   // distância de y até 1  (destinos Q1 e Q2)
    int passosY_neg = abs(-1 - y);  // distância de y até -1 (destinos Q3 e Q4)

    if(x > 0 && y > 0){
        // Q1 -> Q3, destino (-1,-1), adjacentes: Q2 e Q4
        if (c == 2){
            // Evita Q2: move Y primeiro, depois X
            printf("%d passos em y e %d passos em x\n", passosY_neg, passosX_neg);
        }
        else if (c == 4){
            // Evita Q4: move X primeiro, depois Y
            printf("%d passos em x e %d passos em y\n", passosX_neg, passosY_neg);
        }
        else {
            printf("caminhada invalida\n");
        }
    }
    else if(x < 0 && y > 0){
        // Q2 -> Q4, destino (1,-1), adjacentes: Q1 e Q3
        if (c == 1){
            // Evita Q1: move Y primeiro, depois X
            printf("%d passos em y e %d passos em x\n", passosY_neg, passosX_pos);
        }
        else if (c == 3){
            // Evita Q3: move X primeiro, depois Y
            printf("%d passos em x e %d passos em y\n", passosX_pos, passosY_neg);
        }
        else {
            printf("caminhada invalida\n");
        }
    }
    else if(x < 0 && y < 0){
        // Q3 -> Q1, destino (1,1), adjacentes: Q2 e Q4
        if (c == 2){
            // Evita Q2: move X primeiro, depois Y
            printf("%d passos em x e %d passos em y\n", passosX_pos, passosY_pos);
        }
        else if (c == 4){
            // Evita Q4: move Y primeiro, depois X
            printf("%d passos em y e %d passos em x\n", passosY_pos, passosX_pos);
        }
        else {
            printf("caminhada invalida\n");
        }
    }
    else if(x > 0 && y < 0){
        // Q4 -> Q2, destino (-1,1), adjacentes: Q1 e Q3
        if (c == 1){
            // Evita Q1: move X primeiro, depois Y
            printf("%d passos em x e %d passos em y\n", passosX_neg, passosY_pos);
        }
        else if (c == 3){
            // Evita Q3: move Y primeiro, depois X
            printf("%d passos em y e %d passos em x\n", passosY_pos, passosX_neg);
        }
        else {
            printf("caminhada invalida\n");
        }
    }
    else {
        // x=0 ou y=0: Mario está sobre um eixo, inválido
        printf("caminhada invalida\n");
    }

    return 0;
}