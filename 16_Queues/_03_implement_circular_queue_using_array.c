// Implement Circular Queue Using Array

#include <stdio.h>
#define MAX 100

// Circular Queue structure
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
    return (q->rear + 1) % MAX == q->front;
}

// Check if the queue is empty
int isEmpty(struct Queue *q)
{
    return q->front == -1;
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
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = value;
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
        if (q->front == q->rear)
        {
            // Reset queue when last element is dequeued
            q->front = q->rear = -1;
        }
        else
        {
            q->front = (q->front + 1) % MAX;
        }
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
        int i = q->front;
        while (i != q->rear)
        {
            printf("%d ", q->items[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", q->items[i]);
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
