// Implement Stack Using Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct Stack
{
    struct node *head;
};

// Initialize the stack (create a dummy head node)
void create(struct Stack *s)
{
    s->head = (struct node *)malloc(sizeof(struct node));
    s->head->info = 0; // Stack size
    s->head->next = NULL;
}

// Push an element onto the stack
void push(struct Stack *s, int ele)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->info = ele;
    ptr->next = s->head->next;
    s->head->next = ptr;
    s->head->info++; // Increment stack size
}

// Pop an element from the stack
int pop(struct Stack *s)
{
    struct node *ptr;
    int ele;

    if (s->head->next != NULL)
    {
        ptr = s->head->next;
        s->head->next = s->head->next->next;
        s->head->info--; // Decrement stack size
        ele = ptr->info;
        free(ptr);
        return ele;
    }
    else
    {
        printf("Stack is empty!\n");
        return -1; // Stack empty
    }
}

// Check if the stack is empty
int isEmpty(struct Stack *s)
{
    return s->head->next == NULL;
}

// Return the size of the stack
int size(struct Stack *s)
{
    return s->head->info;
}

// Display the elements of the stack
void display(struct Stack *s)
{
    struct node *ptr = s->head->next;
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

// Main function to demonstrate the stack operations
int main()
{
    struct Stack s;
    create(&s); // Initialize the stack

    push(&s, 10);
    push(&s, 5);
    push(&s, 8);

    printf("Stack elements: ");
    display(&s);

    pop(&s);

    printf("Stack elements after pop: ");
    display(&s);

    printf("Stack size: %d\n", size(&s));
    return 0;
}
