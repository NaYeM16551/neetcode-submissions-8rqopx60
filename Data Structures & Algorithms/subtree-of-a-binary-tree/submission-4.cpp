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
    bool isSame(TreeNode* root, TreeNode* subRoot)
    {
        if(!root or !subRoot)
          return root==subRoot;

        bool isSameRoot=root->val==subRoot->val;
        bool leftSame=isSame(root->left,subRoot->left);
        bool rightSame=isSame(root->right,subRoot->right);



        if(isSameRoot and leftSame and rightSame)return true;
        return false;  
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root or !subRoot)
          return root==subRoot;

        bool isSamee=isSame(root,subRoot);

        if(isSamee or isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot))
           return true;
        return false;   
    }
};
