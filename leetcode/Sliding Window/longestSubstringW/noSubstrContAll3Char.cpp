#include <stack>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;


class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastseen[3] = {-1, -1, -1};
        int n = s.size();
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            lastseen[s[i] - 'a'] = i;

            if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1) {
                cnt += 1 + min(min(lastseen[0], lastseen[1]), lastseen[2]);
            }
        }

        return cnt;
    }
};