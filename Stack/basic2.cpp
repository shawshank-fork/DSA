#include <iostream>
#include <stack>
using namespace std;

class mstack {

  public:
       int *arr;
       int top;
       int size;

   //behaviour
   mstack(int size) {

    this -> size = size;
    arr = new int[size];
    top = -1; 

   }

   void push ( int element) {

    if( size - top > 1) {
        top++;
        arr[top] = element;

    } else {

        cout << " stack overflow " << endl;

     }

  }

    void pop() {

        if(top >=0) {
            top--;
        }
        else {
            cout << " stack underflow " << endl;
        }
    }

    int peek() {

        if(top >= 0)
           return arr[top];
        else {

            cout << " stack is empty " << endl;
            return -1;
        }   

    }

    bool isempty() {

        if( top == -1) {
            return true;
        }
        else {
            return false;
        }
    }

 } ;
 

 int main() {

    mstack st(5);

    st.push(12);
    st.push(22);
    st.push(21);
    st.push(45);
    st.push(2);

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    if(st.isempty()) {
        cout << " stack is empty my G " << endl;
    }
    else {
        cout << " stack ain't empty " << endl;
    }

    return 0;

 }



