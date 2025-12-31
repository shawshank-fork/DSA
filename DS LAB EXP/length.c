#include <stdio.h>
#include <string.h>

// Function to calculate the length of a string using a pointer
int stringLength(char *str) {
    char *ptr = str; // Pointer to the start of the string
    int length = 0;

    while (*ptr != '\0') { // Iterate until the null character
        length++;
        ptr++;
    }

    return length;
}

int main() {
    char str[100];

    // Input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character

    // Calculate and display the length of the string
    int length = stringLength(str);
    printf("The length of the string: %d\n", length);

    return 0;
}