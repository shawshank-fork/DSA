#include <iostream>
#include<map>
using namespace std;

int main(){
    map<int,string> m;

    m[1]= "lakhaiyar";
    m[12]= "shashank";
    m[2]= "bimtesh";

    m.insert( {5,"mukesh"}); // to insert value

    cout<<"before erase"<<endl;
    for(auto i : m){
        cout<<i.first<<" "<<i.second
        <<endl;
    }

    cout<<"finding 13 "<<m.count(13)<<endl;

    auto it = m.find(2);
    for(auto i = it; i!=m.end(); i++ ){
        cout<<(*i).first<<endl;
    }

    //to erase = m.erase(n)  
    // O(logn)
}