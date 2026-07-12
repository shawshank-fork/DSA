#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    string alienOrder(vector<string>& words) {

        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        // Initialize all unique characters
        for(auto &word : words) {
            for(char ch : word) {
                adj[ch] = unordered_set<char>();
                indegree[ch] = 0;
            }
        }

        // Build graph
        for(int i = 0; i < words.size() - 1; i++) {

            string word1 = words[i];
            string word2 = words[i + 1];

            int len = min(word1.size(), word2.size());

            // Invalid prefix case
            if(word1.size() > word2.size() &&
               word1.substr(0, len) == word2.substr(0, len)) {
                return "";
            }

            for(int j = 0; j < len; j++) {

                if(word1[j] != word2[j]) {

                    // Avoid duplicate edges
                    if(!adj[word1[j]].count(word2[j])) {

                        adj[word1[j]].insert(word2[j]);
                        indegree[word2[j]]++;
                    }

                    break;
                }
            }
        }

        queue<char> q;

        for(auto &it : indegree) {
            if(it.second == 0)
                q.push(it.first);
        }

        string ans = "";

        while(!q.empty()) {

            char node = q.front();
            q.pop();

            ans += node;

            for(auto neighbour : adj[node]) {

                indegree[neighbour]--;

                if(indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }

        if(ans.size() != indegree.size())
            return "";

        return ans;
    }
};