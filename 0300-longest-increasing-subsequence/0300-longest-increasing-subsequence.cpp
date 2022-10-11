class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res=0;
        vector<int> dp(nums.size(),0);
        for(int i=0;i<nums.size();++i)
        {
            for(int j=i-1;j>=0;--j)
            {
                if(nums[j]<nums[i])
                {dp[i]=max(dp[i],dp[j]+1);
                res=max(res,dp[i]);}
            }
        }
        return res+1;
    }
};