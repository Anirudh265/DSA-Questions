class Solution {
public:
    bool palindrome(string s)
    {
        string temp=s;
        reverse(temp.begin(),temp.end());
        return temp==s;
    }
    
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string,int> mp;
        string temp,s,rev;
        int len;
        for(int i=0;i<words.size();++i)
        {
            mp[words[i]]=i;
        }
        for(int i=0;i<words.size();++i)
        {
            s=words[i];
            int len=words[i].size();
             temp=words[i];
            reverse(temp.begin(),temp.end());
            //checks mirror words
            if(mp.count(temp) and mp[temp]!=i)
            {
                res.push_back({i,mp[temp]});
            }
            
            //checks blank string and palindromes
            if(mp.count("") and palindrome(s) and i!=mp[""])
            {
                res.push_back({mp[""],i});
                res.push_back({i,mp[""]});
            }
            
            //checks for string from backwards of string
            temp="";
            int r=len-1;
            while(r>=1)
            {
                temp+=s[r];
                if(mp.count(temp) and palindrome(s.substr(0,r)) and mp[temp]!=i)
                {
                    res.push_back({mp[temp],i});
                }
                r--;
            }
            //checks for string from front
            temp="";
            int l=0;
            while(l<len-1)
            {
                temp+=s[l];
                rev=temp;
                reverse(rev.begin(),rev.end());
                if(mp.count(rev) and palindrome(s.substr(l+1,len-1-l)) and mp[rev]!=i)
                {
                    res.push_back({i,mp[rev]});
                }
                l++;
            }           
        }
        return res;
    }
};