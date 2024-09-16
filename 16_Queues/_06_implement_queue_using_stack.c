// Implement Queue Using Stack

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Define the stack
struct Stack
{
    int arr[MAX];
    int top;
};

// Initialize the stack
void initStack(struct Stack *stack)
{
    stack->top = -1;
}

// Push function
void push(struct Stack *stack, int data)
{
    if (stack->top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

// Pop function
int pop(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Check if stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Enqueue function
void enqueue(struct Stack *stack, int data)
{
    push(stack, data);
}

// Dequeue function using recursion
int dequeue(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Queue is empty\n");
        return -1;
    }

    int topVal = pop(stack);

    // If this is the last element, return it
    if (isEmpty(stack))
    {
        return topVal;
    }

    // Recursively remove the next item
    int item = dequeue(stack);

    // Push the top element back after recursive call
    push(stack, topVal);

    return item;
}

int main()
{
    struct Stack stack;
    initStack(&stack);

    enqueue(&stack, 10);
    enqueue(&stack, 20);
    enqueue(&stack, 30);

    printf("%d\n", dequeue(&stack)); // 10
    printf("%d\n", dequeue(&stack)); // 20
    enqueue(&stack, 40);
    printf("%d\n", dequeue(&stack)); // 30
    printf("%d\n", dequeue(&stack)); // 40

    return 0;
}
