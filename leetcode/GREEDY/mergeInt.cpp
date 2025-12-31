#include <stack>
#include<vector>
#include<map>
#include<unordered_map>
#include <algorithm>


using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) return res;

        // Step 1: Sort intervals by starting time
        sort(intervals.begin(), intervals.end());

        // Step 2: Iterate through intervals
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            // Compare with last interval in result
            if (res.back()[1] >= intervals[i][0]) {
                // Merge: update end time
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                // No overlap: add new interval
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};
