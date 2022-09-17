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
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<TreeNode*> q;
        int depth=0;
        q.push(root);
        while(!q.empty())
        {
            int len=q.size();
            for(int i=0;i<len;++i)
            {
                TreeNode* head=q.front();
                q.pop();
                if(head->left==nullptr and head->right==nullptr) return depth+1;
                if(head->left!=nullptr)q.push(head->left);
                if(head->right!=nullptr)q.push(head->right);
                
            }
            depth+=1;
        }
        return depth;
        
    }
};