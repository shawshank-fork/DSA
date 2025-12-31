#include<iostream>
using namespace std; 

inline int max(int& a , int& b){

    return (a>b) ? a : b;
}

int main(){

    int a = 1, b = 2;
    int ans = 0;

    ans = max(a,b);
    cout << ans << endl;

    a = a + 3;
    b = b + 1;

    ans = max(a,b);
    cout << ans << endl;

    return 0;



}