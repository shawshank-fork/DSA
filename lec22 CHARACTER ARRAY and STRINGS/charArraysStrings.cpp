#include<iostream>
using namespace std;

int main(){

    char ch[20];

    cout<<"enter your name"<<endl;

    cin>>ch;

    ch[2] = '\0';

    cout<<"your name is"<< ch << endl;

}