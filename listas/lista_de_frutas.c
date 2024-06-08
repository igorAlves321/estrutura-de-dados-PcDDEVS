#include <stdio.h>

#include <stdlib.h>

#include <string.h>

typedef struct Fruta {
char nome[50];
struct Fruta *proxima;
} Fruta;


Fruta* criarFruta(char *nome) {
Fruta *novaFruta = (Fruta*)malloc(sizeof(Fruta));
if (novaFruta == NULL) {
printf("Erro ao alocar na memória.");
exit(1);
}
strcpy(novaFruta->nome, nome);
novaFruta->proxima = NULL;
return novaFruta;
}


void imprimirFrutas(Fruta *cabeca) {
Fruta *temp = cabeca;
while (temp != NULL) {
printf("%s\n", temp->nome);
temp = temp->proxima;
}
}

int main() {
Fruta *cabeca = criarFruta("Maçã");
cabeca->proxima = criarFruta("Banana");
cabeca->proxima->proxima = criarFruta("Laranja");
imprimirFrutas(cabeca);
return 0;
}
