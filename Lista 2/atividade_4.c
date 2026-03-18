#include<stdio.h>

int main(){

    int q;
    int x;
    char c;
    int espaco = 0;
    char ultimo = 'X';

    scanf("%d", &q);

    for(int j = 0; j < q; j++){

        scanf("%d %c", &x, &c);

        if(c == 'D'){

            if(espaco == 0 && ultimo != 'B'){ 
                for(int i= 0; i < x; i++){
                    printf(".");
                    espaco++;
                }
            } else {
                for(int i= 0; i < espaco; i++){
                    printf(" ");
                }

                if(ultimo == 'B'){
                    printf(".");
                    espaco++;
                }

                for(int i= 0; i < x; i++){
                    printf(".");
                    espaco++;
                }
            }

            ultimo = 'D';
            espaco--;

        } else if(c == 'E'){

            if(x > espaco){
                printf("Informacao invalida");
            }

            else{

                 espaco = espaco - x;

                for(int i= 0; i < espaco; i++){
                    printf(" ");
                }
                for(int i= 0; i < x; i++){
                    printf(".");   
                }  
            
                if(ultimo == 'B'){
                    printf(".");
                }
            }

            ultimo = 'E';
        


        } else if(c == 'B'){

            if(x != 1){

            for(int k = 0; k < x-1; k++){
            
                printf("\n");

                for(int i = 0; i < espaco; i++){
                    printf(" ");
                }

                printf(".");
            }
            printf("\n");

        } else{

            printf("\n");
        }
            ultimo = 'B';

        }
    }

    if(ultimo == 'B'){
        for(int i = 0; i < espaco; i++){
            printf(" ");

        }
        printf(".");

    }

    return 0;
}