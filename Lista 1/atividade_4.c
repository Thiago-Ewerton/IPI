#include <stdio.h>
#include <stdlib.h>

int main(){

    int x, y, c;

    scanf("%d %d %d", &x, &y, &c);

    int passosX, passosY;

    if(x > 0 && y > 0){
        // Q1 -> Q3, destino (-1,-1)
        passosX = abs(x) + 1;
        passosY = abs(y) + 1;
        if (c == 2){
            printf("%d passos em y e %d passos em x\n", passosY, passosX);
        }
        else if (c == 4){
            printf("%d passos em x e %d passos em y\n", passosX, passosY);
        }
        else {
            printf("caminhada invalida\n");
        }
    }
    else if(x < 0 && y > 0){
        // Q2 -> Q4, destino (1,-1)
        passosX = abs(x) - 1;
        passosY = abs(y) + 1;
        if (c == 1){
            printf("%d passos em y e %d passos em x\n", passosY, passosX);
        }
        else if (c == 3){
            printf("%d passos em x e %d passos em y\n", passosX, passosY);
        }
        else {
            printf("caminhada invalida\n");
        }
    }
    else if(x < 0 && y < 0){
        // Q3 -> Q1, destino (1,1)
        passosX = abs(x) - 1;
        passosY = abs(y) - 1;
        if (c == 2){
            printf("%d passos em x e %d passos em y\n", passosX, passosY);
        }
        else if (c == 4){
            printf("%d passos em y e %d passos em x\n", passosY, passosX);
        }
        else {
            printf("caminhada invalida\n");
        }
    }
    else if(x > 0 && y < 0){
        // Q4 -> Q2, destino (-1,1)
        passosX = abs(x) + 1;
        passosY = abs(y) - 1;
        if (c == 1){
            printf("%d passos em x e %d passos em y\n", passosX, passosY);
        }
        else if (c == 3){
            printf("%d passos em y e %d passos em x\n", passosY, passosX);
        }
        else {
            printf("caminhada invalida\n");
        }
    }
    else {
        printf("caminhada invalida\n");
    }

    return 0;
}