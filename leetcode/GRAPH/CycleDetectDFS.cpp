#include <stack>
#include<vector>
#include<map>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class solution {
    private:
        bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
            vis[node] = 1;
            pathVis[node] = 1;

            //traverse for adj nodes
            for(auto it : adj[node]) {
                //when the node is not visited
                if(!vis[it]) {
                    if(dfsCheck(it,adj,vis,pathVis) == true) {
                        return true;
                    }
                }
                //if the node has been previously visited
                //but it has to be visited on the sem path

                else if(pathVis[it]) {
                    return true;
                }
            }
            pathVis[node] = 0;
            return false;
        }
    public:
        //function to detect cycle in a directed graph
        bool isCyclic(int V, vector<int> adj[]) {
            int vis[] = {0}; //vis[V] = {0}
            int pathVis[] = {0}; //pathVis[V] = {0}

            for(int i = 0; i < V; i++) {
                if(!vis[i]) {
                    if(dfsCheck(i, adj, vis, pathVis) == true) return true;
                }
            }
            return false;
        }    
};

//TC = O(V+E)
//SC = O(2N)