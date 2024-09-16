// Implement Queue Using Two Stacks

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Define a stack structure
typedef struct Stack
{
    int arr[MAX];
    int top;
} Stack;

// Initialize a stack
void init(Stack *s)
{
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack *s)
{
    return s->top == -1;
}

// Check if the stack is full
int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

// Push an element to the stack
void push(Stack *s, int data)
{
    if (isFull(s))
    {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++(s->top)] = data;
}

// Pop an element from the stack
int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

// Peek at the top element of the stack
int peek(Stack *s)
{
    if (isEmpty(s))
    {
        return -1;
    }
    return s->arr[s->top];
}

// Queue structure using two stacks
typedef struct Queue
{
    Stack stack1;
    Stack stack2;
} Queue;

// Initialize the queue
void initQueue(Queue *q)
{
    init(&q->stack1);
    init(&q->stack2);
}

// Enqueue operation
void enqueue(Queue *q, int data)
{
    push(&q->stack1, data);
    printf("Enqueued: %d\n", data);
}

// Dequeue operation
int dequeue(Queue *q)
{
    if (isEmpty(&q->stack2))
    {
        while (!isEmpty(&q->stack1))
        {
            int data = pop(&q->stack1);
            push(&q->stack2, data);
        }
    }
    int result = pop(&q->stack2);
    if (result != -1)
    {
        printf("Dequeued: %d\n", result);
    }
    return result;
}

// Get the front element (similar to top) of the queue
int top(Queue *q)
{
    if (isEmpty(&q->stack2))
    {
        while (!isEmpty(&q->stack1))
        {
            int data = pop(&q->stack1);
            push(&q->stack2, data);
        }
    }
    int result = peek(&q->stack2);
    if (result != -1)
    {
        printf("Front element: %d\n", result);
    }
    else
    {
        printf("Queue is empty\n");
    }
    return result;
}

// Get the size of the queue
int size(Queue *q)
{
    return (q->stack1.top + 1) + (q->stack2.top + 1);
}

// Main function to demonstrate the queue operations
int main()
{
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Size of queue: %d\n", size(&q)); // Output: 3
    top(&q);                                 // Output: Front element: 10

    dequeue(&q);                             // Output: Dequeued: 10
    printf("Size of queue: %d\n", size(&q)); // Output: 2
    top(&q);                                 // Output: Front element: 20

    enqueue(&q, 40);
    printf("Size of queue: %d\n", size(&q)); // Output: 3

    dequeue(&q);                             // Output: Dequeued: 20
    dequeue(&q);                             // Output: Dequeued: 30
    printf("Size of queue: %d\n", size(&q)); // Output: 1
    top(&q);                                 // Output: Front element: 40

    return 0;
}
