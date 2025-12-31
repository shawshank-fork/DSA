#include <stack>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0; 

        int n = nums.size();
        int l = 0, r = 0, jumps = 0, farthest = 0;

        while (r < n - 1) {
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
                if (farthest >= n - 1) {
                    return jumps + 1;
                }
            }
            l = r + 1;
            r = farthest;
            jumps++;
        }

        return jumps;
    }
};
