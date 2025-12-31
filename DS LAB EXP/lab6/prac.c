#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;


void push(char c);
char pop();
int isempty();
void intopost();
int space(char c);
void print();
int precedence(char symbol);

void push(char c) {
    if (top == MAX - 1) {
        printf(" stack overflow\n ");
        return;
    }
    top++;
    stack[top] = c;
}

char pop() {
    if (top == -1) {
        printf(" stack underflow\n ");
        exit(1);
    }
    return stack[top--];
}

int isempty() {
    return top == -1;
}

void intopost() {
    char symbol, next;
    int j = 0;

    for (int i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        if (!space(symbol)) {
            switch (symbol) {
                case '(':
                    push(symbol);
                    break;

                case ')':
                    while (!isempty() && (next = pop()) != '(') {
                        postfix[j++] = next;
                    }
                    break;

                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while (!isempty() && precedence(stack[top]) >= precedence(symbol)) {
                        postfix[j++] = pop();
                    }
                    push(symbol);
                    break;

                default:
                    postfix[j++] = symbol;
                    break;
            }
        }
    }
    while (!isempty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int space(char c) {
    return c == ' ' || c == '\t';
}

void print() {
    int i = 0;
    printf(" the postfix expression is: ");
    while (postfix[i]) {
        printf("%c", postfix[i++]);
    }
    printf("\n");
}

int precedence(char symbol) {
    switch (symbol) {
        case '^': return 3;
        case '/':
        case '*': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int main() {
    printf(" enter the infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = 0; 

    intopost();
    print();
    return 0;
}
