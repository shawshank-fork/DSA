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
    TreeNode* connect(TreeNode* root) {
        if (!root || !root->left) return root;

        // Connect left child to right child
        root->left->next = root->right;

        // Connect right child to the next left child if exists
        if (root->next) {
            root->right->next = root->next->left;
        }

        // Recur for left and right subtrees
        connect(root->left);
        connect(root->right);

        return root;
    }
};