#include <stdio.h>

int main() {
    char pilha[100000];
    int top = -1; // Pilha vazia
    char c;

    
    while (scanf(" %c", &c) != EOF) {
        // Insere o elemento no topo
        pilha[++top] = c;

        // Processa as combinações e destruições
        int mudou = 1;
        while (mudou) {
            mudou = 0;

            // Regra: 3 blocos iguais juntos no topo são destruídos
            if (top >= 2 && pilha[top] == pilha[top-1] && pilha[top] == pilha[top-2]) {
                top -= 3;
                mudou = 1;
            }
            // Regras de combinação de duas cores no topo
            else if (top >= 1) {
                char b1 = pilha[top-1];
                char b2 = pilha[top];

                // Verde (g) + Azul (b) = Ciano (c)
                if ((b1 == 'g' && b2 == 'b') || (b1 == 'b' && b2 == 'g')) {
                    top -= 1;
                    pilha[top] = 'c';
                    mudou = 1;
                }
                // Vermelho (r) + Azul (b) = Magenta (m)
                else if ((b1 == 'r' && b2 == 'b') || (b1 == 'b' && b2 == 'r')) {
                    top -= 1;
                    pilha[top] = 'm';
                    mudou = 1;
                }
                // Vermelho (r) + Verde (g) = Amarelo (y)
                else if ((b1 == 'r' && b2 == 'g') || (b1 == 'g' && b2 == 'r')) {
                    top -= 1;
                    pilha[top] = 'y';
                    mudou = 1;
                }
            }
        }

        // FORMATAÇÃO DE SAÍDA:
        if (top == -1) {
            printf("Pilha vazia!\n\n"); 
        } else {
            // 
            for (int i = top; i >= 0; i--) {
                printf("%c\n", pilha[i]);
            }
            printf("\n"); 
        }
    }

    
    printf("Thank You So Much For Playing My Game!\n");

    return 0;
}