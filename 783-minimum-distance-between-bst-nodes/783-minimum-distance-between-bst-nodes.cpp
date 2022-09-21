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
    TreeNode* prev=nullptr;
    void inorder(TreeNode* root,int &mindif)
    {
        if(!root) return;
        
        inorder(root->left,mindif);
        if(prev==nullptr)
        {
            prev=root;
        }
        else
        {
            mindif=min(mindif,abs(root->val-prev->val));
            prev=root;
        }
        inorder(root->right,mindif);
    }
    int minDiffInBST(TreeNode* root) {
        if(!root)return 0;
        int mindif=INT_MAX;
        inorder(root,mindif);
        return mindif;
        
    }
};