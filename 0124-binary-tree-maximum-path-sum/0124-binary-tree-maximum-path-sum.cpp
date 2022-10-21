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
    int traverse(TreeNode* root,int &res)
    {
        if(root==nullptr) return 0;
        int lmax=traverse(root->left,res);
        int rmax=traverse(root->right,res);
        lmax=max(lmax,0);
        rmax=max(rmax,0);
        res=max(res,lmax+rmax+root->val);        
        return max(root->val+lmax,root->val+rmax);
    }
    
    
    int maxPathSum(TreeNode* root) {
        int res;
        if(root==nullptr) return 0;
        res=root->val;
        traverse(root,res);
        return res;
        
        
    }
};