#include <iostream>
#include <climits>
using namespace std; 


int largestrowsum(int arr[][3] , int i , int j){

    int maxi = INT_MIN;
    int rowindex = -1;

     for(int i= 0; i<3; i++){
        int sum = 0;
        for(int j = 0; j<3; j++){
            sum += arr[i][j] ;
        }

        if(sum > maxi){
            maxi = sum;
            rowindex = i;
        }
    }

    cout<< "the maximum sum is " << maxi << endl;
    return rowindex;
}


int main(){

    int arr[3][3];

      cout<<"enter the elements"<<endl;

     for(int i= 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cin >> arr[i][j];
        }
    }
     
     
     cout<<"printing the array"<<endl;

     for(int i= 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }

    int ansindex = largestrowsum(arr , 3 ,3);
    cout<< "max row is at index " << ansindex << endl;

    return 0;

}