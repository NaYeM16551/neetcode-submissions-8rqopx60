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
    int find(vector<int>& inorder,int si,int ei,int val)
    {
        for(int i=si;i<=ei;++i)
        {
            if(inorder[i]==val)
              return i;
        }

        return -1;
          
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int si,int ei,int &preorderIndex,int n)
    {
        if(preorderIndex>=n or si>ei)
            return nullptr;
         int pos=find(inorder,si,ei,preorder[preorderIndex]);  
        auto node =new TreeNode(preorder[preorderIndex++]);

        node->left = solve(preorder,inorder,si,pos-1,preorderIndex,n);
        node->right =solve(preorder,inorder,pos+1,ei,preorderIndex,n);

        return node;

       







    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int preorderIndex=0;
        return solve(preorder,inorder,0,n-1,preorderIndex,n);




    }
};
