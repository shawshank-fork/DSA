


#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>

class Solution {
    public:
        int finddays(vector<int>& weights, int cap) {
            int days = 1, load = 0;
            int n = weights.size();
            for(int i = 0; i < n; i++) {
                if(weights[i] + load > cap) {
                    days += 1;
             
                    load = weights[i];
                }
                else {
                    load += weights[i];
                }
            }
            return days;
        }
    
        int shipWithinDays(vector<int>& weights, int d) {
            int s = *max_element(weights.begin(), weights.end());
            int e = accumulate(weights.begin(), weights.end(), 0);
            while(s<=e) {
                int mid = s + (e-s)/2;
                int numberOfDays = finddays(weights, mid);
                if(numberOfDays <= d) {
                    e = mid - 1;
                }
                else {
                    s = mid + 1;
                }
            }
            return s;
        }
    };