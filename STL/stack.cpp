#include <iostream>
#include<stack>
using namespace std;  //LAST INN FIRST OUT

int main(){

    stack<string> s;

    s.push("shashank");
    s.push("lakhaiyar");

    cout<<"top element "<<s.top()<<endl;

    s.pop();
     cout<<"top element "<<s.top()<<endl;
}

