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
    int height(TreeNode* root)
    {
        if(!root)
          return 0;

        int lh=height(root->left);
        int rh=height(root->right);

        return max(lh,rh)+1;  
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
          return true;
        int lh=height(root->left);
        int rh=height(root->right);

        int heightDiff=abs(lh-rh);

        bool isLeftBalanced=isBalanced(root->left);
        bool isRightBalanced=isBalanced(root->right);

        if(isLeftBalanced and isRightBalanced and heightDiff<=1)
          return true;
        return false;    

    }
};
