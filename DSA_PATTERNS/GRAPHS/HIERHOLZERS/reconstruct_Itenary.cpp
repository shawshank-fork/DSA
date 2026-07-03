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
    void dfs(string src, unordered_map<string, deque<string>> &adj, vector<string> &ans) {
        while(!adj[src].empty()){
            string next_airport = adj[src].back();
            adj[src].pop_back();

            dfs(next_airport, adj, ans);
        }
        ans.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, deque<string>> adj;

        for(auto &ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }

        for(auto &it : adj) {
            sort(it.second.rbegin(), it.second.rend());
        }

        vector<string> ans;

        dfs("JFK", adj, ans);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

//TC O(ElogE)