#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include <queue>

//DFS SOL

class Solution {
public:

    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};


    void dfs(int row, int col, vector<vector<int>> &heights, vector<vector<int>> &vis) {
        int n = heights.size();
        int m = heights[0].size();

        vis[row][col] = 1;

        for(int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && heights[nrow][ncol] >= heights[row][col]) {
                dfs(nrow, ncol, heights, vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        //pacific
        //for left side
        for(int row = 0; row < n; row++) {
            dfs(row, 0, heights, pacific);
        }

        //for top side
        for(int col = 0; col < m; col++) {
            dfs(0, col, heights, pacific);
        }

        //atlantic
        //bottom side
        for(int col = 0; col < m; col++) {
            dfs(n-1, col, heights, atlantic);
        }

        //right side
        for(int row = 0; row < n; row++) {
            dfs(row, m - 1, heights, atlantic);
        }
        vector<vector<int>> ans;

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(pacific[row][col] && atlantic[row][col]) {
                    ans.push_back({row, col});
                }
            }
        }
        return ans;
    }
};

// BFS SOL
class Solution {
public:
    void bfs(queue<pair<int,int>>& q,
             vector<vector<int>>& vis,
             vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {

                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   !vis[nrow][ncol] &&
                   heights[nrow][ncol] >= heights[row][col]) {

                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        queue<pair<int,int>> pacQ;
        queue<pair<int,int>> atlQ;

        // Left and right borders
        for(int row = 0; row < n; row++) {

            pacific[row][0] = 1;
            pacQ.push({row, 0});

            atlantic[row][m-1] = 1;
            atlQ.push({row, m-1});
        }

        // Top and bottom borders
        for(int col = 0; col < m; col++) {

            pacific[0][col] = 1;
            pacQ.push({0, col});

            atlantic[n-1][col] = 1;
            atlQ.push({n-1, col});
        }

        bfs(pacQ, pacific, heights);
        bfs(atlQ, atlantic, heights);

        vector<vector<int>> ans;

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {

                if(pacific[row][col] && atlantic[row][col]) {
                    ans.push_back({row, col});
                }
            }
        }

        return ans;
    }
};

// TC O( m * n)