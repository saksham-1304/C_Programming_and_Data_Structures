/*
Implement Stack Using Array

1. Top
2. Push
3. Pop
4. Size(of Stack)
5. Stack Overflow
6. Stack Underflow

*/

#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int top;
    int *A;
    int MAX;
};

void initStack(struct Stack *s, int n)
{
    s->top = -1;
    s->MAX = n;
    s->A = (int *)malloc(sizeof(int) * s->MAX);
}
int push(struct Stack *s, int element)
{
    if (s->top < s->MAX - 1)
    {
        s->A[++s->top] = element;
        return 1;
    }
    else
    {
        return -1;
    }
}

int pop(struct Stack *s)
{
    if (s->top > -1)
    {
        int val = s->A[s->top--];
        return val;
    }
    else
    {
        return -1;
    }
}

void display(struct Stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->A[i]);
    }
    printf("\n");
}

int TopOfStack(struct Stack *s)
{
    if (s->top >= 0)
    {
        return s->A[s->top];
    }
    else
    {
        printf("Stack is empty\n");
        return -1;
    }
}
int isEmpty(struct Stack *s)
{
    return (s->top == -1);
}
int isFull(struct Stack *s)
{
    return (s->top >= s->MAX - 1);
}
int main()
{
    struct Stack s;
    initStack(&s, 10);
    push(&s, 10);
    push(&s, 13);
    push(&s, 5);
    display(&s);
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    display(&s);
    free(s.A);
}

/*

Here’s how you can fix it:

Fix 1: Declaring a regular struct Stack (without a pointer)


int main()
{
    struct Stack s;  // Declaring a regular Stack structure
    initStack(&s, 10);  // Pass the address of the structure
    push(&s, 10);
    push(&s, 13);
    push(&s, 5);
    display(&s);
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    display(&s);
    free(s.A);  // Free the allocated array
}
In this fix, the structure struct Stack s; is declared as a regular variable, and when passing it to functions like initStack, push, pop, etc., you pass its address using &s.

Fix 2: Allocating memory for the pointer
If you still want to use a pointer for struct Stack, you need to allocate memory for it with malloc:


int main() 
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));  // Allocate memory for the Stack structure
    initStack(s, 10);  // Initialize the stack
    push(s, 10);
    push(s, 13);
    push(s, 5);
    display(s);
    printf("Popped: %d\n", pop(s));
    printf("Popped: %d\n", pop(s));
    printf("Popped: %d\n", pop(s));
    display(s);
    free(s->A);  // Free the allocated array
    free(s);  // Free the stack structure itself
}
*/
