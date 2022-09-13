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
    TreeNode* tree(vector<int> &inorder,int s,int e)
    {
        if(s>e) return nullptr;
        int cur=s+(e-s)/2;
        
        TreeNode* root=new TreeNode(inorder[cur]);
        root->left=tree(inorder,s,cur-1);
        root->right=tree(inorder,cur+1,e);
        
        return root;
    }
    void inorder(TreeNode* root,vector<int> &i)
    {
        if(!root) return ;
        inorder(root->left,i);
        i.push_back(root->val);
        inorder(root->right,i);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> i;
        inorder(root,i);
        return tree(i,0,i.size()-1);        
        
    }
};