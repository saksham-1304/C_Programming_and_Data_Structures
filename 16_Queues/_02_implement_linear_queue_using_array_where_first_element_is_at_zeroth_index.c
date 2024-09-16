#include <stdio.h>

#define MAX 10
int storage[MAX];
int Head = -1, Tail = -1;

int isEmpty()
{
    return (Tail == -1); // If Tail is -1, the queue is empty
}

int isFull()
{
    return (Tail == MAX - 1); // If Tail reaches MAX-1, the queue is full
}

void enQueue(int ele)
{
    if (!isFull())
    {
        if (Head == -1)
        {
            Head = 0; // Initialize Head if it's the first element
        }
        storage[++Tail] = ele;
        printf("Enqueue successfully\n");
    }
    else
    {
        printf("Queue Full\n");
    }
}

int deQueue(void)
{
    int i, tmp;

    if (!isEmpty())
    {
        tmp = storage[Head]; // Get the element at the front (index Head)

        // Shift all elements to the left
        for (i = Head; i < Tail; i++)
        {
            storage[i] = storage[i + 1];
        }

        // Update the Tail after shifting
        Tail--;

        // If the queue is now empty, reset the Head and Tail
        if (Tail == -1)
        {
            Head = -1;
        }

        return tmp;
    }
    else
    {
        printf("Queue Empty\n");
        return -1;
    }
}

int main()
{
    // Example usage
    enQueue(5);
    enQueue(10);
    enQueue(15);

    printf("Dequeue: %d\n", deQueue()); // Should print 5
    printf("Dequeue: %d\n", deQueue()); // Should print 10
    printf("Dequeue: %d\n", deQueue()); // Should print 15
    printf("Dequeue: %d\n", deQueue()); // Should print "Queue Empty" and return -1

    return 0;
}
