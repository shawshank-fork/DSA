#include <stdio.h>

void addPolynomials(int poly1[], int poly2[], int result[], int n) {
    for (int i = 0; i <= n; i++) {
        result[i] = poly1[i] + poly2[i];
    }
}

void printPolynomial(int poly[], int n) {
    for (int i = n; i >= 0; i--) {
        if (poly[i] != 0) {
            if (i != n && poly[i] > 0) {
                printf("+");
            }
            printf("%dx^%d ", poly[i], i);
        }
    }
    printf("\n")
}

int main() {
    int n;
    
    printf("Enter the maximum degree of x: ");
    scanf("%d", &n);

    int poly1[n + 1];
    int poly2[n + 1];
    int result[n + 1];

    for (int i = 0; i <= n; i++) {
        poly1[i] = 0;
        poly2[i] = 0;
        result[i] = 0;
    }

    printf("Enter Polynomial-1 from lowest degree to highest degree: ");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &poly1[i]);
    }

    printf("Enter Polynomial-2 from lowest degree to highest degree: ");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &poly2[i]);
    }

    addPolynomials(poly1, poly2, result, n);

    printf("Resultant Polynomial: ");
    printPolynomial(result, n);

    return 0;
}
