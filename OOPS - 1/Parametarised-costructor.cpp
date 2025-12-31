#include <iostream>
using namespace std;

class hero {


private:
int health;

public:
char level;

hero() {
    cout << " constructor called " << endl;
}

hero(int health) {
   cout << " this -> " << this << endl;
   this -> health = health;
}

hero(int health, char level) {
   cout << " this -> " << this << endl;
   this -> health = health;
}

void print(){
    cout << level << endl;
}

int gethealth() {
    return health;
}

int getlevel() {
    return level;
}

void sethealth(int h) {
    health = h;
}

void setlevel(int ch) {
    level = ch;
}

};

int main() {
    
    //statically
    hero ramesh(10);
    cout << " address of ramesh " << &ramesh << endl;
    ramesh.gethealth();


    //dynamically
    hero *h = new hero(11);
}