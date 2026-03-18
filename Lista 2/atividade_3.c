#include <stdio.h>

int main(){

    int q;
    int minuto;
    scanf("%d %d", &minuto, &q);

    int melhor_canal = 0;
    int melhor_termo = 0;
    int melhor_indice = 0;
    int melhor_dist = 0;

    for(int i = 0; i < q; i++){

        int a, b;
        scanf("%d %d", &a, &b);

        int anterior = a;
        int atual = b;
        int proximo = 0;

        int indice_anterior = 1;
        int indice_atual = 2;

        while(atual < minuto){

            proximo = anterior + atual;

            anterior = atual;
            atual = proximo;

            indice_anterior = indice_atual;
            indice_atual++;
        }

        int dist1, dist2;

        if(minuto > anterior)
            dist1 = minuto - anterior;
        else
            dist1 = anterior - minuto;

        if(minuto > atual)
            dist2 = minuto - atual;
        else
            dist2 = atual - minuto;

        int escolhido;
        int distEscolhida;
        int indiceEscolhido;

        if(dist1 <= dist2){
            escolhido = anterior;
            distEscolhida = dist1;
            indiceEscolhido = indice_anterior;
        }
        else{
            escolhido = atual;
            distEscolhida = dist2;
            indiceEscolhido = indice_atual;
        }

        if(i == 0){
            melhor_canal = 1;
            melhor_termo = escolhido;
            melhor_indice = indiceEscolhido;
            melhor_dist = distEscolhida;
        }
        else if(distEscolhida < melhor_dist ||
               (distEscolhida == melhor_dist && i+1 > melhor_canal)){

            melhor_canal = i+1;
            melhor_termo = escolhido;
            melhor_indice = indiceEscolhido;
            melhor_dist = distEscolhida;
        }
    }

    // cálculo VIP
    int soma = 0;
    int temp = melhor_termo;

    while(temp > 0){
        soma += temp % 10;
        temp /= 10;
    }

    if(soma > 10){
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d e com o VIP garantido!!!\n", melhor_canal, melhor_indice);
    }
    else{
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d, mas o ingresso VIP n�o vai rolar :(\n", melhor_canal, melhor_indice);
    }

    return 0;
}