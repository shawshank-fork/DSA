#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>

int f(int ind, int prev_ind, int arr[], int n, vector<vector<int>> &dp) {
    if(ind == n) return 0;
    if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind + 1];

    int len = 0 + f(ind + 1, prev_ind, arr, n, dp);
    if(prev_ind == -1 || arr[ind] > arr[prev_ind]) {
        len = max(len, 1 + f(ind+1, ind, arr, n, dp));
    }
    return dp[ind][prev_ind + 1] = len;
}

int LIS(int arr[], int n) {
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return f(0, -1, arr, n, dp);
}

//tabulation
int IS(int arr[], int n) {
    vector<int> dp(n,1);
    int maxi = 1;
    for(int i = 0; i<n; i++) {
        for(int prev = 0; prev<i; prev++) {
            if(arr[prev] < arr[i]) {
                dp[i] = max(dp[i], i + dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);

    }
    return maxi;
}