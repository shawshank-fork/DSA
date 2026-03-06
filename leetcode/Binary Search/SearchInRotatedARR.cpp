
#include<iostream>
using namespace std;
#include<vector>
#include<climits>

class Solution {
    public:
        int search(vector<int>& nums, int k) {
            int n = nums.size();
    
            int s = 0, e = n -1;
            while(s<=e) {
                int mid = s + (e-s)/2;
                if(nums[mid] == k ) return mid;
    
                if(nums[s] <= nums[mid]) {
                    if(nums[s] <= k && k <= nums[mid]) {
                        e = mid - 1;
                    }
                    else {
                        s = mid + 1;
                    }
                }
                else {
                    if(nums[mid] <= k && k <= nums[e]) {
                        s = mid + 1;
                    }
                    else {
                        e = mid = 1;
                    }
                }
            }
            return -1;
        }
    };