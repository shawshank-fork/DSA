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
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
        vis[node] = 1;

        for(auto &neighbour : adj[node]) {
            if(!vis[neighbour]) {
                dfs(neighbour, adj, vis);
            }
        }
    } 
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int component = 0;

        for(int i = 0; i < n; i ++) {
    
            if(!vis[i]) {
                component++;
                dfs(i, adj, vis);
            }
        }
        return component;
    }
};