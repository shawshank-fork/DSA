#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void push(struct node** top, int data, int* count, int maxsize) {
    if (*count >= maxsize) {
        printf("stack overflow\n");
        return;
    }
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("memory allocation failed\n");
        return;
    }
    newnode->data = data;
    newnode->next = *top;
    *top = newnode;
    (*count)++;
    printf("element %d pushed onto the stack\n", data);
}

int pop(struct node** top, int* count) {
    if (*top == NULL) {
        printf("stack underflow\n");
        return -1;
    }
    int data = (*top)->data;
    struct node* temp = *top;
    *top = (*top)->next;
    free(temp);
    (*count)--;
    return data;
}

void display(struct node* top) {
    if (top == NULL) {
        printf("stack is empty\n");
        return;
    }
    printf("the elements of the stack are: ");
    struct node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* top = NULL;
    int maxsize, initialsize, data;
    int count = 0;
    int choice;
    char cont = 'y';

    printf("enter the maximum size of the stack: ");
    scanf("%d", &maxsize);

    printf("enter the initial number of elements: ");
    scanf("%d", &initialsize);

    if (initialsize > maxsize) {
        printf("initial size cannot be greater than maximum size. exiting.\n");
        return 1;
    }

    for (int i = 0; i < initialsize; i++) {
        printf("enter element %d: ", i + 1);
        scanf("%d", &data);
        push(&top, data, &count, maxsize);
    }

    while (cont == 'y' || cont == 'Y') {
        printf("\n1.push\n2.pop\n3.display\n4.exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("enter the element to be inserted: ");
                scanf("%d", &data);
                push(&top, data, &count, maxsize);
                break;
            case 2:
                data = pop(&top, &count);
                if (data != -1)
                    printf("the deleted element is: %d\n", data);
                break;
            case 3:
                display(top);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("invalid choice. please enter a valid option.\n");
                break;
        }

        printf("do you want to continue (y/n): ");
        scanf(" %c", &cont);
    }

    return 0;
}
