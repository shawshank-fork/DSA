#include <iostream>
using namespace std;

class hero {


private:
int health;

public:
int level;

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

    hero a;
    
    a.sethealth(80);
    a.setlevel('A');

    cout << " level is " << a.level << endl;
    cout << " health is " << a.gethealth() << endl;

    //Dynamically
    hero *b = new hero;

    b->setlevel('C');
    b->sethealth(70);
    
    cout << " level is " << (*b).level << endl;
    cout << " Health is " << (*b).gethealth() << endl;


    cout << " level is " << b->level << endl;
    cout << " health is " << b->gethealth() << endl;

    return 0;
}