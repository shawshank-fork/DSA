#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>

    
    //SPACE OPTIMIZED
    int findWays(vector<int>& arr, int k)
    {
        int n = arr.size();
        vector<int> prev(k+1, 0), cur(k+1, 0);

        // Base case
        if(arr[0] == 0) prev[0] = 2;         // zero doubles ways
        else prev[0] = 1;
        if(arr[0] != 0 && arr[0] <= k) prev[arr[0]] = 1;

        for(int ind = 1; ind < n; ind++){
            for(int sum = 0; sum <= k; sum++){
                int notTake = prev[sum];
                int take = 0;
                if(arr[ind] <= sum) take = prev[sum - arr[ind]];

                cur[sum] = (take + notTake);
            }
            
            prev = cur;
        }

        return prev[k];
    }


    //RECURSION
    int solve(int ind, int currSum, vector<int>& nums, int target) {
        if(ind == nums.size()) {
            return (currSum == target)? 1 : 0;
        }
        int plus = solve(ind + 1, currSum + nums[ind], nums, target);
        int minus = solve(ind + 1, currSum - nums[ind], nums, target);

        return plus + minus;
    }
    
    //TABULATION
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        // vector<vector<int>> dp(n + 1, vector<int>())
        // // return  countPartitions(n, target, nums);
        // return solve(0, 0, nums, target);
        int totSum = 0;
        for(int num : nums) {
            totSum += num;
        }
        if(abs(target) > totSum) return 0;

        if((totSum + target) % 2 != 0) return 0;

        int newT = (totSum + target) / 2;

        vector<vector<int>> dp(n, vector<int>(newT + 1, 0));

        if(nums[0] == 0) dp[0][0] = 2;
        else {
            dp[0][0] = 1;
        }

        if(nums[0] != 0 && nums[0] <= newT){
            dp[0][nums[0]] = 1;
        }

        for(int ind = 1; ind < n; ind++) {
            for(int sum = 0; sum <= newT; sum++) {
                int notTake = dp[ind - 1][sum];
                int take = 0;
                if(nums[ind] <= sum){
                    take = dp[ind - 1][sum- nums[ind]];
                }
                dp[ind][sum] = take + notTake;
            }
        }
        return dp[n-1][newT];
    }