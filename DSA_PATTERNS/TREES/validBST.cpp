
#include<iostream>
using namespace std;
#include<vector>
#include<climits>
#include <algorithm>
#include <numeric>
#include<stack>
#include<string>


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    bool dfs(TreeNode* root, long long left, long long right) {
        if(root == nullptr) return true;

        if(root->val <= left || root->val >= right) return false;

        return dfs(root->left, left, root->val) && dfs(root->right, root->val, right);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }

};

//TC = O(n), SC - O(n)