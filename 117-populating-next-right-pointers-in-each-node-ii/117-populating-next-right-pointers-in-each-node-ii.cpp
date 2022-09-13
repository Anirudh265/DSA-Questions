/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void level(Node* &root)
    {
        //brute force
        queue<Node* > q;
        q.push(root);
        while(!q.empty())
        {
            vector<Node*> temp;
            int len=q.size();
            for(int i=0;i<len;++i)
            {
                Node* h=q.front();
                temp.push_back(h);
                q.pop();
                if(h->left)q.push(h->left);
                if(h->right)q.push(h->right);
                
            }
            if(temp.size()>1){
            for(int i=0;i<temp.size()-1;++i)
            {
                temp[i]->next=temp[i+1];
            }
            }
        }
    }
    Node* connect(Node* root) {
        if(!root) return root;
        level(root);
        return root;
        
    }
};