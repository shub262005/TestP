#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *create_node(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insert_at_start(int data)
{
    struct Node *new_node = create_node(data);
    new_node->next = head;
    if (head != NULL)
    {
        head->prev = new_node;
    }
    head = new_node;
}

void insert_at_end(int data)
{
    struct Node *new_node = create_node(data);
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void insert_at_position(int data, int position)
{
    
    struct Node *new_node = create_node(data);
    struct Node *temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        free(new_node);
        return;
    }
    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
}

void delete_at_start()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
}

void delete_at_end()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    if (temp->next == NULL)
    {
        head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void delete_at_position(int position)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    struct Node *temp = head;
    for (int i = 0; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    free(temp);
}

void display()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    printf("Inserting 10 and 20 at the start:\n");
    insert_at_start(10);
    insert_at_start(20);
    display();
    printf("\nInserting 30 at the end:\n");
    insert_at_end(30);
    display();
    printf("\nInserting 25 at position 2 (index 2):\n");
    insert_at_position(25, 2);
    display();
    printf("\nDeleting from the start:\n");
    delete_at_start();
    display();
    printf("\nDeleting from the end:\n");
    delete_at_end();
    display();
    printf("\nDeleting at position 1 (index 1):\n");
    delete_at_position(1);
    display();
    return 0;
}
