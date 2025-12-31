#include <stack>
#include<vector>
#include<map>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Adjacency list
        vector<pair<int,int>> adj[n+1];
        for(auto it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        // Min-heap priority queue: {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> dist(n+1, 1e9), parent(n+1);
        for(int i = 1; i <= n; i++) parent[i] = i;

        dist[1] = 0;
        pq.push({0, 1});
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int node = it.second;
            
            for(auto edge: adj[node]) {
                int adjNode = edge.first;
                int edW = edge.second;
                if(dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        if(dist[n] == 1e9) return {-1};  // No path
        
        // Trace the path back from node n to node 1
        vector<int> path;               //This code is to print the shortest path
        int node = n;
        while(parent[node] != node) {
            path.push_back(node);            /
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};