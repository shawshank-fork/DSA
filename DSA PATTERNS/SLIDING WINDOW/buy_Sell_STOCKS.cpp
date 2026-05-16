#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>

// using 2 pointer  - tc - O(N), SC -O(1) 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0;
        int r = 1;
        int maxprof = 0;

        while(r < prices.size()) {
            if(prices[l] < prices[r]) {
                int profit = prices[r] - prices[l];
                maxprof = max(maxprof, profit);
            }
            else {
                l = r;
            }
            r++;
        }
        return maxprof;
    }
};

//DP - ONE PASS , SAME TC AND SC
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int maxprof = 0;

        for(int i = 1; i < n; i++) {
            int profit = prices[i] - mini;
            maxprof = max(profit, maxprof);
            mini = min(prices[i], mini);
        }
        return maxprof;
    }
};