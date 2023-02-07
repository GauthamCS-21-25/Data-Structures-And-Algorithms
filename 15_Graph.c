#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct vertex
{
    int value;
    int status;
    struct vertex *next;
} *vertices_list[MAX], *a[MAX];

int n, vertices_array[MAX], adj_matrix[MAX][MAX];
int top = -1, front = -1, rear = -1;

void display_adj_matrix()
{
    int i, j;

    printf("\nAdjaceny Matrix -\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%d\t", adj_matrix[i][j]);
        printf("\n");
    }
}

void display_adj_list()
{
    int i, j;
    struct vertex *ptr;

    printf("\nAdjacency List -\n");

    for(i = 0; i < n; i++)
    {
        ptr = vertices_list[i];

        while(ptr -> next != NULL)
        {
            printf("%d -> ", ptr -> value);
            ptr=ptr->next;
        }

        printf("%d -> ", ptr -> value);
        if(ptr -> next == NULL)
            printf("NULL");

        printf("\n");
    }
}

void enqueue(struct vertex *item)
{
    if(rear == MAX -1)
    {
        printf("Queue overflow.\n");
        exit(0);
    }

    a[++rear] = item;

    if(front == -1)
        front = 0;
}

struct vertex * dequeue()
{
    struct vertex *item;

    item = a[front];

    if(front == rear)
        front = rear = -1;
    else
        front++;

    return item;
}

void bfs()
{
    int i, item, flag = 0;
    struct vertex *ptr;

    printf("Enter starting vertex: ");
    scanf("%d", &item);

    for(i = 0; i < n; i++)
        vertices_list[i] -> status = 1;

    for(i = 0; i < n; i++)
    {
        if(vertices_list[i] -> value == item)
        {
            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        printf("Vertex not found.");
        return;
    }

    enqueue(vertices_list[i]);
    vertices_list[i] -> status = 2;

    printf("BFS: ");

    while(front != -1)
    {
        ptr = dequeue();
        printf("%d ", ptr -> value);
        ptr -> status = 3;

        while(ptr -> next != NULL)
        {
            ptr = ptr -> next;

            for(i = 0; i < n; i++)
            {
                if(vertices_list[i] -> value == ptr -> value)
                    break;
            }

            if(vertices_list[i] -> status == 1)
            {
                enqueue(vertices_list[i]);
                vertices_list[i] -> status = 2;
            }
        }
    }
    printf("\n");
}

void push(struct vertex *item)
{
    if(top == MAX - 1)
    {
        printf("Stack overflow.");
        exit(0);
    }

    a[++top] = item;
}

struct vertex * pop()
{
    return a[top--];
}

void dfs()
{
    int i, item, flag = 0;
    struct vertex *ptr;

    printf("Enter starting vertex: ");
    scanf("%d", &item);

    for(i = 0; i < n; i++)
        vertices_list[i] -> status = 1;

    for(i = 0; i < n; i++)
    {
        if(vertices_list[i] -> value == item)
        {
            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        printf("Vertex not found.");
        return;
    }

    push(vertices_list[i]);
    vertices_list[i] -> status = 2;

    printf("DFS: ");

    while(top != -1)
    {
        ptr = pop();
        printf("%d ", ptr -> value);
        ptr -> status = 3;

        while(ptr -> next != NULL)
        {
            ptr = ptr -> next;

            for(i = 0; i < n; i++)
            {
                if(vertices_list[i] -> value == ptr -> value)
                    break;
            }

            if(vertices_list[i] -> status == 1)
            {
                push(vertices_list[i]);
                vertices_list[i] -> status = 2;
            }
        }
    }
    printf("\n");
}

void main()
{
    int i, j, choice, menu;
    char ch;
    struct vertex *newvertex, *ptr;

    printf("Enter no. of vertices: ");
    scanf("%d", &n);

    printf("Enter the vertices: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &vertices_array[i]);

        newvertex = (struct vertex *)malloc(sizeof(struct vertex));
        newvertex -> value = vertices_array[i];
        newvertex -> next = NULL;

        vertices_list[i] = newvertex;
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("Is %d a neighbour of %d? 1(Yes)/0(No) : ", vertices_array[i], vertices_array[j]);
            scanf("%d", &choice);

            if(choice == 1)
            {
                adj_matrix[i][j] = 1;

                newvertex = (struct vertex *)malloc(sizeof(struct vertex));
                newvertex -> value = vertices_array[j];
                newvertex -> next = NULL;

                ptr = vertices_list[i];
                while(ptr -> next != NULL)
                    ptr = ptr -> next;

                ptr -> next = newvertex;
            }
            else
                adj_matrix[i][j] = 0;
        }
        printf("\n");
    }

    do
    {
        printf("\n1.Breadth First Search \t2.Depth First Search \t3.Adjacency Matrix \t4.Adjacency List");
        printf("\nEnter choice: ");
        scanf("%d", &menu);

        switch(menu)
        {
            case 1: bfs();
                    break;

            case 2: dfs();
                    break;

            case 3: display_adj_matrix();
                    break;
           
            case 4: display_adj_list();
                    break;
            default:
            printf("Invalid choice.");
        }
        printf("Do you wish to continue? (y/n): ");
        scanf(" %c", &ch);
    }while(ch=='Y' || ch=='y');
}
