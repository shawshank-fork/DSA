
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

 #include <stack>
#include<vector>
#include<map>
#include<queue>
#include<unordered_map>

using namespace std;


class Solution {
    unordered_map<int, int> inorderMap; // value -> index
    int postIndex;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inLeft, int inRight) {
        if (inLeft > inRight) return nullptr;

        // Get the root value from postorder
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // Get the index of the root in inorder
        int index = inorderMap[rootVal];

        // Build right subtree before left (postorder is left->right->root, reverse that)
        root->right = build(inorder, postorder, index + 1, inRight);
        root->left = build(inorder, postorder, inLeft, index - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1;

        // Build hashmap for quick index lookup in inorder
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }

        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};