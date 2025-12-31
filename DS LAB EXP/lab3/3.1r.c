#include <stdio.h>
#include <stdlib.h>
void trans(int a[][3], int m)
{
    int r = a[0][1], k = 0;
    int (*b)[3] = malloc(m*sizeof(int[3]));
    for(int i = 1; i < m; i++)
    {
        if(r < a[i][1])
        r = a[i][1];
    }
    for(int i = 0; i <= r; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[j][1] == i)
            {
                b[k][0] = a[j][1];
                b[k][1] = a[j][0];
                b[k][2] = a[j][2];
                k++;
            }            
        }
    }
    printf("Transpose of Sparse Matrix: \n");
    printf("Row \tColumn \tValue \n");
    for(int i = 0; i < m; i++)
    printf("%d \t%d \t%d \n",b[i][0],b[i][1],b[i][2]);
    free(a);
    free(b);
}

int main()
  
{
    int n;
    printf(" Enter the number of non zero elements : ");
    scanf("%d", &n);
    int (*ptr)[3] = malloc(n*sizeof(int[3]));
    printf("Enter the Sparse Matrix: \n");
    for(int i = 0; i < n; i++)
    scanf("%d %d %d",&ptr[i][0],&ptr[i][1],&ptr[i][2]);
    trans(ptr,n);
    free(ptr);
    return 0;
}