#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>



class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int wordlen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordlen * wordCount;

        vector<int> ans;

        unordered_map<string, int> required;
        for(auto ch : words) {
            required[ch]++;
        }

        for(int offset = 0; offset < wordlen; offset++) {
            int left = offset;
            int count = 0;
            
            unordered_map<string, int> current;

            for(int right = offset; right + wordlen <= s.size(); right += wordlen) {
                string word = s.substr(right, wordlen);

                if(required.find(word) == required.end()) {
                    current.clear();
                    count = 0;
                    left = right + wordlen;
                    continue;
                }
                current[word]++;
                count++;

                while(current[word] > required[word]) {
                    string leftword = s.substr(left, wordlen);
                    current[leftword]--;
                    left += wordlen;
                    count--;
                }

                if(count == wordCount) {
                    ans.push_back(left);
                    string leftword = s.substr(left, wordlen);
                    current[leftword]--;
                    count--;
                    left += wordlen;
                }
            }
        }
        return ans;
    }
};