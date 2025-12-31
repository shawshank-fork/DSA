#include <stdio.h>
#include <stdlib.h>

int *stack;
int top = -1;
int maxsize;

void push(int element) {
    if (top == maxsize - 1) {
        printf("stack overflow! cannot push %d\n", element);
    } else {
        stack[++top] = element;
        printf("%d has been pushed onto the stack\n", element);
    }
}

void pop() {
    if (top == -1) {
        printf("stack underflow! cannot pop an element\n");
    } else {
        int element = stack[top--];
        printf("the deleted element is: %d\n", element);
    }
}

void display() {
    if (top == -1) {
        printf("the stack is empty\n");
    } else {
        printf("the elements of the stack are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, element, initial_elements, i;
    char continuechoice;

    printf("enter the size of the stack: ");
    scanf("%d", &maxsize);

    stack = (int *)malloc(maxsize * sizeof(int));

    if (stack == NULL) {
        printf("memory allocation failed\n");
        return 1;
    }

    printf("enter the number of initial elements (up to %d): ", maxsize);
    scanf("%d", &initial_elements);

    if (initial_elements > maxsize) {
        printf("number of initial elements exceeds stack size. setting to maximum size (%d).\n", maxsize);
        initial_elements = maxsize;
    }

    printf("enter %d initial elements:\n", initial_elements);
    for (i = 0; i < initial_elements; i++) {
        scanf("%d", &element);
        push(element);
    }

    do {
        printf("\n1.push\n2.pop\n3.display\n4.exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("enter the element to be inserted: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("exiting program...\n");
                free(stack);
                return 0;
            default:
                printf("invalid choice! please try again.\n");
        }

        printf("do you want to continue (y/n): ");
        scanf(" %c", &continuechoice);

    } while (continuechoice == 'y' || continuechoice == 'Y');

    free(stack);

    return 0;
}
