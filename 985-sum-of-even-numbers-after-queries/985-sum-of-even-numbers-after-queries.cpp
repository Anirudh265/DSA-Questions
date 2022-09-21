class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0;
        unordered_map<int,int> mp;
        vector<int> ret;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]%2==0)
            {
                sum+=nums[i];
                mp[i]=nums[i];
            }
        }
        for(int i=0;i<queries.size();++i)
        {
            
            int val=queries[i][0];
            int ind=queries[i][1];
            nums[ind]=nums[ind]+val;
            if(mp.count(ind))
            {
                if(nums[ind]%2!=0)
                {
                    sum-=mp[ind];
                    mp.erase(ind);
                }
                else
                {
                   int dif=nums[ind]-mp[ind];
                    sum+=dif;
                    mp[ind]=nums[ind];
                }
            }
            else
            {
                if(nums[ind]%2==0)
                {
                    sum+=nums[ind];
                    mp[ind]=nums[ind];
                }
                
            }
            ret.push_back(sum);            
            
        }
        return ret;
        
        
    }
};