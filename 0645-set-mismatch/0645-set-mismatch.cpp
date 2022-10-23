class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> t(nums.size()+1);
        int repeat; 
        for(int i=0;i<nums.size();++i)
        {
            t[nums[i]]++;
            if(t[nums[i]]==2)repeat=nums[i];
        }
        
        // for(int i=0;i<t.size();++i)
        // {
        //     cout<<i<<" "<<t[i]<<endl;
        // }
        vector<int> ans;
        ans.push_back(repeat);
        for(int i=1;i<t.size();++i)
        {
            if(t[i]==0) ans.push_back(i);
        }
        return ans;
        
        
        
    }
};