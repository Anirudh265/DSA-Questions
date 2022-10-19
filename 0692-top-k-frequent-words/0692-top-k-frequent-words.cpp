class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        unordered_map<int,vector<string>> mp2;
        for(auto i:words)
        {
            mp[i]++;
        }
        for(auto i:mp)
        {
            mp2[i.second].push_back(i.first);
        }
        priority_queue<pair<int,vector<string>>> pq;
        for(auto i:mp2)
        {
            pq.push({i.first,i.second});
        }
        vector<string> ans;
        while(!pq.empty() and k>0)
        {
            
            auto i=pq.top();
            vector<string> temp;
            for(auto x:i.second)
            {
                temp.push_back(x);
            }
            sort(temp.begin(),temp.end());
            for(auto p:temp)
            {
                if(k<=0)break;
                k--;
                ans.push_back(p);
            }
            // k--;
            pq.pop();
        }
        return ans;
        
    }
};