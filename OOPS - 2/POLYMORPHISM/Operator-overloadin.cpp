#include <iostream>
using namespace std; 


class b {
  
  public:
  int a;
  int c;

  public:
  int add() {
    return a + c;
  }

  void operator+ (b &obj) {
      
      int val1 = this->a;
      int val2 = obj.a;
      cout << " output " << val2 - val1 << endl;
  }


};

int main() {

   b obj1, obj2;

   obj1.a = 4;
   obj2.a = 7;

   obj1 + obj2;

   return 0;
}