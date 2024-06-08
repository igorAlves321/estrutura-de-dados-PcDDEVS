#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento {
    char nome[50];
    struct elemento* proximo;
} Elemento;

typedef struct {
    Elemento* frente;
    Elemento* tras;
} Fila;

Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    if (fila == NULL) {
        printf("Erro ao alocar memória para a fila.\n");
        exit(EXIT_FAILURE);
    }
    fila->frente = NULL;
    fila->tras = NULL;
    return fila;
}

int filaVazia(Fila* fila) {
    return (fila->frente == NULL);
}

void enfileirar(Fila* fila, char nome[]) {
    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    if (novoElemento == NULL) {
        printf("Erro ao alocar memória para o novo elemento da fila.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(novoElemento->nome, nome);
    novoElemento->proximo = NULL;
    if (filaVazia(fila)) {
        fila->frente = novoElemento;
    } else {
        fila->tras->proximo = novoElemento;
    }
    fila->tras = novoElemento;
}

char* desenfileirar(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Erro: a fila está vazia.\n");
        exit(EXIT_FAILURE);
    }
    char* nomeRemovido = fila->frente->nome;
    Elemento* elementoRemovido = fila->frente;
    fila->frente = fila->frente->proximo;
    free(elementoRemovido);
    if (fila->frente == NULL) {
        fila->tras = NULL;
    }
    return nomeRemovido;
}

void exibirFila(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Nomes na fila:\n");
    Elemento* atual = fila->frente;
    while (atual != NULL) {
        printf("%s\n", atual->nome);
        atual = atual->proximo;
    }
}

void desenfileirarTodos(Fila* fila) {
    printf("Desenfileirando todos os elementos da fila:\n");
    while (!filaVazia(fila)) {
        char* nomeDesenfileirado = desenfileirar(fila);
        printf("Chamando %s\n", nomeDesenfileirado);
    }
}

int main() {
    Fila* fila = criarFila();
    char nome[50];
    char continuar;

    do {
        printf("Digite um nome para enfileirar: ");
        scanf("%s", nome);
        enfileirar(fila, nome);
        printf("Deseja continuar (S/N)? ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');

    exibirFila(fila);

    desenfileirarTodos(fila);

    free(fila);

    return 0;
}
