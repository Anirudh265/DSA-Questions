class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
        {
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        sort(properties.begin(),properties.end(),cmp);
        long long maxi=properties[0][1],cnt=0;
        stack<pair<int,int>> s;
        s.push({properties[0][0],properties[0][1]});
        for(int i=1;i<properties.size();++i)
        {
            while(!s.empty() and properties[i][1]>s.top().second)
            {
                
                
                cnt++;
                s.pop();
                
            }            
            s.push({properties[i][0],properties[i][1]});
            
            
        }
        return cnt;
    }
};