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
    int maxcnt=0;
    int cnt=1;
    TreeNode* prev=nullptr;
    void inorder(TreeNode* root,vector<int> & ans)
    {
        if(root==nullptr) return;
        
        inorder(root->left,ans);
        
        if(prev!=nullptr)
        {
            if(prev->val==root->val) cnt++;
            else cnt=1;
        }
        if(cnt>maxcnt)
        {
            maxcnt=cnt;
            ans.clear();
            ans.push_back(root->val);
        }
        else if(cnt==maxcnt)
        {
            ans.push_back(root->val);
        }
        prev=root;
        
        inorder(root->right,ans);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        inorder(root,ans);
        return ans;
        
        
    }
};