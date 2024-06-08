#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
int value;
struct Node *next;
} Node;

Node *head = NULL;

void addNode(int value) {
Node *newNode = (Node*)malloc(sizeof(Node));
newNode->value = value;
newNode->next = head;
head = newNode;
}

void printList() {
Node *temp = head;
while (temp != NULL) {
printf("%d ", temp->value);
temp = temp->next;
}
printf("\n");
}

int main() {
addNode(10);
addNode(20);
addNode(30);
printList();
return 0;
}
