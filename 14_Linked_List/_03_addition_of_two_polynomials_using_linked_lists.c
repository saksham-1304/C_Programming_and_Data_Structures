#include <stdio.h>
#include <stdlib.h>

// Define a Node structure for the polynomial
struct Node
{
    int coefficient;
    int exponent;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int coefficient, int exponent)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the result polynomial
void appendNode(struct Node **result, int coefficient, int exponent)
{
    struct Node *newNode = createNode(coefficient, exponent);
    if (*result == NULL)
    {
        *result = newNode;
    }
    else
    {
        struct Node *temp = *result;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to add two polynomials represented by linked lists
struct Node *addPolynomials(struct Node *p1, struct Node *p2)
{
    struct Node *result = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exponent == p2->exponent)
        {
            int sum = p1->coefficient + p2->coefficient;
            appendNode(&result, sum, p1->exponent);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exponent > p2->exponent)
        {
            appendNode(&result, p1->coefficient, p1->exponent);
            p1 = p1->next;
        }
        else
        {
            appendNode(&result, p2->coefficient, p2->exponent);
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        appendNode(&result, p1->coefficient, p1->exponent);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        appendNode(&result, p2->coefficient, p2->exponent);
        p2 = p2->next;
    }

    return result;
}

// Function to print a polynomial
void printPolynomial(struct Node *poly)
{
    while (poly != NULL)
    {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        if (poly->next != NULL)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

// Main function to test the polynomial addition
int main()
{
    // Creating first polynomial: 3x^5 + 2x^3 + 1
    struct Node *p1 = createNode(3, 5);
    appendNode(&p1, 2, 3);
    appendNode(&p1, 1, 0);

    // Creating second polynomial: 5x^3 + 2x^2 + 1
    struct Node *p2 = createNode(5, 3);
    appendNode(&p2, 2, 2);
    appendNode(&p2, 1, 0);

    // Adding the two polynomials
    struct Node *result = addPolynomials(p1, p2);

    // Printing the result
    printf("First Polynomial: ");
    printPolynomial(p1);

    printf("Second Polynomial: ");
    printPolynomial(p2);

    printf("Resultant Polynomial after Addition: ");
    printPolynomial(result);

    return 0;
}
