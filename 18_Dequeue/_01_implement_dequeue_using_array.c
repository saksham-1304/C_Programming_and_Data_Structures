// Implement Dequeueue Using Array

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct Dequeue
{
    int arr[SIZE];
    int front;
    int rear;
} Dequeue;

void initialize(Dequeue *dequeue)
{
    dequeue->front = -1;
    dequeue->rear = -1;
}

int isFull(Dequeue *dequeue)
{
    return (dequeue->front == 0 && dequeue->rear == SIZE - 1) || (dequeue->front == dequeue->rear + 1);
}

int isEmpty(Dequeue *dequeue)
{
    return dequeue->front == -1;
}

void insertFront(Dequeue *dequeue, int value)
{
    if (isFull(dequeue))
    {
        printf("Queue Overflow\n");
        return;
    }

    if (dequeue->front == -1)
    {
        dequeue->front = 0;
        dequeue->rear = 0;
    }
    else if (dequeue->front == 0)
    {
        dequeue->front = SIZE - 1;
    }
    else
    {
        dequeue->front = dequeue->front - 1;
    }

    dequeue->arr[dequeue->front] = value;
}

void insertRear(Dequeue *dequeue, int value)
{
    if (isFull(dequeue))
    {
        printf("Queue Overflow\n");
        return;
    }

    if (dequeue->front == -1)
    {
        dequeue->front = 0;
        dequeue->rear = 0;
    }
    else if (dequeue->rear == SIZE - 1)
    {
        dequeue->rear = 0;
    }
    else
    {
        dequeue->rear = dequeue->rear + 1;
    }

    dequeue->arr[dequeue->rear] = value;
}

void deleteFront(Dequeue *dequeue)
{
    if (isEmpty(dequeue))
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", dequeue->arr[dequeue->front]);

    if (dequeue->front == dequeue->rear)
    {
        dequeue->front = -1;
        dequeue->rear = -1;
    }
    else if (dequeue->front == SIZE - 1)
    {
        dequeue->front = 0;
    }
    else
    {
        dequeue->front = dequeue->front + 1;
    }
}

void deleteRear(Dequeue *dequeue)
{
    if (isEmpty(dequeue))
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", dequeue->arr[dequeue->rear]);

    if (dequeue->front == dequeue->rear)
    {
        dequeue->front = -1;
        dequeue->rear = -1;
    }
    else if (dequeue->rear == 0)
    {
        dequeue->rear = SIZE - 1;
    }
    else
    {
        dequeue->rear = dequeue->rear - 1;
    }
}

void display(Dequeue *dequeue)
{
    if (isEmpty(dequeue))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = dequeue->front;
    while (1)
    {
        printf("%d ", dequeue->arr[i]);
        if (i == dequeue->rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main()
{
    Dequeue dequeue;
    initialize(&dequeue);
    int choice, value;

    while (1)
    {
        printf("\n----- Dequeue Operations -----\n");
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert at front: ");
            scanf("%d", &value);
            insertFront(&dequeue, value);
            break;
        case 2:
            printf("Enter value to insert at rear: ");
            scanf("%d", &value);
            insertRear(&dequeue, value);
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
            exit(0);
        default:
            printf("Invalid choice! Please enter again.\n");
        }
    }

    return 0;
}
