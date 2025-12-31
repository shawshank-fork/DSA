#include <stack>
#include<vector>
#include<map>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution {
private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis, vector<int>& result) {
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(dfs(it,adj,vis,pathVis, result))
                    return true;
            } else if(pathVis[it]) {
                return true;
            }
        }

        pathVis[node] = 0;
        result.push_back(node);
        return false;
    } 

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]); // b-> a

        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        vector<int> result;

        for(int i = 0; i < numCourses; ++i) {
            if(!vis[i]) {
                if(dfs(i, adj,vis,pathVis,result)) {
                    return {}; //cycle detected
                }
            }
        }
        reverse(result.begin(), result.end()); // to get correct order
        return result;
    }
};

// TC = O(V + E)
//SC = O(V + E)