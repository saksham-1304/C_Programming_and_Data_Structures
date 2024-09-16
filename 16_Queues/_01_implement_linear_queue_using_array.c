// Implement Queue Using Array

#include <stdio.h>
#define MAX 100

// Queue structure
struct Queue
{
    int items[MAX];
    int front;
    int rear;
};

// Initialize the queue
void initializeQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(struct Queue *q)
{
    return q->rear == MAX - 1;
}

// Check if the queue is empty
int isEmpty(struct Queue *q)
{
    return q->front == q->rear;
}

// Enqueue an element into the queue
void enqueue(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->items[++q->rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

// Dequeue an element from the queue
int dequeue(struct Queue *q)
{
    int dequeuedElement;
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        dequeuedElement = q->items[q->front];
        q->front++;
        /*if (q->front == q->rear)
        {
            // Reset queue when empty
            q->front = q->rear = -1;
        }*/
        return dequeuedElement;
    }
}

// Display the elements of the queue
void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main()
{
    struct Queue q;
    initializeQueue(&q);
    
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    printf("Dequeued element: %d\n", dequeue(&q));
    display(&q);

    return 0;
}
