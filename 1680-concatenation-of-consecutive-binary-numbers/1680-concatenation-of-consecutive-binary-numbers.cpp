class Solution {
public:
    int concatenatedBinary(int n) {
        long long int mod=1e9+7;
        long long int prev=0;
        for(int i=1;i<=n;++i)
        {
            int shift=int(log2(i));
            
            prev=(((prev<<shift+1)%mod)+i)%mod;
        }
        return prev;
        
    }
};