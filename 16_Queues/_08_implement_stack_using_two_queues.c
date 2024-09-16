// Implement Stack Using Two Queues

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct Queue
{
    int items[SIZE];
    int front, rear;
} Queue;

// Function to initialize a queue
void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue *q)
{
    return q->front == -1;
}

// Check if the queue is full
int isFull(Queue *q)
{
    return q->rear == SIZE - 1;
}

// Enqueue an element to the queue
void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Dequeue an element from the queue
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
    {
        q->front = q->rear = -1; // Reset queue
    }
    return item;
}

// Get the front element of the queue
int front(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->items[q->front];
}

// Define a stack structure using two queues
typedef struct Stack
{
    Queue q1, q2;
} Stack;

// Initialize the stack
void initStack(Stack *s)
{
    initQueue(&s->q1);
    initQueue(&s->q2);
}

// Push an element onto the stack
void push(Stack *s, int value)
{
    enqueue(&s->q2, value);

    // Move all elements from q1 to q2
    while (!isEmpty(&s->q1))
    {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    // Swap the names of q1 and q2
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

// Pop an element from the stack
void pop(Stack *s)
{
    if (isEmpty(&s->q1))
    {
        printf("Stack is empty!\n");
        return;
    }
    dequeue(&s->q1);
}

// Get the top element of the stack
int top(Stack *s)
{
    if (isEmpty(&s->q1))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return front(&s->q1);
}

// Check if the stack is empty
int isEmptyStack(Stack *s)
{
    return isEmpty(&s->q1);
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

    printf("Top element: %d\n", top(&s)); // Output: 20
    pop(&s);

    printf("Top element: %d\n", top(&s)); // Output: 10
    pop(&s);

    if (isEmptyStack(&s))
    {
        printf("Stack is empty\n");
    }

    return 0;
}
