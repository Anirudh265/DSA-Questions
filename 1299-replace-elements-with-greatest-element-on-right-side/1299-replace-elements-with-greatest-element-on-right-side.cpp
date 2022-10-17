class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if(arr.size()==1)return {-1};
        vector<int> maxr(arr.size());
        vector<int> ans(arr.size());
        maxr[arr.size()-1]=arr[arr.size()-1];
        int ele=arr[arr.size()-1];
        for(int i=arr.size()-2;i>=0;--i)
        {

            maxr[i]=max(ele,arr[i]);
            ele=max(ele,arr[i]);
        }
        for(int i=0;i<arr.size()-1;++i)
        {
            ans[i]=maxr[i+1];
        }
        ans[ans.size()-1]=-1;
        return ans;
    }
};