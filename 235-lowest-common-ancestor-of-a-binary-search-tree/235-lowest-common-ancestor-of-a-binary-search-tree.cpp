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
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // inefficient code
//     if(root==nullptr or root==p or root==q) return root;
        
//         TreeNode* l=lowestCommonAncestor(root->left,p,q);
//         TreeNode* r=lowestCommonAncestor(root->right,p,q);
        
//         if(!l) return r;
//         else if(!r) return l;
//         return root;
        
        if(root==nullptr or root==p or root==q) return root;
        int v=root->val;
        if(p->val>v and q->val>v) return lowestCommonAncestor(root->right,p,q);
        if(p->val<v and q->val<v) return lowestCommonAncestor(root->left,p,q);
        
        return root;
        
        
    }
};