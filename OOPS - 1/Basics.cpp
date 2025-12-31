#include <iostream>
using namespace std;

class hero {


public:
int health;
int level;

};

int main(){

    hero ramesh;

    ramesh.health = 90;
    ramesh.level = 'S';

    cout << " Ramesh stats " << endl;
    cout << " Health = " << ramesh.health << endl;
    cout << " Level = " << ramesh.level << endl;

    return 0;
}