#include <iostream>
using namespace std;

 class a {

    public:
    void func() {
        cout << " inside func 1 " << endl;
    }
 };

 class b {
    
    public:
    void func() {
       cout << " inside func 2" << endl;
    }

 };

 class c: public a, public b {
    
 };

 int main () {

    c obj;

    //obj.func(); will give error

    obj.a::func();
    obj.b::func();

    return 0; 
 }