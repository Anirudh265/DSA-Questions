class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b)
    {
        return a[1]>b[1];
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> a;
        for(int i=0;i<efficiency.size();++i)
        {
            a.push_back({speed[i],efficiency[i]});
        }
        sort(a.begin(),a.end(),cmp);
        long long mod=pow(10,9)+7;
        long long sum=0,maxperf=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<a.size();++i)
        {
            sum+=a[i][0];
            long perf=sum*a[i][1];
            if(perf>maxperf)
            maxperf=perf;
            pq.push(a[i][0]);  
            if(pq.size()==k)
            {
                sum-=pq.top();
                pq.pop();
            }
        }
        return maxperf%mod;
    
        
        
    }
};