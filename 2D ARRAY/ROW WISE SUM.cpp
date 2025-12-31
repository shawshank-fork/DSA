#include <iostream>
using namespace std;


bool ispresent(int arr[][3] , int target , int i , int j){
            for(int i= 0; i<3; i++){
        for(int j = 0; j<4; j++){
            
            if(arr[i][j] == target){
                return 1;
            }
        }
    }
    return 0;
}


void printsum(int arr[][3] , int i, int j){
     cout<< "printing sum -> "<<endl;

     for(int i= 0; i<3; i++){
        int sum = 0;
        for(int j = 0; j<3; j++){
            sum += arr[i][j] ;
        }

        cout << sum << endl;
    }


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

        cout<< "enter the element to search"<<endl;
    int target;
    cin>>target;

    if(ispresent(arr , target , 3 ,3)){
        cout<<"element found"<<endl;
    }
    else{
        cout<<"element not found"<<endl;
    }
   
    printsum(arr , 3 ,3);

   return 0;

 
}