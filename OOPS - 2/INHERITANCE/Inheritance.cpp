#include <iostream>
using namespace std;

class human {
   
  public:

  int height;
  int weight;
  int age;


  public:

  int getage(){
    return this->age;
  }

  void setweight(int w){
     this->weight = w;
  }

};

class Male: public human {
    
    public:
     string color;

     void sleep(){
        cout << " sleeping " << endl;
     }
};



int main() {

    Male rakesh;
    cout << rakesh.age << endl;
    cout << rakesh.weight << endl;
    cout << rakesh.height << endl;

    cout << rakesh.color << endl;

    rakesh.setweight(90);
    cout << rakesh.weight << endl;
    rakesh.sleep();

    return 0;

}