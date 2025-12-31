#include <stack>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxind = 0;

        for(int i = 0; i <= n-1; i++) {
            if( i > maxind) return false;
            maxind = max(maxind, i + nums[i]);
        }
        return true;
    }
};