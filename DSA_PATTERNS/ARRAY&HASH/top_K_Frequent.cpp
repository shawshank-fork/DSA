#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include<unordered_map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(auto num : nums) {
            freq[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
            for(auto &it : freq) {
                int num = it.first;
                int count = it.second;

                bucket[count].push_back(num);

            }

            vector<int> ans;

            for(int i = bucket.size() - 1; i >= 0; i--) {
                for(auto n : bucket[i]) {
                    ans.push_back(n);

                    if(ans.size() == k){
                        return ans;
                    }
                }
            }
            return ans;
    }
};