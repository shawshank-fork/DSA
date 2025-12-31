#include <stack>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;

        int n = nums.size();
        for(int i = 0; i <= n - 1; i++) {
            // Remove out-of-window elements
            if(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Maintain decreasing order in deque
            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Push current element index
            dq.push_back(i);

            // Record result when window has at least k elements
            if(i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};
