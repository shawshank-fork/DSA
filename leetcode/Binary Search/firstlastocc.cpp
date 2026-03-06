

#include<iostream>
using namespace std;
#include<vector>
#include<climits>

class Solution {
    public:
    
        int firstocc(vector<int>& nums, int k) {
            int n = nums.size();
            int s= 0, e = n-1;
            int first = -1;
    
            while(s<=e) {
                int mid = s + (e-s)/2;
                if(nums[mid] == k) {
                    first = mid;
                    e = mid - 1;
                }
                else if(nums[mid] < k) s = mid + 1;
                else e = mid - 1;
            }
            return first;
        }
    
        int lastocc(vector<int>& nums, int k) {
            int n = nums.size();
            int s= 0, e = n - 1;
            int last = -1;
    
            while(s<=e) {
                int mid = s + (e-s)/2;
                if(nums[mid] == k) {
                    last = mid;
                    s = mid + 1;
                }
                else if(nums[mid] < k) s = mid + 1;
                else e = mid - 1;
            }
            return last;
        }
        vector<int> searchRange(vector<int>& nums, int k) {
            int n = nums.size();
            int first = firstocc(nums,k);
            if(first == -1) return {-1,-1};
            int last = lastocc(nums,k);
            return {first,last};
        }
    };