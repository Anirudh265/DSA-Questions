class Solution {
public:
    int countElements(vector<int>& nums) {
        //sort the array
        //count numbers other than max element and minelement
        sort(nums.begin(),nums.end());
        int minele=nums[0],maxele=nums[nums.size()-1];
        int i=0;
        int ans=nums.size();
        while(i<nums.size() and nums[i]==minele)
        {
            ans--;
            i++;
        }
        i=nums.size()-1;
        while(i>=0 and nums[i]==maxele)
        {
            ans--;
            i--;
        }
        if(ans<0) return 0;
        else return ans;
    }
};