#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0){
                    dp[0][0] = 1;
                    continue;
                }
                int up = 0;
                int left = 0;
                if(i > 0)  up = dp[i - 1][j];
                if(j > 0)  left = dp[i][j - 1];
                dp[i][j] = up + left;

            }
        }
    return dp[n-1][m-1];
}