class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2!=0) return {};
        vector<int> ans;
        unordered_map<int,int> mp;
        sort(changed.begin(),changed.end());
        for(auto i:changed)
        {
            mp[i]++;
        }
        for(auto i:changed)
        {
            if(mp[i]!=0){
            // if(mp[i*2]==0 ) return {};
            ans.push_back(i);
            mp[i]--;
            mp[i*2]--;
            }
            
        }
        if(ans.size()!=changed.size()/2) return {};
        return ans;
        
    }
};