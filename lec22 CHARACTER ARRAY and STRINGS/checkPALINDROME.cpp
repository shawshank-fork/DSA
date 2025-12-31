#include<iostream>
using namespace std;

char lowercase(char ch){
    if(ch>='a' && ch<='z'){
        return ch;
    }
    else{
       char temp = ch - 'A' + 'a';
       return temp;
    }
}


bool checkpal(char a[] , int n){
    int s= 0;
    int e = n-1;

    while(s<=e){
        if(lowercase(a[s]) != lowercase(a[e])){
            return 0;
        }
        else{
            s++;
            e--;
        }
        return 1;
    }
}

int len(char ch[]){

    int count = 0;

    for(int i=0; ch[i] != '\0';i++)
    count++;

    return count;
}

int main(){

    char ch[50];

    cout<<"enter your name"<<endl;

    cin>>ch;

    cout<<"your name is ";
    cout << ch << endl;

    int length = len(ch);
    cout<<"length is "<< length << endl;
    
    // rev(ch,length);
    // cout<<"reverse is "<<endl;
    // cout<< ch << endl;

    cout<<"palindrome or not "<<checkpal(ch , length)<<endl;
    
    return 0;
}
