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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int ans=0;
        queue<pair<int,TreeNode*>> q;
        int minind=0,maxind=0;
        q.push({0,root});
        while(!q.empty())
        {
            
            int len=q.size();
            int sub=q.front().first;
            for(int i=0;i<len;++i)
            {
                auto x=q.front();
                q.pop();
                int index=x.first-sub;
                TreeNode* head=x.second;
                minind=min(minind,index);
                maxind=max(maxind,index);
                if(head->left!=nullptr) q.push({(long long)2*index+1,head->left});
                if(head->right!=nullptr) q.push({(long long)2*index+2,head->right});
                
            }
            // if(maxind!=0 or minind!=0)
        ans=max(ans,1+maxind-minind);
        }
        return ans;
        
    }
};