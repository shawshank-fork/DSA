#include <stdio.h>

// Function to compare two numbers
void compareNumbers(int *num1, int *num2) {
    if (*num1 > *num2) {
        printf("%d is greater than %d\n", *num1, *num2);
    } else if (*num1 < *num2) {
        printf("%d is smaller than %d\n", *num1, *num2);
    } else {
        printf("%d is equal to %d\n", *num1, *num2);
    }
}

int main() {
    int a, b;

    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Compare the numbers
    compareNumbers(&a, &b);

    return 0;
}
