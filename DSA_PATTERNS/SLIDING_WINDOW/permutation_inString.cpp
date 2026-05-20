#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        vector<int> counts1(26, 0);
        vector<int> counts2(26,0);

        if(n1 > n2) return false;

        for(int i = 0; i < n1; i++) {
            counts1[s1[i] - 'a']++;
            counts2[s2[i] - 'a']++;
        }

        if(counts1 == counts2) return true;

        for(int r = n1; r < n2; r++) {
            counts2[s2[r] - 'a']++;
            counts2[s2[r - n1] - 'a']--;

            if(counts1 == counts2) return true;
        }
        return false;
    }
};