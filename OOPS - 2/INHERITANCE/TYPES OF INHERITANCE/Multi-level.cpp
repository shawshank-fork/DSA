#include <iostream>
using namespace std;

class animal {

    public:
    int age;
    int weight;

    public:
    void speak() {
        cout << " speaking " << endl;
    }

};

class dog: public animal {
    
};

class bulldog: public dog {
   

};

int main() {

   bulldog billy;
   billy.speak();

    return 0;


}