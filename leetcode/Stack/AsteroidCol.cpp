#include <stack>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;


class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            list<int> st;
    
            int n = asteroids.size();
            for (int i = 0; i <= n-1; i++) {
                if(asteroids[i] > 0) st.push_back(asteroids[i]);
                else {
                    while(!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) st.pop_back();
    
                    if(!st.empty() && st.back() == abs(asteroids[i])){
                            st.pop_back();
                    } 
    
                    else if(st.empty() || st.back() < 0){
                         st.push_back(asteroids[i]);
                         continue;
                    } 
                }
            }
            return vector<int>(st.begin(), st.end());
    
        }
    };