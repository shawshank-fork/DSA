#include <iostream>
using namespace std;


int firstocc(  int arr[], int n, int k){

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    int ans = -1;

    while(s<=e){

        if(arr[mid] == k){
            ans = mid;
            e = mid -1;
        }
        else if(k > arr[mid]){
            s = mid + 1;
        }
        else if( k < arr[mid]){
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }

    return ans;

}

int lastocc(  int arr[], int n, int k){

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    int ans = -1;

    while(s<=e){

        if(arr[mid] == k){
            ans = mid;
            s = mid + 1;
        }
        else if(k > arr[mid]){
            s = mid + 1;
        }
        else if( k < arr[mid]){
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }

    return ans;

}


int main(){

    int even[5] = {1,3,3,4,5};
    
    cout<< "first occ is at index " << firstocc(even , 5 , 3)<<endl;
    cout<< "last occ is at index " << lastocc(even , 5 , 3)<<endl;

    return 0;
}     