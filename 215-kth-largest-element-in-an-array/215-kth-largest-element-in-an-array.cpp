class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();++i)
        {
            pq.push(nums[i]);
        }
        int f=pq.size()-k+1;
        while(pq.size()>f)
        {
            pq.pop();
        }
        return pq.top();
        
    }
};