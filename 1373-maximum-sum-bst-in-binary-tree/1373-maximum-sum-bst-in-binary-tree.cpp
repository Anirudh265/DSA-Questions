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
class solver
{
    public:
    int minval;
    int maxval;
    int sum;
    
    solver(int minval, int maxval,int sum)
    {
        this->minval=minval;
        this->maxval=maxval;
        this->sum=sum;
    }
    
};

class Solution {
public:
    solver adder(TreeNode* root,int &maxsum)
    {
        if(root==nullptr) 
        {
            return solver(INT_MAX,INT_MIN,0);
        }
        
        solver l=adder(root->left,maxsum);
        solver r=adder(root->right,maxsum);

        if(root->val>l.maxval and root->val<r.minval)
        {
            maxsum=max(maxsum,root->val+r.sum+l.sum);
            return solver(min(root->val,l.minval),max(root->val,r.maxval),root->val+l.sum+r.sum);
        }   
        maxsum=max(maxsum,max(l.sum,r.sum));
        return solver(INT_MIN,INT_MAX,max(l.sum,r.sum));

    }
    
    int maxSumBST(TreeNode* root) {
        int maxsum=0;
        
        adder(root,maxsum);
        return maxsum;        
    }
};