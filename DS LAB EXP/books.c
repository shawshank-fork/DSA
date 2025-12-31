#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store book information
struct Book {
    char title[100];
    char author[100];
    char publication[100];
    float price;
};

int main() {
    int n;
    printf("Enter the number of books: ");
    scanf("%d", &n);
    getchar(); // To consume the newline character left by scanf

    // Dynamically allocate memory for n books
    struct Book *books = (struct Book *)malloc(n * sizeof(struct Book));
    
    // Input books information
    for (int i = 0; i < n; i++) {
        printf("Enter title for book %d: ", i + 1);
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = 0; // Remove newline character

        printf("Enter author for book %d: ", i + 1);
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = 0; // Remove newline character

        printf("Enter publication for book %d: ", i + 1);
        fgets(books[i].publication, sizeof(books[i].publication), stdin);
        books[i].publication[strcspn(books[i].publication, "\n")] = 0; // Remove newline character

        printf("Enter price for book %d: ", i + 1);
        scanf("%f", &books[i].price);
        getchar(); // To consume the newline character left by scanf
    }

    char searchAuthor[100];
    printf("Enter the author to search for: ");
    fgets(searchAuthor, sizeof(searchAuthor), stdin);
    searchAuthor[strcspn(searchAuthor, "\n")] = 0; // Remove newline character

    // Display books by the particular author
    printf("\nBooks by %s:\n", searchAuthor);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].author, searchAuthor) == 0) {
            printf(" %s,  %s,  %s, %.2f\n",
                   books[i].title, books[i].author, books[i].publication, books[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("No books found by author %s.\n", searchAuthor);
    }

    // Free the allocated memory
    free(books);

    return 0;
}
