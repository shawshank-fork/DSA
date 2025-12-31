#include<iostream>
using namespace std;

bool search( int *arr, int s, int e, int k){

    if(s>e){
      return false;
    }

    int mid = s + (e - s)/2;

    if(arr[mid] == k){
        return true;
    }

    if(arr[mid] < k){

        return search(arr, mid + 1, e, k);
    }
    else{
        return search(arr, s, mid - 1, k);
    }
}



int main(){
    
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    int key = 4;

    cout << " present or not " << search(arr , 0, 5, key ) << endl;

    return 0;
}