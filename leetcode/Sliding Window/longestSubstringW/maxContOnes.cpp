#include <stack>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

//OPTIMAL SOL 1

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0, l = 0, r = 0, zeroes = 0;
        int n = nums.size();

        while(r < n) {
            if(nums[r] == 0) zeroes++;
            while(zeroes > k) {
                if(nums[l] == 0) zeroes--;
                    l++;
            }
            if(zeroes <= k) {
                int len = r - l + 1;
                maxlen = max(len,maxlen);
            }
            r++;       
        }
        return maxlen;
    }
};