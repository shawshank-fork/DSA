#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include <queue>

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, int>> q;
        int fresh = 0;

        // Put all rotten oranges into the queue
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {

                if(grid[row][col] == 2) {
                    q.push({{row, col}, 0});
                }
                else if(grid[row][col] == 1) {
                    fresh++;
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        int time = 0;
        int rotten = 0;

        while(!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);

            for(int i = 0; i < 4; i++) {

                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   grid[nrow][ncol] == 1) {

                    grid[nrow][ncol] = 2;     // mark as rotten
                    rotten++;

                    q.push({{nrow, ncol}, t + 1});
                }
            }
        }

        if(rotten != fresh)
            return -1;

        return time;
    }
};

//TC - O(n * m);