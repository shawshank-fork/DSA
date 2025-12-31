#include<iostream>
using namespace std;

bool search(int arr[] , int size , int key){
    if( size == 0 ){
        return  false;
    }

    if(arr[0] == key){
        return true;
    }

    else{
        bool remainingpart = search( arr + 1, size - 1, key);
        return remainingpart;
    }

}




int main(){

    int arr[5] = {1,2,3,4,5};
    int size = 5;
    int key = 9;

    bool ans = search(arr , size , key);

    if(ans){
        cout << " present " << endl;
    }else{
        cout << " absent " << endl;
    }

    return 0;
}