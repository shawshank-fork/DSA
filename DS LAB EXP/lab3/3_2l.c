#include <stdio.h>
#include <stdlib.h>

void readsm(int (*sm)[3], int rows) {
    printf("Enter sparse matrix in 3-tuple form:\n");
    for (int i = 0; i < rows; i++) {
        scanf("%d %d %d", &sm[i][0], &sm[i][1], &sm[i][2]);
    }
}

void printsm(int (*sm)[3], int rows) {
    printf("Resultant Matrix in 3-tuple format:\n");
    printf("%d %d %d\n", sm[0][0], sm[0][1], sm[0][2]);
    for (int i = 1; i < rows; i++) {
        printf("%d %d %d\n", sm[i][0], sm[i][1], sm[i][2]);
    }
}

void addsm(int (*sm1)[3], int rows1, int (*sm2)[3], int rows2) {
    int maxSize = rows1 + rows2 - 1; 
    int (*result)[3] = malloc(maxSize * sizeof(int[3]));
    result[0][0] = sm1[0][0];
    result[0][1] = sm1[0][1];
    int k = 1;

    int i = 1, j = 1;
    while (i < rows1 && j < rows2) {
        if (sm1[i][0] < sm2[j][0] || (sm1[i][0] == sm2[j][0] && sm1[i][1] < sm2[j][1])) {
            result[k][0] = sm1[i][0];\
            result[k][1] = sm1[i][1];
            result[k][2] = sm1[i][2];
            i++;
        } else if (sm1[i][0] > sm2[j][0] || (sm1[i][0] == sm2[j][0] && sm1[i][1] > sm2[j][1])) {
            result[k][0] = sm2[j][0];
            result[k][1] = sm2[j][1];
            result[k][2] = sm2[j][2];
            j++;
        } else {
            result[k][0] = sm1[i][0];
            result[k][1] = sm1[i][1];
            result[k][2] = sm1[i][2] + sm2[j][2];
            i++;
            j++;
        }
        k++;
    }

    while (i < rows1) {
        result[k][0] = sm1[i][0];
        result[k][1] = sm1[i][1];
        result[k][2] = sm1[i][2];
        i++;
        k++;
    }

    while (j < rows2) {
        result[k][0] = sm2[j][0];
        result[k][1] = sm2[j][1];
        result[k][2] = sm2[j][2];
        j++;
        k++;
    }

    result[0][2] = k - 1;
    printsm(result, k);
    free(result);
}

int main() {
    int rows1, rows2;

    printf("Enter the number of non-zero elements for sparse matrix - 1: ");
    scanf("%d", &rows1);
    int (*sm1)[3] = malloc(rows1 * sizeof(int[3]));
    readsm(sm1, rows1);

    printf("Enter the number of non-zero element for sparse matrix - 2: ");
    scanf("%d", &rows2);
    int (*sm2)[3] = malloc(rows2 * sizeof(int[3]));
    readsm(sm2, rows2);

    if (sm1[0][0] != sm2[0][0] || sm1[0][1] != sm2[0][1]) {
        printf(" dimensions do not match for addition \n");
        free(sm1);
        free(sm2);
        return 1;
    }

    addsm(sm1, rows1, sm2, rows2);

    free(sm1);
    free(sm2);
    return 0;
}
