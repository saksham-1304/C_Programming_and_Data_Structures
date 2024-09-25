// Implement Dequeueue Using Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Dequeue structure
typedef struct
{
    Node *front;
    Node *rear;
} Dequeue;

// Function to initialize the dequeue
void initializeDequeue(Dequeue *dequeue)
{
    dequeue->front = NULL;
    dequeue->rear = NULL;
}

// Function to check if the dequeue is empty
int isEmpty(Dequeue *dequeue)
{
    return dequeue->front == NULL;
}

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an element at the front of the dequeue
void insertFront(Dequeue *dequeue, int data)
{
    Node *newNode = createNode(data);

    if (isEmpty(dequeue))
    {
        dequeue->front = newNode;
        dequeue->rear = newNode;
    }
    else
    {
        newNode->next = dequeue->front;
        dequeue->front->prev = newNode;
        dequeue->front = newNode;
    }
    printf("Inserted %d at the front\n", data);
}

// Function to insert an element at the rear of the dequeue
void insertRear(Dequeue *dequeue, int data)
{
    Node *newNode = createNode(data);

    if (isEmpty(dequeue))
    {
        dequeue->front = newNode;
        dequeue->rear = newNode;
    }
    else
    {
        newNode->prev = dequeue->rear;
        dequeue->rear->next = newNode;
        dequeue->rear = newNode;
    }
    printf("Inserted %d at the rear\n", data);
}

// Function to delete an element from the front of the dequeue
int deleteFront(Dequeue *dequeue)
{
    if (isEmpty(dequeue))
    {
        printf("Error: Dequeue is empty\n");
        return -1;
    }

    int data = dequeue->front->data;
    Node *temp = dequeue->front;

    if (dequeue->front == dequeue->rear)
    {
        dequeue->front = NULL;
        dequeue->rear = NULL;
    }
    else
    {
        dequeue->front = dequeue->front->next;
        dequeue->front->prev = NULL;
    }

    free(temp);
    printf("Deleted %d from the front\n", data);
    return data;
}

// Function to delete an element from the rear of the dequeue
int deleteRear(Dequeue *dequeue)
{
    if (isEmpty(dequeue))
    {
        printf("Error: Dequeue is empty\n");
        return -1;
    }

    int data = dequeue->rear->data;
    Node *temp = dequeue->rear;

    if (dequeue->front == dequeue->rear)
    {
        dequeue->front = NULL;
        dequeue->rear = NULL;
    }
    else
    {
        dequeue->rear = dequeue->rear->prev;
        dequeue->rear->next = NULL;
    }

    free(temp);
    printf("Deleted %d from the rear\n", data);
    return data;
}

// Function to display the dequeue from front to rear
void display(Dequeue *dequeue)
{
    if (isEmpty(dequeue))
    {
        printf("Dequeue is empty\n");
        return;
    }

    printf("Dequeue (Front to Rear): ");
    Node *temp = dequeue->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the allocated memory
void destroyDequeue(Dequeue *dequeue)
{
    Node *temp = dequeue->front;
    while (temp != NULL)
    {
        Node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    dequeue->front = NULL;
    dequeue->rear = NULL;
}

int main()
{
    Dequeue dequeue;
    initializeDequeue(&dequeue);
    int choice, data;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at the front: ");
            scanf("%d", &data);
            insertFront(&dequeue, data);
            break;
        case 2:
            printf("Enter data to insert at the rear: ");
            scanf("%d", &data);
            insertRear(&dequeue, data);
            break;
        case 3:
            deleteFront(&dequeue);
            break;
        case 4:
            deleteRear(&dequeue);
            break;
        case 5:
            display(&dequeue);
            break;
        case 6:
            destroyDequeue(&dequeue);
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
