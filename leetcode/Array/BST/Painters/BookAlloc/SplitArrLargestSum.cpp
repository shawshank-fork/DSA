
#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>

class Solution {
    public:
        int splitcount(vector<int>& nums, int number) {
            int split = 1;
            long long sumOfNumbers = 0;
            int n = nums.size();
    
            for(int i = 0; i < n; i++) {
                if(sumOfNumbers + nums[i] <= number) {
                    sumOfNumbers += nums[i];
                }
                else {
                    split += 1;
                    sumOfNumbers = nums[i];
                }
            }
            return split;
        }
    
        int splitArray(vector<int>& nums, int k) {
            int n = nums.size();
            if(k > n) return -1;
    
            int s = *max_element(nums.begin(), nums.end());
            int e = accumulate(nums.begin(), nums.end(), 0);
            while(s<=e) {
                int mid = s + (e-s)/2;
                int split = splitcount(nums, mid);
    
                if(split > k) {
                    s = mid + 1;
                }
                else {
                    e = mid - 1;
                }
            }
            return s;
        }
    };