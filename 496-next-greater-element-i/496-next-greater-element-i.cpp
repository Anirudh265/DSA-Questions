class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        stack<int> st;
        unordered_map<int,int> mp;
        st.push(b[b.size()-1]);
        mp[b[b.size()-1]]=-1;
        for(int i=b.size()-2;i>=0;--i)
        {
            while(!st.empty() and b[i]>=st.top())
            {
                st.pop();
            }
            if(st.empty())
            {
                st.push(b[i]);
                mp[b[i]]=-1;
            }
            else
            {
                mp[b[i]]=st.top();
                st.push(b[i]);
            }
        }
        for(int i=0;i<a.size();++i)
        {
            ans.push_back(mp[a[i]]);
            // mp.erase(a[i]);
        }
        return ans;
    }
};