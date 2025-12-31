#include <stack>
#include<vector>
#include<map>
#include<queue>
#include<unordered_map>

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

class Solution {
public:
    struct SubtreeData {
        int minVal, maxVal, sum;
        bool isBST;
    };
    
    int maxSum = 0;

    SubtreeData helper(TreeNode* root) {
        if (!root) {
            return {INT_MAX, INT_MIN, 0, true};
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        if (left.isBST && right.isBST && left.maxVal < root->val && root->val < right.minVal) {
            int currSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currSum);
            return {
                min(root->val, left.minVal),
                max(root->val, right.maxVal),
                currSum,
                true
            };
        }

        return {INT_MIN, INT_MAX, 0, false};  // not a BST
    }

    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};