class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto i:nums1)
        {
            mp[i]=-1;
        }
        for(auto i:nums2)
        {
            if(mp.count(i))
            {
                mp[i]=1;
            }
        }
        for(auto x:mp)
        {
            if(x.second==1)
            {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};