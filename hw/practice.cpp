#include <iostream>

using namespace std;

int arrsum( int arr[] , int n){

    int sum = 0;

    for( int i = 0 ; i<n; i++){

        sum = sum + arr[i];
    }

    return sum;
}

// void upd(int a){

//     a = a / 2;
   
//    cout<< a << endl;
// }

// int pp(int b){

//     b -= 5;

//     cout << b << endl;
//     return b;

// }

int main(){

    // int a = 10 ;
    // upd(a);
    // cout<< a << endl;

    // int x = 15;
    // pp(x);
    // cout << x << endl;

    //  {

        /* To make all elements 1 */

//    int ar[10];
//    fill_n(ar,10,1);
//    for (int i = 0; i <= 10; i++)
//     {
//       cout << ar[i] << " ";
//    }


   /* PRINTING SUM OF ALL THE ELEMENTS OF AN ARRAY*/

   int size;
   int arr[100];

   cout<<" enter the size of the array "<<endl;
   cin>>size;

   cout<< " enter the elements of the array"<<endl;

   for( int i = 0 ; i<size; i++){
      cin>>arr[i];

   }

   cout<<" sum of the elements of the array is" << arrsum(arr , size);
  }
