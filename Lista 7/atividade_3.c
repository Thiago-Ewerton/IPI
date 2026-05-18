#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mecha Mecha;

typedef struct {
    char nome[30];
    int atrib1;
    int atrib2;
    void (*subrotina)(Mecha *m, int slot, int input, int *output);
}SubSistema;

struct Mecha {
    int id;
    char modelo[50];
    int energia_atual;
    int num_sistemas;
    int valor_wintermute;
    SubSistema sistemas[];
};

// funções sub-rotinas

void def_func(Mecha *m, int slot, int input, int *output) {
    int dano = input - m->sistemas[slot].atrib1 - (slot * m->sistemas[slot].atrib2);
    *output = (dano < 0) ? 0 : dano;
}

void util_func(Mecha *m, int slot, int input, int *output) {
    int recuperado = m->sistemas[slot].atrib1 + (slot * m->sistemas[slot].atrib2);
    m->energia_atual += recuperado;
    *output = m->energia_atual;
}

void atk_func(Mecha *m, int slot, int input, int *output) {
    if (m->energia_atual < m->sistemas[slot].atrib2) {
        *output = -1; // Sinalizador de energia insuficiente
    } else {
        *output = m->sistemas[slot].atrib1 + m->energia_atual + slot - input;
        m->energia_atual -= m->sistemas[slot].atrib2;
    }
}


int main(){
    int N;

    scanf("%d", &N);

    Mecha *esquadrao[N];

    for(int i = 0; i < N; i++){
        int id, energia, Q;
        char modelo[50];
        scanf("%d %s %d %d", &id, modelo, &energia, &Q);

        //Alcar a FAM
        Mecha *novo = malloc(sizeof(Mecha) + (Q * sizeof(SubSistema)));
        novo->id = id;
        strcpy(novo->modelo, modelo);
        novo->energia_atual = energia;
        novo->num_sistemas = Q;

        for (int j = 0; j < Q; j++){
            char tipo; 
            scanf(" %c %s %d %d", &tipo, novo ->sistemas[j].nome, 
                &novo->sistemas[j].atrib1, &novo->sistemas[j].atrib2);

            //Fase de montagem

            if (tipo == 'A') novo->sistemas[j].subrotina = atk_func;
            else if (tipo == 'D') novo -> sistemas[j].subrotina = def_func;
            else if (tipo == 'U') novo -> sistemas[j].subrotina = util_func;

        }

        scanf("%d", &novo->valor_wintermute);

        esquadrao[id] = novo;
    }

  

    //Relatório 

    printf("[RELATORIO DE MISSÃO: OPERAÇÃO LANÇA DE NETUNO]\n");

    for(int i = 0; i < N; i++){
        Mecha *m = esquadrao[i];
        int inicial = m->energia_atual;

        printf("ID: %d | MECHA: %s | ENERGIA: %d\n", m->id, m->modelo, inicial);

        //Combate
    void (*ordem[3])() = {def_func, util_func, atk_func};
        char *labels[3] = {"DEFESA", "UTILIDADE", "ATAQUE"};

        for (int p = 0; p < 3; p++) {
            for (int s = 0; s < m->num_sistemas; s++) {
                if (m->sistemas[s].subrotina == ordem[p]) {
                    int out;
                    m->sistemas[s].subrotina(m, s, m->valor_wintermute, &out);
                    
                    if (p == 0) printf("-> [DEFESA] %s | Dano final sofrido: %d\n", m->sistemas[s].nome, out);
                    else if (p == 1) printf("-> [UTILIDADE] %s | Energia atual: %d\n", m->sistemas[s].nome, out);
                    else if (p == 2) {
                        if (out == -1) printf("-> [ATAQUE] %s | Energia insuficiente!\n", m->sistemas[s].nome);
                        else printf("-> [ATAQUE] %s | Dano causado: %d | Energia restante: %d\n", m->sistemas[s].nome, out, m->energia_atual);
                    }
                }
            }
        }
        printf("ENERGIA FINAL: %d\n-----------------------------------------\n", m->energia_atual);
        free(m);
    }

    printf("Esquadrao pronto para o combate.\n");
    return 0;
}