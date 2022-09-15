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
    bool sum(TreeNode* root,int s,int limit)
    {
        if(!root) return false;
        
        bool l=sum(root->left,s+root->val,limit);
        bool r=sum(root->right,s+root->val,limit);
        if(!root->right and !root->left)
        {
            s+=root->val;
            if(s<limit) return false;
            return true;
        }
        if(!l)root->left=nullptr;
        if(!r)root->right=nullptr;
        if(l or r) return true;
        return false;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(!root)return nullptr;
        int s=0;
      bool ret= sum(root,s,limit);
       if(!ret)return nullptr;
        
        return root;
    }
};