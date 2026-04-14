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

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p or !q)
          return p==q;

        if(p->val !=q->val)
          return false;
        return isSameTree(p->left,q->left) and isSameTree(p->right,q->right);    
        
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {  
        if(!subRoot)
          return true;
        if(!root)
          return false;  
        if(isSameTree(root,subRoot))
          return true;
        if(isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot))
           return true;
        return false;     
        
    }
};
