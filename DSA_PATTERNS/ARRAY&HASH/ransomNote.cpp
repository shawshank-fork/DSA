#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include<unordered_map>

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26, 0);
 

        for(char c : magazine) {
            count[c - 'a']++;
        }

        for(char c : ransomNote) {
            if(count[c - 'a'] == 0) return false;
            count[c - 'a']--;
        }
        return true;
    }
};