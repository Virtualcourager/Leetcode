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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        else
            return check(root,root);
    }
    private:
    bool check(TreeNode* a,TreeNode* b)
    {
        if(a==NULL&&b==NULL)
            return true;
        if(a==NULL||b==NULL)
            return false;
        if(a->val!=b->val)
            return false;
        return check(a->left,b->right)&&check(a->right,b->left);
        
    }
};
