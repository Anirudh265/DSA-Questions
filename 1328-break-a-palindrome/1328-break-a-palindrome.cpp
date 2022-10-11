class Solution {
public:
    string breakPalindrome(string palindrome) {
        string ans="";
        if(palindrome.length()==1) return ans;
        ans=palindrome;
        int cnt=0;
        for(int i=0;i<palindrome.size();++i)
        {
            if(palindrome[i]=='a')cnt++;
        }
        for(int i=0;i<palindrome.size();++i)
        {
            if(palindrome[i]!='a')
            {
                palindrome[i]='a';
                cnt++;
                break;
            }
            if(i==palindrome.size()-1 and palindrome[palindrome.size()-1]!='a')
            {
                palindrome[palindrome.size()-1]='a';
                cnt++;
            }
            else if(i==palindrome.size()-1 and palindrome[palindrome.size()-1]=='a')
            {
                palindrome[palindrome.size()-1]='b';
                cnt--;
            }
        }
        // cout<<cnt<<" ";
        int first=0,ind=0;
        if(cnt==palindrome.size())
        {
            ans[ans.size()-1]='b';
            return ans;
        }   
        return palindrome;
        
    }
};