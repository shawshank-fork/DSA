#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define max 100

struct stack {
    int top;
    char items[max];
};

void push(struct stack* s, char value) {
    if (s->top == (max - 1)) {
        printf("stack overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

char pop(struct stack* s) {
    if (s->top == -1) {
        printf("stack underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

char peek(struct stack* s) {
    if (s->top == -1) {
        return -1;
    }
    return s->items[s->top];
}

int isoperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^');
}

int precedence(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixtopostfix(char infix[], char postfix[]) {
    struct stack s;
    s.top = -1;
    int i = 0, j = 0;
    char symbol;

    while ((symbol = infix[i++]) != '\0') {
        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        } else if (symbol == '(') {
            push(&s, symbol);
        } else if (symbol == ')') {
            while (peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        } else if (isoperator(symbol)) {
            while (s.top != -1 && precedence(peek(&s)) > precedence(symbol)) {
                postfix[j++] = pop(&s);
            }
            push(&s, symbol);
        }
    }

    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';
}

void reversestring(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void swapparentheses(char str[]) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(') {
            str[i] = ')';
        } else if (str[i] == ')') {
            str[i] = '(';
        }
    }
}

void infixtoprefix(char infix[], char prefix[]) {
    char reversedinfix[max];
    char postfix[max];

    strcpy(reversedinfix, infix);
    reversestring(reversedinfix);
    swapparentheses(reversedinfix);

    infixtopostfix(reversedinfix, postfix);
    reversestring(postfix);

    strcpy(prefix, postfix);
}

int main() {
    char infix[max], prefix[max];

    printf("enter the infix expression: ");
    scanf("%s", infix);

    infixtoprefix(infix, prefix);

    printf("equivalent prefix expression is: %s\n", prefix);

    return 0;
}
