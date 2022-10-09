class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        
        for(int i=0;i<ast.size();++i)
        {
            //if array is empty or the value or positive the there is no need for checking
            if(st.empty() or ast[i]>0)
            {
                st.push(ast[i]);
            }
            else
            {
                //if top is empty then add number regardless of sign because they would either be in opp direction or left
                if(st.top()<0) {
                    st.push(ast[i]);
                    continue;
                }
                //remove postive values 
                while(!st.empty() and abs(ast[i])>st.top() and st.top()>0)
                {
                    st.pop();
                }
                //if it is empty or top is -ve so add the number
                 if(st.empty() or st.top()<0)
                 {
                     st.push(ast[i]);
                 }
                //in case of equal values the stack will be popped once
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