#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

void traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

bool search(struct node *ptr, int ele)
{
    while (ptr != NULL)
    {
        if (ptr->info == ele)
        {
            printf("Found\n");
            return true;
        }
        ptr = ptr->next;
    }
    printf("Not Found\n");
    return 0;
}

struct node *insertAtFirst(struct node *head, int ele)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->info = ele;
    new_node->next = head;
    head = new_node;

    return head;
}
struct node *insertAtLast(struct node *head, int ele)
{
    if (head == NULL)
    {
        return insertAtFirst(head, ele);
    }
    struct node *ptr, *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->info = ele;
    new_node->next = NULL;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    return head;
}
struct node *insertAtPosition(struct node *head, int ele, int pos)
{
    struct node *ptr, *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->info = ele;
    new_node->next = NULL;
    if (pos == 1)
    {
        return insertAtFirst(head, ele);
    }

    else
    {
        int cnt = 1;
        ptr = head;
        while (cnt < pos - 1 && ptr != NULL)
        {
            ptr = ptr->next;
            cnt++;
        }
    }

    if (ptr == NULL)
    {
        printf("Position is beyond the range\n");
    }

    else
    {
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
    return head;
}
int deleteFirst(struct node **head)
{
    struct node *ptr = *head;
    int data = (*head)->info;
    (*head) = (*head)->next;
    free(ptr);
    return data;
}

int deleteLast(struct node *head)
{
    struct node *curr, *prev;
    int data;
    curr = head;
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    data = curr->info;
    free(curr);
    return data;
}

int deleteAtPosition(struct node **head, int pos)
{
    struct node *curr = NULL, *prev;
    int cnt = 1;
    int data;
    if (pos == 1)
    {
        return deleteFirst(&*head);
    }
    else
    {
        curr = *head;
        while (cnt < pos && curr != NULL)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
    }

    if (curr == NULL)
    {
        printf("Position out of range\n");
    }

    else
    {
        prev->next = curr->next;
        data = curr->info;
        free(curr);
    }
    return data;
}
int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->info = 3;
    head->next = (struct node *)malloc(sizeof(struct node));
    head->next->info = 1;
    head->next->next = (struct node *)malloc(sizeof(struct node));
    head->next->next->info = 7;
    head->next->next->next = NULL;
    printf("First Element: %d\n", head->info);
    printf("Second Element: %d\n", head->next->info);
    printf("Third Element: %d\n", head->next->next->info);
    traverse(head);
    search(head, 7);
    search(head, 8);
    head = insertAtFirst(head, 6);
    traverse(head);
    head = insertAtLast(head, 56);
    traverse(head);
    head = insertAtPosition(head, 5, 4);
    traverse(head);
    head = insertAtPosition(head, 55, 1);
    traverse(head);
    head = insertAtPosition(head, 43, 8);
    traverse(head);
    printf("The value deleted is %d\n", deleteFirst(&head));
    traverse(head);
    printf("The value deleted is %d\n", deleteLast(head));
    traverse(head);
    printf("The value deleted is %d\n", deleteAtPosition(&head, 2));
    traverse(head);
    printf("The value deleted is %d\n", deleteAtPosition(&head, 1));
    traverse(head);
}