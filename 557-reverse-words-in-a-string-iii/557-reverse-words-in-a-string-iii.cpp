class Solution {
public:
    string reverseWords(string s) {
        // string ans="";
        // string temp="";
        // for(int i=0;i<s.size();++i)
        // {
        //     if(s[i]==' ')
        //     {
        //         reverse(temp.begin(),temp.end());
        //         ans+=temp;
        //         ans+=" ";
        //         temp="";
        //     }
        //     else
        //     temp+=s[i];
        // }
        // reverse(temp.begin(),temp.end());
        // ans+=temp;
        // return ans;
        
        //----------------------------------------------
        
        //another approach can be to pass iterator in reverse method
        
        int j=0;
        for(int i=0;i<=s.size();++i)
        {
            if(s[i]==' ' or s[i]==NULL)
            {
                reverse(s.begin()+j,s.begin()+i);
                j=i+1;
            }
            
        }
        return s;
        
        
    }
};