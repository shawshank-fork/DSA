#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>

//Recursion
class Solution {
public:
    int f(int i, int j, string &s, string &p) {
        if( i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(j<0 && i >=0) {
            for (int ii = 0; ii<=i; ii++) {
                if(p[ii] != '*') return false;
            }
            return true;
        }
        if(p[j] == s[i] || p[j] == '?') {
            return f(i-1, j-1, s, p);
        }
        if(p[j] == '*') {
            return f(i-1, j, s, p) | f(i,j-1,s,p);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        return f(n-1,m-1,s,p);
    }
};

//Tabulation

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        dp[0][0] = true;

        // empty string vs pattern
        for(int j = 1; j <= m; j++) {
            dp[0][j] = (p[j-1] == '*' && dp[0][j-1]);
        }

        // string vs empty pattern
        for(int i = 1; i <= n; i++) {
            dp[i][0] = false;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(p[j-1] == s[i-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};

