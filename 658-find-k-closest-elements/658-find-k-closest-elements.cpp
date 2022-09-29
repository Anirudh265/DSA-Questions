class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int small=arr[0];
        int big=arr[arr.size()-1];
        vector<int> ans;
        if(x<small)
        {
            int i=0;
            while(k>0 and i<arr.size())
            {
                ans.push_back(arr[i]);
                i++;
                k--;
            }
        }
        else if(x>big)
        {
            int i=arr.size()-1;
            while(k>0 and i>=0)
            {
                ans.push_back(arr[i]);
                i--;
                k--;
            }
        }
        else
        {
            int ind=0;
            for(int i=0;i<arr.size();++i)
            {
                if(arr[i]<=x)
                {
                    ind=i;
                }
            }
            // cout<<ind;
            int i=ind,j=ind+1;
            while(i>=0 and j<arr.size() and k>0)
            {
                if((arr[j]-x)==(x-arr[i]))
                {
                    ans.push_back(arr[i]);
                    i--;
                    k--;
                    
                }
                else if((x-arr[i])<(arr[j]-x))
                {
                    ans.push_back(arr[i]);
                    i--;
                    k--;
                    
                }
                else if((x-arr[i])>(arr[j]-x))
                {
                    ans.push_back(arr[j]);
                    j++;
                    k--;
                    
                }                   
            }
            while(i>=0 and k>0) 
            {
                k--;
                ans.push_back(arr[i]);
                i--;
            }
            while(j<arr.size() and k>0)
            {ans.push_back(arr[j]);
                k--;
                j++;
                
            }
        }    
        sort(ans.begin(),ans.end());
        return ans;
    }
};