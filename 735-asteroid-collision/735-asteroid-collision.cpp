class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        
        for(int i=0;i<ast.size();++i)
        {
            if(st.empty() or ast[i]>0)
            {
                st.push(ast[i]);
            }
            else
            {
                if(st.top()<0) {
                    st.push(ast[i]);
                    continue;
                }
                while(!st.empty() and abs(ast[i])>st.top() and st.top()>0)
                {
                    st.pop();
                }
                 if(st.empty() or st.top()<0)
                 {
                     st.push(ast[i]);
                 }
                else if(abs(ast[i])==st.top())st.pop();              
            }
            
        }
        vector<int> ans(st.size());
        int temp=st.size();
        for(int i=temp-1;i>=0;--i)
        {
            ans[i]=st.top();
            st.pop();
        }
        return ans;
        
    }
};