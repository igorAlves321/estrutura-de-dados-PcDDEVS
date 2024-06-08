#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM 6

typedef struct {
char pratos[MAX_TAM][20];
int topo;
} PilhaPratos;

void inicializarPilha(PilhaPratos *pilha) {
pilha->topo = -1;
}

void empilharPrato(PilhaPratos *pilha, char *prato) {
if (pilha->topo == MAX_TAM - 1) {
printf("Já deu mano, não cabe mais pratos, vamos enxaguar..\n");
return;
}
pilha->topo++;
strcpy(pilha->pratos[pilha->topo], prato);
}

void desempilharPrato(PilhaPratos *pilha) {
if (pilha->topo == -1) {
printf("Erro: Pilha vazia. Não é possível remover mais pratos.\n");
return;
}
printf("Prato enxaguado: %s\n", pilha->pratos[pilha->topo]);
pilha->topo--;
}

int main() {
PilhaPratos pilha;

inicializarPilha(&pilha);

printf("Rosa, o que acha de lavar alguns pratos?\n");
printf("Vamos começar a lavar os pratos...\n\n");

for (int i = 0; i < MAX_TAM; i++) {
char corPrato[20];
printf("Informe a cor do prato %d: ", i + 1);
scanf("%s", corPrato);

empilharPrato(&pilha, corPrato);

printf("Prato %d (%s) empilhado.\n\n", i + 1, corPrato);
}

printf("Todos os pratos empilhados. Agora vamos enxaguá-los...\n\n");

while (pilha.topo >= 0) {
desempilharPrato(&pilha);
}

printf("Cara, você arrasou. Louça zerada!\n");

return 0;
}
```