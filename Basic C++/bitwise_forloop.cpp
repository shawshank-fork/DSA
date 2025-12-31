#include<iostream>
using namespace std;

int main(){
    /* Sum from 1 to n */
    // int n;
    // cout<<"enter the value of n "<<endl;
    // cin>>n;

    // int sum = 0;
    // for(int i=1 ;i<=n;i++ ){
    //     sum = sum + i;   
    // }
    // cout<<sum<<endl;


    // /* fibonacchi series */

 
    // int n =10 ;

    // int a = 0 ;
    // int b = 1 ;

    // cout<< a << " " <<b<< " " ;

    // for(int i = 1; i<=n;i++){

    //     int nextnum = a + b;
    //     cout<< nextnum <<" ";
        
    //     a = b;
    //     b = nextnum;

    // }

    /* CHECKING PRIME understanding "break operators use" */ 

    int n;
    cout<<"enter the number"<<endl;
    cin>>n;

    bool isprime = 1;

    for(int i=2; i<n;i++){

        if(n%i==0){
            isprime == 0;
            break;
        }
    }

    if(isprime == 0){
        cout<< "not a prime number"<<endl;
    }else{
        cout<<"is a prime number"<<endl;
    
      

      /*UNDERSTANDING 'continue*/

      // for(int i = 0; i < 5 ; i++){
      //   cout<<"helo"<<endl;
      //   cout<<"mukesh"<<endl;
      //   continue;

      //   cout<<"reply to dede bkl"<<endl;
      // }

  }
}
