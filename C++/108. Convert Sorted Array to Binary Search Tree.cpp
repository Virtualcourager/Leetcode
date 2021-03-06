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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return NULL;
        return build(nums,0,n-1);
    }
    TreeNode* build(vector<int>& nums,int l,int r)
    {
        if(r<l)
            return NULL;
        int mid=l+(r-l)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=build(nums,l,mid-1);
        node->right=build(nums,mid+1,r);
        return node;
    }
};
