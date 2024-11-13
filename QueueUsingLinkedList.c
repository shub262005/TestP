#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

int dequeue()
{
    if (front == NULL)
        return -1;
    int value = front->data;
    struct Node *temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
    return value;
}

int peek()
{
    if(front==NULL)
        return -1;
    else
        return front->data;
    // return (front == NULL) ? -1 : front->data;
}

int isEmpty()
{
    return front == NULL;
}

void display()
{
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("Front element: %d\n", peek());
    printf("Dequeued element: %d\n", dequeue());
    display();
    return 0;
}
