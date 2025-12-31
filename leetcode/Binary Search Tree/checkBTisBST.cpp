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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST(TreeNode* root, long minval, long maxval) {
        if(root == NULL) return true;
        if(root->val >= maxval || root->val <= minval) return false;

        return isValidBST(root->left, minval, root->val)
             && isValidBST(root->right, root->val, maxval);
    }
};