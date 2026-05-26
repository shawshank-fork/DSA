#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[right]) {
                // Drop is on right side
                left = mid + 1;
            } else {
                // nums[mid] < nums[right] (unique elements, so not equal)
                // Right side sorted, min is at mid or left of it
                right = mid;
            }
        }
        return nums[left];  // or nums[right], they're equal
    }
};