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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        int n=0;
        vector<int> ans;
        while(!q.empty())
        {
            if(n==0)
            {
                n=q.size();
            }
            TreeNode* node=new TreeNode(0);
            node=q.front();
            q.pop();
            ans.push_back(node->val);
            if(node->left!=NULL)
                q.push(node->left);
            if(node->right!=NULL)
                q.push(node->right);
            n--;
            if(n==0)
            {
                res.push_back(ans);
                ans.clear();
            }
        }
        return res;
    }
};
