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
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for(int i = 1; i < n; i++) {
            int take = nums[i];
            if(i > 1) take += prev2;

            int notTake = 0 + prev; 

            int curi = max(take, notTake);
            prev2 = prev;
            prev = curi;

        }
        return prev;

        // vector<int>dp(n);

        // if(n == 1) return nums[0];

        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);

        // for(int i = 2; i < n; i++) {
        //     int  take = nums[i];
        //     if(i > 1) take += dp[i - 2];

        //     int notTake = dp[i - 1];

        //     dp[i] = max(take, notTake);
        // }
        // return dp[n - 1];

        // int prev2 = nums[0];
        // int prev = max(nums[0], nums[1]);

        // for(int i = 2; i < n; i++) {
        //     int take = nums[i];
        //     if(i > 1) take += prev2;

        //     int notTake = prev;

        //     prev2 = prev;
        //     prev = max(take, notTake);
        // }
        // return prev;
    }
};