#include <iostream>
using namespace std;

int main(){

int f = 100;
int* p = &f;

int **q = &p;
int second = ++(**q);
int**r = q;
//++(*r);


cout << *p << endl << p << endl << &f << endl << f << endl <<second << endl << *r << endl << *q << endl << **q ;


    return 0;
}
