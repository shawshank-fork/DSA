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


class BSTIterator {
private: stack<TreeNode*> st;

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* tmpNode = st.top();
        st.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

private:
    void pushAll(TreeNode* node) {
        for(; node != NULL; st.push(node), node = node->left);
    }    
};