
// LIFO - Last in First out 


#include <iostream>
#include <stack>
using namespace std;

int main() {

    stack<int> s;

    s.push(2);
    s.push(5);

    s.pop();
    
    cout << endl;
    cout << " the top element is " << s.top() << endl;
    cout << endl;

    if(s.empty()) {

        cout << " stack is empty " << endl;
    } else {

        cout << " stack is not empty " << endl;
    }

    cout << " size of the stack is " << s.size() <<  endl;

    return 0;
}