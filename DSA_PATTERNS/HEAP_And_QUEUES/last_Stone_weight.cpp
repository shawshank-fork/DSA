#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include <queue>

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for(int stone : stones) {
            maxHeap.push(stone);
        }

        while(maxHeap.size() > 1) {
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();

            if(second != first){
                maxHeap.push(first - second);
            }
        }
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};