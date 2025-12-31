#include <stack>
#include<vector>
#include<map>
#include<queue>
#include<unordered_map>
#include<string>
#include<iostream>
#include <limits>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode* next;
      TreeNode() : val(0), left(nullptr), right(nullptr),next(NULL) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(NULL) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class MedianFinder {
private:
    priority_queue<int> left; // max-heap
    priority_queue<int, vector<int>, greater<int>> right; // min-heap

public:
    MedianFinder() {}

    void addNum(int num) {
        // Step 1: Add to max-heap
        left.push(num);

        // Step 2: Balance: move largest from left to right
        right.push(left.top());
        left.pop();

        // Step 3: Maintain size property
        if (left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() == right.size())
            return (left.top() + right.top()) / 2.0;
        else
            return left.top();
    }
};