#include<iostream>
using namespace std;

int len(char ch[]){

    int count = 0;

    for(int i=0; ch[i] != '\0';i++)
    count++;

    return count;
}


int main(){

    char ch[20];

    cout<<"enter your name"<<endl;

    cin>>ch;

    cout<<"your name is "<< ch << endl;

    cout<<"length "<<len(ch)<<endl;
    
    return 0;
}