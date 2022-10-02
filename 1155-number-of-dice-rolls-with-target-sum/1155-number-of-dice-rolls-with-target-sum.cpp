class Solution {
public:
    long long mod=1e9+7;
    int ways(int n,int k,int target,vector<vector<int>>&dp)
    {
        if(target==0 and n==0) return 1;
        
        if(target<=0 or n<=0) return 0;
        
        if(dp[n][target]!=-1) return dp[n][target];
        int cnt=0;
        for(int i=1;i<=k;++i)
        {
            cnt=(cnt+ways(n-1,k,target-i,dp))%mod;
        }
       return dp[n][target]=cnt%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        //k is choices
        //n is depth of tree
        vector<vector<int>>dp(1001,vector<int> (1001,-1));
        return ways(n,k,target,dp);
        
        
        
    }
};