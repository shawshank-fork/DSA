#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>

class Solution {
    public:
        int sumByD(vector<int>& nums, int div) {
            int sum = 0;
            int n = nums.size();
            for(int i = 0; i < n; i++) {
                sum = sum + ceil((double)(nums[i]) / (double)(div));
            }
            return sum;
        }
        int smallestDivisor(vector<int>& nums, int threshold) {
            
            int s = 1, e = *max_element(nums.begin(), nums.end());
            while(s<=e) {
                int mid = s + (e-s)/2;
                if(sumByD(nums, mid) <= threshold) {
                    e = mid - 1;
                }
                else {
                    s = mid + 1;
                }
            }
            return s;
        }
    };