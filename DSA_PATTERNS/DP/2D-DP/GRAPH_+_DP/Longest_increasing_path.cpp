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
    int dfs(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& matrix) {
        if(dp[row][col] != -1) return dp[row][col];

        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 1;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && matrix[nrow][ncol] > matrix[row][col]) {
                ans = max(ans, 1 + dfs(nrow, ncol, dp, matrix));
            }
        }
        return dp[row][col] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int longestPath = 1;

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                longestPath = max(longestPath, dfs(row, col, dp, matrix));
            }
        }
        return longestPath;
    }
};