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
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int curMax = nums[0];
        int curMin = nums[0];
        int ans = nums[0];

        for(int i = 1; i < n; i++) {
            int prevMax = curMax;
            int prevMin = curMin;

            curMax = max({nums[i], nums[i] * prevMax, nums[i] * prevMin});
            curMin = min({nums[i], nums[i] * prevMax, nums[i] * prevMin});

            ans = max(ans, curMax); 
        }
        return ans;
    }
};