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
    Contact newContact = (Contact)malloc(sizeof(Contact));
    if (newContact == NULL) {
        printf("Erro ao alocar na memória.");
        exit(1);
    }
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->next = NULL;
    return newContact;
}