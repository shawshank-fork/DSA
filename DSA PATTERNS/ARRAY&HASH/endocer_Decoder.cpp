#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include<unordered_map>
#include<string>
class Solution {
public:

    string encode(vector<string>& strs) {
        vector<string> res;
        string ans;
        for(auto s : strs){
            ans += to_string(s.length()) + '#' + s;
        }
        return ans;
        
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;

        while(i < s.size()) {
            int j = i;

            while(s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            j++;

            string word = s.substr(j, len);
            ans.push_back(word);
            i = j + len;
        }
        return ans;
    }
};

/*
ENCODING
Okay so what we are doing in thsi question is that, we are given a endocder and a decoder function. when we have to encode a string we will encode it in such a way that it becomes helpul for decoding. We add the legnth of the sring and a delimiter(ex '#')  
in encoder function we interate through the strs and store exaxh word in s with and the take a ans string and convert its length to string and add the delimiter and the light to string s and return the ans.

DECODING
in decoder function we will ahve to decode the set of strings but first we need to find the leght of the strings so that we can understand how long a word is . so we will interate through the 
string till we reach the delimiter while increasing the value of loop j. when we reach the condition we will be at the place where the size of the word is stored. and move j ahead a point so tht it points now at the actual word
we will take the value as len by convertion stoi and then create a string for words which will iterate from j(at actual word) to length(len) and we push these words in the ans and move loop i to j + len and continue
*/
