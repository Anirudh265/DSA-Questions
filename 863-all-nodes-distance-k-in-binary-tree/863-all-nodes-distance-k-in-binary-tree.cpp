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
    void parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& mp)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int len=q.size();
            for(int i=0;i<len;++i)
            {
                TreeNode* h=q.front();
                q.pop();
                if(h->left)
                {
                    q.push(h->left);
                    mp[h->left]=h;
                }
                if(h->right)
                {
                    q.push(h->right);
                    mp[h->right]=h;
                }
            }
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root)return {};
        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*> mp;
        parent(root,mp);
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*,bool> vis;
        vector<int> ret;
        vis[target]=true;
        
        while(!q.empty())
        {
            int len=q.size();
            if(k==0) break;
            for(int i=0;i<len;++i)
            {
                TreeNode* h=q.front();
                q.pop();
                if(h->left and !vis[h->left])
                {
                    q.push(h->left);
                    vis[h->left]=true;
                }
                if(h->right and !vis[h->right])
                {
                    q.push(h->right);
                    vis[h->right]=true;
                }
                if(mp[h] and !vis[mp[h]])
                {
                    q.push(mp[h]);
                    vis[mp[h]]=true;
                }
            }
            k--;
        }
        while(!q.empty())
        {
            TreeNode* h=q.front();
            ret.push_back(h->val);
            q.pop();
        }
        return ret;
    }
};