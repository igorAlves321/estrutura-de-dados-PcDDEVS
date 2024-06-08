//para entrada/saída 
#include <stdio.h>

//alocação de memória dinâmica
#include <stdlib.h>

//manipulação de strings 
#include <string.h>

// Definição da estrutura do nó da lista
typedef struct Contact {
    char name[50];
    char phone[15];
    struct Contact *next;
} Contact;

//Função para criar um novo contato
Contact* createContact(char *name, char *phone) {
    Contact *newContact = (Contact*)malloc(sizeof(Contact));
    if (newContact == NULL) {
        printf("Erro ao alocar na memória.");
        exit(1);
    }
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->next = NULL;
    return newContact;
}

//Função para adicionar um contato no final da lista
void addContact(Contact **head, char *name, char *phone) {
    Contact *newContact = createContact(name, phone);
    if(*head == NULL){
        *head = newContact;
        return;
    }
    Contact *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newContact;
}

// Função para exibir todos os contatos da lista
void displayContacts(Contact *head) {
    printf("Lista de contatos:\n");
    while (head != NULL) {
        printf("Nome: %s, Telefone: %s\n", head->name, head->phone);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Contact *contactList = NULL;
    char name[50];
    char phone[15];
    int numContacts;

    printf("Quantos contatos deseja adicionar? ");
    scanf("%d", &numContacts);

    for (int i = 0; i < numContacts; i++) {
        printf("Digite o nome do contato: ");
        scanf("%s", name);
        printf("Digite o número de telefone do contato: ");
        scanf("%s", phone);

        addContact(&contactList, name, phone);
    }

    displayContacts(contactList);

    return 0;
}
