#include<iostream>
#include<string>
using namespace std; 

bool palindrome(string str, int i, int j){

    if(i>j){
        return true;
    }

    if(str[i] != str[j]){
        return false;
    }
    else{
        return palindrome(str, i+1, j+1);
    }
}



int main(){

    string name = "bookkoob";
    cout << endl;

    bool isplaindrome =  palindrome(name, 0, name.length() - 1);

    if(palindrome){
        cout << " its a palindrome " << endl;
    }
    else{
        cout << " not a palindrome " << endl;
    }
}