#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main() {

    unordered_map<string,int> m;  //< key, value >

    //ways for insertion

    //1
    pair<string,int> pair1("shashank", 3);
    m.insert(pair1);

    //2
    pair<string,int> p2 = make_pair("lakhaiyar", 4);
    m.insert(p2);

    //3
    m["mera"] = 1;

    //what will happen?
    m["mera"] = 2;  //it updates mappng from 1 to 2

    //search
    cout << m["mera"] << endl;
    cout << m.at("lakhaiyar") << endl;

    cout << m["unknownkey"] << endl; //by searchingin this way it creates an entry for the unkown key by assigning it 0
    // cout << m.at("unkownkey") << endl; //this does not do that and will not assign anything

    //size
    cout << m.size() << endl;

    //check presence
    cout << m.count("shashank") << endl;

    //erase
    m.erase("shashank");
    cout << m.size() << endl;

    //to access whole map
    unordered_map<string,int> :: iterator it = m.begin();

    while(it != m.end()) {
        cout << it->first << " " << it->second << endl;
        it++;
    } //it prints the key and value in an unordered way, to print it in an ordered way use just map instead of unordered_map




    return 0;
}
