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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n + 1, 1e9);

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()) {

            int node = pq.top().second;
            int timeTaken = pq.top().first;
            pq.pop();

            if(timeTaken > dist[node])
                continue;

            for(auto iter : adj[node]) {

                int adjNode = iter.first;
                int adjNode_weight = iter.second;

                if(timeTaken + adjNode_weight < dist[adjNode]) {
                    dist[adjNode] = timeTaken + adjNode_weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int maxTime = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == 1e9)return -1;
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};

//TC - O(V + E)