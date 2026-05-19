#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();
        int l = 0, r = n - 1;
        int res = 0;

        while(l < r) {

            int area = min(height[l], height[r]) * (r - l);
            res = max(res, area);
            if(height[l] < height[r]) {
                // res = max(res, height[l] * (r - l));
                l++;
            }
            else{
                // res = max(res, height[r] * (r - l));
                r--;
            }
        }
        return res;
    }
};