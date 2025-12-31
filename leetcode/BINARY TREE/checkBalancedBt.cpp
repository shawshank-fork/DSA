
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
public:
    bool isBalanced(TreeNode* root) {
        return h(root) != -1;
    }

    int h(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = h(root->left);
        if(lh == -1) return -1;
        int rh = h(root->right);
        if(rh == -1) return -1;

        if(abs(lh - rh) > 1) return -1;
        return max(lh,rh) + 1;
    }
};