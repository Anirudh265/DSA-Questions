class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        for(int x=0;x<nums.size();++x)
        {
            int i=x+1,j=nums.size()-1;
            int target=-nums[x];
            while(i<j)
            {
                int sum=nums[i]+nums[j];
                if(sum==target)
                {
                    ans.push_back({nums[i],nums[j],nums[x]});
                    while(i<j and nums[i]==nums[i+1])i++;
                    while(i<j and nums[j-1]==nums[j])j--;
                    i++;j--;
                }
                
                else if(sum<target)i++;
                else
                {
                j--;
                }
                
            }
            while(x+1<nums.size() and nums[x]==nums[x+1])x++;
        }
        return ans;
        
    }
};