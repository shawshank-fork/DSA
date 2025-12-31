#include <stack>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;


class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int maxlen = 0, l = 0, r = 0;
        unordered_map<char, int> mpp;  // fixed declaration
        int n = s.size();

        while (r < n) {
            mpp[s[r]]++;  // add character at right

            while (mpp.size() > k) {  // fix: while instead of if
                mpp[s[l]]--;  // reduce count of left char

                if (mpp[s[l]] == 0)  // if count becomes 0, erase it
                    mpp.erase(s[l]);

                l++;  // move left pointer
            }

            maxlen = max(maxlen, r - l + 1);
            r++;  // increment right pointer
        }

        return maxlen;
    }
};