//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          string ans="",temp="";
          ans+=w[0];
          temp+=w[0];
          
          unordered_map<char,int> mp;
          for(int i=0;i<n;++i)
          {
              mp[x[i]]=b[i];
          }
          int gsum=0,lsum=0;
          if(mp.count(w[0]))
          {
              lsum=mp[w[0]];
              gsum=mp[w[0]];
          }
          else
          {
              lsum=int(w[0]);
              gsum=int(w[0]);
          }
          for(int i=1;i<w.size();++i)
          {
              int val=0;
              if(mp.count(w[i]))
              {
                  val=mp[w[i]];
              }
              else
              {
                  val=int(w[i]);
              }
              
              if(lsum+val>=val)
              {
                  lsum+=val;
                  temp+=w[i];
              }
              else
              {
                 lsum=val;
                 temp=w[i];
              }
              
              if(lsum>gsum)
              {
                  gsum=lsum;
                  ans=temp;
              }
              
          }
          return ans;
          
          // code here        
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends