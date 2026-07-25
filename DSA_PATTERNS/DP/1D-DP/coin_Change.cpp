#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>

//Unbounded knapsack approach

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1, 0), cur(amount+1,0);

        for(int T = 0; T<=amount; T++) {
            if( T % coins[0] == 0) prev[T] =  T / coins[0];
            else prev[T] = 1e9; 
        }

        for(int ind = 1; ind < n; ind++) {
            for(int T = 0; T <= amount; T++) {
                 int notTake = 0 + prev[T];
                 int take = INT_MAX;
                 if(coins[ind] <= T) {
                    take = 1 + cur[T-coins[ind]];
                }
                cur[T] = min(take, notTake);
            }
            prev = cur;
        }
        int ans = prev[amount];          
        if(ans >= 1e9) return -1;
        return ans;
    }
};

// 1D Dp appraoch
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
         vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++) {
            for(auto coin : coins) {
                if( i - coin >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};    