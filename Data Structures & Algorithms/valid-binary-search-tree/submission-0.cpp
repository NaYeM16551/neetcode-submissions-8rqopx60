/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    bool help(TreeNode* root,int min_val,int max_val)
    {
        if(!root)
          return true;

        if(root->val<min_val or root->val > max_val)
           return false;
        if(help(root->left,min_val,(root->val)-1) and help(root->right,(root->val)+1,max_val))
           return true;
        return false;        
    }
public:
    bool isValidBST(TreeNode* root) {

        return help(root,INT_MIN,INT_MAX);
        
    }
};
