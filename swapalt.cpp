#include <iostream>

using namespace std;

void swap( int arr[], int n){

    for(int i = 0 ; i<n ; i+=2){

        if( i + 1 < n){
            swap( arr[i] , arr[i+1]);
        }
    }
} 

int printarr(int arr[], int n){

    for( int i = 0; i<n; i++){
        cout<< arr[i] << " ";
    }
     cout<< endl;
}

int main(){

    int arr[6] = {1,3,5,7,9,11};

    swap(arr , 6);

    printarr(arr , 6);

    return 0;
}