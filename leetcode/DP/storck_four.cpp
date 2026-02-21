#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>

//Tabulation
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

        for(int ind = n-1; ind>=0; ind--) {
            for(int tranNo = 2*k-1; tranNo >= 0; tranNo--) {
                if(tranNo % 2 == 0) {     //buy
                    dp[ind][tranNo] = max(-prices[ind] + dp[ind+1][tranNo+1], 
                    dp[ind+1][tranNo]);
                }
                else dp[ind][tranNo] = max(prices[ind] + dp[ind+1][tranNo+1], 
                dp[ind+1][tranNo]);
            }
        }
        return dp[0][0];
    }
};

//Space opt
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> after(2*k+1, 0);
        vector<int> cur(2*k+1, 0);

        for(int ind = n-1; ind>=0; ind--) {
            for(int tranNo = 2*k-1; tranNo >= 0; tranNo--) {
                if(tranNo % 2 == 0) {     //buy
                    cur[tranNo] = max(-prices[ind] + after[tranNo+1], 
                    after[tranNo]);
                }
                else cur[tranNo] = max(prices[ind] + after[tranNo+1], 
                after[tranNo]);
            }
            after = cur;
        }
        return after[0];
    }
};