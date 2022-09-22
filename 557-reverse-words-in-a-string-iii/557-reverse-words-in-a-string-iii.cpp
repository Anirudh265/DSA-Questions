class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";
        for(int i=0;i<s.size();++i)
        {
            if(s[i]==' ')
            {
                // cout<<temp<<" ";
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans+=" ";
                temp="";
            }
            else
            temp+=s[i];
        }
        reverse(temp.begin(),temp.end());
        ans+=temp;
        return ans;
        
        
    }
};