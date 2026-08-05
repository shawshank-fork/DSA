#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>

long change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<long>> dp(n, vector<long> (amount + 1, 0));
        vector<int> prev(amount+1, 0), cur(amount+1, 0);

        for(int T = 0; T <= amount; T++) {
            dp[0][T] = (T % coins[0] == 0);
        }

        for(int ind = 1; ind < n; ind++) {
            for(int T = 0; T <= amount; T++) {
                long notTake = dp[ind-1][T];
                long take = 0;
                if(coins[ind] <= T) take = dp[ind][T-coins[ind]];
                dp[ind][T] =  take + notTake;
            }
        }
        return dp[n-1][amount];