#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
       int l = 0;
       int maxFreq = 0;
       int res = 0;

       for(int r = 0; r < s.length(); r++) {
            count[s[r] - 'A']++;
            maxFreq = max(maxFreq, count[s[r] - 'A']);
            int window_length = r - l + 1;

            while(window_length - maxFreq > k) {
                count[s[l] - 'A']--;
                l++;
                window_length = r - l + 1;
            }
            res = max(res, window_length);
       }
       return res;

    }
};