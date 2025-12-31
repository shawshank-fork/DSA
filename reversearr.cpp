#include <iostream>
using namespace std;

// 2 cases *odd and *even 

void reverse( int arr[], int n){

    int start = 0;
    int end = n-1;

    while (start <= end){

         swap( arr[start], arr[end]);
         start++;
         end--;
    }    
}

void printarr ( int arr[], int n) {

    for ( int i =0; i < n ; i++){
        cout<< arr[i]<< " ";
    }
    cout << endl;
}

int main(){
 
  int arr[6] = { 1,2,3,4,5,6};

  int brr[5] = {2,4,6,8,10};

  reverse (arr , 6);

  reverse (brr,5);

 

  printarr(arr,6);
  printarr(brr, 5);

  return 0;

}



#include <stdio.h>
#include <stdlib.h>

void reverseArray(int* arr, int n) {
    int temp;
    for(int i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

int main() {
    int n;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    // Dynamically allocate memory for the array
    int* arr = (int*)malloc(n * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }
    
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    reverseArray(arr, n);
    
    printf("Reversed array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Free the allocated memory
    free(arr);
    
    return 0;
}
