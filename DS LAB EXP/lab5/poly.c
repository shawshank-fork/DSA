#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int power;
    struct node* next;
};

struct node* createnode(int coeff, int power) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->power = power;
    newnode->next = NULL;
    return newnode;
}

void addnode(struct node** head, int coeff, int power) {
    struct node* newnode = createnode(coeff, power);
    if (*head == NULL) {
        *head = newnode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp -> next = newnode;
    }
}

void displaypolynomial(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {

        printf("%dx^%d", temp->coeff, temp->power);
        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;

    }

    printf("\n");
}

struct node* addpolynomials(struct node* poly1, struct node* poly2) {

    struct node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {

        if (poly1->power > poly2->power) {
            addnode(&result, poly1->coeff, poly1->power);
            poly1 = poly1->next;

        } else if (poly1->power < poly2->power) {

            addnode(&result, poly2->coeff, poly2->power);
            poly2 = poly2->next;

        } else {

            addnode(&result, poly1->coeff + poly2->coeff, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;

        }
    }
    while (poly1 != NULL) {

        addnode(&result, poly1->coeff, poly1->power);
        poly1 = poly1->next;

    }

    while (poly2 != NULL) {

        addnode(&result, poly2->coeff, poly2->power);
        poly2 = poly2->next;

    }

    return result;
}

int main() {

    struct node *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    int maxpower, coeff;

    printf("Polynomial-1:\n");
    printf("enter the maximum power of x: ");
    scanf("%d", &maxpower);
    for (int i = maxpower; i >= 0; i--) {
        printf("enter the coefficient of degree %d: ", i);
        scanf("%d", &coeff);
        addnode(&poly1, coeff, i);
    }

    printf("Polynomial-2:\n");
    printf("enter the maximum power of x: ");
    scanf("%d", &maxpower);
    for (int i = maxpower; i >= 0; i--) {
        printf("enter the coefficient of degree %d: ", i);
        scanf("%d", &coeff);
        addnode(&poly2, coeff, i);
    }

    printf("Polynomial 1: ");
    displaypolynomial(poly1);

    printf("Polynomial 2: ");
    displaypolynomial(poly2);

    sum = addpolynomials(poly1, poly2);

    printf("Sum: ");
    displaypolynomial(sum);

    return 0;
}
