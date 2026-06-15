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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int min_value{min(p->val, q->val)};
        int max_value{max(p->val, q->val)};
        while (true) {
            if (root->val > max_value) {
                root = root->left;
            } else if (root->val < min_value) {
                root = root->right;
            } else {
                return root;
            }
        }

        return nullptr;
    }
};