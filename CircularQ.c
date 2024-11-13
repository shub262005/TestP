#include <stdio.h>
#include <conio.h>
#define MAX 10
int data[MAX], rear, front;
void initialize();
int empty();
int full();
void insertion();
void deletion();
void print();
void main()
{
    int ch;
    initialize();
    do
    {
        printf("\n ***Circular QUEUE OPERATIONS");
        printf("\n 1. Insertion");
        printf("\n 2. Deletion");
        printf("\n 3. Print");
        printf("\n 4. EXIT");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (full() == 0)
            {
                insertion();
            }
            else
            {
                printf("\nQueue is Full !!!");
            }
            break;
        case 2:
            if (empty() == 0)
            {
                deletion();
            }
            else
            {
                printf("\nQueue is Empty !!!");
            }
            break;
        case 3:
            print();
            break;
        case 4:
            break;
        default:
            printf("Invalid choice");
        }
    } while (ch != 4);
    getch();
}
void initialize()
{
    rear = front = -1;
}
int full()
{
    if ((rear + 1) % MAX == front)
        return (1);
    else
        return (0);
}
int empty()
{
    if (rear == -1)
        return (1);
    else
        return (0);
}
void insertion()
{
    int x;
    printf("Enter data to be insert: ");
    scanf("%d", &x);
    if (rear == -1)
    {
        rear = front = 0;
        data[rear] = x;
    }
    else
    {
        rear = (rear + 1) % MAX;
        data[rear] = x;
    }
}
void deletion()
{
    int x;
    x = data[front];
    if (front == rear)
    {
        rear = front = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
    printf("\nDeleted data= %d", x);
}
void print()
{
    int i;
    if (front == -1)
    {
        printf("\nQueue is Empty!!!");
    }
    else
    {
        i = front;
        printf("\nQueue data: ");
        do
        {
            printf("%d\t", data[i]);
            i = (i + 1) % MAX;
        } while (i != rear);
        printf("%d\t", data[i]);
    }
}