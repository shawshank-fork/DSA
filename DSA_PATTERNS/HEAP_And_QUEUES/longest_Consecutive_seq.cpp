#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto num : nums) {
            mp[num] = num;
        }

        int longest = 0;

        for(auto num : mp) {
            int dig = num.first;
            if(mp.find(dig - 1) == mp.end()) {
                int current = dig;
                int length = 1;

                while(mp.find(current + 1) != mp.end()){
                    current++;
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};