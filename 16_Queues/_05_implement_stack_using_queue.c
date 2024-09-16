// Implement Stack Using Queue

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
typedef struct
{
    int data[MAX];
    int front, rear;
} Queue;

// Initialize the queue
void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue *q)
{
    return (q->front == -1);
}

// Enqueue operation
void enqueue(Queue *q, int value)
{
    if (q->rear == MAX - 1)
    {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = value;
}

// Dequeue operation
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1; // Reset the queue if last element is dequeued
    }
    else
    {
        q->front++;
    }
    return value;
}

// Get the front element of the queue
int front(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->data[q->front];
}

// Stack structure using a single queue
typedef struct
{
    Queue q;
} Stack;

// Initialize the stack
void initStack(Stack *s)
{
    initQueue(&s->q);
}

// Push operation for stack
void push(Stack *s, int value)
{
    int size = s->q.rear - s->q.front + 1;
    enqueue(&s->q, value);

    // Move all previous elements behind the newly added element
    for (int i = 0; i < size; i++)
    {
        enqueue(&s->q, dequeue(&s->q));
    }
}

// Pop operation for stack
void pop(Stack *s)
{
    if (isEmpty(&s->q))
    {
        printf("Stack is empty\n");
        return;
    }
    dequeue(&s->q);
}

// Top operation for stack
int top(Stack *s)
{
    if (isEmpty(&s->q))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return front(&s->q);
}

// Check if the stack is empty
int isStackEmpty(Stack *s)
{
    return isEmpty(&s->q);
}

int main()
{
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", top(&s)); // Output: 30
    pop(&s);

    printf("Top element after pop: %d\n", top(&s)); // Output: 20
    pop(&s);

    printf("Top element after second pop: %d\n", top(&s)); // Output: 10

    return 0;
}
