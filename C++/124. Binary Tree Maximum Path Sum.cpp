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
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        bfs(root,ans);
        return ans;
    }
    int bfs(TreeNode* node,int& ans)
    {
        if(node==NULL)
            return 0;
        int left=max(0,bfs(node->left,ans));
        int right=max(0,bfs(node->right,ans));
        ans=max(ans,left+right+node->val);
        return max(left+node->val,right+node->val);
    }
};
