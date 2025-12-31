#include<iostream>
using namespace std;

int main(){

   int i = 6;
   int* p = &i;
   int** p2 = &p;

   cout << endl << " printing p " << p << endl;
   cout << " address of p " << &p << endl;



   cout<< *p2 << endl;

   cout<< i << endl;
   cout << *p << endl;
   cout << **p2 << endl;

   return 0;
}