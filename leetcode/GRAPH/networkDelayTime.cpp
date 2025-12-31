#include <stack>
#include<vector>
#include<map>
#include<queue>
#include<unordered_map>

using namespace std;


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        pq.push({0,k});

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int timeTaken = it.first;
            int node = it.second;

            for(auto iter : adj[node]) {
                int adjNode = iter.first;
                int edW = iter.second;

                if(timeTaken + edW < dist[adjNode]) {
                    dist[adjNode] = timeTaken + edW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int maxTime = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == 1e9) return -1;
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};