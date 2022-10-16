//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


int findElement(int arr[], int n) {
    vector<int> maxl,minr;
    int ele=0;
    minr.push_back(arr[n-1]);
    for(int i=n-2;i>=0;--i)
    {
        minr.push_back(min(minr.back(),arr[i]));
    }
    maxl.push_back(arr[0]);
    for(int i=1;i<n;++i)
    {
        maxl.push_back(max(maxl.back(),arr[i]));
    }
    // for(int i=0;i<n;++i)
    // {
    //     cout<<maxl[i]<<" "<<minr[i]<<endl;
    // }
    for(int i=1;i<n-1;++i)
    {
       if(arr[i]>=maxl[i-1] and arr[i]<=minr[n-i-1])return arr[i];
    }
    return -1;
}