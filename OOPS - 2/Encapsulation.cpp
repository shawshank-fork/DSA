//Wrapping up data members and functions. (Data Hiding)

// Fully encapsulated class - all D.M -> private marked.

#include <iostream>
using namespace std;

class student {

    private:
        string name;
        int age;
        int height;


    public:
    int getage(){
        return this->age;
    } 
  
};

int main(){

    student first;

    cout << endl ;
    cout << " All good my G " <<endl;
    cout << endl;

    return 0;
}


