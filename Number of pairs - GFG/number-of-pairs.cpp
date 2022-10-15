//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
 

class Solution{
    public:
    
    // X[], Y[]: input arrau
    // M, N: size of arrays X[] and Y[] respectively
    //Function to count number of pairs such that x^y is greater than y^x.
    int bs(int y[],int num,int s)
    {
        int h=s-1;
        int l=0;
        int ind=-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(y[mid]>num)
            {
                ind=mid;
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ind;
    }
    long long countPairs(int x[], int y[], int m, int n)
    {
        sort(y,y+n);
        int z=0,o=0,t=0,f=0,th=0;
        for(int i=0;i<n;++i)
        {
            if(y[i]==0)z++;
            if(y[i]==1)o++;
            if(y[i]==2)t++;
            if(y[i]==3)th++;
            if(y[i]==4)f++;
        }
        long long ans=0;
        for(int i=0;i<m;++i)
        {
            if(x[i]==0)continue;
            else if(x[i]==1)ans+=z;
            else if(x[i]==2)
            {
                int ind=bs(y,2,n);
                if(ind!=-1)ans+=n-ind;
                ans+=z;
                ans+=o;
                ans-=f;
                ans-=th;
            }
            else
            {
                int ind=bs(y,x[i],n);
                if(ind!=-1) ans+=n-ind;
                ans+=z;
                ans+=o;
                if(x[i]==3)ans+=t;
            }
        }
        return ans;
        
       //Your code here
    }
};


//{ Driver Code Starts.
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		Solution ob;
		cout<<ob.countPairs(a, b, M, N)<<endl;
	}
}
// } Driver Code Ends