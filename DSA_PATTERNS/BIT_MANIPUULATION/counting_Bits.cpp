#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>

//sol 1
vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i <= n; i++) {
            int count = 0;
            int num = i;
            while(num) {
                num = num & (num - 1);
                count++;
            }
            res.push_back(count);
        }
        return res;
}

// sol 2 - optimised usign DP
vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);

    int count = 0;
    for(int i = 1; i <= n; i++) {
            dp[i] = dp[i << 1] + (i & 1);
    }
    return dp;
}