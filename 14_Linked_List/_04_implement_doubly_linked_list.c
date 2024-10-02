// Implement Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int info;
    struct node *next;
    struct node *prev;
};

// Insert at the beginning
void insertFirst(struct node **head, struct node **tail, int ele) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = ele;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL)
        (*head)->prev = newNode;
    else
        *tail = newNode; // If list was empty, set tail to new node

    *head = newNode;
}

// Delete the first node
int deleteFirst(struct node **head, struct node **tail) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return -1;
    }

    struct node *temp = *head;
    int data = temp->info;

    *head = (*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    else
        *tail = NULL;  // List becomes empty

    free(temp);
    return data;
}

// Insert at the end
void insertLast(struct node **tail, int ele) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = ele;
    newNode->next = NULL;
    newNode->prev = *tail;

    if (*tail != NULL)
        (*tail)->next = newNode;
    
    *tail = newNode;
}

// Delete the last node
int deleteLast(struct node **tail) {
    if (*tail == NULL) {
        printf("List is empty!\n");
        return -1;
    }

    struct node *temp = *tail;
    int data = temp->info;

    *tail = (*tail)->prev;
    if (*tail != NULL)
        (*tail)->next = NULL;

    free(temp);
    return data;
}

// Print the list
void printList(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->info);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL, *tail = NULL;

    // Insert at the beginning and end
    insertFirst(&head, &tail, 3);
    insertLast(&tail, 1);
    insertLast(&tail, 7);

    printf("Initial List: ");
    printList(head);

    // Delete the first node
    deleteFirst(&head, &tail);
    printf("After deleting first: ");
    printList(head);

    // Delete the last node
    deleteLast(&tail);
    printf("After deleting last: ");
    printList(head);

    return 0;
}
