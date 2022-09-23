class Solution {
public:
    int concatenatedBinary(int n) {
        long long int mod=1e9+7;
        long long int prev=0;
        //next sum becomes previous sum->leftshifted by the no of bits in the number + the number
        //1->1
        //2-> 1<<2+2=6
        //3-> 6<<2+3=27
        //basic logic is to just leftshift the previous sum by the number if bits in number and add the number to it
        for(int i=1;i<=n;++i)
        {
            int shift=int(log2(i));
            
            prev=(((prev<<shift+1)%mod)+i)%mod;
        }
        
        return prev;
        
    }
};