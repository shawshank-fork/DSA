#include <iostream>
#include<queue>
using namespace std;  //FIRST INN FIRST OUT

int main(){

    queue<string> q;

       q.push("shashank");
    q.push("lakhaiyar");
    
    cout<<"size before pop"<<q.size()<<endl;

    cout<<"first element"<<q.front()<<endl;

    q.pop();
    cout<<"firsr element"<<q.front()<<endl;

    cout<<"size after pop"<<q.size()<<endl;

}