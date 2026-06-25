class Solution {
public:

    bool dfs(int node,
             int parent,
             vector<vector<int>>& adj,
             vector<int>& vis) {

        vis[node] = 1;

        for(auto neighbor : adj[node]) {

            if(!vis[neighbor]) {

                if(dfs(neighbor, node, adj, vis))
                    return true;
            }
            else if(neighbor != parent) {
                return true;        // cycle found
            }
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for(auto &e : edges) {

            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n,0);

        // Check cycle
        if(dfs(0, -1, adj, vis))
            return false;

        // Check connected
        for(int i=0;i<n;i++)
            if(!vis[i])
                return false;

        return true;
    }
};