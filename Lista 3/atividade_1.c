#include <stdio.h>

int main(){

    int T;
    scanf("%d", &T);

    while(T--){

        int N;
        scanf("%d", &N);

        int v[100];

        // Lendo a lista
        for(int i = 0; i < N; i++){
            scanf("%d", &v[i]);
        }

        int tam_atual = 1;
        int tam_melhor = 1;

        int inicio_atual = 0;
        int inicio_melhor = 0;

        for(int i = 1; i < N; i++){

            // Se continua decrescente
            if(v[i] < v[i-1]){
                tam_atual++;
            } 
            else {
                // Se parou, verifica se era a melhor
                if(tam_atual > tam_melhor){
                    tam_melhor = tam_atual;
                    inicio_melhor = inicio_atual;
                }

                // Reinicia sequência
                tam_atual = 1;
                inicio_atual = i;
            }
        }

        // Verifica a última sequência
        if(tam_atual > tam_melhor){
            tam_melhor = tam_atual;
            inicio_melhor = inicio_atual;
        }


        if(tam_melhor < 2){
            printf("0");
        } else{

        // Saída
        printf("%d\n", tam_melhor);

        for(int i = 0; i < tam_melhor; i++){
            printf("%d ", v[inicio_melhor + i]);
        }
    }
        printf("\n");
    }

    return 0;
}