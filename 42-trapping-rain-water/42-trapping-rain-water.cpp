class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1,lmax=0,rmax=0,trap=0;
        while(l<r)
        {
            if(height[l]<height[r])
            {
                if(height[l]>lmax)
                {
                    lmax=height[l];
                }
                else
                {
                    trap+=lmax-height[l];
                }
                l++;
            }
            else
            {
                if(height[r]>rmax)
                {
                    rmax=height[r];
                }
                else
                {
                    trap+=rmax-height[r];
                }
                r--;
            }
        }
        return trap;
        
    }
};