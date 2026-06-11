#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include <queue>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(auto num : nums) {
            minHeap.push(num);

            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        return minHeap.top(); // O(n logk)
        // Place the kth largest element in its final sorted position
        // nth_element(nums.begin(), nums.begin() + (n - k), nums.end());
        // return nums[n - k];
    }
};


