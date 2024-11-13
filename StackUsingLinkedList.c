#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    if (top == NULL)
        return -1;
    int value = top->data;
    struct Node *temp = top;
    top = top->next;
    free(temp);
    return value;
}

int peek()
{
    return (top == NULL) ? -1 : top->data;
}

int isEmpty()
{
    return top == NULL;
}

void display()
{
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    display();
    printf("Top element: %d\n", peek());
    printf("Popped element: %d\n", pop());
    display();
    return 0;
}
