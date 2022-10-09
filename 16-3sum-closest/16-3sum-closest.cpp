class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();++i)
        {
            
            
            int l=i+1,r=nums.size()-1;
            
            while(l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];
                if(abs(sum-target)<mini)
                {
                    mini=abs(sum-target);
                    ans=sum;
                }
                if(sum==target) break;
                else if(sum>target)r--;
                else l++;
                
            }
            while(i+1<nums.size() and nums[i]==nums[i+1])i++;
        }
        return ans;
        
    }
};