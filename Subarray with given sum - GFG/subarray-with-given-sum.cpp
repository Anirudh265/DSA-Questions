//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        if(s==0) return {-1};
        long long sum=0;
        vector<int> ans;
        bool flag=false;
        int l=0,r=0;
        while(l<=n and r<=n)
        {
            if(sum<s)
            {
                while(sum<s)
                {
                    sum+=arr[r];
                    r++;
                }
            }
            else if(sum==s and sum!=0)
            {
                flag=true;
                break;
            }
            else if(sum>s)
            {
                while(sum>s)
                {
                    sum-=arr[l];
                    l++;
                }
            }
            
        }
        if(flag)
        {
            l++;
            ans.push_back(l);
            ans.push_back(r);}
        else
        {
            return {-1};
        }
        return ans;
        
        // Your code here
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends