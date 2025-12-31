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
   this -> level = level;
   this -> health = health;
}

//copy consructor
hero(hero& temp) {
    cout << " copy constructor called " << endl; 
   this->health  = temp.health;
   this->level = temp.level;
}

void print(){
    cout << health << endl;
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

 hero suresh(70, 'C');
 suresh.print();

//copy constructor
 hero ritesh(suresh);
 ritesh.print();

}