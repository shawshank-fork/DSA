#include <iostream>
#include <vector>
using namespace std;

int main(){

    double b = 2.34;

    double *ptr = &b;

    cout<< "answer you got is "<< *ptr<< endl;
    cout<< "answer you got is "<<  ptr<< endl;

    return 0;
}