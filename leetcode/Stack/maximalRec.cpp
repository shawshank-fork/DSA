#include <stack>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int lhist(vector<int>& heights) {
        stack<int> st;
        int maxarea = 0;
        int n = heights.size();

        for(int i = 0; i <= n - 1; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int element = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxarea = max(heights[element] * (nse - pse - 1), maxarea);
            }
            st.push(i);
        }

        while(!st.empty()) {
            int nse = n;
            int element = st.top();
            st.pop();

            int pse = st.empty() ? -1 : st.top();
            maxarea = max(maxarea, (nse - pse - 1) * heights[element]);
        }

        return maxarea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;

        int m = matrix[0].size();
        int maxarea = 0;
        int psum[n][m];

        for(int j = 0; j <= m - 1; j++) {
            int sum = 0;
            for(int i = 0; i <= n - 1; i++) {
                if(matrix[i][j] == '0') sum = 0;
                else sum = sum + 1;

                psum[i][j] = sum;
            }
        }

        for(int i = 0; i <= n - 1; i++) {
            vector<int> row;
            for(int j = 0; j <= m - 1; j++) {
                row.push_back(psum[i][j]);
            }
            maxarea = max(maxarea, lhist(row));
        }

        return maxarea;
    }
};
