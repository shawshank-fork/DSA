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

    int climbStairs(int n) {

        vector<int> dp(n + 1, -1);
        if(n <= 2) return 1;

        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

//Space optimized approach
class Solution {
public:

    int climbStairs(int n) {
        int prev2 = 1;
        int prev = 1;

        for(int i = 2; i <=n; i++) {
            int curi = prev2 + prev;
            prev2 = prev;
            prev = curi;
        }

        return prev;
    }
};    