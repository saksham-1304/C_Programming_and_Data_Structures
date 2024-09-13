#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the stack
struct node
{
    int info;
    struct node *next;
};

// Define a stack structure that only keeps track of the top of the stack
struct Stack
{
    struct node *top;
};

// Function to initialize the stack (set top to NULL)
void create(struct Stack *s)
{
    s->top = NULL; // The stack is empty initially
}

// Function to push an element onto the stack
void PUSH(struct Stack *s, int ele)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node)); // Create a new node
    if (!ptr)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    ptr->info = ele;
    ptr->next = s->top; // New node points to the current top node
    s->top = ptr;       // Update top to point to the new node
    printf("%d pushed to stack.\n", ele);
}

// Function to pop an element from the stack
int POP(struct Stack *s)
{
    if (s->top == NULL)
    {
        printf("Stack Underflow! Stack is empty.\n");
        return -1; // Return -1 to indicate an error
    }

    struct node *ptr = s->top;
    int ele = ptr->info;
    s->top = s->top->next; // Move top to the next node
    free(ptr);             // Free the memory of the popped node
    return ele;
}

// Function to display the elements of the stack
void display(struct Stack *s)
{
    struct node *ptr = s->top;
    if (ptr == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

// Function to check if the stack is empty
int isEmpty(struct Stack *s)
{
    return s->top == NULL;
}

// Function to get the current size of the stack
int size(struct Stack *s)
{
    int count = 0;
    struct node *ptr = s->top;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

// Main function to demonstrate stack operations
int main()
{
    struct Stack s; // Declare a stack
    create(&s);     // Initialize the stack

    // Push elements onto the stack
    PUSH(&s, 10);
    PUSH(&s, 20);
    PUSH(&s, 30);

    // Display the current stack
    display(&s);

    // Pop elements from the stack
    printf("Popped element: %d\n", POP(&s));
    printf("Popped element: %d\n", POP(&s));

    // Display the stack again
    display(&s);

    // Show stack size
    printf("Current stack size: %d\n", size(&s));

    // Check if stack is empty
    if (isEmpty(&s))
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack is not empty.\n");
    }

    return 0;
}
