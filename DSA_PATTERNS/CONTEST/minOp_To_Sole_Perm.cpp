#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int c = nums[0];
        
        // Case A: increasing cyclic (rotation of sorted array)
        bool isRotation = true;
        for (int i = 0; i < n; ++i) {
            if ((c + i) % n != nums[i]) {
                isRotation = false;
                break;
            }
        }
        
        // Case B: decreasing cyclic (reflection / reverse of sorted array)
        bool isReflection = true;
        for (int i = 0; i < n; ++i) {
            if ((c - i + n) % n != nums[i]) {
                isReflection = false;
                break;
            }
        }
        
        if (!isRotation && !isReflection) return -1;
        
        int ans = INT_MAX;
        
        if (isRotation) {
            if (c == 0) {
                ans = 0;                     // already sorted
            } else {
                ans = min(ans, min(n - c,     // rotate left by (n-c)
                                   c + 2));   // reverse -> rotate left by c -> reverse
            }
        }
        
        if (isReflection) {
            int k = n - 1 - c;               // offset to align after reversing
            ans = min(ans, min(k + 1,         // reverse -> rotate left by k
                               n - k + 1));   // rotate left by (n-k) -> reverse
        }
        
        return ans;
    }
};