#include<stdio.h>

int main(){
    int N, X, Y;
    int hora = 60*7;
    int W,Z, L;
    int latinhas = 50;

    scanf("%d", &N);
    scanf("%d", &X);
    scanf("%d", &Y);

    int horario_compras[1000];
    int latinhas_compradas[1000];

    for(int i= 0; i<Y; i++){
        scanf("%d:%d %d", &W, &Z, &L);

        horario_compras[i] = (W * 60) + Z; 
        latinhas_compradas[i] = L; 
    }

    for(int i = 0; i < N; i++){

        if(X == 0){

            // S considerar a lista em caso de X = 0
            int encontrou = 0;

            for(int j = 0; j < Y; j++){
                if(hora == horario_compras[j]){
                    encontrou = 1;
                    latinhas -= latinhas_compradas[j];
                    break;
                }
            }

        } else {

           
            if(i % X == 0){
                latinhas--;
            }

            int encontrou = 0;
            for(int j = 0; j < Y; j++){
                if(hora == horario_compras[j]){
                    encontrou = 1;
                    latinhas = latinhas - latinhas_compradas[j];
                        if(i % X == 0){ 
                        latinhas++; 
                     }
                    break;
                }
            }
        }

        if(latinhas < 0){
            int hora_print, minuto_print;

            hora_print = hora / 60;
            minuto_print = hora % 60;

            printf("Quem levou a cesta basica foi o %d* cliente atendido por coragem, as %02d:%02d. ", i, hora_print, minuto_print);

            int encontrou = 0;
            for(int j = 0; j < Y; j++){
                if(hora == horario_compras[j]){
                    printf("Que comprou %d latas.", latinhas_compradas[j]);
                    encontrou = 1;
                    break;
                }
            }

            if(!encontrou){
                printf("Que comprou 1 lata.");
            }

            return 0; 
        }

        hora = hora + 3;
    }

    if(latinhas > 0){
        printf("Ainda nao foram vendidas latas suficientes. ");

        (latinhas == 1) ? printf("Falta 1 lata.") : printf("Faltam %d latas.", latinhas);
    }

    return 0;
}