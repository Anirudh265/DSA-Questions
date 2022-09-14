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
    void palindrome(TreeNode* root,unordered_map<int,int>&mp,int &res)
    {
        if(!root)return ;
        
        mp[root->val]++;
        if(!root->left and !root->right)
        {
            int odd=0;
            for(auto i:mp)
            {
                if(i.second%2!=0) odd++;
                if(odd>1) break;
            }
            if(odd<=1) res++;
            
        }
        
        palindrome(root->left,mp,res);
        palindrome(root->right,mp,res);
        mp[root->val]--;
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root) return 0;
        int res=0;
        unordered_map<int,int> mp;
        palindrome(root,mp,res);
        return res;
        
    }
};