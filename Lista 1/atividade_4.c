#include <stdio.h>
#include <stdlib.h>

int main(){

    int x, y, c;
    int passosX, passosY;
    int destinoX, destinoY;

    scanf("%d %d %d", &x, &y, &c);

    if(x > 0 && y > 0){
        // Q1 -> Q3
        destinoX = -1;
        destinoY = -1;

        passosX = abs(x - destinoX);
        passosY = abs(y - destinoY);

        if (c == 2){
            printf("%d passos em y e %d passos em x\n", passosY, passosX);
        }
        else if (c == 4){
            printf("%d passos em x e %d passos em y\n", passosX, passosY);
        }
        else{
            printf("caminhada invalida\n");
        }
    }

    else if(x < 0 && y > 0){
        // Q2 -> Q4
        destinoX = 1;
        destinoY = -1;

        passosX = abs(x - destinoX);
        passosY = abs(y - destinoY);

        if (c == 1){
            printf("%d passos em y e %d passos em x\n", passosY, passosX);
        }
        else if (c == 3){
            printf("%d passos em x e %d passos em y\n", passosX, passosY);
        }
        else{
            printf("caminhada invalida\n");
        }
    }

    else if(x < 0 && y < 0){
        // Q3 -> Q1
        destinoX = 1;
        destinoY = 1;

        passosX = abs(x - destinoX);
        passosY = abs(y - destinoY);

        if (c == 2){
            printf("%d passos em x e %d passos em y\n", passosX, passosY);
        }
        else if (c == 4){
            printf("%d passos em y e %d passos em x\n", passosY, passosX);
        }
        else{
            printf("caminhada invalida\n");
        }
    }

    else if(x > 0 && y < 0){
        // Q4 -> Q2
        destinoX = -1;
        destinoY = 1;

        passosX = abs(x - destinoX);
        passosY = abs(y - destinoY);

        if (c == 1){
            printf("%d passos em x e %d passos em y\n", passosX, passosY);
        }
        else if (c == 3){
            printf("%d passos em y e %d passos em x\n", passosY, passosX);
        }
        else{
            printf("caminhada invalida\n");
        }
    }

    else{
        printf("caminhada invalida\n");
    }

    return 0;
} 