#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, element, found = 0;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n integers
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input array elements
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &element);

    // Search for the element in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            printf("%d exists at index %d\n", element, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("%d does not exist in the array\n", element);
    }

    // Free the allocated memory
    free(arr);

    return 0;
}

