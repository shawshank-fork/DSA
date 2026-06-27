#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include <queue>

class Solution {
public:
    int find(int x, vector<int> &parent) {
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x], parent);
    }
    bool unite(int x, int y, vector<int> &parent, vector<int> &rank) {
        int px = find(x, parent);
        int py = find(y, parent);

        if(px == py) return false;

        if(rank[px] > rank[py]) {
            parent[py] = px;
        }

        else if(rank[py] > rank[px]) {
            parent[px] = py;
        }

        else {
            parent[py] = px;
            rank[px]++; 
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        vector<int> rank(n+1, 0);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(auto e : edges) {
            if(!unite(e[0], e[1], parent, rank)){
                return e;
            }
        }
        return {};
    }
};