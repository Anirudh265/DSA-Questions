class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //dp solution longest increasing subsequence(tle)
        // vector<int> dp(nums.size(),0);
        // int trip=0;
        // for(int i=0;i<nums.size();++i)
        // {
        //     for(int j=i-1;j>=0;--j)
        //     {
        //         if(nums[j]<nums[i])
        //         {
        //             dp[i]=max(dp[i],dp[j]+1);
        //             trip=max(trip,dp[i]+1);
        //             cout<<trip<<" ";
        //             if(trip>=3) return true;
        //         }
        //     }
        // }
        
        //second appraoch is maintaining a smallest and second variable and searching for a 3rd largest variable
        int num1=INT_MAX,num2=INT_MAX;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]<num1)num1=nums[i];
            if(nums[i]>num1 and nums[i]<num2)
            {
                num2=nums[i];
                
            }
            if(nums[i]>num2)return true;
        }
        
        return false;
        
    }
};