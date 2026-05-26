#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>

class Solution {
public:
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = 0;

        while(l<=r) {
            int k = l + (r - l)/2;
            long long totalH = 0;

            for(int pile : piles) {
                totalH += (pile + k - 1)/k;
            }
            if(totalH > h){
                l = k + 1;
            }
            else {
                res = k;
                r = k - 1;
            }
        }
        return res;     
    }
};