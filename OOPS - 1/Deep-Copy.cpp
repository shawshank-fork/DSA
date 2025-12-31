#include <iostream>
#include <cstring>
using namespace std;


class Hero {


private:
int health;

public:
char *name;
char level;

Hero() {
    cout << " constructor called " << endl;
    name = new char[100];
}

Hero(int health) {
   this -> health = health;
}

Hero(int health, char level) {
   this -> level = level;
   this -> health = health;
}

//copy constructor 
Hero(Hero& temp) {

    char *ch = new char[strlen(temp.name) + 1];
    strcpy(ch, temp.name);
    this->name = ch;

   cout << " copy constructor called " << endl; 
   this->health  = temp.health;
   this->level = temp.level;
}

  void print(){
    cout << " name " << this->name << " , ";
    cout << " health " << this->health << " , ";
    cout << " level " << this->level << " , ";
    cout << endl << endl;
  }

    int getHealth() {
    return health;
  }

    int getLevel() {
    return level;
  }

    void setHealth(int h) {
      health = h;
   }

    void setLevel(int ch) {
    level = ch;
  }

    void setName(char name[]) {
    strcpy(this->name, name) ;
  }

  

};

int main() {

  //STATIC KEYWORD - datatype className :: fieldname = value
    // ex - int gero :: timetocomplete = 5; should be written before int main


    Hero hero1;

    /* For printing static keywod
    
    cout << hero :: timetocomplete << endl;  */

    hero1.setHealth(12);

    hero1.setLevel('D');

    char name[7] = "Babbar";

    hero1.setName(name);

    hero1.print();

    //use default copy constructor

    Hero hero2(hero1);
    hero2.print();

    hero1.name[0] = 'G';
    
    cout << "1" << endl;
    hero1.print();

    cout << "2" << endl;
    hero2.print();

    return 0;
}