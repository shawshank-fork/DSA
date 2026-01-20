#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxprof = 0;

        int n = prices.size();

        for(int i = 1; i<n; i++) {
            int cost = prices[i] - mini;
            maxprof = max(maxprof, cost);
            mini = min(mini, prices[i]);
        }
        return maxprof;
    }
};