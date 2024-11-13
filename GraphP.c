#include <stdio.h>
#define VERTEX 5
int graph[VERTEX][VERTEX] = {0};

void deleteEdges();
void insertEdges();
void insertEdge(int v1, int v2)
{
    graph[v1][v2] = 1;
    graph[v2][v1] = 1;
}
void deleteEdge(int v1, int v2)
{
    graph[v1][v2] = 0;
    graph[v2][v1] = 0;
}
void printGraph()
{
    int v1, v2;
    char c;
    printf("\nAdjacency Matrix Representation of the given Undirected Graph:\n\n ");
    for (v1 = 0, c = 'A'; v1 < VERTEX; ++v1, ++c)
        printf(" %c", c);
    printf("\n");
    for (v1 = 0, c = 'A'; v1 < VERTEX; ++v1, ++c)
    {
        printf("%c ", c);
        for (v2 = 0; v2 < VERTEX; ++v2)
            printf(" %d ", graph[v1][v2]);
        printf("\n");
    }
}

int main()
{
    while (1)
    {
        int choice;
        printf("\n-- Graph Representation: Using Adjacency Matrix --\n");
        printf("\n1. Insert edge\n2. Delete edge\n3. Print matrix\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertEdges();
            break;
        case 2:
            deleteEdges();
            break;
        case 3:
            printGraph();
            break;
        case 4:
            return 0;
        default:
            printf("\nINVALID CHOICE!!!");
        }
    }
    return 0;
}

void insertEdges()
{
    int a, b, edge;
    printf("Enter number of edges: ");
    scanf("%d", &edge);
    for (int i = 1; i <= edge; i++)
    {
        printf("Enter edge %d (two vertices as numbers 0-%d): ", i, VERTEX - 1);
        scanf("%d%d", &a, &b);
        if (a >= 0 && a < VERTEX && b >= 0 && b < VERTEX)
        {
            insertEdge(a, b);
        }
        else
        {
            printf("Invalid vertices. Please enter values between 0 and %d.\n", VERTEX - 1);
        }
    }
}

void deleteEdges()
{
    int a, b, edge;
    printf("Enter number of edges you want to delete: ");
    scanf("%d", &edge);
    for (int i = 1; i <= edge; i++)
    {
        printf("Enter edge %d (two vertices as numbers 0-%d): ", i, VERTEX - 1);
        scanf("%d%d", &a, &b);
        if (a >= 0 && a < VERTEX && b >= 0 && b < VERTEX)
        {
            deleteEdge(a, b);
        }
        else
        {
            printf("Invalid vertices. Please enter values between 0 and %d.\n", VERTEX - 1);
        }
    }
}
