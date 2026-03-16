#include <stdio.h>

int main(){

    int N, K, P;
    scanf("%d %d %d", &N, &K, &P);

    int primeiro = -1;
    int Q = 0;

    for(int i = N; i < K; i++){

        int temp = i; // Copia do i vara verificações
        int fatores = 0;
        int invalido = 0; //flag

        // remove todos os fatores 2
        while(temp % 2 == 0 && temp > 0){
            temp /= 2;
        }

        // verifica fatores ímpares pela raiz
        for(int d = 3; d * d <= temp; d += 2){

            if(temp % d == 0){

                fatores++;
                temp /= d;

                // se repetir fator primo ímpar vai para o break
                if(temp % d == 0){
                    invalido = 1;
                    break;
                }

                while(temp % d == 0){
                    temp /= d;
                }
            }
        }

        // se sobrou primo ímpar
        if(temp > 1){
            fatores++;
        }

        // Verificação se achou o número 
        if(!invalido && fatores == P){

            if(primeiro == -1){
                primeiro = i;
            } else {
                Q++;
            }
        }
    }

    if(primeiro == -1){
        printf("Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.");
    } else {
        printf("%d %d", primeiro, Q);
    }

    return 0;
}