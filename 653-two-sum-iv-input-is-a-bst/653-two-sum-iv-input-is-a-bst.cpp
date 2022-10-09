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
    void traverse(TreeNode* root,vector<int>& t)
    {
        if(!root)return;
        traverse(root->left,t);
        t.push_back(root->val);
        traverse(root->right,t);
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        vector<int> t;
        unordered_map<int,int> mp;
        traverse(root,t);
        for(int i=0;i<t.size();++i)
        {
            if(mp.count(k-t[i]))return true;
            mp[t[i]]++;
        }
        return false;
    }
    
};