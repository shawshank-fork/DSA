#include <iostream>
#include<vector>
using namespace std;

vector<int> reverse(vector<int> v){

    int s = 0;
    int e = v.size() - 1;

    while(s<=e){
        swap(v[s] , v[e]);
        s++;
        e--;
    }
    return v;
}

void print(vector<int> v){

    for(int i = 0; i<v.size(); i++){
        cout<< v[i] << " ";
    }
    cout<< endl;
}

int main(){

    vector<int> v;

    v.push_back(23);
    v.push_back(3);
    v.push_back(63);
    v.push_back(83);
    v.push_back(13);

    vector<int> ans = reverse(v);

    cout<<"printing reverse array"<<endl;
    print(ans);

    return 0;
}