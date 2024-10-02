//Implement Linked List With A Dedicated Head Node

#include <stdio.h>
#include <stdlib.h>

// Structure for the nodes in the linked list
struct node {
    int info;
    struct node *next;
};

// Function to insert a node at the beginning of the list
void insertFirst(struct node *head, int ele) {
    struct node *nPtr = (struct node *)malloc(sizeof(struct node));
    nPtr->info = ele;
    nPtr->next = head->next;  // Link the new node to the first element
    head->next = nPtr;        // Update the head to point to the new first node
}

// Function to print the elements of the linked list
void printList(struct node *head) {
    struct node *current = head->next;  // Skip the head node
    while (current != NULL) {
        printf("%d -> ", current->info);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create the head node (dedicated head)
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;  // Initially, the list is empty

    // Insert some elements
    insertFirst(head, 10);
    insertFirst(head, 20);
    insertFirst(head, 30);

    // Print the list
    printList(head);

    // Free allocated memory (not shown here for simplicity)
    
    return 0;
}
