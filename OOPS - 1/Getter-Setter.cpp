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

int main(){

    //creation of object
    hero ramesh;
    cout << "The health is " << ramesh.gethealth() << endl;

    //use setter
    ramesh.sethealth(70);
    ramesh.level = 'S';

    cout << " Ramesh stats " << endl;
    cout << " Health = " << ramesh.gethealth() << endl;
    cout << " Level = " << ramesh.level << endl;

    return 0;
}