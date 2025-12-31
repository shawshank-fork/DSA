#include<iostream>
using namespace std;

void rev(char ch[], int n){
    int s = 0;
    int e = n-1;

    while(s<=e){
        swap(ch[s++] , ch[e--]);
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
    
    rev(ch,length);
    cout<<"reverse is "<<endl;
    cout<< ch << endl;
    
    return 0;
}