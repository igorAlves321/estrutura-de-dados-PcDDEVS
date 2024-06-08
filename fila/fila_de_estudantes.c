#include <stdio.h>

#include <stdlib.h>

#include <string.h>

typedef struct Estudante {
char nome[50];
struct Estudante *proximo;
} Estudante;

Estudante* criarEstudante(char *nome) {
Estudante *novoEstudante = (Estudante*)malloc(sizeof(Estudante));
if (novoEstudante == NULL) {
printf("Erro ao alocar na memória.");
exit(1);
}
strcpy(novoEstudante->nome, nome);
novoEstudante->proximo = NULL;
return novoEstudante;
}

void imprimirEstudantes(Estudante *cabeca) {
if (cabeca == NULL) {
printf("Fila vazia.\n");
return;
}
printf("Estudantes na fila:\n");
Estudante *atual = cabeca;
while (atual != NULL) {
printf("%s\n", atual->nome);
atual = atual->proximo;
}
}

int main() {
Estudante *cabeca = criarEstudante("João");
cabeca->proximo = criarEstudante("Maria");
cabeca->proximo->proximo = criarEstudante("Pedro");
imprimirEstudantes(cabeca);
return 0;
}
