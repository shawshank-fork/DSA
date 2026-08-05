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
    // Function to find minimum insertions/deletions
    int minOperations(string s1, string s2) {
        // Get lengths of both strings
        int n = s1.length();
        int m = s2.length();

        // Create DP table of size (n+1) x (m+1)
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill the table using bottom-up approach
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // If characters match, extend LCS
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Get LCS length
        int lcs = dp[n][m];

        // Return total operations = deletions + insertions
        return (n - lcs) + (m - lcs);
    }
};

//space optimixzed
  int minOperations(string s1, string s2) {
        // Get the lengths of both strings
        int n = s1.size(), m = s2.size();

        // Create two 1D DP arrays
        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        // Iterate through each character of s1
        for (int i = 1; i <= n; i++) {

            // Iterate through each character of s2
            for (int j = 1; j <= m; j++) {

                // If characters match, increment LCS length
                if (s1[i - 1] == s2[j - 1])
                    cur[j] = 1 + prev[j - 1];

                // Else, take max from left or top
                else
                    cur[j] = max(prev[j], cur[j - 1]);
            }

            // Update prev row to current
            prev = cur;
        }

        // Calculate total operations
        int lcs = prev[m];
        return (n - lcs) + (m - lcs);
    }
