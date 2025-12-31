#include <iostream>
using namespace std;

int main(){

    int arr[10] = { 2,5,6};



    cout<< " address - " << arr << endl;
    cout<< " address - " << &arr[0] << endl;
    cout << " value - " << *arr << endl;

    cout<< " value - " << *arr + 1 << endl;
    cout<< " value - " << *(arr + 1) << endl;
    cout<< " value - " << *(arr) + 1 << endl;

    return 0;
}