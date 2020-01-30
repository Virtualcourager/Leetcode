/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)
            return NULL;
        int n=preorder.size();
        int pre=0;
        return rebuilt(preorder,inorder,0,n-1,pre);
    }
    TreeNode* rebuilt(vector<int>& preorder, vector<int>& inorder,int l,int r,int &preptr)
    {
        if(l>r)
            return NULL;
        int k=preorder[preptr];
        preptr++;
        TreeNode* node=new TreeNode(k);
        int i;
        for(i=l;i<r&&inorder[i]!=k;i++);
        node->left=rebuilt(preorder,inorder,l,i-1,preptr);
        node->right=rebuilt(preorder,inorder,i+1,r,preptr);
        return node;
    }
};
