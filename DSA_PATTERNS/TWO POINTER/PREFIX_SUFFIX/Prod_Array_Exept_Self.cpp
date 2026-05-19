#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        vector<int> prefix(n);
        vector<int> suffix(n);
        
        prefix[0] = 1;
        suffix[n-1] = 1;

        for(int i = 1; i < n; i++) {
            prefix[i] = nums[i-1] * prefix[i-1];
        }

        for(int i = n-2; i >= 0; i--) {
            suffix[i] = nums[i + 1] * suffix[i + 1];
        }

        for(int i = 0; i < n; i++) {
            answer[i] = prefix[i] * suffix[i]; 
        }
        return answer;
        
    }
};

//Without creating seprate array for suffix and prefix - reducing sc to O(1) and TC is SAME - O(1)