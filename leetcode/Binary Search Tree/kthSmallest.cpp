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

 
 int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int small = INT_MAX;
        inorder(root, cnt, k, small);
        return small;
    }
    void inorder(TreeNode* root, int& cnt, int k, int& small) {
        if (!root || cnt >= k)
            return;
        inorder(root->left, cnt ,k,small);

        cnt++;

        if(cnt == k){
            small = root->val;
            return;
        }
        inorder(root->right, cnt ,k,small);
    }
