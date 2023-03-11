//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        vector<int> ret;
        int cnt=0,row=0;
        for(int i=0;i<N;++i)
        {
            int one=0;
            for(int j=0;j<N;++j)
            {
               if(mat[i][j]==1)
               {
                   one++;
               }
               
               
            }
            if(one>cnt)
            {
                cnt=one;
                row=i;
            }
        }
        ret.push_back(row);
        ret.push_back(cnt);
        return ret;
        //code here
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends