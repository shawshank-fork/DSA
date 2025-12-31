#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>


class Solution {
    const int mod = 1e9+7;
    
    // Recursion
    int f(int ind, int tar, vector<int>& arr) {
        // Base Case
        if (ind == 0) {
            if (tar == 0 && arr[0] == 0) return 2;   // Base case for array containing 0s
            if (tar == 0) return 1; 
            return (tar==arr[0]);
            return 0;
        }

        int notPick = f(ind - 1, tar, arr);
        int pick = 0;

        if (tar >= arr[ind])
            pick = f(ind - 1, tar - arr[ind], arr);

        return (pick + notPick) % mod;
    }
    
    // Memoization
    int f(int ind, int tar, vector<int>& arr,vector<vector<int>>&dp) {
        // Base Case
        if (ind == 0) {
            if (tar == 0 && arr[0] == 0) return 2;   // Base case for array containing 0s
            if (tar == 0) return 1; 
            return (tar==arr[0]);
            return 0;
        }
        if(dp[ind][tar]!=-1)    return dp[ind][tar];
        int notPick = f(ind - 1, tar, arr,dp);
        int pick = 0;

        if (tar >= arr[ind])
            pick = f(ind - 1, tar - arr[ind], arr,dp);

        return dp[ind][tar]=(pick + notPick) % mod;
    }

  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        
        // Memoization
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        int ans=f(n-1,target,arr,dp);
        return ans;
        
        // Tabulation
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        dp[0][0]=1;
        if(arr[0]==0)   dp[0][0]=2;
        if(arr[0]!=0 && target>=arr[0])  dp[0][arr[0]]=1;
        
        for(int ind=1;ind<n;ind++){
            for(int k=0;k<=target;k++){
                int notPick=dp[ind-1][k];
                int pick=0;
                if(k>=arr[ind])  pick=dp[ind-1][k-arr[ind]];
                dp[ind][k]=(pick+notPick);
            }
        }
        return dp[n-1][target];
        
        
        // Sapce Optimizaton
        vector<int>pre(target+1,0),cur(target+1,0);
        pre[0]=1;
        if(arr[0]==0)   pre[0]=2;
        if(arr[0]!=0 && target>=arr[0])  pre[arr[0]]=1;
        
        for(int ind=1;ind<n;ind++){
            for(int k=0;k<=target;k++){
                int notPick=pre[k];
                int pick=0;
                if(k>=arr[ind])  pick=pre[k-arr[ind]];
                cur[k]=(pick+notPick);
            }
            pre=cur;
        }
        return pre[target];
        
        
    }
};