#include <stdio.h>
#include <string.h>

// Definição da estrutura para armazenar um contato
typedef struct {
    char nome[50];
    char telefone[15];
} Contato;

int main() {
    // Definição de um contato
    Contato contato;

    // Entrada dos dados do contato
    printf("Digite o nome do contato: ");
    scanf("%s", contato.nome);

    printf("Digite o telefone do contato: ");
    scanf("%s", contato.telefone);

    // Exibindo os dados do contato
    printf("\nContato adicionado:\n");
    printf("Nome: %s\n", contato.nome);
    printf("Telefone: %s\n", contato.telefone);

    return 0;
}
