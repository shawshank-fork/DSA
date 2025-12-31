#include <iostream>
using namespace std;
/* evenodd*/

// bool iseven(int a){
//        //odd
//         if(a&1){
//             return 0;
//         } else{
//             return 1;
//         }
// }

/* ncr*/

// int factorial (int n){
//     int fact = 1;

//     for(int i =1 ; i<=n ; i++){
//         fact = fact * i;
//     }
//     return fact;
// }

// int ncr(int n , int r){
//     int num = factorial(n);
//     int denom = factorial(r) * factorial(n-r);
//     return num/denom;
// }

/* prime no*/

bool isprime(int n){

    for( int i = 2; i<n ; i++ ){

        if(n%i == 0) {

            return 0;
        }
    }

    return 1;
}



int main(){

    // int a , b;
    // cout<< " enter the value of a"<<endl;
    // cin>>a;

    // cout<<"enter the value of b"<<endl;
    // cin>>b;

    // char op;
    // cout<<"enter operation you want to perform"<<endl;
    // cin>>op;

    // switch(op){

    //     case '+':cout<< (a+b)<<endl;
    //     break;

    //     case '-': cout<< (a-b)<<endl;
    //     break;

    //     case '*': cout<< (a*b)<<endl;
    //     break;

    //     case '/': cout<< (a/b)<<endl;
    //     break;

    //     case '%':cout<< (a%b)<<endl;
    //     break;

    //     default : cout<<"not a valid operation"<<endl;

    //     }


        //FUNCTIONS

    //1. pow(a,b)
    //2. even odd programme

    // int n;
    // cout<<"enter the number "<<endl;
    // cin>>n;

    // if (iseven(n)){
    //     cout<<"number is even"<<endl;
    // } else{
    //     cout<<"number is odd"<<endl;
    // }

    // return 0;


    //3.ncr

    // int n , r;
    // cin>> n >> r ;
    // cout<<"answer is "<< ncr(n , r) << endl;

    //4. primeno

    int n;

    cin>>n;

    if(isprime(n)) {

        cout<< "prime number" <<endl;
    }

     else{
        cout<< "not a prime number" <<endl;
    }






            }

