class Solution {
public:
    int ways(string &s,int i,int *dp)
    {
        if(i>=s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        int a=s[i]-'0',b=0;
        if(i<s.size()-1)
        {
            b=a*10+s[i+1]-'0';
        }
        if(a>0) ans+=ways(s,i+1,dp);
        if(a>0 and b<=26 and b>0) ans+=ways(s,i+2,dp);
        
        return dp[i]=ans;
    }
    //recursion solution gives tle
    int numDecodings(string s) {
        int dp[101];
        memset(dp,-1,sizeof dp);
        if(s.size()==0) return 0;
        if(s[0]=='0') return 0;
        return ways(s,0,dp);
        
    }
};