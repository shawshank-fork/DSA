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

class NodeValue {
public:
    int maxnode, minnode, maxsize;

    NodeValue(int minnode, int maxnode, int maxsize) {
        this->maxnode = maxnode;
        this->minnode = minnode;
        this->maxsize = maxsize;
    }    
};

class Solution {
private:
    NodeValue helper(TreeNode* root) {
        if(!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        if(left.maxnode < root->val && root->val < right.minnode) {
            return NodeValue(min(root->val, left.minnode), max(root->val, right.maxnode), left.maxsize + right.maxsize + 1);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.maxsize, right.maxsize));
    }    
public:
    int maxSumBST(TreeNode* root) {
        return helper(root).maxsize;
    }
};