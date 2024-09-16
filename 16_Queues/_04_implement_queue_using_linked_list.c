// Implement Queue Using Linked List

#include <stdio.h>
#include <stdlib.h>

// Define a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Define the queue structure
struct Queue
{
    struct Node *front, *rear;
};

// Function to create a new node
struct Node *newNode(int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

// Function to create a queue
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue an element
void enqueue(struct Queue *q, int value)
{
    // Create a new node
    struct Node *temp = newNode(value);

    // If the queue is empty, new node is both front and rear
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }

    // Add the new node at the rear and change the rear
    q->rear->next = temp;
    q->rear = temp;
}

// Function to dequeue an element
int dequeue(struct Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }

    // Store the front node and move the front pointer to the next node
    struct Node *temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    // If the front becomes NULL, set rear to NULL
    if (q->front == NULL)
        q->rear = NULL;

    // Free the dequeued node and return the value
    free(temp);
    return value;
}

// Function to display the queue
void displayQueue(struct Queue *q)
{
    struct Node *temp = q->front;
    if (temp == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Queue *q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Queue after enqueue operations: ");
    displayQueue(q);

    printf("Dequeued element: %d\n", dequeue(q));

    printf("Queue after dequeue operation: ");
    displayQueue(q);

    return 0;
}
