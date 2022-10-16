class Solution {
public:
    static bool comp(int &a,int &b)
    {
        if(to_string(a)+to_string(b)>to_string(b)+to_string(a))return true;
        else return false;
    }
        
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comp);
        string ans="";
        long long sum=0;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];ans+=to_string(nums[i]);}
        if(sum==0)return "0";
        return ans;
    }
};