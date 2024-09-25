// Implement Dequeue Using Array

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct Deque
{
    int arr[SIZE];
    int front;
    int rear;
} Deque;

void initialize(Deque *deque)
{
    deque->front = -1;
    deque->rear = -1;
}

int isFull(Deque *deque)
{
    return (deque->front == 0 && deque->rear == SIZE - 1) || (deque->front == deque->rear + 1);
}

int isEmpty(Deque *deque)
{
    return deque->front == -1;
}

void insertFront(Deque *deque, int value)
{
    if (isFull(deque))
    {
        printf("Queue Overflow\n");
        return;
    }

    if (deque->front == -1)
    {
        deque->front = 0;
        deque->rear = 0;
    }
    else if (deque->front == 0)
    {
        deque->front = SIZE - 1;
    }
    else
    {
        deque->front = deque->front - 1;
    }

    deque->arr[deque->front] = value;
}

void insertRear(Deque *deque, int value)
{
    if (isFull(deque))
    {
        printf("Queue Overflow\n");
        return;
    }

    if (deque->front == -1)
    {
        deque->front = 0;
        deque->rear = 0;
    }
    else if (deque->rear == SIZE - 1)
    {
        deque->rear = 0;
    }
    else
    {
        deque->rear = deque->rear + 1;
    }

    deque->arr[deque->rear] = value;
}

void deleteFront(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", deque->arr[deque->front]);

    if (deque->front == deque->rear)
    {
        deque->front = -1;
        deque->rear = -1;
    }
    else if (deque->front == SIZE - 1)
    {
        deque->front = 0;
    }
    else
    {
        deque->front = deque->front + 1;
    }
}

void deleteRear(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", deque->arr[deque->rear]);

    if (deque->front == deque->rear)
    {
        deque->front = -1;
        deque->rear = -1;
    }
    else if (deque->rear == 0)
    {
        deque->rear = SIZE - 1;
    }
    else
    {
        deque->rear = deque->rear - 1;
    }
}

void display(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = deque->front;
    while (1)
    {
        printf("%d ", deque->arr[i]);
        if (i == deque->rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main()
{
    Deque deque;
    initialize(&deque);
    int choice, value;

    while (1)
    {
        printf("\n----- Deque Operations -----\n");
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
            insertFront(&deque, value);
            break;
        case 2:
            printf("Enter value to insert at rear: ");
            scanf("%d", &value);
            insertRear(&deque, value);
            break;
        case 3:
            deleteFront(&deque);
            break;
        case 4:
            deleteRear(&deque);
            break;
        case 5:
            display(&deque);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Please enter again.\n");
        }
    }

    return 0;
}
