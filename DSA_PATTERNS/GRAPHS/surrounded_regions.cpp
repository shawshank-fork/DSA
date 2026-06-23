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
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

       //for left and right border
        for(int row = 0; row < n; row++){
            if(board[row][0] == 'O' && !vis[row][0]){
                q.push({row, 0});
                vis[row][0] = 1;
            }

            if(board[row][m-1] == 'O' && !vis[row][m - 1]) {
                q.push({row, m - 1});
                vis[row][m - 1] = 1;
            }
        
        }

        //for top and bottom
        for(int col = 0; col < m; col++) {
            if(board[0][col] == 'O' && !vis[0][col]) {
                q.push({0, col});
                vis[0][col] = 1;
            }

            if(board[n - 1][col] == 'O' && !vis[n - 1][col]) {
                q.push({n - 1, col});
                vis[n - 1][col] = 1;
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i ++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(board[row][col] == 'O' && !vis[row][col]) {
                    board[row][col] = 'X';
                }
            }
        }
    }
};

//TC - O(m * n)