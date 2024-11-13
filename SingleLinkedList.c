#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *head = NULL;

void insertAfter(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteAtPosition(int position) {
    if (head == NULL) 
        return;

    struct Node* temp = head;

    if (position == 0) {
        head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // if (temp == NULL || temp->next == NULL) 
    //     return;

    struct Node* dnext = temp->next->next;
    // free(temp->next);
    temp->next = dnext;
}

void printList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertAfter(10);
    insertAfter(20);
    insertAfter(30);
    printList();

    deleteAtPosition(1);
    printList();

    return 0;
}
