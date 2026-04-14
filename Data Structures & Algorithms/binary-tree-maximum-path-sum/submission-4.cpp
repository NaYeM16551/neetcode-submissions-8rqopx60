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
    int maxSum(TreeNode* root,int &ans)
     {
         if(!root)
          return 0;
        int leftSum=maxSum(root->left,ans);
        int rightSum=maxSum(root->right,ans);
        int d=root->val;
        ans=max(ans,max({d,d+leftSum,d+rightSum+leftSum,d+rightSum}));
        return max({d,d+leftSum,d+rightSum});
     }
public:
    int maxPathSum(TreeNode* root) {

      if(!root)
          return 0;
       int ans=INT_MIN;
       maxSum(root,ans);
       return ans;

    }
};
