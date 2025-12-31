
#include <iostream>
#include <climits>
using namespace std;


int getMin(int num[], int n) {

    // int min = INT_MAX;
    int mini = INT_MAX;

 
    for (int i = 0; i < n; i++) {
         
         mini = min( mini , num[i]);

    //     if (num[i] < min) {
    //         min = num[i];
    //     }
    }

    return mini;
}

int getMax(int num[], int n) {
    // int max = INT_MIN;
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++) {

        maxi = max( maxi , num[i]);   // alt way through max and min comms.

        // if (num[i] > max) {
        //     max = num[i];
        // }
    }

    return maxi;
}

// // void printarray( int arr[] , int size){

// //     cout<< " printing the array "<< endl;

// //     //print the array
// //     for( int i = 0 ; i < size ; i++){
// //         cout << arr[i] << " ";
// //     }
// //      cout<< endl;
      
// //     cout << " printing done "<< endl;
// // }

int main() {
    
//     // int num[15];

//     // cout<<"value at index 14 is "<< num[14] << endl;

//     // int ar[15] = {2,7};

//     // int n = 15;

//     // printarray(ar,15);

//     // cout<< "printing array " << endl;

//     // for( int i = 0; i<n ; i++) {

//     //     cout<< ar[i] << " ";
//     // }

       /* MAX MIN */

    int size;
    cin >> size;

    int num[100];

    //taking input in array
    for (int i = 0; i < size; i++) {
        cin >> num[i];
    }

    cout << "max value is " << getMax(num, size) << endl;
    cout << "min value is " << getMin(num, size) << endl;

    return 0;
}



