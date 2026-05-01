#include<stdio.h>
#include<stdlib.h>

//Funções para valores
int calibracao(int v) { return v + 5; }
int saturacao(int v) { return (v > 80) ? 80 : v; }
int amplificador(int v) { return v * 2; }

//Funções para a matriz
int** alocarMatriz(int M, int N){
    int ** matriz = (int**)malloc(M * sizeof(int*));

    for(int i = 0; i < M; i++){
        matriz[i]= (int*)malloc(N * sizeof(int));
    }
    return matriz;
}

void lermatriz(int** matriz, int M, int N){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

//Função única

void modificar(int** matriz, int N, int M, int *pipelone, int qntfiltros, int(*filtros_disp[])(int)){

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            
            // Pega o valor atual da célula
            int valor_atual = matriz[i][j];
            
            // Aplica a sequência de filtros
            for (int p = 0; p < qtd_filtros; p++) {
                int id_filtro = pipeline[p];
                
                // Valida se o ID do filtro é conhecido 
                if (id_filtro >= 1 && id_filtro <= 3) {
                    valor_atual = filtros_disp[id_filtro](valor_atual);
                }
            }
            
            // Atualiza a matriz
            matriz[i][j] = valor_atual;
        }
    }

}


int main(){

    int M, N;

    scanf("%d %d", &M, &N);

    //alocando memoria
    int** matriz = alocarMatriz(M, N);
    
    //lendo matriz
    lerMatriz(matriz, M, N)

    int (*vetorfiltros(4))(int) = {NULL, calibracao, saturacao, amplificador};

    int comando; 

    while(scanf("%d", &comando)== 1 && comando != 0){

        if (comando >= 1 && comando <= 3) {
            int pipeline_simples[1] = { comando };
    }

         if (comando >= 1 && comando <= 3) {
            int pipeline_simples[1] = { comando };
            modificar(matriz, N, M, pipeline_simples, 1, vetor_filtros);
        }

}

else if (comando == 4) {
            int k;
            scanf("%d", &k);
            
            // Aloca o pipeline dinamicamente baseado no tamanho K
            int *pipeline_complexo = (int *)malloc(k * sizeof(int));
            for (int i = 0; i < k; i++) {
                scanf("%d", &pipeline_complexo[i]);
            }
            
            // Executa a modificação e libera o array do pipeline
            modificar(matriz, N, M, pipeline_complexo, k, vetor_filtros);
            free(pipeline_complexo);
        }
    }


    printf("Matriz processada:\n");
    
    int sensor_critico = matriz[0][0];
    int pos_i = 0, pos_j = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d", matriz[i][j]);
            if (j < M - 1) printf(" ");
            
            // Checa sensor critico
            if (matriz[i][j] > sensor_critico) {
                sensor_critico = matriz[i][j];
                pos_i = i;
                pos_j = j;
            }
        }
        printf("\n");
        free(matriz[i]); 
    }
    free(matriz); // Libera os ponteiros das linhas

    print("\n");
    printf("Sensor critico: %d\n", sensor_critico);
    printf("Posicao: (%d,%d)\n", pos_i, pos_j);

return 0;

