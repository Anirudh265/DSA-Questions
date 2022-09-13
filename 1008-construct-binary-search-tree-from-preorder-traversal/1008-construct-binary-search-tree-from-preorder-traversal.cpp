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
    TreeNode* tree(vector<int> &a,int &i,int limit)
    {
        if(i==a.size() or a[i]>=limit) return nullptr;
        
        TreeNode* root=new TreeNode(a[i++]);
        
        root->left=tree(a,i,root->val);
        root->right=tree(a,i,limit);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i=0;
       return tree(preorder,i,INT_MAX);
        
    }
};