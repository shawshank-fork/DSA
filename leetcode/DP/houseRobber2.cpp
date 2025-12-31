#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>


class Solution {
public:
    int maxNonAdj(vector<int>& value) {
        int n = value.size();
        int prev = value[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++) {
            int take = value[i];
            if (i > 1) take += prev2;

            int notTake = prev;

            int curi = max(take, notTake);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }

    long long int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++) {
            if (i != 0) temp1.push_back(nums[i]);
            if (i != n - 1) temp2.push_back(nums[i]);
        }

        return max(maxNonAdj(temp1), maxNonAdj(temp2));
    }
};
