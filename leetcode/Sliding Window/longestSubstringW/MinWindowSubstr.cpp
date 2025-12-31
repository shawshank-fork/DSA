#include <stack>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int hash[256] = {0};
        int l = 0, r = 0, minlen = INT_MAX, sindex = -1, cnt = 0;

        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        int required = m;

        while (r < n) {
            if (hash[s[r]] > 0) {
                cnt++;
            }
            hash[s[r]]--;

            while (cnt == required) {
                if ((r - l + 1) < minlen) {
                    minlen = r - l + 1;
                    sindex = l;
                }

                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
            r++;
        }

        return sindex == -1 ? "" : s.substr(sindex, minlen);
    }
};