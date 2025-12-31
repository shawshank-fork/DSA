#include <stack>
#include<vector>
#include<map>
#include<unordered_map>
#include <algorithm>


using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 1;  
        int lastEnd = intervals[0][1];
        int n = intervals.size();

        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] >= lastEnd) {
                count++;
                lastEnd = intervals[i][1];
            }
        }

        return n - count;  
    }
};