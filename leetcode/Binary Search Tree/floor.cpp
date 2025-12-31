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


 int floor(TreeNode* root, int key) {

    int floor = -1;
    while(root){
            if(root->val = key) {
            floor = root->val;
            return floor;
        }

        if(key > root->val) {
            floor = root->val;
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
   
    return floor;
 }