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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        else
            return dfs(root,1);
    }
    int dfs(TreeNode* node,int depth)
    {
        if(node->left==NULL&&node->right==NULL)
            return depth;
        else if(node->left==NULL)
            return dfs(node->right,depth+1);
        else if(node->right==NULL)
            return dfs(node->left,depth+1);
        return max(dfs(node->left,depth+1),dfs(node->right,depth+1));
    }
};
