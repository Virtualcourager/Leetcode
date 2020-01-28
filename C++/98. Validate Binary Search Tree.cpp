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
    bool isValidBST(TreeNode* root) {
        return dfs(root,LONG_MIN,LONG_MAX);
    }
    bool dfs(TreeNode* node,long minn,long maxn)
    {
        if(node==NULL)
            return true;
        if(node->val<=minn)
            return false;
        if(node->val>=maxn)
            return false;
        return dfs(node->left,minn,node->val)&&dfs(node->right,node->val,maxn);
    }
};
