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
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<int> minDist(n, INT_MAX);
        vector<int> vis(n, 0);

        minDist[0] = 0;
        int cost = 0;

        for(int i = 0; i < n; i++) {
            int node = -1;

            for(int j = 0; j < n; j++) {
                if(!vis[j] && (node == -1 || minDist[j] < minDist[node])){
                    node = j;
                }
            }

            vis[node] = 1;
            cost += minDist[node];

            for(int j = 0; j < n; j++) {

                if(!vis[j]){
                    int  newCost = abs(points[node][0] - points[j][0]) + abs(points[node][1] - points[j][1]);

                    minDist[j] = min(minDist[j], newCost);
                }
                
            }
        }
        return cost;
    }
};

//TC - O(n^2)