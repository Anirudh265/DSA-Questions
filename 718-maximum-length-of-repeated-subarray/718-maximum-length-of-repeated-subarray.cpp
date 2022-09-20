class Solution {
public:
    int dp[1001][1001];
    int longest(vector<int> nums1,vector<int> nums2,int l1,int l2)
    {
        int maxlen=0;
        for(int i=1;i<=l1;++i)
        {
            for(int j=1;j<=l2;++j)
            {
                if(i==0 or j==0) 
                {
                    dp[i][j]=0;
                }
                else if(nums1[i-1]==nums2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                maxlen=max(maxlen,dp[i][j]);
            }
        }
        return maxlen;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,0,sizeof dp);
        int l1=nums1.size();
        int l2=nums2.size();
        
        return longest(nums1,nums2,l1,l2);
        
        
    }
};