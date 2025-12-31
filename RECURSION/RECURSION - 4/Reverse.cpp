#include<iostream>
#include <string>
using namespace std; 

void rev( string& str, int i, int j){
     
    cout << " call recieved for " << str << endl;

    if(i>j){
        return;
    }

    swap(str[i], str[j]);
    i++;
    j--;

    rev(str,i,j);
}



int main(){

    string name = "shashank";

    cout << endl; 

    rev(name, 0, name.length() - 1);

    cout << endl;

    cout << name << endl;

    return 0;

}