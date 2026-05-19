#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>

//using 2 poimterwsss

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1;
            int r = n - 1;

            while(l < r) {
                int sum =  nums[i] + nums[l] + nums[r];

                if(sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++; r--;

                    while(l < r && nums[l] == nums[l - 1]) l++;
                    while(l < r && nums[r] == nums[r + 1]) r--;
                }

                else if(sum > 0) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        return ans;
    }
};

//using hash map

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> count;

        sort(nums.begin(), nums.end());
        for(auto num : nums) {
            count[num]++;
        }

        vector<vector<int>> res;

        for(int i = 0; i < nums.size(); i++) {
            count[nums[i]]--;

            if(i > 0 && nums[i] == nums[i-1])continue;
            for(int j = i + 1; j < nums.size(); j++) {
                count[nums[j]]--;
                if(j > i+1 && nums[j] == nums[j-1])continue;

                int target = -(nums[i] + nums[j]);
                if(count[target] > 0){
                    res.push_back({nums[i], nums[j], target});
                }
            }

            for(int j = i + 1; j < nums.size(); j++) {
                count[nums[j]]++;
            }
        }
        return res;
    }
};
