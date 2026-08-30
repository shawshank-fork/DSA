#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include<unordered_map>

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_map<int, int> mp;

        mp[0] = 1;
        
        int prefixSum = 0;
        int count = 0;

        for(int i = 0; i < n; i++) {
            prefixSum += nums[i];

            int remove = prefixSum - k;

            if(mp.find(remove) != mp.end()) {
                count += mp[remove];
            }
            mp[prefixSum]++;
        }
        return count;
    }
};