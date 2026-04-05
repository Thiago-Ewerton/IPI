#include<stdio.h>


int main(){

    int N, X, Y;
    int horario_real = 7*60;
    int latas = 50;
    

    scanf("%d", &N);
    scanf("%d", &X);
    scanf("%d", &Y);

    int horario_sistema[1000];
    int latas_sistema[1000];

    
    for (int i = 0; i < Y; i++) {
        int h, m, latas;
        scanf("%d:%d %d", &h, &m, &latas);
        horario_sistema[i] = h * 60 + m;
        latas_sistema[i] = latas;
    }

    for (int i = 0; i < N; i++){

        if(i%x == 0){
            latas--;

            if horario_real 

        }





        horario_real = horario_real + 3;

    }


       

    


}