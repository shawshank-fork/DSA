#include <stdio.h>
#define n 100
int stack[n];

int top = -1;

void push( int x) {
    
    if( top == n  - 1) {

        printf( " stack overflow \n ");

    }
    else {
        top ++;
        stack[top] = x;
    }
}

void pop (int item) {

    if(top == -1) {
        printf( " stack underflow\n ");
    }

    else {
        item = stack[top];
        top--;
    }
}

void peek() {

    if(top == -1) {
        printf(" stack is empty\n ");
    }
    else {
        printf ( "%d", stack[top]);
    }
}

void display() {
    
    for( int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
    }
}

int main() {
    
    int x, item;
    int ch;

    do {
        printf("enter choice of operation: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
            push(x);
            break;
            case 2:
            pop(item);
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            default:
            printf("Invalid choice");
        }
    }while(ch!= 0);
}

