#include <stdio.h>
#include <stdlib.h>


typedef struct Tarefa {
    int id;
    int prioridade;
    struct Tarefa *prox;
} Tarefa;

// Ponteiros auxiliares 
Tarefa *head = NULL;
Tarefa *tail = NULL;

// Função para inserir uma nova tarefa no final da fila 
void inserir(int id, int prioridade) {

    Tarefa *novo = (Tarefa*) malloc(sizeof(Tarefa));
    if (novo == NULL) {
        return; 
    }
    
    novo->id = id;
    novo->prioridade = prioridade;
    novo->prox = NULL;

    // Se a fila estiver vazia, o novo nó será o início e o fim
    if (tail == NULL) {
        head = novo;
        tail = novo;
    } else {
        // Conecta ao final atual e atualiza o ponteiro tail
        tail->prox = novo;
        tail = novo;
    }
}

// Função para remover a tarefa do início da fila 
void remover() {
    if (head == NULL) {
        printf("Fila vazia\n");
        return;
    }

    // Isola o nó do início
    Tarefa *temp = head;
    
    // Imprime os dados da tarefa removida
    printf("Removida: id=%d prioridade=%d\n", temp->id, temp->prioridade);
    
    // Avança o início para a próxima tarefa
    head = head->prox;
    
    // Se a fila ficou vazia, ajusta o tail para NULL
    if (head == NULL) {
        tail = NULL;
    }
    
   
    free(temp);
}

// Função para listar todas as tarefas do início ao fim
void listar() {
    if (head == NULL) {
        printf("Fila vazia\n");
        return;
    }

    Tarefa *atual = head;
    // Percorre a lista até o último elemento
    while (atual != NULL) {
        printf("id=%d prioridade=%d\n", atual->id, atual->prioridade);
        atual = atual->prox;
    }
}

int main() {
    char comando;
    int id, prioridade;

    // Loop de leitura dos comandos até o fim do arquivo ou comando 'F'
    while (scanf(" %c", &comando) != EOF) {
        if (comando == 'F') {
            break;
        }
        
        switch (comando) {
            case 'I':
                scanf("%d %d", &id, &prioridade);
                inserir(id, prioridade);
                break;
            case 'R':
                remover();
                break;
            case 'L':
                listar();
                break;
            default:
                break;
        }
    }

    // Liberar memoria restante
    while (head != NULL) {
        Tarefa *temp = head;
        head = head->prox;
        free(temp);
    }

    return 0;
}