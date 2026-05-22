#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include<stack>
#include<string>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> c;

        for(auto s : tokens) {
            if(s == "+") {
                int a = c.top(); c.pop();
                int b = c.top(); c.pop();
                c.push(b + a);
            }
            else if(s == "-") {
                int a = c.top(); c.pop();
                int b = c.top(); c.pop();
                c.push(b - a);
            }
            else if(s == "*") {
                int a = c.top(); c.pop();
                int b = c.top(); c.pop();
                c.push(b * a);
            }
            else if(s == "/") {
                int a = c.top(); c.pop();
                int b = c.top(); c.pop();
                c.push(b / a);
            }
            else {
                c.push(stoi(s));
            }
        }
        return c.top();
        
    }
};