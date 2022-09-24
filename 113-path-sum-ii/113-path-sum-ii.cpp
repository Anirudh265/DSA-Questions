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
    vector<int> temp;
    void path(TreeNode* root,int k,vector<vector<int>> &paths)
    {
        if(!root) return;
        temp.push_back(root->val);
        if(!root->left and !root->right)
        {
            if(k==root->val)
            {
                paths.push_back(temp);
            }
        }
        path(root->left,k-root->val,paths);
        path(root->right,k-root->val,paths);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root) return ans;
        path(root,targetSum,ans);
        return ans;
        
    }
};