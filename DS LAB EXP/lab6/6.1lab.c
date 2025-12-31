#include <stdio.h>
#include <stdlib.h>

int *stack;
int top = -1;
int maxsize;

void push( int element) {

    if( top == maxsize - 1) {
        printf( " stack overflow cnat push %d\n", element);
    }else {
        stack[++top] = element;
        printf("%d has been pushed\n", element);
    }
}

void pop () {

    if( top == -1) {
        printf( " stack underflow bitch!\n ");
    }else {
        int element = stack[top--];
        printf( " deleted %d\n", element);
    }
}

void display() {
    if(top == -1) {
        printf(" stack is empty \n");
    }
    else{
        printf( " the elements of the stack are: ");
        for( int i = top; i >= 0; i-- ) {
            printf("%d", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, element, initialelements;
    char cont;

    printf(" size of stack: ");
    scanf("%d", &maxsize);

    stack = (int *)malloc(maxsize * sizeof(int));

    if(stack == NULL) {
        printf(" memory allocation failed!\n ");
        return 1;
    }
    
    printf( " enter the number of elements: ");
    scanf( "%d", &initialelements);

    if(initialelements > maxsize) {
       printf(" number of elements exceeds the size of stack.");
    }

    printf(" enter the %d elements: \n", initialelements);
    for(int i = 0; i<initialelements; i++) {
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

        if( choice != 4) {
            printf( " do you wnat to continue (Y/N): ");
            scanf( "%d", &cont);
            if(cont == 'n' || cont == 'N') {
                break;
            }
        }
    } while (choice != 4);

    return 0;   
}