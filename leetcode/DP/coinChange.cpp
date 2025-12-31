#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>

// recursion 
class Solution {
public:

    long f(int ind, int T, vector<int> &a) {
        if(ind == 0) return ( T % a[0] == 0);

        long notTake = f(ind - 1, T, a);
        long take = 0;
        if(a[ind] <= T) take = f(ind, T - a[ind], a);
        return take + notTake;
    }
    long change(int amount, vector<int>& coins) {
        int n = coins.size();

        return f(n-1, amount, coins);
    }
};


//memoization
class Solution {
public:

    long f(int ind, int T, vector<int> &a, vector<vector<long>> &dp) {
        if(ind == 0) return ( T % a[0] == 0);

        if (dp[ind][T] != -1) return dp[ind][T]; 
        long notTake = f(ind - 1, T, a, dp);
        long take = 0;
        if(a[ind] <= T) take = f(ind, T - a[ind], a, dp);
        return dp[ind][T] =  take + notTake;
    }
    long change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<long>> dp(n, vector<long> (amount + 1, -1));

        return f(n-1, amount, coins, dp);
    }
};