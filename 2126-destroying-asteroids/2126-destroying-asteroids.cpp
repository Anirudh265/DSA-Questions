class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(),a.end());
        if(mass>=a[a.size()-1])return true;
        if(mass<a[0])return false;
        long long sum=mass;
        for(auto i:a)
        {
            if(sum>=i)sum+=i;
            else
                return false;
        }
        return true;
        
  
        
        
    }
};