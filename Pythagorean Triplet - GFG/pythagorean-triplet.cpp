//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    if(n<3)return false;
	    unordered_map<int,int> mp;
	    vector<int> temp;
	    for(int i=0;i<n;++i)
	    {
	        temp.push_back(pow(arr[i],2));
	        mp[pow(arr[i],2)]++;
	    }
	    sort(temp.begin(),temp.end());
	    for(int i=n-1;i>=0;--i)
	    {
	        int t=temp[i];
	        int l=0,j=i-1;
	        while(l<j)
	        {
	            if(temp[l]+temp[j]==t)return true;
	            else if(temp[l]+temp[j]>t)j--;
	            else l++;
	        }
	    }
	    return false;
	    
	    
	    // code here
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends