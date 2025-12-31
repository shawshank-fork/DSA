#include <stdio.h>
#include <stdlib.h>

void transposeSparseMatrix(int sparseMatrix[][3], int rows) {
    int (*transposed)[3] = malloc(rows * sizeof(int[3]));
    transposed[0][0] = sparseMatrix[0][1];
    transposed[0][1] = sparseMatrix[0][0];
    transposed[0][2] = sparseMatrix[0][2];
    

    int k = 1;
    for (int i = 0; i < sparseMatrix[0][1]; i++) {
        for (int j = 1; j <= sparseMatrix[0][2]; j++) {
            if (sparseMatrix[j][1] == i) {
                transposed[k][0] = sparseMatrix[j][1];
                transposed[k][1] = sparseMatrix[j][0];
                transposed[k][2] = sparseMatrix[j][2];
                k++;
            }
        }
    }

    printf("Transpose of sparse matrix:\n");
    printf("R C Element\n");
    for (int i = 0; i <= transposed[0][2]; i++) {
        printf("%d %d %d\n", transposed[i][0], transposed[i][1], transposed[i][2]);
    }
    free(transposed);
}

int main() {
    int rows;
    printf("Enter the number of non-zero elements : ");
    scanf("%d", &rows);

    int (*sparseMatrix)[3] = malloc(rows * sizeof(int[3]));
    printf("Enter sparse matrix in 3-tuple format:\n");
    for (int i = 0; i < rows; i++) {
        scanf("%d %d %d", &sparseMatrix[i][0], &sparseMatrix[i][1], &sparseMatrix[i][2]);
    }

    transposeSparseMatrix(sparseMatrix, rows);
    free(sparseMatrix);
    return 0;
}
