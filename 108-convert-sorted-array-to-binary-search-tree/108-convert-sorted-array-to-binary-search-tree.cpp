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
public:
    TreeNode* tree(vector<int>& nums,int s,int e)
    {
        if(s>e) return nullptr;
        
        int mid=(s+e)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=tree(nums,s,mid-1);
        root->right=tree(nums,mid+1,e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if(nums.size()==1) 
        {
            TreeNode* root=new TreeNode(nums[0]);
            return root;
        }
        
        return tree(nums,0,nums.size()-1);
        
    }
};