#include <stack>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
};