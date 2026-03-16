#include <stdio.h>

int main(){

    int q;
    scanf("%d", &q);

    int pos = 0;  // posição atual do cursor
    int pula_linha =0; //flag do B

    for(int i = 0; i < q; i++){
        int x;
        char c;

        scanf("%d %c", &x, &c);

        if(c == 'D'){

            if (pos != 0){
                for(int j= 0; j < pos; j++){
                    printf(" ");
                }
            }
            for(int j = 0; j < x; j++){
                printf(".");
            }

            pos =+ x;

        } else if (c == 'B'){
            int linha = 0;

            do {
                
                printf("\n");
                for(int k = 0; k < pos; k++){
                    printf(" ");
                }
                printf(".");
                linha++;
                
            } while (linha < x);

            pula_linha = 1;


        } else if (c == 'E'){
            
            pos -= x;

            if (pula_linha == 1){

                x =+ 1;
                pula_linha = 0;
            }

            for (int j = 0; j < pos - x ; j++){
                printf(" ");
            }
            for(int j = 0; j < x; j++){
                printf(".");
            }
            

        }

    }
    return 0;
}