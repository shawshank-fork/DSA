#include <stack>
#include<vector>
#include<map>
#include<queue>
#include<unordered_map>    //s=source

using namespace std;

class Solution {
    public:

        vector<int> bellmanFord(int v, vector<vector<int>>& edges, int s) {
            vector<int> dist(v, 1e8);
            dist[s] = 0;

            for(int i = 0; i < v-1; i++) {
                for(auto it : edges) {
                    int u = it[0];
                    int v = it[1];
                    int wt = it[2];

                    if(dist[u] != 1e18 && dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
            return dist;

            //to check -ve cycle
            //do Nth relaxation aswell
            for(auto it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                if(dist[u] != 1e18 && dist[u] + wt < dist[v]) {
                    return {-1};
                }
            }
            return dist;
        } 
};

// TC = O(V x E)