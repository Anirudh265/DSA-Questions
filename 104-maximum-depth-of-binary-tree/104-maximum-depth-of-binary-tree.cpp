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
    int height(TreeNode* head)
    {
        int lh=0,rh=0;
        if(head==nullptr) return 0;
        lh+=height(head->left);
        rh+=height(head->right);
        return 1+max(lh,rh);
    }
    int maxDepth(TreeNode* root) {
        return height(root);
        
    }
};